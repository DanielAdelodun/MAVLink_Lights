// MESSAGE AIRLINK_EYE_GS_HOLE_PUSH_RESPONSE support class

#pragma once

namespace mavlink {
namespace csAirLink {
namespace msg {

/**
 * @brief AIRLINK_EYE_GS_HOLE_PUSH_RESPONSE message
 *
 * Response information about the connected device
 */
struct AIRLINK_EYE_GS_HOLE_PUSH_RESPONSE : mavlink::Message {
    static constexpr msgid_t MSG_ID = 52003;
    static constexpr size_t LENGTH = 26;
    static constexpr size_t MIN_LENGTH = 26;
    static constexpr uint8_t CRC_EXTRA = 166;
    static constexpr auto NAME = "AIRLINK_EYE_GS_HOLE_PUSH_RESPONSE";


    uint8_t resp_type; /*<  Hole push response type */
    uint8_t ip_version; /*<  ip version */
    std::array<uint8_t, 4> ip_address_4; /*<  ip 4 address */
    std::array<uint8_t, 16> ip_address_6; /*<  ip 6 address */
    uint32_t ip_port; /*<  port */


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
        ss << "  ip_version: " << +ip_version << std::endl;
        ss << "  ip_address_4: [" << to_string(ip_address_4) << "]" << std::endl;
        ss << "  ip_address_6: [" << to_string(ip_address_6) << "]" << std::endl;
        ss << "  ip_port: " << ip_port << std::endl;

        return ss.str();
    }

    inline void serialize(mavlink::MsgMap &map) const override
    {
        map.reset(MSG_ID, LENGTH);

        map << ip_port;                       // offset: 0
        map << resp_type;                     // offset: 4
        map << ip_version;                    // offset: 5
        map << ip_address_4;                  // offset: 6
        map << ip_address_6;                  // offset: 10
    }

    inline void deserialize(mavlink::MsgMap &map) override
    {
        map >> ip_port;                       // offset: 0
        map >> resp_type;                     // offset: 4
        map >> ip_version;                    // offset: 5
        map >> ip_address_4;                  // offset: 6
        map >> ip_address_6;                  // offset: 10
    }
};

} // namespace msg
} // namespace csAirLink
} // namespace mavlink
