// MESSAGE LED_STRIP_CONFIG support class

#pragma once

namespace mavlink {
namespace ledstrip {
namespace msg {

/**
 * @brief LED_STRIP_CONFIG message
 *
 * Set an LED strips colours. Can set up to 8 starting from led_index, or all using fill_mode=LED_FILL_MODE_ALL.
 */
struct LED_STRIP_CONFIG : mavlink::Message {
    static constexpr msgid_t MSG_ID = 60200;
    static constexpr size_t LENGTH = 38;
    static constexpr size_t MIN_LENGTH = 38;
    static constexpr uint8_t CRC_EXTRA = 215;
    static constexpr auto NAME = "LED_STRIP_CONFIG";


    uint8_t target_system; /*<  System ID */
    uint8_t target_component; /*<  Component ID (LED_Strips_Controller should be 134) */
    uint8_t fill_mode; /*<  Fill Mode */
    uint8_t led_index; /*<  Start LED */
    uint8_t length; /*<  Number of LEDs to fill (limited to 8 by colors array) */
    uint8_t strip_id; /*<  Which strip to configure */
    std::array<uint32_t, 8> colors; /*<  Array of 32-bit Colours (0xWWRRGGBB) */


    inline std::string get_name(void) const override
    {
            return NAME;
    }

    inline Info get_message_info(void) const override
    {
            return { MSG_ID, LENGTH, MIN_LENGTH, CRC_EXTRA };
    }

    inline std::string to_yaml(void) const override
    {
        std::stringstream ss;

        ss << NAME << ":" << std::endl;
        ss << "  target_system: " << +target_system << std::endl;
        ss << "  target_component: " << +target_component << std::endl;
        ss << "  fill_mode: " << +fill_mode << std::endl;
        ss << "  led_index: " << +led_index << std::endl;
        ss << "  length: " << +length << std::endl;
        ss << "  strip_id: " << +strip_id << std::endl;
        ss << "  colors: [" << to_string(colors) << "]" << std::endl;

        return ss.str();
    }

    inline void serialize(mavlink::MsgMap &map) const override
    {
        map.reset(MSG_ID, LENGTH);

        map << colors;                        // offset: 0
        map << target_system;                 // offset: 32
        map << target_component;              // offset: 33
        map << fill_mode;                     // offset: 34
        map << led_index;                     // offset: 35
        map << length;                        // offset: 36
        map << strip_id;                      // offset: 37
    }

    inline void deserialize(mavlink::MsgMap &map) override
    {
        map >> colors;                        // offset: 0
        map >> target_system;                 // offset: 32
        map >> target_component;              // offset: 33
        map >> fill_mode;                     // offset: 34
        map >> led_index;                     // offset: 35
        map >> length;                        // offset: 36
        map >> strip_id;                      // offset: 37
    }
};

} // namespace msg
} // namespace ledstrip
} // namespace mavlink
