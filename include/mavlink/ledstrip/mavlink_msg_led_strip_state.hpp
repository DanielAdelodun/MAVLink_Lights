// MESSAGE LED_STRIP_STATE support class

#pragma once

namespace mavlink {
namespace ledstrip {
namespace msg {

/**
 * @brief LED_STRIP_STATE message
 *
 * Current LED State. Emitted by LED 'server'.
 */
struct LED_STRIP_STATE : mavlink::Message {
    static constexpr msgid_t MSG_ID = 60201;
    static constexpr size_t LENGTH = 36;
    static constexpr size_t MIN_LENGTH = 36;
    static constexpr uint8_t CRC_EXTRA = 254;
    static constexpr auto NAME = "LED_STRIP_STATE";


    uint8_t length; /*<  How many LEDs on strip_id are being reported, starting from led_index */
    uint8_t led_index; /*<  Index of first LED being reported */
    uint8_t strip_id; /*<  Which strip */
    uint8_t following_mode; /*<  Boolean indicating if LED colours are following the flightmode (1) or not (0) */
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
        ss << "  length: " << +length << std::endl;
        ss << "  led_index: " << +led_index << std::endl;
        ss << "  strip_id: " << +strip_id << std::endl;
        ss << "  following_mode: " << +following_mode << std::endl;
        ss << "  colors: [" << to_string(colors) << "]" << std::endl;

        return ss.str();
    }

    inline void serialize(mavlink::MsgMap &map) const override
    {
        map.reset(MSG_ID, LENGTH);

        map << colors;                        // offset: 0
        map << length;                        // offset: 32
        map << led_index;                     // offset: 33
        map << strip_id;                      // offset: 34
        map << following_mode;                // offset: 35
    }

    inline void deserialize(mavlink::MsgMap &map) override
    {
        map >> colors;                        // offset: 0
        map >> length;                        // offset: 32
        map >> led_index;                     // offset: 33
        map >> strip_id;                      // offset: 34
        map >> following_mode;                // offset: 35
    }
};

} // namespace msg
} // namespace ledstrip
} // namespace mavlink
