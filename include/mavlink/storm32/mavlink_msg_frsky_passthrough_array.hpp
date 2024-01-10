// MESSAGE FRSKY_PASSTHROUGH_ARRAY support class

#pragma once

namespace mavlink {
namespace storm32 {
namespace msg {

/**
 * @brief FRSKY_PASSTHROUGH_ARRAY message
 *
 * Frsky SPort passthrough multi packet container.
 */
struct FRSKY_PASSTHROUGH_ARRAY : mavlink::Message {
    static constexpr msgid_t MSG_ID = 60040;
    static constexpr size_t LENGTH = 245;
    static constexpr size_t MIN_LENGTH = 245;
    static constexpr uint8_t CRC_EXTRA = 156;
    static constexpr auto NAME = "FRSKY_PASSTHROUGH_ARRAY";


    uint32_t time_boot_ms; /*< [ms] Timestamp (time since system boot). */
    uint8_t count; /*<  Number of passthrough packets in this message. */
    std::array<uint8_t, 240> packet_buf; /*<  Passthrough packet buffer. A packet has 6 bytes: uint16_t id + uint32_t data. The array has space for 40 packets. */


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
        ss << "  time_boot_ms: " << time_boot_ms << std::endl;
        ss << "  count: " << +count << std::endl;
        ss << "  packet_buf: [" << to_string(packet_buf) << "]" << std::endl;

        return ss.str();
    }

    inline void serialize(mavlink::MsgMap &map) const override
    {
        map.reset(MSG_ID, LENGTH);

        map << time_boot_ms;                  // offset: 0
        map << count;                         // offset: 4
        map << packet_buf;                    // offset: 5
    }

    inline void deserialize(mavlink::MsgMap &map) override
    {
        map >> time_boot_ms;                  // offset: 0
        map >> count;                         // offset: 4
        map >> packet_buf;                    // offset: 5
    }
};

} // namespace msg
} // namespace storm32
} // namespace mavlink
