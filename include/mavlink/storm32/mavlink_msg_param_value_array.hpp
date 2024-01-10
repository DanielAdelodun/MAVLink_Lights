// MESSAGE PARAM_VALUE_ARRAY support class

#pragma once

namespace mavlink {
namespace storm32 {
namespace msg {

/**
 * @brief PARAM_VALUE_ARRAY message
 *
 * Parameter multi param value container.
 */
struct PARAM_VALUE_ARRAY : mavlink::Message {
    static constexpr msgid_t MSG_ID = 60041;
    static constexpr size_t LENGTH = 255;
    static constexpr size_t MIN_LENGTH = 255;
    static constexpr uint8_t CRC_EXTRA = 191;
    static constexpr auto NAME = "PARAM_VALUE_ARRAY";


    uint16_t param_count; /*<  Total number of onboard parameters. */
    uint16_t param_index_first; /*<  Index of the first onboard parameter in this array. */
    uint8_t param_array_len; /*<  Number of onboard parameters in this array. */
    uint16_t flags; /*<  Flags. */
    std::array<uint8_t, 248> packet_buf; /*<  Parameters buffer. Contains a series of variable length parameter blocks, one per parameter, with format as specifed elsewhere. */


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
        ss << "  param_count: " << param_count << std::endl;
        ss << "  param_index_first: " << param_index_first << std::endl;
        ss << "  param_array_len: " << +param_array_len << std::endl;
        ss << "  flags: " << flags << std::endl;
        ss << "  packet_buf: [" << to_string(packet_buf) << "]" << std::endl;

        return ss.str();
    }

    inline void serialize(mavlink::MsgMap &map) const override
    {
        map.reset(MSG_ID, LENGTH);

        map << param_count;                   // offset: 0
        map << param_index_first;             // offset: 2
        map << flags;                         // offset: 4
        map << param_array_len;               // offset: 6
        map << packet_buf;                    // offset: 7
    }

    inline void deserialize(mavlink::MsgMap &map) override
    {
        map >> param_count;                   // offset: 0
        map >> param_index_first;             // offset: 2
        map >> flags;                         // offset: 4
        map >> param_array_len;               // offset: 6
        map >> packet_buf;                    // offset: 7
    }
};

} // namespace msg
} // namespace storm32
} // namespace mavlink
