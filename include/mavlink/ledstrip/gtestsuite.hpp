/** @file
 *	@brief MAVLink comm testsuite protocol generated from ledstrip.xml
 *	@see http://mavlink.org
 */

#pragma once

#include <gtest/gtest.h>
#include "ledstrip.hpp"

#ifdef TEST_INTEROP
using namespace mavlink;
#undef MAVLINK_HELPER
#include "mavlink.h"
#endif


TEST(ledstrip, LED_STRIP_CONFIG)
{
    mavlink::mavlink_message_t msg;
    mavlink::MsgMap map1(msg);
    mavlink::MsgMap map2(msg);

    mavlink::ledstrip::msg::LED_STRIP_CONFIG packet_in{};
    packet_in.target_system = 101;
    packet_in.target_component = 168;
    packet_in.fill_mode = 235;
    packet_in.led_index = 46;
    packet_in.length = 113;
    packet_in.strip_id = 180;
    packet_in.colors = {{ 963497464, 963497465, 963497466, 963497467, 963497468, 963497469, 963497470, 963497471 }};

    mavlink::ledstrip::msg::LED_STRIP_CONFIG packet1{};
    mavlink::ledstrip::msg::LED_STRIP_CONFIG packet2{};

    packet1 = packet_in;

    //std::cout << packet1.to_yaml() << std::endl;

    packet1.serialize(map1);

    mavlink::mavlink_finalize_message(&msg, 1, 1, packet1.MIN_LENGTH, packet1.LENGTH, packet1.CRC_EXTRA);

    packet2.deserialize(map2);

    EXPECT_EQ(packet1.target_system, packet2.target_system);
    EXPECT_EQ(packet1.target_component, packet2.target_component);
    EXPECT_EQ(packet1.fill_mode, packet2.fill_mode);
    EXPECT_EQ(packet1.led_index, packet2.led_index);
    EXPECT_EQ(packet1.length, packet2.length);
    EXPECT_EQ(packet1.strip_id, packet2.strip_id);
    EXPECT_EQ(packet1.colors, packet2.colors);
}

#ifdef TEST_INTEROP
TEST(ledstrip_interop, LED_STRIP_CONFIG)
{
    mavlink_message_t msg;

    // to get nice print
    memset(&msg, 0, sizeof(msg));

    mavlink_led_strip_config_t packet_c {
         { 963497464, 963497465, 963497466, 963497467, 963497468, 963497469, 963497470, 963497471 }, 101, 168, 235, 46, 113, 180
    };

    mavlink::ledstrip::msg::LED_STRIP_CONFIG packet_in{};
    packet_in.target_system = 101;
    packet_in.target_component = 168;
    packet_in.fill_mode = 235;
    packet_in.led_index = 46;
    packet_in.length = 113;
    packet_in.strip_id = 180;
    packet_in.colors = {{ 963497464, 963497465, 963497466, 963497467, 963497468, 963497469, 963497470, 963497471 }};

    mavlink::ledstrip::msg::LED_STRIP_CONFIG packet2{};

    mavlink_msg_led_strip_config_encode(1, 1, &msg, &packet_c);

    // simulate message-handling callback
    [&packet2](const mavlink_message_t *cmsg) {
        MsgMap map2(cmsg);

        packet2.deserialize(map2);
    } (&msg);

    EXPECT_EQ(packet_in.target_system, packet2.target_system);
    EXPECT_EQ(packet_in.target_component, packet2.target_component);
    EXPECT_EQ(packet_in.fill_mode, packet2.fill_mode);
    EXPECT_EQ(packet_in.led_index, packet2.led_index);
    EXPECT_EQ(packet_in.length, packet2.length);
    EXPECT_EQ(packet_in.strip_id, packet2.strip_id);
    EXPECT_EQ(packet_in.colors, packet2.colors);

#ifdef PRINT_MSG
    PRINT_MSG(msg);
#endif
}
#endif

TEST(ledstrip, LED_STRIP_STATE)
{
    mavlink::mavlink_message_t msg;
    mavlink::MsgMap map1(msg);
    mavlink::MsgMap map2(msg);

    mavlink::ledstrip::msg::LED_STRIP_STATE packet_in{};
    packet_in.length = 101;
    packet_in.led_index = 168;
    packet_in.strip_id = 235;
    packet_in.following_mode = 46;
    packet_in.colors = {{ 963497464, 963497465, 963497466, 963497467, 963497468, 963497469, 963497470, 963497471 }};

    mavlink::ledstrip::msg::LED_STRIP_STATE packet1{};
    mavlink::ledstrip::msg::LED_STRIP_STATE packet2{};

    packet1 = packet_in;

    //std::cout << packet1.to_yaml() << std::endl;

    packet1.serialize(map1);

    mavlink::mavlink_finalize_message(&msg, 1, 1, packet1.MIN_LENGTH, packet1.LENGTH, packet1.CRC_EXTRA);

    packet2.deserialize(map2);

    EXPECT_EQ(packet1.length, packet2.length);
    EXPECT_EQ(packet1.led_index, packet2.led_index);
    EXPECT_EQ(packet1.strip_id, packet2.strip_id);
    EXPECT_EQ(packet1.following_mode, packet2.following_mode);
    EXPECT_EQ(packet1.colors, packet2.colors);
}

#ifdef TEST_INTEROP
TEST(ledstrip_interop, LED_STRIP_STATE)
{
    mavlink_message_t msg;

    // to get nice print
    memset(&msg, 0, sizeof(msg));

    mavlink_led_strip_state_t packet_c {
         { 963497464, 963497465, 963497466, 963497467, 963497468, 963497469, 963497470, 963497471 }, 101, 168, 235, 46
    };

    mavlink::ledstrip::msg::LED_STRIP_STATE packet_in{};
    packet_in.length = 101;
    packet_in.led_index = 168;
    packet_in.strip_id = 235;
    packet_in.following_mode = 46;
    packet_in.colors = {{ 963497464, 963497465, 963497466, 963497467, 963497468, 963497469, 963497470, 963497471 }};

    mavlink::ledstrip::msg::LED_STRIP_STATE packet2{};

    mavlink_msg_led_strip_state_encode(1, 1, &msg, &packet_c);

    // simulate message-handling callback
    [&packet2](const mavlink_message_t *cmsg) {
        MsgMap map2(cmsg);

        packet2.deserialize(map2);
    } (&msg);

    EXPECT_EQ(packet_in.length, packet2.length);
    EXPECT_EQ(packet_in.led_index, packet2.led_index);
    EXPECT_EQ(packet_in.strip_id, packet2.strip_id);
    EXPECT_EQ(packet_in.following_mode, packet2.following_mode);
    EXPECT_EQ(packet_in.colors, packet2.colors);

#ifdef PRINT_MSG
    PRINT_MSG(msg);
#endif
}
#endif
