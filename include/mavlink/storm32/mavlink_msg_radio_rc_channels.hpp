// MESSAGE RADIO_RC_CHANNELS support class

#pragma once

namespace mavlink {
namespace storm32 {
namespace msg {

/**
 * @brief RADIO_RC_CHANNELS message
 *
 * Radio channels. Supports up to 24 channels. Channel values are in centerd 13 bit format. Range is [-4096,4096], center is 0. Conversion to PWM is x * 5/32 + 1500. Should be emitted only by components with component id MAV_COMP_ID_TELEMETRY_RADIO.
 */
struct RADIO_RC_CHANNELS : mavlink::Message {
    static constexpr msgid_t MSG_ID = 60045;
    static constexpr size_t LENGTH = 50;
    static constexpr size_t MIN_LENGTH = 2;
    static constexpr uint8_t CRC_EXTRA = 89;
    static constexpr auto NAME = "RADIO_RC_CHANNELS";


    uint8_t count; /*<  Total number of RC channels being received. This can be larger than 24, indicating that more channels are available but not given in this message. */
    uint8_t flags; /*<  Radio channels status flags. */
    std::array<int16_t, 24> channels; /*<  RC channels. Channels above count should be set to 0, to benefit from MAVLink's zero padding. */


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
        ss << "  count: " << +count << std::endl;
        ss << "  flags: " << +flags << std::endl;
        ss << "  channels: [" << to_string(channels) << "]" << std::endl;

        return ss.str();
    }

    inline void serialize(mavlink::MsgMap &map) const override
    {
        map.reset(MSG_ID, LENGTH);

        map << count;                         // offset: 0
        map << flags;                         // offset: 1
        map << channels;                      // offset: 2
    }

    inline void deserialize(mavlink::MsgMap &map) override
    {
        map >> count;                         // offset: 0
        map >> flags;                         // offset: 1
        map >> channels;                      // offset: 2
    }
};

} // namespace msg
} // namespace storm32
} // namespace mavlink
