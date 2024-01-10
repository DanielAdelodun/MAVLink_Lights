// MESSAGE AIRLINK_EYE_GS_HOLE_PUSH_REQUEST support class

#pragma once

namespace mavlink {
namespace csAirLink {
namespace msg {

/**
 * @brief AIRLINK_EYE_GS_HOLE_PUSH_REQUEST message
 *
 * Request to hole punching
 */
struct AIRLINK_EYE_GS_HOLE_PUSH_REQUEST : mavlink::Message {
    static constexpr msgid_t MSG_ID = 52002;
    static constexpr size_t LENGTH = 1;
    static constexpr size_t MIN_LENGTH = 1;
    static constexpr uint8_t CRC_EXTRA = 24;
    static constexpr auto NAME = "AIRLINK_EYE_GS_HOLE_PUSH_REQUEST";


    uint8_t resp_type; /*<  Hole push response type */


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
        ss << "  resp_type: " << +resp_type << std::endl;

        return ss.str();
    }

    inline void serialize(mavlink::MsgMap &map) const override
    {
        map.reset(MSG_ID, LENGTH);

        map << resp_type;                     // offset: 0
    }

    inline void deserialize(mavlink::MsgMap &map) override
    {
        map >> resp_type;                     // offset: 0
    }
};

} // namespace msg
} // namespace csAirLink
} // namespace mavlink
