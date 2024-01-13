#include <stdio.h>
#include "pico/stdlib.h"
#include "pico/multicore.h"
#include "pico/util/queue.h"
#include "hardware/dma.h"
#include "hardware/pio.h"
#include "hardware/gpio.h"

#include "mavlink/stemstudios/mavlink.h"
#include "ws2812.pio.h"

#include "flight_mode.h"

#define BUTTON_POWER 2 // Set Low Turn Off Lights (TODO)
#define BUTTON_TESTn 3 // Set Low Test (All On) Lights (TODO)
#define LED_POWER   25 // Power LED (Pico LED)

#define UART1_TX_PIN 4
#define UART1_RX_PIN 5

#define MAVLINK_PIXEL_ARRAY_SIZE 8
#define MAX_PIXELS_PER_STRIP 32  // Power of 2
#define MAX_STRIPS 8 // 8 or less
#define IS_RGBW false

#define MAVLINK_SYS_ID 1
#define MAVLINK_COMP_ID 134

inline static void io_init();

typedef struct WS2812 {
    PIO pio; 
    uint8_t sm;
    uint8_t gpio;
    uint8_t dma;

    bool followfm;

    _Alignas(MAX_PIXELS_PER_STRIP * sizeof(uint32_t)) 
        uint32_t pixels[MAX_PIXELS_PER_STRIP];
} WS2812_t;
inline static void ws2812_init(uint offset);
static WS2812_t ws2812s[MAX_STRIPS];

inline static uint32_t rgb_u32(const uint8_t red, const uint8_t green, const uint8_t blue);
inline static uint32_t rgb32_u32(const uint32_t rgb);

void queue_write();
void queue_read();
bool send_heartbeat(struct repeating_timer *t);
bool ws2812_render(struct repeating_timer *t);
void configure_led_strip(WS2812_t *ws2812, mavlink_led_strip_config_t *config);

queue_t msg_queue;
mutex_t ws2812_mutex;

int main() {
    stdio_init_all();

    io_init();

    queue_init(&msg_queue, sizeof(mavlink_message_t), 64);
    mutex_init(&ws2812_mutex);

    struct repeating_timer msg_timer;
    add_repeating_timer_ms(-1000, send_heartbeat, NULL, &msg_timer);

    uint offset = pio_add_program(pio0, &ws2812_program);
    pio_add_program_at_offset(pio1, &ws2812_program, offset);
    ws2812_init(offset);

    struct repeating_timer ws2812_timer;
    add_repeating_timer_ms(-20, ws2812_render, NULL, &ws2812_timer);

    multicore_launch_core1(queue_read);
    queue_write();

    return 0;
}

inline static void io_init() {
    stdio_init_all();

    uart_init(uart1, 115200);
    gpio_set_function(UART1_TX_PIN, GPIO_FUNC_UART);
    gpio_set_function(UART1_RX_PIN, GPIO_FUNC_UART);
#ifdef DEBUG
    puts("Hello From UART0 (stdin)!");
    uart_puts(uart1, "Hello From UART1 (mavlink)!\n");
#endif
}

inline static void ws2812_init(uint offset) {
    for (int i = 0; i < MAX_STRIPS; i++) {
        WS2812_t *ws2812 = &ws2812s[i];
        ws2812->pio = (i < 4) ? pio0 : pio1;
        ws2812->sm = pio_claim_unused_sm(ws2812->pio, true);
        ws2812->gpio = 6 + i;
        ws2812->dma = dma_claim_unused_channel(true);
        ws2812->followfm = true;
        for (int j = 0; j < MAX_PIXELS_PER_STRIP; j++) {
            switch (i) {
                case 0:
                    ws2812->pixels[j] = rgb_u32(0xFF, 0x00, 0x00);
                    break;
                case 1:
                    ws2812->pixels[j] = rgb_u32(0x00, 0xFF, 0x00);
                    break;
                case 2:
                    ws2812->pixels[j] = rgb_u32(0x00, 0x00, 0xFF);
                    break;
                default: 
                    if (j >= 3 && j < 8)
                        ws2812->pixels[j] = rgb_u32(0x00, 0x22 * i, 0xFF);
                    else
                        ws2812->pixels[j] = rgb_u32(0x00, 0x00, 0x00);
                    break;
            }
        }
        ws2812_program_init(ws2812->pio, ws2812->sm, offset, ws2812->gpio, 800000, IS_RGBW);
        ws2812_dma_init(ws2812->dma, ws2812->pio, ws2812->sm, MAX_PIXELS_PER_STRIP, ws2812->pixels);
    }
}

void queue_write() {
    while (true) {
        mavlink_message_t msg;
        mavlink_status_t status;
        uint8_t c;
        while ( true ) {
            c = uart_getc(uart1);
            if (mavlink_parse_char(MAVLINK_COMM_0, c, &msg, &status)) {
                if (msg.msgid == MAVLINK_MSG_ID_LED_STRIP_CONFIG)
                    queue_add_blocking(&msg_queue, &msg);
                else if (msg.msgid == MAVLINK_MSG_ID_HEARTBEAT && msg.sysid == MAVLINK_SYS_ID && msg.compid == 1)
                    queue_add_blocking(&msg_queue, &msg);
            }
        }
    }
}

void queue_read() {
    while (true) {
        mavlink_message_t msg;
        queue_remove_blocking(&msg_queue, &msg);
        printf("Received message with ID %d, sequence: %d from component %d of system %d\n", 
            msg.msgid, msg.seq, msg.compid, msg.sysid);

        if (msg.msgid == MAVLINK_MSG_ID_LED_STRIP_CONFIG) {
            mavlink_led_strip_config_t config;
            mavlink_msg_led_strip_config_decode(&msg, &config);
#ifdef DEBUG
            const char *mode_map[] = {"ALL", "INDEX", "FOLLOW_FLIGHT_MODE", "CLEAR"};
            printf("Requested Target System: %d\n", config.target_system);
            printf("Requested Target Component: %d\n", config.target_component);
            printf("Requested Fill Mode: %s\n", mode_map[config.fill_mode]);
            printf("Requested LED Strip ID: %d\n", config.strip_id);
            printf("Requested LED Index: %d\n", config.led_index);
            printf("Requested Colors:\n");
            for (int i = 0; i < MAVLINK_PIXEL_ARRAY_SIZE; i++) {
                printf(" LED %d: %08X\n", i, config.colors[i]);
            }
            printf("\n");
#endif
            if (config.target_system == MAVLINK_SYS_ID) {
                if (config.strip_id == UINT8_MAX) {
                    for (int i = 0; i < MAX_STRIPS; i++) {
                        configure_led_strip(&ws2812s[i], &config);
                        continue;
                    }
                }
                if (config.strip_id >= MAX_STRIPS) {
#ifdef DEBUG
                    printf("Invalid LED Strip ID. Max is: %d\n", MAX_STRIPS - 1);
#endif
                    continue;
                }
                configure_led_strip(&ws2812s[config.strip_id], &config);
            }
        } else if (msg.msgid == MAVLINK_MSG_ID_HEARTBEAT) {
            mavlink_heartbeat_t hb;
            mavlink_msg_heartbeat_decode(&msg, &hb);
#ifdef DEBUG
            printf("Received Heartbeat:\n");
            printf("Type: %d\n", hb.type);
            printf("Autopilot: %d\n", hb.autopilot);
            printf("Base Mode: %08X\n", hb.base_mode);
            printf("Custom Mode: %08X\n", hb.custom_mode);
            printf("System Status: %d\n", hb.system_status);
            printf("Mavlink Version: %d\n", hb.mavlink_version);
#endif
            union px4_custom_mode custom_mode;
            custom_mode.data = hb.custom_mode;

            uint8_t main_mode = custom_mode.main_mode;
            uint8_t sub_mode = custom_mode.sub_mode;
#ifdef DEBUG
            printf("Main Mode: %d\n", main_mode);
            printf("Sub Mode: %d\n", sub_mode);
#endif

            if (msg.sysid == MAVLINK_SYS_ID && msg.compid == 1) {
                uint32_t color = 0x000000;

                switch (main_mode) {
                    case PX4_CUSTOM_MAIN_MODE_MANUAL:
                        color = 0xFF0000; // Red
                        break;
                    case PX4_CUSTOM_MAIN_MODE_ALTCTL:
                        color = 0xD2691E; // Chocolate
                        break;
                    case PX4_CUSTOM_MAIN_MODE_POSCTL:
                        switch (sub_mode) {
                            case PX4_CUSTOM_SUB_MODE_POSCTL_POSCTL:
                                color = 0x0000FF; // Blue
                                break;
                            case PX4_CUSTOM_SUB_MODE_POSCTL_ORBIT:
                                color = 0xA020F0; // Purple
                                break;
                            case PX4_CUSTOM_SUB_MODE_POSCTL_SLOW:
                                color = 0x9370DB; // MediumPurple
                                break;
                            default:
                                color = 0xFFFFFF;
                                break;
                        }
                        break;
                    case PX4_CUSTOM_MAIN_MODE_AUTO:
                        switch (sub_mode) {
                            case PX4_CUSTOM_SUB_MODE_AUTO_READY:
                                color = 0x00FF8F; // SpringGreen
                                break;
                            case PX4_CUSTOM_SUB_MODE_AUTO_TAKEOFF:
                                color = 0xFFA07A; // LightSalmon
                                break;
                            case PX4_CUSTOM_SUB_MODE_AUTO_LOITER:
                                color = 0xFF8C00; // DarkOrange
                                break;
                            case PX4_CUSTOM_SUB_MODE_AUTO_MISSION:
                                color = 0x00FF00; // Green
                                break;
                            case PX4_CUSTOM_SUB_MODE_AUTO_RTL:
                                color = 0x00FFFF; // Cyan
                                break;
                            case PX4_CUSTOM_SUB_MODE_AUTO_LAND:
                                color = 0xFFA500; // Orange
                                break;
                            case PX4_CUSTOM_SUB_MODE_AUTO_RESERVED_DO_NOT_USE:
                                color = 0x000000; 
                                break;
                            case PX4_CUSTOM_SUB_MODE_AUTO_FOLLOW_TARGET:
                                color = 0x98FB98; // PaleGreen
                                break;
                            default:
                                color = 0xFFFFFF;
                                break;
                        }
                        break;
                    case PX4_CUSTOM_MAIN_MODE_ACRO:
                        color = 0xFF69B4; // HotPink
                        break;
                    case PX4_CUSTOM_MAIN_MODE_OFFBOARD:
                        color = 0xFFFF00; // Yellow
                        break;
                    case PX4_CUSTOM_MAIN_MODE_STABILIZED:
                        color = 0xFF0000; // Red
                        break;
                    case PX4_CUSTOM_MAIN_MODE_RATTITUDE_LEGACY:
                        color = 0xFFFFFF;
                        break;
                    case PX4_CUSTOM_MAIN_MODE_SIMPLE:
                        color = 0xFFFFFF;
                        break;
                    case PX4_CUSTOM_MAIN_MODE_TERMINATION:
                        color = 0xFFFFFF;
                        break;
                    default:
                        color = 0xFFFFFF;
                        break;
                }

#ifdef DEBUG
                printf("Color: %08X\n", color);
                printf("\n");
#endif

                for (int i = 0; i < MAX_STRIPS; i++) {
                    WS2812_t *ws2812 = &ws2812s[i];
                    mutex_enter_blocking(&ws2812_mutex);
                    if (ws2812->followfm) {
                        for (int j = 0; j < MAX_PIXELS_PER_STRIP; j++) {
                            ws2812->pixels[j] = rgb32_u32(color);
                        }
                    }
                    mutex_exit(&ws2812_mutex);
                }
            }
        }
    }
}

bool send_heartbeat(struct repeating_timer *t) {
    mavlink_message_t msg;
    mavlink_msg_heartbeat_pack(
        MAVLINK_SYS_ID, 
        MAVLINK_COMP_ID, 
        &msg, 
        MAV_TYPE_ONBOARD_CONTROLLER, 
        MAV_AUTOPILOT_INVALID, 
        0, 0, 
        MAV_STATE_STANDBY
    );
    uint8_t buf[MAVLINK_MAX_PACKET_LEN];
    uint16_t len = mavlink_msg_to_send_buffer(buf, &msg);
    uart_write_blocking(uart1, buf, len);    
    return true;
}

bool ws2812_render(struct repeating_timer *t) {
    if (!mutex_try_enter(&ws2812_mutex, 0)) {
        return true;
    }
    for (int i = 0; i < MAX_STRIPS; i++) {
        dma_channel_start(ws2812s[i].dma);
    }
    mutex_exit(&ws2812_mutex);
    return true;
}

static inline uint32_t rgb_u32(const uint8_t red, const uint8_t green, const uint8_t blue) {
    return
            ((uint32_t) (red)   << 16) |
            ((uint32_t) (green) << 24) |
            ((uint32_t) (blue)  <<  8) ;
}

static inline uint32_t rgb32_u32(const uint32_t rgb) {
    uint8_t r = (0x00ff0000 & rgb) >> 16;
    uint8_t g = (0x0000ff00 & rgb) >> 8;
    uint8_t b = (0x000000ff & rgb);
    return rgb_u32(r, g, b);
}

void configure_led_strip(WS2812_t *ws2812, mavlink_led_strip_config_t *config) {
    uint8_t  id         = config->strip_id;
    uint8_t  led_index  = config->led_index;
    uint8_t  length     = config->length;
    uint32_t *colors    = config->colors;

    mutex_enter_blocking(&ws2812_mutex);

    switch (config->fill_mode) {
        case LED_FILL_MODE_ALL:
            ws2812->followfm = false;
            for (int i = 0; i < MAX_PIXELS_PER_STRIP; i++) {
                ws2812->pixels[i] = rgb32_u32(colors[0]);
            }
            break;
        case LED_FILL_MODE_INDEX:
            if (ws2812->followfm) {
                ws2812->followfm = false;
                for (int i = 0; i < MAX_PIXELS_PER_STRIP; i++) {
                    ws2812->pixels[i] = rgb_u32(0x00, 0x00, 0x00);
                }
            }
            for (int i = 0; i < length && (i + led_index) < MAX_PIXELS_PER_STRIP; i++) {
                ws2812->pixels[i + led_index] = rgb32_u32(colors[i]);
            }
            break;
        case LED_FILL_MODE_FOLLOW_FLIGHT_MODE:
            for (int i = 0; i < MAX_STRIPS; i++) {
                ws2812s[i].followfm = true;
            }
            break;
        case LED_FILL_MODE_CLEAR:
            ws2812->followfm = false;
            for (int i = 0; i < MAX_PIXELS_PER_STRIP; i++) {
                ws2812->pixels[i] = rgb_u32(0x00, 0x00, 0x00);
            }
            break;
        default:
            break;
    }

    mutex_exit(&ws2812_mutex);
}