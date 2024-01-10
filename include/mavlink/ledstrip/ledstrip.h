/** @file
 *  @brief MAVLink comm protocol generated from ledstrip.xml
 *  @see http://mavlink.org
 */
#pragma once
#ifndef MAVLINK_LEDSTRIP_H
#define MAVLINK_LEDSTRIP_H

#ifndef MAVLINK_H
    #error Wrong include order: MAVLINK_LEDSTRIP.H MUST NOT BE DIRECTLY USED. Include mavlink.h from the same directory instead or set ALL AND EVERY defines from MAVLINK.H manually accordingly, including the #define MAVLINK_H call.
#endif

#define MAVLINK_LEDSTRIP_XML_HASH 3487412677184301548

#ifdef __cplusplus
extern "C" {
#endif

// MESSAGE LENGTHS AND CRCS

#ifndef MAVLINK_MESSAGE_LENGTHS
#define MAVLINK_MESSAGE_LENGTHS {}
#endif

#ifndef MAVLINK_MESSAGE_CRCS
#define MAVLINK_MESSAGE_CRCS {{60200, 215, 38, 38, 3, 32, 33}, {60201, 254, 36, 36, 0, 0, 0}}
#endif

#include "../protocol.h"

#define MAVLINK_ENABLED_LEDSTRIP

// ENUM DEFINITIONS


/** @brief How to fill LEDs (Fill all, Starting from a specfic LED, etc.) */
#ifndef HAVE_ENUM_LED_FILL_MODE
#define HAVE_ENUM_LED_FILL_MODE
typedef enum LED_FILL_MODE
{
   LED_FILL_MODE_ALL=0, /* Fill All LEDs in Strip with Colour | */
   LED_FILL_MODE_INDEX=1, /* Fill (LENGTH) LEDs with colours in (ARRAY). Start from LED (INDEX). | */
   LED_FILL_MODE_FOLLOW_FLIGHT_MODE=2, /* All LEDs in all* strips change according to flight-mode. | */
   LED_FILL_MODE_CLEAR=3, /* Fill All LEDs in Strip with Black. | */
   LED_FILL_MODE_ENUM_END=4, /*  | */
} LED_FILL_MODE;
#endif

// MAVLINK VERSION

#ifndef MAVLINK_VERSION
#define MAVLINK_VERSION 2
#endif

#if (MAVLINK_VERSION == 0)
#undef MAVLINK_VERSION
#define MAVLINK_VERSION 2
#endif

// MESSAGE DEFINITIONS
#include "./mavlink_msg_led_strip_config.h"
#include "./mavlink_msg_led_strip_state.h"

// base include



#if MAVLINK_LEDSTRIP_XML_HASH == MAVLINK_PRIMARY_XML_HASH
# define MAVLINK_MESSAGE_INFO {MAVLINK_MESSAGE_INFO_LED_STRIP_CONFIG, MAVLINK_MESSAGE_INFO_LED_STRIP_STATE}
# define MAVLINK_MESSAGE_NAMES {{ "LED_STRIP_CONFIG", 60200 }, { "LED_STRIP_STATE", 60201 }}
# if MAVLINK_COMMAND_24BIT
#  include "../mavlink_get_info.h"
# endif
#endif

#ifdef __cplusplus
}
#endif // __cplusplus
#endif // MAVLINK_LEDSTRIP_H
