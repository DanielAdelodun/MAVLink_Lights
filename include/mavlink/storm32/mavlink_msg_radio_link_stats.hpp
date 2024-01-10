// MESSAGE RADIO_LINK_STATS support class

#pragma once

namespace mavlink {
namespace storm32 {
namespace msg {

/**
 * @brief RADIO_LINK_STATS message
 *
 * Radio link statistics. Should be emitted only by components with component id MAV_COMP_ID_TELEMETRY_RADIO. Per default, rssi values are in MAVLink units: 0 represents weakest signal, 254 represents maximum signal; can be changed to dBm with the flag RADIO_LINK_STATS_FLAGS_RSSI_DBM.
 */
struct RADIO_LINK_STATS : mavlink::Message {
    static constexpr msgid_t MSG_ID = 60046;
    static constexpr size_t LENGTH = 15;
    static constexpr size_t MIN_LENGTH = 15;
    static constexpr uint8_t CRC_EXTRA = 238;
    static constexpr auto NAME = "RADIO_LINK_STATS";


    uint8_t flags; /*<  Radio link statistics flags. */
    uint8_t rx_LQ; /*< [c%] Values: 0..100. UINT8_MAX: invalid/unknown. */
    uint8_t rx_rssi1; /*<  Rssi of antenna1. UINT8_MAX: invalid/unknown. */
    int8_t rx_snr1; /*<  Noise on antenna1. Radio dependent. INT8_MAX: invalid/unknown. */
    uint8_t rx_rssi2; /*<  Rssi of antenna2. UINT8_MAX: ignore/unknown, use rx_rssi1. */
    int8_t rx_snr2; /*<  Noise on antenna2. Radio dependent. INT8_MAX: ignore/unknown, use rx_snr1. */
    uint8_t rx_receive_antenna; /*<  0: antenna1, 1: antenna2, UINT8_MAX: ignore, no Rx receive diversity, use rx_rssi1, rx_snr1. */
    uint8_t rx_transmit_antenna; /*<  0: antenna1, 1: antenna2, UINT8_MAX: ignore, no Rx transmit diversity. */
    uint8_t tx_LQ; /*< [c%] Values: 0..100. UINT8_MAX: invalid/unknown. */
    uint8_t tx_rssi1; /*<  Rssi of antenna1. UINT8_MAX: invalid/unknown. */
    int8_t tx_snr1; /*<  Noise on antenna1. Radio dependent. INT8_MAX: invalid/unknown. */
    uint8_t tx_rssi2; /*<  Rssi of antenna2. UINT8_MAX: ignore/unknown, use tx_rssi1. */
    int8_t tx_snr2; /*<  Noise on antenna2. Radio dependent. INT8_MAX: ignore/unknown, use tx_snr1. */
    uint8_t tx_receive_antenna; /*<  0: antenna1, 1: antenna2, UINT8_MAX: ignore, no Tx receive diversity, use tx_rssi1, tx_snr1. */
    uint8_t tx_transmit_antenna; /*<  0: antenna1, 1: antenna2, UINT8_MAX: ignore, no Tx transmit diversity. */


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
        ss << "  flags: " << +flags << std::endl;
        ss << "  rx_LQ: " << +rx_LQ << std::endl;
        ss << "  rx_rssi1: " << +rx_rssi1 << std::endl;
        ss << "  rx_snr1: " << +rx_snr1 << std::endl;
        ss << "  rx_rssi2: " << +rx_rssi2 << std::endl;
        ss << "  rx_snr2: " << +rx_snr2 << std::endl;
        ss << "  rx_receive_antenna: " << +rx_receive_antenna << std::endl;
        ss << "  rx_transmit_antenna: " << +rx_transmit_antenna << std::endl;
        ss << "  tx_LQ: " << +tx_LQ << std::endl;
        ss << "  tx_rssi1: " << +tx_rssi1 << std::endl;
        ss << "  tx_snr1: " << +tx_snr1 << std::endl;
        ss << "  tx_rssi2: " << +tx_rssi2 << std::endl;
        ss << "  tx_snr2: " << +tx_snr2 << std::endl;
        ss << "  tx_receive_antenna: " << +tx_receive_antenna << std::endl;
        ss << "  tx_transmit_antenna: " << +tx_transmit_antenna << std::endl;

        return ss.str();
    }

    inline void serialize(mavlink::MsgMap &map) const override
    {
        map.reset(MSG_ID, LENGTH);

        map << flags;                         // offset: 0
        map << rx_LQ;                         // offset: 1
        map << rx_rssi1;                      // offset: 2
        map << rx_snr1;                       // offset: 3
        map << rx_rssi2;                      // offset: 4
        map << rx_snr2;                       // offset: 5
        map << rx_receive_antenna;            // offset: 6
        map << rx_transmit_antenna;           // offset: 7
        map << tx_LQ;                         // offset: 8
        map << tx_rssi1;                      // offset: 9
        map << tx_snr1;                       // offset: 10
        map << tx_rssi2;                      // offset: 11
        map << tx_snr2;                       // offset: 12
        map << tx_receive_antenna;            // offset: 13
        map << tx_transmit_antenna;           // offset: 14
    }

    inline void deserialize(mavlink::MsgMap &map) override
    {
        map >> flags;                         // offset: 0
        map >> rx_LQ;                         // offset: 1
        map >> rx_rssi1;                      // offset: 2
        map >> rx_snr1;                       // offset: 3
        map >> rx_rssi2;                      // offset: 4
        map >> rx_snr2;                       // offset: 5
        map >> rx_receive_antenna;            // offset: 6
        map >> rx_transmit_antenna;           // offset: 7
        map >> tx_LQ;                         // offset: 8
        map >> tx_rssi1;                      // offset: 9
        map >> tx_snr1;                       // offset: 10
        map >> tx_rssi2;                      // offset: 11
        map >> tx_snr2;                       // offset: 12
        map >> tx_receive_antenna;            // offset: 13
        map >> tx_transmit_antenna;           // offset: 14
    }
};

} // namespace msg
} // namespace storm32
} // namespace mavlink
