/** @file
 *	@brief MAVLink comm protocol generated from ledstrip.xml
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
namespace ledstrip {

/**
 * Array of msg_entry needed for @p mavlink_parse_char() (through @p mavlink_get_msg_entry())
 */
constexpr std::array<mavlink_msg_entry_t, 2> MESSAGE_ENTRIES {{ {60200, 215, 38, 38, 3, 32, 33}, {60201, 254, 36, 36, 0, 0, 0} }};

//! MAVLINK VERSION
constexpr auto MAVLINK_VERSION = 2;


// ENUM DEFINITIONS


/** @brief How to fill LEDs (Fill all, Starting from a specfic LED, etc.) */
enum class LED_FILL_MODE : uint8_t
{
    ALL=0, /* Fill All LEDs in Strip with Colour | */
    INDEX=1, /* Fill (LENGTH) LEDs with colours in (ARRAY). Start from LED (INDEX). | */
    FOLLOW_FLIGHT_MODE=2, /* All LEDs in all* strips change according to flight-mode. | */
    CLEAR=3, /* Fill All LEDs in Strip with Black. | */
};

//! LED_FILL_MODE ENUM_END
constexpr auto LED_FILL_MODE_ENUM_END = 4;


} // namespace ledstrip
} // namespace mavlink

// MESSAGE DEFINITIONS
#include "./mavlink_msg_led_strip_config.hpp"
#include "./mavlink_msg_led_strip_state.hpp"

// base include

