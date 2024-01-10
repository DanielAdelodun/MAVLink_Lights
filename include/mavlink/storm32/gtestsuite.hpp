/** @file
 *	@brief MAVLink comm testsuite protocol generated from storm32.xml
 *	@see http://mavlink.org
 */

#pragma once

#include <gtest/gtest.h>
#include "storm32.hpp"

#ifdef TEST_INTEROP
using namespace mavlink;
#undef MAVLINK_HELPER
#include "mavlink.h"
#endif


TEST(storm32, STORM32_GIMBAL_MANAGER_INFORMATION)
{
    mavlink::mavlink_message_t msg;
    mavlink::MsgMap map1(msg);
    mavlink::MsgMap map2(msg);

    mavlink::storm32::msg::STORM32_GIMBAL_MANAGER_INFORMATION packet_in{};
    packet_in.gimbal_id = 101;
    packet_in.device_cap_flags = 963497464;
    packet_in.manager_cap_flags = 963497672;
    packet_in.roll_min = 73.0;
    packet_in.roll_max = 101.0;
    packet_in.pitch_min = 129.0;
    packet_in.pitch_max = 157.0;
    packet_in.yaw_min = 185.0;
    packet_in.yaw_max = 213.0;

    mavlink::storm32::msg::STORM32_GIMBAL_MANAGER_INFORMATION packet1{};
    mavlink::storm32::msg::STORM32_GIMBAL_MANAGER_INFORMATION packet2{};

    packet1 = packet_in;

    //std::cout << packet1.to_yaml() << std::endl;

    packet1.serialize(map1);

    mavlink::mavlink_finalize_message(&msg, 1, 1, packet1.MIN_LENGTH, packet1.LENGTH, packet1.CRC_EXTRA);

    packet2.deserialize(map2);

    EXPECT_EQ(packet1.gimbal_id, packet2.gimbal_id);
    EXPECT_EQ(packet1.device_cap_flags, packet2.device_cap_flags);
    EXPECT_EQ(packet1.manager_cap_flags, packet2.manager_cap_flags);
    EXPECT_EQ(packet1.roll_min, packet2.roll_min);
    EXPECT_EQ(packet1.roll_max, packet2.roll_max);
    EXPECT_EQ(packet1.pitch_min, packet2.pitch_min);
    EXPECT_EQ(packet1.pitch_max, packet2.pitch_max);
    EXPECT_EQ(packet1.yaw_min, packet2.yaw_min);
    EXPECT_EQ(packet1.yaw_max, packet2.yaw_max);
}

#ifdef TEST_INTEROP
TEST(storm32_interop, STORM32_GIMBAL_MANAGER_INFORMATION)
{
    mavlink_message_t msg;

    // to get nice print
    memset(&msg, 0, sizeof(msg));

    mavlink_storm32_gimbal_manager_information_t packet_c {
         963497464, 963497672, 73.0, 101.0, 129.0, 157.0, 185.0, 213.0, 101
    };

    mavlink::storm32::msg::STORM32_GIMBAL_MANAGER_INFORMATION packet_in{};
    packet_in.gimbal_id = 101;
    packet_in.device_cap_flags = 963497464;
    packet_in.manager_cap_flags = 963497672;
    packet_in.roll_min = 73.0;
    packet_in.roll_max = 101.0;
    packet_in.pitch_min = 129.0;
    packet_in.pitch_max = 157.0;
    packet_in.yaw_min = 185.0;
    packet_in.yaw_max = 213.0;

    mavlink::storm32::msg::STORM32_GIMBAL_MANAGER_INFORMATION packet2{};

    mavlink_msg_storm32_gimbal_manager_information_encode(1, 1, &msg, &packet_c);

    // simulate message-handling callback
    [&packet2](const mavlink_message_t *cmsg) {
        MsgMap map2(cmsg);

        packet2.deserialize(map2);
    } (&msg);

    EXPECT_EQ(packet_in.gimbal_id, packet2.gimbal_id);
    EXPECT_EQ(packet_in.device_cap_flags, packet2.device_cap_flags);
    EXPECT_EQ(packet_in.manager_cap_flags, packet2.manager_cap_flags);
    EXPECT_EQ(packet_in.roll_min, packet2.roll_min);
    EXPECT_EQ(packet_in.roll_max, packet2.roll_max);
    EXPECT_EQ(packet_in.pitch_min, packet2.pitch_min);
    EXPECT_EQ(packet_in.pitch_max, packet2.pitch_max);
    EXPECT_EQ(packet_in.yaw_min, packet2.yaw_min);
    EXPECT_EQ(packet_in.yaw_max, packet2.yaw_max);

#ifdef PRINT_MSG
    PRINT_MSG(msg);
#endif
}
#endif

TEST(storm32, STORM32_GIMBAL_MANAGER_STATUS)
{
    mavlink::mavlink_message_t msg;
    mavlink::MsgMap map1(msg);
    mavlink::MsgMap map2(msg);

    mavlink::storm32::msg::STORM32_GIMBAL_MANAGER_STATUS packet_in{};
    packet_in.gimbal_id = 17;
    packet_in.supervisor = 84;
    packet_in.device_flags = 17235;
    packet_in.manager_flags = 17339;
    packet_in.profile = 151;

    mavlink::storm32::msg::STORM32_GIMBAL_MANAGER_STATUS packet1{};
    mavlink::storm32::msg::STORM32_GIMBAL_MANAGER_STATUS packet2{};

    packet1 = packet_in;

    //std::cout << packet1.to_yaml() << std::endl;

    packet1.serialize(map1);

    mavlink::mavlink_finalize_message(&msg, 1, 1, packet1.MIN_LENGTH, packet1.LENGTH, packet1.CRC_EXTRA);

    packet2.deserialize(map2);

    EXPECT_EQ(packet1.gimbal_id, packet2.gimbal_id);
    EXPECT_EQ(packet1.supervisor, packet2.supervisor);
    EXPECT_EQ(packet1.device_flags, packet2.device_flags);
    EXPECT_EQ(packet1.manager_flags, packet2.manager_flags);
    EXPECT_EQ(packet1.profile, packet2.profile);
}

#ifdef TEST_INTEROP
TEST(storm32_interop, STORM32_GIMBAL_MANAGER_STATUS)
{
    mavlink_message_t msg;

    // to get nice print
    memset(&msg, 0, sizeof(msg));

    mavlink_storm32_gimbal_manager_status_t packet_c {
         17235, 17339, 17, 84, 151
    };

    mavlink::storm32::msg::STORM32_GIMBAL_MANAGER_STATUS packet_in{};
    packet_in.gimbal_id = 17;
    packet_in.supervisor = 84;
    packet_in.device_flags = 17235;
    packet_in.manager_flags = 17339;
    packet_in.profile = 151;

    mavlink::storm32::msg::STORM32_GIMBAL_MANAGER_STATUS packet2{};

    mavlink_msg_storm32_gimbal_manager_status_encode(1, 1, &msg, &packet_c);

    // simulate message-handling callback
    [&packet2](const mavlink_message_t *cmsg) {
        MsgMap map2(cmsg);

        packet2.deserialize(map2);
    } (&msg);

    EXPECT_EQ(packet_in.gimbal_id, packet2.gimbal_id);
    EXPECT_EQ(packet_in.supervisor, packet2.supervisor);
    EXPECT_EQ(packet_in.device_flags, packet2.device_flags);
    EXPECT_EQ(packet_in.manager_flags, packet2.manager_flags);
    EXPECT_EQ(packet_in.profile, packet2.profile);

#ifdef PRINT_MSG
    PRINT_MSG(msg);
#endif
}
#endif

TEST(storm32, STORM32_GIMBAL_MANAGER_CONTROL)
{
    mavlink::mavlink_message_t msg;
    mavlink::MsgMap map1(msg);
    mavlink::MsgMap map2(msg);

    mavlink::storm32::msg::STORM32_GIMBAL_MANAGER_CONTROL packet_in{};
    packet_in.target_system = 101;
    packet_in.target_component = 168;
    packet_in.gimbal_id = 235;
    packet_in.client = 46;
    packet_in.device_flags = 18691;
    packet_in.manager_flags = 18795;
    packet_in.q = {{ 17.0, 18.0, 19.0, 20.0 }};
    packet_in.angular_velocity_x = 129.0;
    packet_in.angular_velocity_y = 157.0;
    packet_in.angular_velocity_z = 185.0;

    mavlink::storm32::msg::STORM32_GIMBAL_MANAGER_CONTROL packet1{};
    mavlink::storm32::msg::STORM32_GIMBAL_MANAGER_CONTROL packet2{};

    packet1 = packet_in;

    //std::cout << packet1.to_yaml() << std::endl;

    packet1.serialize(map1);

    mavlink::mavlink_finalize_message(&msg, 1, 1, packet1.MIN_LENGTH, packet1.LENGTH, packet1.CRC_EXTRA);

    packet2.deserialize(map2);

    EXPECT_EQ(packet1.target_system, packet2.target_system);
    EXPECT_EQ(packet1.target_component, packet2.target_component);
    EXPECT_EQ(packet1.gimbal_id, packet2.gimbal_id);
    EXPECT_EQ(packet1.client, packet2.client);
    EXPECT_EQ(packet1.device_flags, packet2.device_flags);
    EXPECT_EQ(packet1.manager_flags, packet2.manager_flags);
    EXPECT_EQ(packet1.q, packet2.q);
    EXPECT_EQ(packet1.angular_velocity_x, packet2.angular_velocity_x);
    EXPECT_EQ(packet1.angular_velocity_y, packet2.angular_velocity_y);
    EXPECT_EQ(packet1.angular_velocity_z, packet2.angular_velocity_z);
}

#ifdef TEST_INTEROP
TEST(storm32_interop, STORM32_GIMBAL_MANAGER_CONTROL)
{
    mavlink_message_t msg;

    // to get nice print
    memset(&msg, 0, sizeof(msg));

    mavlink_storm32_gimbal_manager_control_t packet_c {
         { 17.0, 18.0, 19.0, 20.0 }, 129.0, 157.0, 185.0, 18691, 18795, 101, 168, 235, 46
    };

    mavlink::storm32::msg::STORM32_GIMBAL_MANAGER_CONTROL packet_in{};
    packet_in.target_system = 101;
    packet_in.target_component = 168;
    packet_in.gimbal_id = 235;
    packet_in.client = 46;
    packet_in.device_flags = 18691;
    packet_in.manager_flags = 18795;
    packet_in.q = {{ 17.0, 18.0, 19.0, 20.0 }};
    packet_in.angular_velocity_x = 129.0;
    packet_in.angular_velocity_y = 157.0;
    packet_in.angular_velocity_z = 185.0;

    mavlink::storm32::msg::STORM32_GIMBAL_MANAGER_CONTROL packet2{};

    mavlink_msg_storm32_gimbal_manager_control_encode(1, 1, &msg, &packet_c);

    // simulate message-handling callback
    [&packet2](const mavlink_message_t *cmsg) {
        MsgMap map2(cmsg);

        packet2.deserialize(map2);
    } (&msg);

    EXPECT_EQ(packet_in.target_system, packet2.target_system);
    EXPECT_EQ(packet_in.target_component, packet2.target_component);
    EXPECT_EQ(packet_in.gimbal_id, packet2.gimbal_id);
    EXPECT_EQ(packet_in.client, packet2.client);
    EXPECT_EQ(packet_in.device_flags, packet2.device_flags);
    EXPECT_EQ(packet_in.manager_flags, packet2.manager_flags);
    EXPECT_EQ(packet_in.q, packet2.q);
    EXPECT_EQ(packet_in.angular_velocity_x, packet2.angular_velocity_x);
    EXPECT_EQ(packet_in.angular_velocity_y, packet2.angular_velocity_y);
    EXPECT_EQ(packet_in.angular_velocity_z, packet2.angular_velocity_z);

#ifdef PRINT_MSG
    PRINT_MSG(msg);
#endif
}
#endif

TEST(storm32, STORM32_GIMBAL_MANAGER_CONTROL_PITCHYAW)
{
    mavlink::mavlink_message_t msg;
    mavlink::MsgMap map1(msg);
    mavlink::MsgMap map2(msg);

    mavlink::storm32::msg::STORM32_GIMBAL_MANAGER_CONTROL_PITCHYAW packet_in{};
    packet_in.target_system = 65;
    packet_in.target_component = 132;
    packet_in.gimbal_id = 199;
    packet_in.client = 10;
    packet_in.device_flags = 18067;
    packet_in.manager_flags = 18171;
    packet_in.pitch = 17.0;
    packet_in.yaw = 45.0;
    packet_in.pitch_rate = 73.0;
    packet_in.yaw_rate = 101.0;

    mavlink::storm32::msg::STORM32_GIMBAL_MANAGER_CONTROL_PITCHYAW packet1{};
    mavlink::storm32::msg::STORM32_GIMBAL_MANAGER_CONTROL_PITCHYAW packet2{};

    packet1 = packet_in;

    //std::cout << packet1.to_yaml() << std::endl;

    packet1.serialize(map1);

    mavlink::mavlink_finalize_message(&msg, 1, 1, packet1.MIN_LENGTH, packet1.LENGTH, packet1.CRC_EXTRA);

    packet2.deserialize(map2);

    EXPECT_EQ(packet1.target_system, packet2.target_system);
    EXPECT_EQ(packet1.target_component, packet2.target_component);
    EXPECT_EQ(packet1.gimbal_id, packet2.gimbal_id);
    EXPECT_EQ(packet1.client, packet2.client);
    EXPECT_EQ(packet1.device_flags, packet2.device_flags);
    EXPECT_EQ(packet1.manager_flags, packet2.manager_flags);
    EXPECT_EQ(packet1.pitch, packet2.pitch);
    EXPECT_EQ(packet1.yaw, packet2.yaw);
    EXPECT_EQ(packet1.pitch_rate, packet2.pitch_rate);
    EXPECT_EQ(packet1.yaw_rate, packet2.yaw_rate);
}

#ifdef TEST_INTEROP
TEST(storm32_interop, STORM32_GIMBAL_MANAGER_CONTROL_PITCHYAW)
{
    mavlink_message_t msg;

    // to get nice print
    memset(&msg, 0, sizeof(msg));

    mavlink_storm32_gimbal_manager_control_pitchyaw_t packet_c {
         17.0, 45.0, 73.0, 101.0, 18067, 18171, 65, 132, 199, 10
    };

    mavlink::storm32::msg::STORM32_GIMBAL_MANAGER_CONTROL_PITCHYAW packet_in{};
    packet_in.target_system = 65;
    packet_in.target_component = 132;
    packet_in.gimbal_id = 199;
    packet_in.client = 10;
    packet_in.device_flags = 18067;
    packet_in.manager_flags = 18171;
    packet_in.pitch = 17.0;
    packet_in.yaw = 45.0;
    packet_in.pitch_rate = 73.0;
    packet_in.yaw_rate = 101.0;

    mavlink::storm32::msg::STORM32_GIMBAL_MANAGER_CONTROL_PITCHYAW packet2{};

    mavlink_msg_storm32_gimbal_manager_control_pitchyaw_encode(1, 1, &msg, &packet_c);

    // simulate message-handling callback
    [&packet2](const mavlink_message_t *cmsg) {
        MsgMap map2(cmsg);

        packet2.deserialize(map2);
    } (&msg);

    EXPECT_EQ(packet_in.target_system, packet2.target_system);
    EXPECT_EQ(packet_in.target_component, packet2.target_component);
    EXPECT_EQ(packet_in.gimbal_id, packet2.gimbal_id);
    EXPECT_EQ(packet_in.client, packet2.client);
    EXPECT_EQ(packet_in.device_flags, packet2.device_flags);
    EXPECT_EQ(packet_in.manager_flags, packet2.manager_flags);
    EXPECT_EQ(packet_in.pitch, packet2.pitch);
    EXPECT_EQ(packet_in.yaw, packet2.yaw);
    EXPECT_EQ(packet_in.pitch_rate, packet2.pitch_rate);
    EXPECT_EQ(packet_in.yaw_rate, packet2.yaw_rate);

#ifdef PRINT_MSG
    PRINT_MSG(msg);
#endif
}
#endif

TEST(storm32, STORM32_GIMBAL_MANAGER_CORRECT_ROLL)
{
    mavlink::mavlink_message_t msg;
    mavlink::MsgMap map1(msg);
    mavlink::MsgMap map2(msg);

    mavlink::storm32::msg::STORM32_GIMBAL_MANAGER_CORRECT_ROLL packet_in{};
    packet_in.target_system = 17;
    packet_in.target_component = 84;
    packet_in.gimbal_id = 151;
    packet_in.client = 218;
    packet_in.roll = 17.0;

    mavlink::storm32::msg::STORM32_GIMBAL_MANAGER_CORRECT_ROLL packet1{};
    mavlink::storm32::msg::STORM32_GIMBAL_MANAGER_CORRECT_ROLL packet2{};

    packet1 = packet_in;

    //std::cout << packet1.to_yaml() << std::endl;

    packet1.serialize(map1);

    mavlink::mavlink_finalize_message(&msg, 1, 1, packet1.MIN_LENGTH, packet1.LENGTH, packet1.CRC_EXTRA);

    packet2.deserialize(map2);

    EXPECT_EQ(packet1.target_system, packet2.target_system);
    EXPECT_EQ(packet1.target_component, packet2.target_component);
    EXPECT_EQ(packet1.gimbal_id, packet2.gimbal_id);
    EXPECT_EQ(packet1.client, packet2.client);
    EXPECT_EQ(packet1.roll, packet2.roll);
}

#ifdef TEST_INTEROP
TEST(storm32_interop, STORM32_GIMBAL_MANAGER_CORRECT_ROLL)
{
    mavlink_message_t msg;

    // to get nice print
    memset(&msg, 0, sizeof(msg));

    mavlink_storm32_gimbal_manager_correct_roll_t packet_c {
         17.0, 17, 84, 151, 218
    };

    mavlink::storm32::msg::STORM32_GIMBAL_MANAGER_CORRECT_ROLL packet_in{};
    packet_in.target_system = 17;
    packet_in.target_component = 84;
    packet_in.gimbal_id = 151;
    packet_in.client = 218;
    packet_in.roll = 17.0;

    mavlink::storm32::msg::STORM32_GIMBAL_MANAGER_CORRECT_ROLL packet2{};

    mavlink_msg_storm32_gimbal_manager_correct_roll_encode(1, 1, &msg, &packet_c);

    // simulate message-handling callback
    [&packet2](const mavlink_message_t *cmsg) {
        MsgMap map2(cmsg);

        packet2.deserialize(map2);
    } (&msg);

    EXPECT_EQ(packet_in.target_system, packet2.target_system);
    EXPECT_EQ(packet_in.target_component, packet2.target_component);
    EXPECT_EQ(packet_in.gimbal_id, packet2.gimbal_id);
    EXPECT_EQ(packet_in.client, packet2.client);
    EXPECT_EQ(packet_in.roll, packet2.roll);

#ifdef PRINT_MSG
    PRINT_MSG(msg);
#endif
}
#endif

TEST(storm32, QSHOT_STATUS)
{
    mavlink::mavlink_message_t msg;
    mavlink::MsgMap map1(msg);
    mavlink::MsgMap map2(msg);

    mavlink::storm32::msg::QSHOT_STATUS packet_in{};
    packet_in.mode = 17235;
    packet_in.shot_state = 17339;

    mavlink::storm32::msg::QSHOT_STATUS packet1{};
    mavlink::storm32::msg::QSHOT_STATUS packet2{};

    packet1 = packet_in;

    //std::cout << packet1.to_yaml() << std::endl;

    packet1.serialize(map1);

    mavlink::mavlink_finalize_message(&msg, 1, 1, packet1.MIN_LENGTH, packet1.LENGTH, packet1.CRC_EXTRA);

    packet2.deserialize(map2);

    EXPECT_EQ(packet1.mode, packet2.mode);
    EXPECT_EQ(packet1.shot_state, packet2.shot_state);
}

#ifdef TEST_INTEROP
TEST(storm32_interop, QSHOT_STATUS)
{
    mavlink_message_t msg;

    // to get nice print
    memset(&msg, 0, sizeof(msg));

    mavlink_qshot_status_t packet_c {
         17235, 17339
    };

    mavlink::storm32::msg::QSHOT_STATUS packet_in{};
    packet_in.mode = 17235;
    packet_in.shot_state = 17339;

    mavlink::storm32::msg::QSHOT_STATUS packet2{};

    mavlink_msg_qshot_status_encode(1, 1, &msg, &packet_c);

    // simulate message-handling callback
    [&packet2](const mavlink_message_t *cmsg) {
        MsgMap map2(cmsg);

        packet2.deserialize(map2);
    } (&msg);

    EXPECT_EQ(packet_in.mode, packet2.mode);
    EXPECT_EQ(packet_in.shot_state, packet2.shot_state);

#ifdef PRINT_MSG
    PRINT_MSG(msg);
#endif
}
#endif

TEST(storm32, RADIO_RC_CHANNELS)
{
    mavlink::mavlink_message_t msg;
    mavlink::MsgMap map1(msg);
    mavlink::MsgMap map2(msg);

    mavlink::storm32::msg::RADIO_RC_CHANNELS packet_in{};
    packet_in.count = 5;
    packet_in.flags = 72;
    packet_in.channels = {{ 17339, 17340, 17341, 17342, 17343, 17344, 17345, 17346, 17347, 17348, 17349, 17350, 17351, 17352, 17353, 17354, 17355, 17356, 17357, 17358, 17359, 17360, 17361, 17362 }};

    mavlink::storm32::msg::RADIO_RC_CHANNELS packet1{};
    mavlink::storm32::msg::RADIO_RC_CHANNELS packet2{};

    packet1 = packet_in;

    //std::cout << packet1.to_yaml() << std::endl;

    packet1.serialize(map1);

    mavlink::mavlink_finalize_message(&msg, 1, 1, packet1.MIN_LENGTH, packet1.LENGTH, packet1.CRC_EXTRA);

    packet2.deserialize(map2);

    EXPECT_EQ(packet1.count, packet2.count);
    EXPECT_EQ(packet1.flags, packet2.flags);
    EXPECT_EQ(packet1.channels, packet2.channels);
}

#ifdef TEST_INTEROP
TEST(storm32_interop, RADIO_RC_CHANNELS)
{
    mavlink_message_t msg;

    // to get nice print
    memset(&msg, 0, sizeof(msg));

    mavlink_radio_rc_channels_t packet_c {
         5, 72, { 17339, 17340, 17341, 17342, 17343, 17344, 17345, 17346, 17347, 17348, 17349, 17350, 17351, 17352, 17353, 17354, 17355, 17356, 17357, 17358, 17359, 17360, 17361, 17362 }
    };

    mavlink::storm32::msg::RADIO_RC_CHANNELS packet_in{};
    packet_in.count = 5;
    packet_in.flags = 72;
    packet_in.channels = {{ 17339, 17340, 17341, 17342, 17343, 17344, 17345, 17346, 17347, 17348, 17349, 17350, 17351, 17352, 17353, 17354, 17355, 17356, 17357, 17358, 17359, 17360, 17361, 17362 }};

    mavlink::storm32::msg::RADIO_RC_CHANNELS packet2{};

    mavlink_msg_radio_rc_channels_encode(1, 1, &msg, &packet_c);

    // simulate message-handling callback
    [&packet2](const mavlink_message_t *cmsg) {
        MsgMap map2(cmsg);

        packet2.deserialize(map2);
    } (&msg);

    EXPECT_EQ(packet_in.count, packet2.count);
    EXPECT_EQ(packet_in.flags, packet2.flags);
    EXPECT_EQ(packet_in.channels, packet2.channels);

#ifdef PRINT_MSG
    PRINT_MSG(msg);
#endif
}
#endif

TEST(storm32, RADIO_LINK_STATS)
{
    mavlink::mavlink_message_t msg;
    mavlink::MsgMap map1(msg);
    mavlink::MsgMap map2(msg);

    mavlink::storm32::msg::RADIO_LINK_STATS packet_in{};
    packet_in.flags = 5;
    packet_in.rx_LQ = 72;
    packet_in.rx_rssi1 = 139;
    packet_in.rx_snr1 = -50;
    packet_in.rx_rssi2 = 17;
    packet_in.rx_snr2 = 84;
    packet_in.rx_receive_antenna = 151;
    packet_in.rx_transmit_antenna = 218;
    packet_in.tx_LQ = 29;
    packet_in.tx_rssi1 = 96;
    packet_in.tx_snr1 = -93;
    packet_in.tx_rssi2 = 230;
    packet_in.tx_snr2 = 41;
    packet_in.tx_receive_antenna = 108;
    packet_in.tx_transmit_antenna = 175;

    mavlink::storm32::msg::RADIO_LINK_STATS packet1{};
    mavlink::storm32::msg::RADIO_LINK_STATS packet2{};

    packet1 = packet_in;

    //std::cout << packet1.to_yaml() << std::endl;

    packet1.serialize(map1);

    mavlink::mavlink_finalize_message(&msg, 1, 1, packet1.MIN_LENGTH, packet1.LENGTH, packet1.CRC_EXTRA);

    packet2.deserialize(map2);

    EXPECT_EQ(packet1.flags, packet2.flags);
    EXPECT_EQ(packet1.rx_LQ, packet2.rx_LQ);
    EXPECT_EQ(packet1.rx_rssi1, packet2.rx_rssi1);
    EXPECT_EQ(packet1.rx_snr1, packet2.rx_snr1);
    EXPECT_EQ(packet1.rx_rssi2, packet2.rx_rssi2);
    EXPECT_EQ(packet1.rx_snr2, packet2.rx_snr2);
    EXPECT_EQ(packet1.rx_receive_antenna, packet2.rx_receive_antenna);
    EXPECT_EQ(packet1.rx_transmit_antenna, packet2.rx_transmit_antenna);
    EXPECT_EQ(packet1.tx_LQ, packet2.tx_LQ);
    EXPECT_EQ(packet1.tx_rssi1, packet2.tx_rssi1);
    EXPECT_EQ(packet1.tx_snr1, packet2.tx_snr1);
    EXPECT_EQ(packet1.tx_rssi2, packet2.tx_rssi2);
    EXPECT_EQ(packet1.tx_snr2, packet2.tx_snr2);
    EXPECT_EQ(packet1.tx_receive_antenna, packet2.tx_receive_antenna);
    EXPECT_EQ(packet1.tx_transmit_antenna, packet2.tx_transmit_antenna);
}

#ifdef TEST_INTEROP
TEST(storm32_interop, RADIO_LINK_STATS)
{
    mavlink_message_t msg;

    // to get nice print
    memset(&msg, 0, sizeof(msg));

    mavlink_radio_link_stats_t packet_c {
         5, 72, 139, -50, 17, 84, 151, 218, 29, 96, -93, 230, 41, 108, 175
    };

    mavlink::storm32::msg::RADIO_LINK_STATS packet_in{};
    packet_in.flags = 5;
    packet_in.rx_LQ = 72;
    packet_in.rx_rssi1 = 139;
    packet_in.rx_snr1 = -50;
    packet_in.rx_rssi2 = 17;
    packet_in.rx_snr2 = 84;
    packet_in.rx_receive_antenna = 151;
    packet_in.rx_transmit_antenna = 218;
    packet_in.tx_LQ = 29;
    packet_in.tx_rssi1 = 96;
    packet_in.tx_snr1 = -93;
    packet_in.tx_rssi2 = 230;
    packet_in.tx_snr2 = 41;
    packet_in.tx_receive_antenna = 108;
    packet_in.tx_transmit_antenna = 175;

    mavlink::storm32::msg::RADIO_LINK_STATS packet2{};

    mavlink_msg_radio_link_stats_encode(1, 1, &msg, &packet_c);

    // simulate message-handling callback
    [&packet2](const mavlink_message_t *cmsg) {
        MsgMap map2(cmsg);

        packet2.deserialize(map2);
    } (&msg);

    EXPECT_EQ(packet_in.flags, packet2.flags);
    EXPECT_EQ(packet_in.rx_LQ, packet2.rx_LQ);
    EXPECT_EQ(packet_in.rx_rssi1, packet2.rx_rssi1);
    EXPECT_EQ(packet_in.rx_snr1, packet2.rx_snr1);
    EXPECT_EQ(packet_in.rx_rssi2, packet2.rx_rssi2);
    EXPECT_EQ(packet_in.rx_snr2, packet2.rx_snr2);
    EXPECT_EQ(packet_in.rx_receive_antenna, packet2.rx_receive_antenna);
    EXPECT_EQ(packet_in.rx_transmit_antenna, packet2.rx_transmit_antenna);
    EXPECT_EQ(packet_in.tx_LQ, packet2.tx_LQ);
    EXPECT_EQ(packet_in.tx_rssi1, packet2.tx_rssi1);
    EXPECT_EQ(packet_in.tx_snr1, packet2.tx_snr1);
    EXPECT_EQ(packet_in.tx_rssi2, packet2.tx_rssi2);
    EXPECT_EQ(packet_in.tx_snr2, packet2.tx_snr2);
    EXPECT_EQ(packet_in.tx_receive_antenna, packet2.tx_receive_antenna);
    EXPECT_EQ(packet_in.tx_transmit_antenna, packet2.tx_transmit_antenna);

#ifdef PRINT_MSG
    PRINT_MSG(msg);
#endif
}
#endif

TEST(storm32, FRSKY_PASSTHROUGH_ARRAY)
{
    mavlink::mavlink_message_t msg;
    mavlink::MsgMap map1(msg);
    mavlink::MsgMap map2(msg);

    mavlink::storm32::msg::FRSKY_PASSTHROUGH_ARRAY packet_in{};
    packet_in.time_boot_ms = 963497464;
    packet_in.count = 17;
    packet_in.packet_buf = {{ 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125, 126, 127, 128, 129, 130, 131, 132, 133, 134, 135, 136, 137, 138, 139, 140, 141, 142, 143, 144, 145, 146, 147, 148, 149, 150, 151, 152, 153, 154, 155, 156, 157, 158, 159, 160, 161, 162, 163, 164, 165, 166, 167, 168, 169, 170, 171, 172, 173, 174, 175, 176, 177, 178, 179, 180, 181, 182, 183, 184, 185, 186, 187, 188, 189, 190, 191, 192, 193, 194, 195, 196, 197, 198, 199, 200, 201, 202, 203, 204, 205, 206, 207, 208, 209, 210, 211, 212, 213, 214, 215, 216, 217, 218, 219, 220, 221, 222, 223, 224, 225, 226, 227, 228, 229, 230, 231, 232, 233, 234, 235, 236, 237, 238, 239, 240, 241, 242, 243, 244, 245, 246, 247, 248, 249, 250, 251, 252, 253, 254, 255, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67 }};

    mavlink::storm32::msg::FRSKY_PASSTHROUGH_ARRAY packet1{};
    mavlink::storm32::msg::FRSKY_PASSTHROUGH_ARRAY packet2{};

    packet1 = packet_in;

    //std::cout << packet1.to_yaml() << std::endl;

    packet1.serialize(map1);

    mavlink::mavlink_finalize_message(&msg, 1, 1, packet1.MIN_LENGTH, packet1.LENGTH, packet1.CRC_EXTRA);

    packet2.deserialize(map2);

    EXPECT_EQ(packet1.time_boot_ms, packet2.time_boot_ms);
    EXPECT_EQ(packet1.count, packet2.count);
    EXPECT_EQ(packet1.packet_buf, packet2.packet_buf);
}

#ifdef TEST_INTEROP
TEST(storm32_interop, FRSKY_PASSTHROUGH_ARRAY)
{
    mavlink_message_t msg;

    // to get nice print
    memset(&msg, 0, sizeof(msg));

    mavlink_frsky_passthrough_array_t packet_c {
         963497464, 17, { 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125, 126, 127, 128, 129, 130, 131, 132, 133, 134, 135, 136, 137, 138, 139, 140, 141, 142, 143, 144, 145, 146, 147, 148, 149, 150, 151, 152, 153, 154, 155, 156, 157, 158, 159, 160, 161, 162, 163, 164, 165, 166, 167, 168, 169, 170, 171, 172, 173, 174, 175, 176, 177, 178, 179, 180, 181, 182, 183, 184, 185, 186, 187, 188, 189, 190, 191, 192, 193, 194, 195, 196, 197, 198, 199, 200, 201, 202, 203, 204, 205, 206, 207, 208, 209, 210, 211, 212, 213, 214, 215, 216, 217, 218, 219, 220, 221, 222, 223, 224, 225, 226, 227, 228, 229, 230, 231, 232, 233, 234, 235, 236, 237, 238, 239, 240, 241, 242, 243, 244, 245, 246, 247, 248, 249, 250, 251, 252, 253, 254, 255, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67 }
    };

    mavlink::storm32::msg::FRSKY_PASSTHROUGH_ARRAY packet_in{};
    packet_in.time_boot_ms = 963497464;
    packet_in.count = 17;
    packet_in.packet_buf = {{ 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125, 126, 127, 128, 129, 130, 131, 132, 133, 134, 135, 136, 137, 138, 139, 140, 141, 142, 143, 144, 145, 146, 147, 148, 149, 150, 151, 152, 153, 154, 155, 156, 157, 158, 159, 160, 161, 162, 163, 164, 165, 166, 167, 168, 169, 170, 171, 172, 173, 174, 175, 176, 177, 178, 179, 180, 181, 182, 183, 184, 185, 186, 187, 188, 189, 190, 191, 192, 193, 194, 195, 196, 197, 198, 199, 200, 201, 202, 203, 204, 205, 206, 207, 208, 209, 210, 211, 212, 213, 214, 215, 216, 217, 218, 219, 220, 221, 222, 223, 224, 225, 226, 227, 228, 229, 230, 231, 232, 233, 234, 235, 236, 237, 238, 239, 240, 241, 242, 243, 244, 245, 246, 247, 248, 249, 250, 251, 252, 253, 254, 255, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67 }};

    mavlink::storm32::msg::FRSKY_PASSTHROUGH_ARRAY packet2{};

    mavlink_msg_frsky_passthrough_array_encode(1, 1, &msg, &packet_c);

    // simulate message-handling callback
    [&packet2](const mavlink_message_t *cmsg) {
        MsgMap map2(cmsg);

        packet2.deserialize(map2);
    } (&msg);

    EXPECT_EQ(packet_in.time_boot_ms, packet2.time_boot_ms);
    EXPECT_EQ(packet_in.count, packet2.count);
    EXPECT_EQ(packet_in.packet_buf, packet2.packet_buf);

#ifdef PRINT_MSG
    PRINT_MSG(msg);
#endif
}
#endif

TEST(storm32, PARAM_VALUE_ARRAY)
{
    mavlink::mavlink_message_t msg;
    mavlink::MsgMap map1(msg);
    mavlink::MsgMap map2(msg);

    mavlink::storm32::msg::PARAM_VALUE_ARRAY packet_in{};
    packet_in.param_count = 17235;
    packet_in.param_index_first = 17339;
    packet_in.param_array_len = 151;
    packet_in.flags = 17443;
    packet_in.packet_buf = {{ 218, 219, 220, 221, 222, 223, 224, 225, 226, 227, 228, 229, 230, 231, 232, 233, 234, 235, 236, 237, 238, 239, 240, 241, 242, 243, 244, 245, 246, 247, 248, 249, 250, 251, 252, 253, 254, 255, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125, 126, 127, 128, 129, 130, 131, 132, 133, 134, 135, 136, 137, 138, 139, 140, 141, 142, 143, 144, 145, 146, 147, 148, 149, 150, 151, 152, 153, 154, 155, 156, 157, 158, 159, 160, 161, 162, 163, 164, 165, 166, 167, 168, 169, 170, 171, 172, 173, 174, 175, 176, 177, 178, 179, 180, 181, 182, 183, 184, 185, 186, 187, 188, 189, 190, 191, 192, 193, 194, 195, 196, 197, 198, 199, 200, 201, 202, 203, 204, 205, 206, 207, 208, 209 }};

    mavlink::storm32::msg::PARAM_VALUE_ARRAY packet1{};
    mavlink::storm32::msg::PARAM_VALUE_ARRAY packet2{};

    packet1 = packet_in;

    //std::cout << packet1.to_yaml() << std::endl;

    packet1.serialize(map1);

    mavlink::mavlink_finalize_message(&msg, 1, 1, packet1.MIN_LENGTH, packet1.LENGTH, packet1.CRC_EXTRA);

    packet2.deserialize(map2);

    EXPECT_EQ(packet1.param_count, packet2.param_count);
    EXPECT_EQ(packet1.param_index_first, packet2.param_index_first);
    EXPECT_EQ(packet1.param_array_len, packet2.param_array_len);
    EXPECT_EQ(packet1.flags, packet2.flags);
    EXPECT_EQ(packet1.packet_buf, packet2.packet_buf);
}

#ifdef TEST_INTEROP
TEST(storm32_interop, PARAM_VALUE_ARRAY)
{
    mavlink_message_t msg;

    // to get nice print
    memset(&msg, 0, sizeof(msg));

    mavlink_param_value_array_t packet_c {
         17235, 17339, 17443, 151, { 218, 219, 220, 221, 222, 223, 224, 225, 226, 227, 228, 229, 230, 231, 232, 233, 234, 235, 236, 237, 238, 239, 240, 241, 242, 243, 244, 245, 246, 247, 248, 249, 250, 251, 252, 253, 254, 255, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125, 126, 127, 128, 129, 130, 131, 132, 133, 134, 135, 136, 137, 138, 139, 140, 141, 142, 143, 144, 145, 146, 147, 148, 149, 150, 151, 152, 153, 154, 155, 156, 157, 158, 159, 160, 161, 162, 163, 164, 165, 166, 167, 168, 169, 170, 171, 172, 173, 174, 175, 176, 177, 178, 179, 180, 181, 182, 183, 184, 185, 186, 187, 188, 189, 190, 191, 192, 193, 194, 195, 196, 197, 198, 199, 200, 201, 202, 203, 204, 205, 206, 207, 208, 209 }
    };

    mavlink::storm32::msg::PARAM_VALUE_ARRAY packet_in{};
    packet_in.param_count = 17235;
    packet_in.param_index_first = 17339;
    packet_in.param_array_len = 151;
    packet_in.flags = 17443;
    packet_in.packet_buf = {{ 218, 219, 220, 221, 222, 223, 224, 225, 226, 227, 228, 229, 230, 231, 232, 233, 234, 235, 236, 237, 238, 239, 240, 241, 242, 243, 244, 245, 246, 247, 248, 249, 250, 251, 252, 253, 254, 255, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125, 126, 127, 128, 129, 130, 131, 132, 133, 134, 135, 136, 137, 138, 139, 140, 141, 142, 143, 144, 145, 146, 147, 148, 149, 150, 151, 152, 153, 154, 155, 156, 157, 158, 159, 160, 161, 162, 163, 164, 165, 166, 167, 168, 169, 170, 171, 172, 173, 174, 175, 176, 177, 178, 179, 180, 181, 182, 183, 184, 185, 186, 187, 188, 189, 190, 191, 192, 193, 194, 195, 196, 197, 198, 199, 200, 201, 202, 203, 204, 205, 206, 207, 208, 209 }};

    mavlink::storm32::msg::PARAM_VALUE_ARRAY packet2{};

    mavlink_msg_param_value_array_encode(1, 1, &msg, &packet_c);

    // simulate message-handling callback
    [&packet2](const mavlink_message_t *cmsg) {
        MsgMap map2(cmsg);

        packet2.deserialize(map2);
    } (&msg);

    EXPECT_EQ(packet_in.param_count, packet2.param_count);
    EXPECT_EQ(packet_in.param_index_first, packet2.param_index_first);
    EXPECT_EQ(packet_in.param_array_len, packet2.param_array_len);
    EXPECT_EQ(packet_in.flags, packet2.flags);
    EXPECT_EQ(packet_in.packet_buf, packet2.packet_buf);

#ifdef PRINT_MSG
    PRINT_MSG(msg);
#endif
}
#endif
