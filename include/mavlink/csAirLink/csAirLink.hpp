/** @file
 *	@brief MAVLink comm protocol generated from csAirLink.xml
 *	@see http://mavlink.org
 */

#pragma once

#include <array>
#include <cstdint>
#include <sstream>

#ifndef MAVLINK_STX
#define MAVLINK_STX 253
#endif

#include "../message.hpp"

namespace mavlink {
namespace csAirLink {

/**
 * Array of msg_entry needed for @p mavlink_parse_char() (through @p mavlink_get_msg_entry())
 */
constexpr std::array<mavlink_msg_entry_t, 6> MESSAGE_ENTRIES {{ {52000, 13, 100, 100, 0, 0, 0}, {52001, 239, 1, 1, 0, 0, 0}, {52002, 24, 1, 1, 0, 0, 0}, {52003, 166, 26, 26, 0, 0, 0}, {52004, 39, 1, 1, 0, 0, 0}, {52005, 145, 1, 1, 0, 0, 0} }};

//! MAVLINK VERSION
constexpr auto MAVLINK_VERSION = 3;


// ENUM DEFINITIONS


/** @brief  */
enum class AIRLINK_AUTH_RESPONSE_TYPE : uint8_t
{
    ERROR_LOGIN_OR_PASS=0, /* Login or password error | */
    OK=1, /* Auth successful | */
};

//! AIRLINK_AUTH_RESPONSE_TYPE ENUM_END
constexpr auto AIRLINK_AUTH_RESPONSE_TYPE_ENUM_END = 2;

/** @brief  */
enum class AIRLINK_EYE_GS_HOLE_PUSH_RESP_TYPE : uint8_t
{
    HPR_PARTNER_NOT_READY=0, /*  | */
    HPR_PARTNER_READY=1, /*  | */
};

//! AIRLINK_EYE_GS_HOLE_PUSH_RESP_TYPE ENUM_END
constexpr auto AIRLINK_EYE_GS_HOLE_PUSH_RESP_TYPE_ENUM_END = 2;

/** @brief  */
enum class AIRLINK_EYE_IP_VERSION : uint8_t
{
    IP_V4=0, /*  | */
    IP_V6=1, /*  | */
};

//! AIRLINK_EYE_IP_VERSION ENUM_END
constexpr auto AIRLINK_EYE_IP_VERSION_ENUM_END = 2;

/** @brief  */
enum class AIRLINK_EYE_HOLE_PUSH_TYPE : uint8_t
{
    HP_NOT_PENETRATED=0, /*  | */
    HP_BROKEN=1, /*  | */
};

//! AIRLINK_EYE_HOLE_PUSH_TYPE ENUM_END
constexpr auto AIRLINK_EYE_HOLE_PUSH_TYPE_ENUM_END = 2;

/** @brief  */
enum class AIRLINK_EYE_TURN_INIT_TYPE : uint8_t
{
    TURN_INIT_START=0, /*  | */
    TURN_INIT_OK=1, /*  | */
    TURN_INIT_BAD=2, /*  | */
};

//! AIRLINK_EYE_TURN_INIT_TYPE ENUM_END
constexpr auto AIRLINK_EYE_TURN_INIT_TYPE_ENUM_END = 3;


} // namespace csAirLink
} // namespace mavlink

// MESSAGE DEFINITIONS
#include "./mavlink_msg_airlink_auth.hpp"
#include "./mavlink_msg_airlink_auth_response.hpp"
#include "./mavlink_msg_airlink_eye_gs_hole_push_request.hpp"
#include "./mavlink_msg_airlink_eye_gs_hole_push_response.hpp"
#include "./mavlink_msg_airlink_eye_hp.hpp"
#include "./mavlink_msg_airlink_eye_turn_init.hpp"

// base include

