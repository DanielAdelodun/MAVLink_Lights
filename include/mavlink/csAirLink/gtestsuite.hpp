/** @file
 *	@brief MAVLink comm testsuite protocol generated from csAirLink.xml
 *	@see http://mavlink.org
 */

#pragma once

#include <gtest/gtest.h>
#include "csAirLink.hpp"

#ifdef TEST_INTEROP
using namespace mavlink;
#undef MAVLINK_HELPER
#include "mavlink.h"
#endif


TEST(csAirLink, AIRLINK_AUTH)
{
    mavlink::mavlink_message_t msg;
    mavlink::MsgMap map1(msg);
    mavlink::MsgMap map2(msg);

    mavlink::csAirLink::msg::AIRLINK_AUTH packet_in{};
    packet_in.login = to_char_array("ABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVW");
    packet_in.password = to_char_array("YZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTU");

    mavlink::csAirLink::msg::AIRLINK_AUTH packet1{};
    mavlink::csAirLink::msg::AIRLINK_AUTH packet2{};

    packet1 = packet_in;

    //std::cout << packet1.to_yaml() << std::endl;

    packet1.serialize(map1);

    mavlink::mavlink_finalize_message(&msg, 1, 1, packet1.MIN_LENGTH, packet1.LENGTH, packet1.CRC_EXTRA);

    packet2.deserialize(map2);

    EXPECT_EQ(packet1.login, packet2.login);
    EXPECT_EQ(packet1.password, packet2.password);
}

#ifdef TEST_INTEROP
TEST(csAirLink_interop, AIRLINK_AUTH)
{
    mavlink_message_t msg;

    // to get nice print
    memset(&msg, 0, sizeof(msg));

    mavlink_airlink_auth_t packet_c {
         "ABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVW", "YZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTU"
    };

    mavlink::csAirLink::msg::AIRLINK_AUTH packet_in{};
    packet_in.login = to_char_array("ABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVW");
    packet_in.password = to_char_array("YZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTU");

    mavlink::csAirLink::msg::AIRLINK_AUTH packet2{};

    mavlink_msg_airlink_auth_encode(1, 1, &msg, &packet_c);

    // simulate message-handling callback
    [&packet2](const mavlink_message_t *cmsg) {
        MsgMap map2(cmsg);

        packet2.deserialize(map2);
    } (&msg);

    EXPECT_EQ(packet_in.login, packet2.login);
    EXPECT_EQ(packet_in.password, packet2.password);

#ifdef PRINT_MSG
    PRINT_MSG(msg);
#endif
}
#endif

TEST(csAirLink, AIRLINK_AUTH_RESPONSE)
{
    mavlink::mavlink_message_t msg;
    mavlink::MsgMap map1(msg);
    mavlink::MsgMap map2(msg);

    mavlink::csAirLink::msg::AIRLINK_AUTH_RESPONSE packet_in{};
    packet_in.resp_type = 5;

    mavlink::csAirLink::msg::AIRLINK_AUTH_RESPONSE packet1{};
    mavlink::csAirLink::msg::AIRLINK_AUTH_RESPONSE packet2{};

    packet1 = packet_in;

    //std::cout << packet1.to_yaml() << std::endl;

    packet1.serialize(map1);

    mavlink::mavlink_finalize_message(&msg, 1, 1, packet1.MIN_LENGTH, packet1.LENGTH, packet1.CRC_EXTRA);

    packet2.deserialize(map2);

    EXPECT_EQ(packet1.resp_type, packet2.resp_type);
}

#ifdef TEST_INTEROP
TEST(csAirLink_interop, AIRLINK_AUTH_RESPONSE)
{
    mavlink_message_t msg;

    // to get nice print
    memset(&msg, 0, sizeof(msg));

    mavlink_airlink_auth_response_t packet_c {
         5
    };

    mavlink::csAirLink::msg::AIRLINK_AUTH_RESPONSE packet_in{};
    packet_in.resp_type = 5;

    mavlink::csAirLink::msg::AIRLINK_AUTH_RESPONSE packet2{};

    mavlink_msg_airlink_auth_response_encode(1, 1, &msg, &packet_c);

    // simulate message-handling callback
    [&packet2](const mavlink_message_t *cmsg) {
        MsgMap map2(cmsg);

        packet2.deserialize(map2);
    } (&msg);

    EXPECT_EQ(packet_in.resp_type, packet2.resp_type);

#ifdef PRINT_MSG
    PRINT_MSG(msg);
#endif
}
#endif

TEST(csAirLink, AIRLINK_EYE_GS_HOLE_PUSH_REQUEST)
{
    mavlink::mavlink_message_t msg;
    mavlink::MsgMap map1(msg);
    mavlink::MsgMap map2(msg);

    mavlink::csAirLink::msg::AIRLINK_EYE_GS_HOLE_PUSH_REQUEST packet_in{};
    packet_in.resp_type = 5;

    mavlink::csAirLink::msg::AIRLINK_EYE_GS_HOLE_PUSH_REQUEST packet1{};
    mavlink::csAirLink::msg::AIRLINK_EYE_GS_HOLE_PUSH_REQUEST packet2{};

    packet1 = packet_in;

    //std::cout << packet1.to_yaml() << std::endl;

    packet1.serialize(map1);

    mavlink::mavlink_finalize_message(&msg, 1, 1, packet1.MIN_LENGTH, packet1.LENGTH, packet1.CRC_EXTRA);

    packet2.deserialize(map2);

    EXPECT_EQ(packet1.resp_type, packet2.resp_type);
}

#ifdef TEST_INTEROP
TEST(csAirLink_interop, AIRLINK_EYE_GS_HOLE_PUSH_REQUEST)
{
    mavlink_message_t msg;

    // to get nice print
    memset(&msg, 0, sizeof(msg));

    mavlink_airlink_eye_gs_hole_push_request_t packet_c {
         5
    };

    mavlink::csAirLink::msg::AIRLINK_EYE_GS_HOLE_PUSH_REQUEST packet_in{};
    packet_in.resp_type = 5;

    mavlink::csAirLink::msg::AIRLINK_EYE_GS_HOLE_PUSH_REQUEST packet2{};

    mavlink_msg_airlink_eye_gs_hole_push_request_encode(1, 1, &msg, &packet_c);

    // simulate message-handling callback
    [&packet2](const mavlink_message_t *cmsg) {
        MsgMap map2(cmsg);

        packet2.deserialize(map2);
    } (&msg);

    EXPECT_EQ(packet_in.resp_type, packet2.resp_type);

#ifdef PRINT_MSG
    PRINT_MSG(msg);
#endif
}
#endif

TEST(csAirLink, AIRLINK_EYE_GS_HOLE_PUSH_RESPONSE)
{
    mavlink::mavlink_message_t msg;
    mavlink::MsgMap map1(msg);
    mavlink::MsgMap map2(msg);

    mavlink::csAirLink::msg::AIRLINK_EYE_GS_HOLE_PUSH_RESPONSE packet_in{};
    packet_in.resp_type = 17;
    packet_in.ip_version = 84;
    packet_in.ip_address_4 = {{ 151, 152, 153, 154 }};
    packet_in.ip_address_6 = {{ 163, 164, 165, 166, 167, 168, 169, 170, 171, 172, 173, 174, 175, 176, 177, 178 }};
    packet_in.ip_port = 963497464;

    mavlink::csAirLink::msg::AIRLINK_EYE_GS_HOLE_PUSH_RESPONSE packet1{};
    mavlink::csAirLink::msg::AIRLINK_EYE_GS_HOLE_PUSH_RESPONSE packet2{};

    packet1 = packet_in;

    //std::cout << packet1.to_yaml() << std::endl;

    packet1.serialize(map1);

    mavlink::mavlink_finalize_message(&msg, 1, 1, packet1.MIN_LENGTH, packet1.LENGTH, packet1.CRC_EXTRA);

    packet2.deserialize(map2);

    EXPECT_EQ(packet1.resp_type, packet2.resp_type);
    EXPECT_EQ(packet1.ip_version, packet2.ip_version);
    EXPECT_EQ(packet1.ip_address_4, packet2.ip_address_4);
    EXPECT_EQ(packet1.ip_address_6, packet2.ip_address_6);
    EXPECT_EQ(packet1.ip_port, packet2.ip_port);
}

#ifdef TEST_INTEROP
TEST(csAirLink_interop, AIRLINK_EYE_GS_HOLE_PUSH_RESPONSE)
{
    mavlink_message_t msg;

    // to get nice print
    memset(&msg, 0, sizeof(msg));

    mavlink_airlink_eye_gs_hole_push_response_t packet_c {
         963497464, 17, 84, { 151, 152, 153, 154 }, { 163, 164, 165, 166, 167, 168, 169, 170, 171, 172, 173, 174, 175, 176, 177, 178 }
    };

    mavlink::csAirLink::msg::AIRLINK_EYE_GS_HOLE_PUSH_RESPONSE packet_in{};
    packet_in.resp_type = 17;
    packet_in.ip_version = 84;
    packet_in.ip_address_4 = {{ 151, 152, 153, 154 }};
    packet_in.ip_address_6 = {{ 163, 164, 165, 166, 167, 168, 169, 170, 171, 172, 173, 174, 175, 176, 177, 178 }};
    packet_in.ip_port = 963497464;

    mavlink::csAirLink::msg::AIRLINK_EYE_GS_HOLE_PUSH_RESPONSE packet2{};

    mavlink_msg_airlink_eye_gs_hole_push_response_encode(1, 1, &msg, &packet_c);

    // simulate message-handling callback
    [&packet2](const mavlink_message_t *cmsg) {
        MsgMap map2(cmsg);

        packet2.deserialize(map2);
    } (&msg);

    EXPECT_EQ(packet_in.resp_type, packet2.resp_type);
    EXPECT_EQ(packet_in.ip_version, packet2.ip_version);
    EXPECT_EQ(packet_in.ip_address_4, packet2.ip_address_4);
    EXPECT_EQ(packet_in.ip_address_6, packet2.ip_address_6);
    EXPECT_EQ(packet_in.ip_port, packet2.ip_port);

#ifdef PRINT_MSG
    PRINT_MSG(msg);
#endif
}
#endif

TEST(csAirLink, AIRLINK_EYE_HP)
{
    mavlink::mavlink_message_t msg;
    mavlink::MsgMap map1(msg);
    mavlink::MsgMap map2(msg);

    mavlink::csAirLink::msg::AIRLINK_EYE_HP packet_in{};
    packet_in.resp_type = 5;

    mavlink::csAirLink::msg::AIRLINK_EYE_HP packet1{};
    mavlink::csAirLink::msg::AIRLINK_EYE_HP packet2{};

    packet1 = packet_in;

    //std::cout << packet1.to_yaml() << std::endl;

    packet1.serialize(map1);

    mavlink::mavlink_finalize_message(&msg, 1, 1, packet1.MIN_LENGTH, packet1.LENGTH, packet1.CRC_EXTRA);

    packet2.deserialize(map2);

    EXPECT_EQ(packet1.resp_type, packet2.resp_type);
}

#ifdef TEST_INTEROP
TEST(csAirLink_interop, AIRLINK_EYE_HP)
{
    mavlink_message_t msg;

    // to get nice print
    memset(&msg, 0, sizeof(msg));

    mavlink_airlink_eye_hp_t packet_c {
         5
    };

    mavlink::csAirLink::msg::AIRLINK_EYE_HP packet_in{};
    packet_in.resp_type = 5;

    mavlink::csAirLink::msg::AIRLINK_EYE_HP packet2{};

    mavlink_msg_airlink_eye_hp_encode(1, 1, &msg, &packet_c);

    // simulate message-handling callback
    [&packet2](const mavlink_message_t *cmsg) {
        MsgMap map2(cmsg);

        packet2.deserialize(map2);
    } (&msg);

    EXPECT_EQ(packet_in.resp_type, packet2.resp_type);

#ifdef PRINT_MSG
    PRINT_MSG(msg);
#endif
}
#endif

TEST(csAirLink, AIRLINK_EYE_TURN_INIT)
{
    mavlink::mavlink_message_t msg;
    mavlink::MsgMap map1(msg);
    mavlink::MsgMap map2(msg);

    mavlink::csAirLink::msg::AIRLINK_EYE_TURN_INIT packet_in{};
    packet_in.resp_type = 5;

    mavlink::csAirLink::msg::AIRLINK_EYE_TURN_INIT packet1{};
    mavlink::csAirLink::msg::AIRLINK_EYE_TURN_INIT packet2{};

    packet1 = packet_in;

    //std::cout << packet1.to_yaml() << std::endl;

    packet1.serialize(map1);

    mavlink::mavlink_finalize_message(&msg, 1, 1, packet1.MIN_LENGTH, packet1.LENGTH, packet1.CRC_EXTRA);

    packet2.deserialize(map2);

    EXPECT_EQ(packet1.resp_type, packet2.resp_type);
}

#ifdef TEST_INTEROP
TEST(csAirLink_interop, AIRLINK_EYE_TURN_INIT)
{
    mavlink_message_t msg;

    // to get nice print
    memset(&msg, 0, sizeof(msg));

    mavlink_airlink_eye_turn_init_t packet_c {
         5
    };

    mavlink::csAirLink::msg::AIRLINK_EYE_TURN_INIT packet_in{};
    packet_in.resp_type = 5;

    mavlink::csAirLink::msg::AIRLINK_EYE_TURN_INIT packet2{};

    mavlink_msg_airlink_eye_turn_init_encode(1, 1, &msg, &packet_c);

    // simulate message-handling callback
    [&packet2](const mavlink_message_t *cmsg) {
        MsgMap map2(cmsg);

        packet2.deserialize(map2);
    } (&msg);

    EXPECT_EQ(packet_in.resp_type, packet2.resp_type);

#ifdef PRINT_MSG
    PRINT_MSG(msg);
#endif
}
#endif
