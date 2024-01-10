/** @file
 *	@brief MAVLink comm protocol generated from ardupilotmega.xml
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
namespace ardupilotmega {

/**
 * Array of msg_entry needed for @p mavlink_parse_char() (through @p mavlink_get_msg_entry())
 */
constexpr std::array<mavlink_msg_entry_t, 302> MESSAGE_ENTRIES {{ {0, 50, 9, 9, 0, 0, 0}, {1, 124, 31, 43, 0, 0, 0}, {2, 137, 12, 12, 0, 0, 0}, {4, 237, 14, 14, 3, 12, 13}, {5, 217, 28, 28, 1, 0, 0}, {6, 104, 3, 3, 0, 0, 0}, {7, 119, 32, 32, 0, 0, 0}, {8, 117, 36, 36, 0, 0, 0}, {11, 89, 6, 6, 1, 4, 0}, {20, 214, 20, 20, 3, 2, 3}, {21, 159, 2, 2, 3, 0, 1}, {22, 220, 25, 25, 0, 0, 0}, {23, 168, 23, 23, 3, 4, 5}, {24, 24, 30, 52, 0, 0, 0}, {25, 23, 101, 101, 0, 0, 0}, {26, 170, 22, 24, 0, 0, 0}, {27, 144, 26, 29, 0, 0, 0}, {28, 67, 16, 16, 0, 0, 0}, {29, 115, 14, 16, 0, 0, 0}, {30, 39, 28, 28, 0, 0, 0}, {31, 246, 32, 48, 0, 0, 0}, {32, 185, 28, 28, 0, 0, 0}, {33, 104, 28, 28, 0, 0, 0}, {34, 237, 22, 22, 0, 0, 0}, {35, 244, 22, 22, 0, 0, 0}, {36, 222, 21, 37, 0, 0, 0}, {37, 212, 6, 7, 3, 4, 5}, {38, 9, 6, 7, 3, 4, 5}, {39, 254, 37, 38, 3, 32, 33}, {40, 230, 4, 5, 3, 2, 3}, {41, 28, 4, 4, 3, 2, 3}, {42, 28, 2, 18, 0, 0, 0}, {43, 132, 2, 3, 3, 0, 1}, {44, 221, 4, 9, 3, 2, 3}, {45, 232, 2, 3, 3, 0, 1}, {46, 11, 2, 2, 0, 0, 0}, {47, 153, 3, 8, 3, 0, 1}, {48, 41, 13, 21, 1, 12, 0}, {49, 39, 12, 20, 0, 0, 0}, {50, 78, 37, 37, 3, 18, 19}, {51, 196, 4, 5, 3, 2, 3}, {54, 15, 27, 27, 3, 24, 25}, {55, 3, 25, 25, 0, 0, 0}, {61, 167, 72, 72, 0, 0, 0}, {62, 183, 26, 26, 0, 0, 0}, {63, 119, 181, 181, 0, 0, 0}, {64, 191, 225, 225, 0, 0, 0}, {65, 118, 42, 42, 0, 0, 0}, {66, 148, 6, 6, 3, 2, 3}, {67, 21, 4, 4, 0, 0, 0}, {69, 243, 11, 30, 1, 10, 0}, {70, 124, 18, 38, 3, 16, 17}, {73, 38, 37, 38, 3, 32, 33}, {74, 20, 20, 20, 0, 0, 0}, {75, 158, 35, 35, 3, 30, 31}, {76, 152, 33, 33, 3, 30, 31}, {77, 143, 3, 10, 3, 8, 9}, {80, 14, 4, 4, 3, 2, 3}, {81, 106, 22, 22, 0, 0, 0}, {82, 49, 39, 51, 3, 36, 37}, {83, 22, 37, 37, 0, 0, 0}, {84, 143, 53, 53, 3, 50, 51}, {85, 140, 51, 51, 0, 0, 0}, {86, 5, 53, 53, 3, 50, 51}, {87, 150, 51, 51, 0, 0, 0}, {89, 231, 28, 28, 0, 0, 0}, {90, 183, 56, 56, 0, 0, 0}, {91, 63, 42, 42, 0, 0, 0}, {92, 54, 33, 33, 0, 0, 0}, {93, 47, 81, 81, 0, 0, 0}, {100, 175, 26, 34, 0, 0, 0}, {101, 102, 32, 117, 0, 0, 0}, {102, 158, 32, 117, 0, 0, 0}, {103, 208, 20, 57, 0, 0, 0}, {104, 56, 32, 116, 0, 0, 0}, {105, 93, 62, 63, 0, 0, 0}, {106, 138, 44, 44, 0, 0, 0}, {107, 108, 64, 65, 0, 0, 0}, {108, 32, 84, 92, 0, 0, 0}, {109, 185, 9, 9, 0, 0, 0}, {110, 84, 254, 254, 3, 1, 2}, {111, 34, 16, 18, 3, 16, 17}, {112, 174, 12, 12, 0, 0, 0}, {113, 124, 36, 39, 0, 0, 0}, {114, 237, 44, 44, 0, 0, 0}, {115, 4, 64, 64, 0, 0, 0}, {116, 76, 22, 24, 0, 0, 0}, {117, 128, 6, 6, 3, 4, 5}, {118, 56, 14, 14, 0, 0, 0}, {119, 116, 12, 12, 3, 10, 11}, {120, 134, 97, 97, 0, 0, 0}, {121, 237, 2, 2, 3, 0, 1}, {122, 203, 2, 2, 3, 0, 1}, {123, 250, 113, 113, 3, 0, 1}, {124, 87, 35, 57, 0, 0, 0}, {125, 203, 6, 6, 0, 0, 0}, {126, 220, 79, 81, 3, 79, 80}, {127, 25, 35, 35, 0, 0, 0}, {128, 226, 35, 35, 0, 0, 0}, {129, 46, 22, 24, 0, 0, 0}, {130, 29, 13, 13, 0, 0, 0}, {131, 223, 255, 255, 0, 0, 0}, {132, 85, 14, 39, 0, 0, 0}, {133, 6, 18, 18, 0, 0, 0}, {134, 229, 43, 43, 0, 0, 0}, {135, 203, 8, 8, 0, 0, 0}, {136, 1, 22, 22, 0, 0, 0}, {137, 195, 14, 16, 0, 0, 0}, {138, 109, 36, 120, 0, 0, 0}, {139, 168, 43, 43, 3, 41, 42}, {140, 181, 41, 41, 0, 0, 0}, {141, 47, 32, 32, 0, 0, 0}, {142, 72, 243, 243, 0, 0, 0}, {143, 131, 14, 16, 0, 0, 0}, {144, 127, 93, 93, 0, 0, 0}, {146, 103, 100, 100, 0, 0, 0}, {147, 154, 36, 54, 0, 0, 0}, {148, 178, 60, 78, 0, 0, 0}, {149, 200, 30, 60, 0, 0, 0}, {150, 134, 42, 42, 0, 0, 0}, {151, 219, 8, 8, 3, 6, 7}, {152, 208, 4, 8, 0, 0, 0}, {153, 188, 12, 12, 0, 0, 0}, {154, 84, 15, 15, 3, 6, 7}, {155, 22, 13, 13, 3, 4, 5}, {156, 19, 6, 6, 3, 0, 1}, {157, 21, 15, 15, 3, 12, 13}, {158, 134, 14, 15, 3, 12, 13}, {160, 78, 12, 12, 3, 8, 9}, {161, 68, 3, 3, 3, 0, 1}, {162, 189, 8, 9, 0, 0, 0}, {163, 127, 28, 28, 0, 0, 0}, {164, 154, 44, 44, 0, 0, 0}, {165, 21, 3, 3, 0, 0, 0}, {166, 21, 9, 9, 0, 0, 0}, {167, 144, 22, 22, 0, 0, 0}, {168, 1, 12, 12, 0, 0, 0}, {169, 234, 18, 18, 0, 0, 0}, {170, 73, 34, 34, 0, 0, 0}, {171, 181, 66, 66, 0, 0, 0}, {172, 22, 98, 98, 0, 0, 0}, {173, 83, 8, 8, 0, 0, 0}, {174, 167, 48, 48, 0, 0, 0}, {175, 138, 19, 19, 3, 14, 15}, {176, 234, 3, 3, 3, 0, 1}, {177, 240, 20, 20, 0, 0, 0}, {178, 47, 24, 24, 0, 0, 0}, {179, 189, 29, 29, 1, 26, 0}, {180, 52, 45, 47, 1, 42, 0}, {181, 174, 4, 4, 0, 0, 0}, {182, 229, 40, 40, 0, 0, 0}, {183, 85, 2, 2, 3, 0, 1}, {184, 159, 206, 206, 3, 4, 5}, {185, 186, 7, 7, 3, 4, 5}, {186, 72, 29, 29, 3, 0, 1}, {191, 92, 27, 27, 0, 0, 0}, {192, 36, 44, 54, 0, 0, 0}, {193, 71, 22, 26, 0, 0, 0}, {194, 98, 25, 33, 0, 0, 0}, {195, 120, 37, 37, 0, 0, 0}, {200, 134, 42, 42, 3, 40, 41}, {201, 205, 14, 14, 3, 12, 13}, {214, 69, 8, 8, 3, 6, 7}, {215, 101, 3, 3, 0, 0, 0}, {216, 50, 3, 3, 3, 0, 1}, {217, 202, 6, 6, 0, 0, 0}, {218, 17, 7, 7, 3, 0, 1}, {219, 162, 2, 2, 0, 0, 0}, {225, 208, 65, 73, 0, 0, 0}, {226, 207, 8, 8, 0, 0, 0}, {230, 163, 42, 42, 0, 0, 0}, {231, 105, 40, 40, 0, 0, 0}, {232, 151, 63, 65, 0, 0, 0}, {233, 35, 182, 182, 0, 0, 0}, {234, 150, 40, 40, 0, 0, 0}, {235, 179, 42, 42, 0, 0, 0}, {241, 90, 32, 32, 0, 0, 0}, {242, 104, 52, 60, 0, 0, 0}, {243, 85, 53, 61, 1, 52, 0}, {244, 95, 6, 6, 0, 0, 0}, {245, 130, 2, 2, 0, 0, 0}, {246, 184, 38, 38, 0, 0, 0}, {247, 81, 19, 19, 0, 0, 0}, {248, 8, 254, 254, 3, 3, 4}, {249, 204, 36, 36, 0, 0, 0}, {250, 49, 30, 30, 0, 0, 0}, {251, 170, 18, 18, 0, 0, 0}, {252, 44, 18, 18, 0, 0, 0}, {253, 83, 51, 54, 0, 0, 0}, {254, 46, 9, 9, 0, 0, 0}, {256, 71, 42, 42, 3, 8, 9}, {257, 131, 9, 9, 0, 0, 0}, {258, 187, 32, 232, 3, 0, 1}, {259, 92, 235, 236, 0, 0, 0}, {260, 146, 5, 13, 0, 0, 0}, {261, 179, 27, 61, 0, 0, 0}, {262, 12, 18, 22, 0, 0, 0}, {263, 133, 255, 255, 0, 0, 0}, {264, 49, 28, 28, 0, 0, 0}, {265, 26, 16, 20, 0, 0, 0}, {266, 193, 255, 255, 3, 2, 3}, {267, 35, 255, 255, 3, 2, 3}, {268, 14, 4, 4, 3, 2, 3}, {269, 109, 213, 213, 0, 0, 0}, {270, 59, 19, 19, 0, 0, 0}, {271, 22, 52, 52, 0, 0, 0}, {275, 126, 31, 31, 0, 0, 0}, {276, 18, 49, 49, 0, 0, 0}, {280, 70, 33, 33, 0, 0, 0}, {281, 48, 13, 13, 0, 0, 0}, {282, 123, 35, 35, 3, 32, 33}, {283, 74, 144, 145, 0, 0, 0}, {284, 99, 32, 32, 3, 30, 31}, {285, 137, 40, 49, 3, 38, 39}, {286, 210, 53, 57, 3, 50, 51}, {287, 1, 23, 23, 3, 20, 21}, {288, 20, 23, 23, 3, 20, 21}, {290, 251, 46, 46, 0, 0, 0}, {291, 10, 57, 57, 0, 0, 0}, {299, 19, 96, 98, 0, 0, 0}, {300, 217, 22, 22, 0, 0, 0}, {301, 243, 58, 58, 0, 0, 0}, {310, 28, 17, 17, 0, 0, 0}, {311, 95, 116, 116, 0, 0, 0}, {320, 243, 20, 20, 3, 2, 3}, {321, 88, 2, 2, 3, 0, 1}, {322, 243, 149, 149, 0, 0, 0}, {323, 78, 147, 147, 3, 0, 1}, {324, 132, 146, 146, 0, 0, 0}, {330, 23, 158, 167, 0, 0, 0}, {331, 91, 230, 233, 0, 0, 0}, {332, 236, 239, 239, 0, 0, 0}, {333, 231, 109, 109, 0, 0, 0}, {334, 72, 10, 10, 0, 0, 0}, {335, 225, 24, 24, 0, 0, 0}, {336, 245, 84, 84, 0, 0, 0}, {339, 199, 5, 5, 0, 0, 0}, {340, 99, 70, 70, 0, 0, 0}, {350, 232, 20, 252, 0, 0, 0}, {360, 11, 25, 25, 0, 0, 0}, {370, 75, 87, 109, 0, 0, 0}, {373, 117, 42, 42, 0, 0, 0}, {375, 251, 140, 140, 0, 0, 0}, {380, 232, 20, 20, 0, 0, 0}, {385, 147, 133, 133, 3, 2, 3}, {386, 132, 16, 16, 3, 4, 5}, {387, 4, 72, 72, 3, 4, 5}, {388, 8, 37, 37, 3, 32, 33}, {390, 156, 238, 238, 0, 0, 0}, {395, 0, 212, 212, 0, 0, 0}, {397, 182, 108, 108, 0, 0, 0}, {400, 110, 254, 254, 3, 4, 5}, {401, 183, 6, 6, 3, 4, 5}, {410, 160, 53, 53, 0, 0, 0}, {411, 106, 3, 3, 0, 0, 0}, {412, 33, 6, 6, 3, 4, 5}, {413, 77, 7, 7, 3, 4, 5}, {9000, 113, 137, 137, 0, 0, 0}, {9005, 117, 34, 34, 0, 0, 0}, {10001, 209, 20, 20, 0, 0, 0}, {10002, 186, 41, 41, 0, 0, 0}, {10003, 4, 1, 1, 0, 0, 0}, {11000, 134, 51, 52, 3, 4, 5}, {11001, 15, 135, 136, 0, 0, 0}, {11002, 234, 179, 180, 3, 4, 5}, {11003, 64, 5, 5, 0, 0, 0}, {11010, 46, 49, 49, 0, 0, 0}, {11011, 106, 44, 44, 0, 0, 0}, {11020, 205, 16, 16, 0, 0, 0}, {11030, 144, 44, 44, 0, 0, 0}, {11031, 133, 44, 44, 0, 0, 0}, {11032, 85, 44, 44, 0, 0, 0}, {11033, 195, 37, 37, 3, 16, 17}, {11034, 79, 5, 5, 0, 0, 0}, {11035, 128, 8, 8, 3, 4, 5}, {11036, 177, 34, 34, 0, 0, 0}, {11037, 130, 28, 28, 0, 0, 0}, {11038, 47, 38, 38, 0, 0, 0}, {11039, 142, 9, 9, 0, 0, 0}, {12900, 114, 44, 44, 3, 0, 1}, {12901, 254, 59, 59, 3, 30, 31}, {12902, 140, 53, 53, 3, 4, 5}, {12903, 249, 46, 46, 3, 0, 1}, {12904, 77, 54, 54, 3, 28, 29}, {12905, 49, 43, 43, 3, 0, 1}, {12915, 94, 249, 249, 3, 0, 1}, {12918, 139, 51, 51, 0, 0, 0}, {12919, 7, 18, 18, 3, 16, 17}, {12920, 20, 5, 5, 0, 0, 0}, {42000, 227, 1, 1, 0, 0, 0}, {42001, 239, 46, 46, 0, 0, 0}, {50001, 246, 32, 32, 0, 0, 0}, {50002, 181, 246, 246, 0, 0, 0}, {50003, 62, 19, 19, 0, 0, 0}, {50004, 240, 10, 10, 3, 8, 9}, {50005, 152, 6, 6, 3, 4, 5}, {52000, 13, 100, 100, 0, 0, 0}, {52001, 239, 1, 1, 0, 0, 0}, {52002, 24, 1, 1, 0, 0, 0}, {52003, 166, 26, 26, 0, 0, 0}, {52004, 39, 1, 1, 0, 0, 0}, {52005, 145, 1, 1, 0, 0, 0} }};

//! MAVLINK VERSION
constexpr auto MAVLINK_VERSION = 2;


// ENUM DEFINITIONS


/** @brief  */
enum class ACCELCAL_VEHICLE_POS
{
    LEVEL=1, /*  | */
    LEFT=2, /*  | */
    RIGHT=3, /*  | */
    NOSEDOWN=4, /*  | */
    NOSEUP=5, /*  | */
    BACK=6, /*  | */
    SUCCESS=16777215, /*  | */
    FAILED=16777216, /*  | */
};

//! ACCELCAL_VEHICLE_POS ENUM_END
constexpr auto ACCELCAL_VEHICLE_POS_ENUM_END = 16777217;

/** @brief  */
enum class HEADING_TYPE
{
    COURSE_OVER_GROUND=0, /*  | */
    HEADING=1, /*  | */
};

//! HEADING_TYPE ENUM_END
constexpr auto HEADING_TYPE_ENUM_END = 2;

/** @brief  */
enum class SCRIPTING_CMD
{
    REPL_START=0, /* Start a REPL session. | */
    REPL_STOP=1, /* End a REPL session. | */
    STOP=2, /* Stop execution of scripts. | */
    STOP_AND_RESTART=3, /* Stop execution of scripts and restart. | */
};

//! SCRIPTING_CMD ENUM_END
constexpr auto SCRIPTING_CMD_ENUM_END = 4;

/** @brief  */
enum class LIMITS_STATE : uint8_t
{
    INIT=0, /* Pre-initialization. | */
    DISABLED=1, /* Disabled. | */
    ENABLED=2, /* Checking limits. | */
    TRIGGERED=3, /* A limit has been breached. | */
    RECOVERING=4, /* Taking action e.g. Return/RTL. | */
    RECOVERED=5, /* We're no longer in breach of a limit. | */
};

//! LIMITS_STATE ENUM_END
constexpr auto LIMITS_STATE_ENUM_END = 6;

/** @brief  */
enum class LIMIT_MODULE : uint8_t
{
    GPSLOCK=1, /* Pre-initialization. | */
    GEOFENCE=2, /* Disabled. | */
    ALTITUDE=4, /* Checking limits. | */
};

//! LIMIT_MODULE ENUM_END
constexpr auto LIMIT_MODULE_ENUM_END = 5;

/** @brief Flags in RALLY_POINT message. */
enum class RALLY_FLAGS : uint8_t
{
    FAVORABLE_WIND=1, /* Flag set when requiring favorable winds for landing. | */
    LAND_IMMEDIATELY=2, /* Flag set when plane is to immediately descend to break altitude and land without GCS intervention. Flag not set when plane is to loiter at Rally point until commanded to land. | */
};

//! RALLY_FLAGS ENUM_END
constexpr auto RALLY_FLAGS_ENUM_END = 3;

/** @brief  */
enum class CAMERA_STATUS_TYPES : uint8_t
{
    TYPE_HEARTBEAT=0, /* Camera heartbeat, announce camera component ID at 1Hz. | */
    TYPE_TRIGGER=1, /* Camera image triggered. | */
    TYPE_DISCONNECT=2, /* Camera connection lost. | */
    TYPE_ERROR=3, /* Camera unknown error. | */
    TYPE_LOWBATT=4, /* Camera battery low. Parameter p1 shows reported voltage. | */
    TYPE_LOWSTORE=5, /* Camera storage low. Parameter p1 shows reported shots remaining. | */
    TYPE_LOWSTOREV=6, /* Camera storage low. Parameter p1 shows reported video minutes remaining. | */
};

//! CAMERA_STATUS_TYPES ENUM_END
constexpr auto CAMERA_STATUS_TYPES_ENUM_END = 7;

/** @brief  */
enum class CAMERA_FEEDBACK_FLAGS : uint8_t
{
    PHOTO=0, /* Shooting photos, not video. | */
    VIDEO=1, /* Shooting video, not stills. | */
    BADEXPOSURE=2, /* Unable to achieve requested exposure (e.g. shutter speed too low). | */
    CLOSEDLOOP=3, /* Closed loop feedback from camera, we know for sure it has successfully taken a picture. | */
    OPENLOOP=4, /* Open loop camera, an image trigger has been requested but we can't know for sure it has successfully taken a picture. | */
};

//! CAMERA_FEEDBACK_FLAGS ENUM_END
constexpr auto CAMERA_FEEDBACK_FLAGS_ENUM_END = 5;

/** @brief  */
enum class MAV_MODE_GIMBAL
{
    UNINITIALIZED=0, /* Gimbal is powered on but has not started initializing yet. | */
    CALIBRATING_PITCH=1, /* Gimbal is currently running calibration on the pitch axis. | */
    CALIBRATING_ROLL=2, /* Gimbal is currently running calibration on the roll axis. | */
    CALIBRATING_YAW=3, /* Gimbal is currently running calibration on the yaw axis. | */
    INITIALIZED=4, /* Gimbal has finished calibrating and initializing, but is relaxed pending reception of first rate command from copter. | */
    ACTIVE=5, /* Gimbal is actively stabilizing. | */
    RATE_CMD_TIMEOUT=6, /* Gimbal is relaxed because it missed more than 10 expected rate command messages in a row. Gimbal will move back to active mode when it receives a new rate command. | */
};

//! MAV_MODE_GIMBAL ENUM_END
constexpr auto MAV_MODE_GIMBAL_ENUM_END = 7;

/** @brief  */
enum class GIMBAL_AXIS
{
    YAW=0, /* Gimbal yaw axis. | */
    PITCH=1, /* Gimbal pitch axis. | */
    ROLL=2, /* Gimbal roll axis. | */
};

//! GIMBAL_AXIS ENUM_END
constexpr auto GIMBAL_AXIS_ENUM_END = 3;

/** @brief  */
enum class GIMBAL_AXIS_CALIBRATION_STATUS
{
    IN_PROGRESS=0, /* Axis calibration is in progress. | */
    SUCCEEDED=1, /* Axis calibration succeeded. | */
    FAILED=2, /* Axis calibration failed. | */
};

//! GIMBAL_AXIS_CALIBRATION_STATUS ENUM_END
constexpr auto GIMBAL_AXIS_CALIBRATION_STATUS_ENUM_END = 3;

/** @brief  */
enum class GIMBAL_AXIS_CALIBRATION_REQUIRED
{
    UNKNOWN=0, /* Whether or not this axis requires calibration is unknown at this time. | */
    TRUE_=1, /* This axis requires calibration. | */
    FALSE_=2, /* This axis does not require calibration. | */
};

//! GIMBAL_AXIS_CALIBRATION_REQUIRED ENUM_END
constexpr auto GIMBAL_AXIS_CALIBRATION_REQUIRED_ENUM_END = 3;

/** @brief  */
enum class GOPRO_HEARTBEAT_STATUS : uint8_t
{
    DISCONNECTED=0, /* No GoPro connected. | */
    INCOMPATIBLE=1, /* The detected GoPro is not HeroBus compatible. | */
    CONNECTED=2, /* A HeroBus compatible GoPro is connected. | */
    ERROR=3, /* An unrecoverable error was encountered with the connected GoPro, it may require a power cycle. | */
};

//! GOPRO_HEARTBEAT_STATUS ENUM_END
constexpr auto GOPRO_HEARTBEAT_STATUS_ENUM_END = 4;

/** @brief  */
enum class GOPRO_HEARTBEAT_FLAGS : uint8_t
{
    FLAG_RECORDING=1, /* GoPro is currently recording. | */
};

//! GOPRO_HEARTBEAT_FLAGS ENUM_END
constexpr auto GOPRO_HEARTBEAT_FLAGS_ENUM_END = 2;

/** @brief  */
enum class GOPRO_REQUEST_STATUS : uint8_t
{
    SUCCESS=0, /* The write message with ID indicated succeeded. | */
    FAILED=1, /* The write message with ID indicated failed. | */
};

//! GOPRO_REQUEST_STATUS ENUM_END
constexpr auto GOPRO_REQUEST_STATUS_ENUM_END = 2;

/** @brief  */
enum class GOPRO_COMMAND : uint8_t
{
    POWER=0, /* (Get/Set). | */
    CAPTURE_MODE=1, /* (Get/Set). | */
    SHUTTER=2, /* (___/Set). | */
    BATTERY=3, /* (Get/___). | */
    MODEL=4, /* (Get/___). | */
    VIDEO_SETTINGS=5, /* (Get/Set). | */
    LOW_LIGHT=6, /* (Get/Set). | */
    PHOTO_RESOLUTION=7, /* (Get/Set). | */
    PHOTO_BURST_RATE=8, /* (Get/Set). | */
    PROTUNE=9, /* (Get/Set). | */
    PROTUNE_WHITE_BALANCE=10, /* (Get/Set) Hero 3+ Only. | */
    PROTUNE_COLOUR=11, /* (Get/Set) Hero 3+ Only. | */
    PROTUNE_GAIN=12, /* (Get/Set) Hero 3+ Only. | */
    PROTUNE_SHARPNESS=13, /* (Get/Set) Hero 3+ Only. | */
    PROTUNE_EXPOSURE=14, /* (Get/Set) Hero 3+ Only. | */
    TIME=15, /* (Get/Set). | */
    CHARGING=16, /* (Get/Set). | */
};

//! GOPRO_COMMAND ENUM_END
constexpr auto GOPRO_COMMAND_ENUM_END = 17;

/** @brief  */
enum class GOPRO_CAPTURE_MODE : uint8_t
{
    VIDEO=0, /* Video mode. | */
    PHOTO=1, /* Photo mode. | */
    BURST=2, /* Burst mode, Hero 3+ only. | */
    TIME_LAPSE=3, /* Time lapse mode, Hero 3+ only. | */
    MULTI_SHOT=4, /* Multi shot mode, Hero 4 only. | */
    PLAYBACK=5, /* Playback mode, Hero 4 only, silver only except when LCD or HDMI is connected to black. | */
    SETUP=6, /* Playback mode, Hero 4 only. | */
    UNKNOWN=255, /* Mode not yet known. | */
};

//! GOPRO_CAPTURE_MODE ENUM_END
constexpr auto GOPRO_CAPTURE_MODE_ENUM_END = 256;

/** @brief  */
enum class GOPRO_RESOLUTION
{
    RESOLUTION_480p=0, /* 848 x 480 (480p). | */
    RESOLUTION_720p=1, /* 1280 x 720 (720p). | */
    RESOLUTION_960p=2, /* 1280 x 960 (960p). | */
    RESOLUTION_1080p=3, /* 1920 x 1080 (1080p). | */
    RESOLUTION_1440p=4, /* 1920 x 1440 (1440p). | */
    RESOLUTION_2_7k_17_9=5, /* 2704 x 1440 (2.7k-17:9). | */
    RESOLUTION_2_7k_16_9=6, /* 2704 x 1524 (2.7k-16:9). | */
    RESOLUTION_2_7k_4_3=7, /* 2704 x 2028 (2.7k-4:3). | */
    RESOLUTION_4k_16_9=8, /* 3840 x 2160 (4k-16:9). | */
    RESOLUTION_4k_17_9=9, /* 4096 x 2160 (4k-17:9). | */
    RESOLUTION_720p_SUPERVIEW=10, /* 1280 x 720 (720p-SuperView). | */
    RESOLUTION_1080p_SUPERVIEW=11, /* 1920 x 1080 (1080p-SuperView). | */
    RESOLUTION_2_7k_SUPERVIEW=12, /* 2704 x 1520 (2.7k-SuperView). | */
    RESOLUTION_4k_SUPERVIEW=13, /* 3840 x 2160 (4k-SuperView). | */
};

//! GOPRO_RESOLUTION ENUM_END
constexpr auto GOPRO_RESOLUTION_ENUM_END = 14;

/** @brief  */
enum class GOPRO_FRAME_RATE
{
    RATE_12=0, /* 12 FPS. | */
    RATE_15=1, /* 15 FPS. | */
    RATE_24=2, /* 24 FPS. | */
    RATE_25=3, /* 25 FPS. | */
    RATE_30=4, /* 30 FPS. | */
    RATE_48=5, /* 48 FPS. | */
    RATE_50=6, /* 50 FPS. | */
    RATE_60=7, /* 60 FPS. | */
    RATE_80=8, /* 80 FPS. | */
    RATE_90=9, /* 90 FPS. | */
    RATE_100=10, /* 100 FPS. | */
    RATE_120=11, /* 120 FPS. | */
    RATE_240=12, /* 240 FPS. | */
    RATE_12_5=13, /* 12.5 FPS. | */
};

//! GOPRO_FRAME_RATE ENUM_END
constexpr auto GOPRO_FRAME_RATE_ENUM_END = 14;

/** @brief  */
enum class GOPRO_FIELD_OF_VIEW
{
    WIDE=0, /* 0x00: Wide. | */
    MEDIUM=1, /* 0x01: Medium. | */
    NARROW=2, /* 0x02: Narrow. | */
};

//! GOPRO_FIELD_OF_VIEW ENUM_END
constexpr auto GOPRO_FIELD_OF_VIEW_ENUM_END = 3;

/** @brief  */
enum class GOPRO_VIDEO_SETTINGS_FLAGS
{
    TV_MODE=1, /* 0=NTSC, 1=PAL. | */
};

//! GOPRO_VIDEO_SETTINGS_FLAGS ENUM_END
constexpr auto GOPRO_VIDEO_SETTINGS_FLAGS_ENUM_END = 2;

/** @brief  */
enum class GOPRO_PHOTO_RESOLUTION
{
    RESOLUTION_5MP_MEDIUM=0, /* 5MP Medium. | */
    RESOLUTION_7MP_MEDIUM=1, /* 7MP Medium. | */
    RESOLUTION_7MP_WIDE=2, /* 7MP Wide. | */
    RESOLUTION_10MP_WIDE=3, /* 10MP Wide. | */
    RESOLUTION_12MP_WIDE=4, /* 12MP Wide. | */
};

//! GOPRO_PHOTO_RESOLUTION ENUM_END
constexpr auto GOPRO_PHOTO_RESOLUTION_ENUM_END = 5;

/** @brief  */
enum class GOPRO_PROTUNE_WHITE_BALANCE
{
    AUTO=0, /* Auto. | */
    BALANCE_3000K=1, /* 3000K. | */
    BALANCE_5500K=2, /* 5500K. | */
    BALANCE_6500K=3, /* 6500K. | */
    RAW=4, /* Camera Raw. | */
};

//! GOPRO_PROTUNE_WHITE_BALANCE ENUM_END
constexpr auto GOPRO_PROTUNE_WHITE_BALANCE_ENUM_END = 5;

/** @brief  */
enum class GOPRO_PROTUNE_COLOUR
{
    STANDARD=0, /* Auto. | */
    NEUTRAL=1, /* Neutral. | */
};

//! GOPRO_PROTUNE_COLOUR ENUM_END
constexpr auto GOPRO_PROTUNE_COLOUR_ENUM_END = 2;

/** @brief  */
enum class GOPRO_PROTUNE_GAIN
{
    GAIN_400=0, /* ISO 400. | */
    GAIN_800=1, /* ISO 800 (Only Hero 4). | */
    GAIN_1600=2, /* ISO 1600. | */
    GAIN_3200=3, /* ISO 3200 (Only Hero 4). | */
    GAIN_6400=4, /* ISO 6400. | */
};

//! GOPRO_PROTUNE_GAIN ENUM_END
constexpr auto GOPRO_PROTUNE_GAIN_ENUM_END = 5;

/** @brief  */
enum class GOPRO_PROTUNE_SHARPNESS
{
    LOW=0, /* Low Sharpness. | */
    MEDIUM=1, /* Medium Sharpness. | */
    HIGH=2, /* High Sharpness. | */
};

//! GOPRO_PROTUNE_SHARPNESS ENUM_END
constexpr auto GOPRO_PROTUNE_SHARPNESS_ENUM_END = 3;

/** @brief  */
enum class GOPRO_PROTUNE_EXPOSURE
{
    NEG_5_0=0, /* -5.0 EV (Hero 3+ Only). | */
    NEG_4_5=1, /* -4.5 EV (Hero 3+ Only). | */
    NEG_4_0=2, /* -4.0 EV (Hero 3+ Only). | */
    NEG_3_5=3, /* -3.5 EV (Hero 3+ Only). | */
    NEG_3_0=4, /* -3.0 EV (Hero 3+ Only). | */
    NEG_2_5=5, /* -2.5 EV (Hero 3+ Only). | */
    NEG_2_0=6, /* -2.0 EV. | */
    NEG_1_5=7, /* -1.5 EV. | */
    NEG_1_0=8, /* -1.0 EV. | */
    NEG_0_5=9, /* -0.5 EV. | */
    ZERO=10, /* 0.0 EV. | */
    POS_0_5=11, /* +0.5 EV. | */
    POS_1_0=12, /* +1.0 EV. | */
    POS_1_5=13, /* +1.5 EV. | */
    POS_2_0=14, /* +2.0 EV. | */
    POS_2_5=15, /* +2.5 EV (Hero 3+ Only). | */
    POS_3_0=16, /* +3.0 EV (Hero 3+ Only). | */
    POS_3_5=17, /* +3.5 EV (Hero 3+ Only). | */
    POS_4_0=18, /* +4.0 EV (Hero 3+ Only). | */
    POS_4_5=19, /* +4.5 EV (Hero 3+ Only). | */
    POS_5_0=20, /* +5.0 EV (Hero 3+ Only). | */
};

//! GOPRO_PROTUNE_EXPOSURE ENUM_END
constexpr auto GOPRO_PROTUNE_EXPOSURE_ENUM_END = 21;

/** @brief  */
enum class GOPRO_CHARGING
{
    DISABLED=0, /* Charging disabled. | */
    ENABLED=1, /* Charging enabled. | */
};

//! GOPRO_CHARGING ENUM_END
constexpr auto GOPRO_CHARGING_ENUM_END = 2;

/** @brief  */
enum class GOPRO_MODEL
{
    UNKNOWN=0, /* Unknown gopro model. | */
    HERO_3_PLUS_SILVER=1, /* Hero 3+ Silver (HeroBus not supported by GoPro). | */
    HERO_3_PLUS_BLACK=2, /* Hero 3+ Black. | */
    HERO_4_SILVER=3, /* Hero 4 Silver. | */
    HERO_4_BLACK=4, /* Hero 4 Black. | */
};

//! GOPRO_MODEL ENUM_END
constexpr auto GOPRO_MODEL_ENUM_END = 5;

/** @brief  */
enum class GOPRO_BURST_RATE
{
    RATE_3_IN_1_SECOND=0, /* 3 Shots / 1 Second. | */
    RATE_5_IN_1_SECOND=1, /* 5 Shots / 1 Second. | */
    RATE_10_IN_1_SECOND=2, /* 10 Shots / 1 Second. | */
    RATE_10_IN_2_SECOND=3, /* 10 Shots / 2 Second. | */
    RATE_10_IN_3_SECOND=4, /* 10 Shots / 3 Second (Hero 4 Only). | */
    RATE_30_IN_1_SECOND=5, /* 30 Shots / 1 Second. | */
    RATE_30_IN_2_SECOND=6, /* 30 Shots / 2 Second. | */
    RATE_30_IN_3_SECOND=7, /* 30 Shots / 3 Second. | */
    RATE_30_IN_6_SECOND=8, /* 30 Shots / 6 Second. | */
};

//! GOPRO_BURST_RATE ENUM_END
constexpr auto GOPRO_BURST_RATE_ENUM_END = 9;

/** @brief  */
enum class MAV_CMD_DO_AUX_FUNCTION_SWITCH_LEVEL
{
    LOW=0, /* Switch Low. |Reserved (default:0)| Reserved (default:0)| Reserved (default:0)| Reserved (default:0)| Reserved (default:0)| Reserved (default:0)| Reserved (default:0)|  */
    MIDDLE=1, /* Switch Middle. |Reserved (default:0)| Reserved (default:0)| Reserved (default:0)| Reserved (default:0)| Reserved (default:0)| Reserved (default:0)| Reserved (default:0)|  */
    HIGH=2, /* Switch High. |Reserved (default:0)| Reserved (default:0)| Reserved (default:0)| Reserved (default:0)| Reserved (default:0)| Reserved (default:0)| Reserved (default:0)|  */
};

//! MAV_CMD_DO_AUX_FUNCTION_SWITCH_LEVEL ENUM_END
constexpr auto MAV_CMD_DO_AUX_FUNCTION_SWITCH_LEVEL_ENUM_END = 3;

/** @brief  */
enum class LED_CONTROL_PATTERN
{
    OFF=0, /* LED patterns off (return control to regular vehicle control). | */
    FIRMWAREUPDATE=1, /* LEDs show pattern during firmware update. | */
    CUSTOM=255, /* Custom Pattern using custom bytes fields. | */
};

//! LED_CONTROL_PATTERN ENUM_END
constexpr auto LED_CONTROL_PATTERN_ENUM_END = 256;

/** @brief Flags in EKF_STATUS message. */
enum class EKF_STATUS_FLAGS : uint16_t
{
    ATTITUDE=1, /* Set if EKF's attitude estimate is good. | */
    VELOCITY_HORIZ=2, /* Set if EKF's horizontal velocity estimate is good. | */
    VELOCITY_VERT=4, /* Set if EKF's vertical velocity estimate is good. | */
    POS_HORIZ_REL=8, /* Set if EKF's horizontal position (relative) estimate is good. | */
    POS_HORIZ_ABS=16, /* Set if EKF's horizontal position (absolute) estimate is good. | */
    POS_VERT_ABS=32, /* Set if EKF's vertical position (absolute) estimate is good. | */
    POS_VERT_AGL=64, /* Set if EKF's vertical position (above ground) estimate is good. | */
    CONST_POS_MODE=128, /* EKF is in constant position mode and does not know it's absolute or relative position. | */
    PRED_POS_HORIZ_REL=256, /* Set if EKF's predicted horizontal position (relative) estimate is good. | */
    PRED_POS_HORIZ_ABS=512, /* Set if EKF's predicted horizontal position (absolute) estimate is good. | */
    UNINITIALIZED=1024, /* Set if EKF has never been healthy. | */
};

//! EKF_STATUS_FLAGS ENUM_END
constexpr auto EKF_STATUS_FLAGS_ENUM_END = 1025;

/** @brief  */
enum class PID_TUNING_AXIS : uint8_t
{
    ROLL=1, /*  | */
    PITCH=2, /*  | */
    YAW=3, /*  | */
    ACCZ=4, /*  | */
    STEER=5, /*  | */
    LANDING=6, /*  | */
};

//! PID_TUNING_AXIS ENUM_END
constexpr auto PID_TUNING_AXIS_ENUM_END = 7;

/** @brief Special ACK block numbers control activation of dataflash log streaming. */
enum class MAV_REMOTE_LOG_DATA_BLOCK_COMMANDS : uint32_t
{
    STOP=2147483645, /* UAV to stop sending DataFlash blocks. | */
    START=2147483646, /* UAV to start sending DataFlash blocks. | */
};

//! MAV_REMOTE_LOG_DATA_BLOCK_COMMANDS ENUM_END
constexpr auto MAV_REMOTE_LOG_DATA_BLOCK_COMMANDS_ENUM_END = 2147483647;

/** @brief Possible remote log data block statuses. */
enum class MAV_REMOTE_LOG_DATA_BLOCK_STATUSES : uint8_t
{
    NACK=0, /* This block has NOT been received. | */
    ACK=1, /* This block has been received. | */
};

//! MAV_REMOTE_LOG_DATA_BLOCK_STATUSES ENUM_END
constexpr auto MAV_REMOTE_LOG_DATA_BLOCK_STATUSES_ENUM_END = 2;

/** @brief Bus types for device operations. */
enum class DEVICE_OP_BUSTYPE : uint8_t
{
    I2C=0, /* I2C Device operation. | */
    SPI=1, /* SPI Device operation. | */
};

//! DEVICE_OP_BUSTYPE ENUM_END
constexpr auto DEVICE_OP_BUSTYPE_ENUM_END = 2;

/** @brief Deepstall flight stage. */
enum class DEEPSTALL_STAGE : uint8_t
{
    FLY_TO_LANDING=0, /* Flying to the landing point. | */
    ESTIMATE_WIND=1, /* Building an estimate of the wind. | */
    WAIT_FOR_BREAKOUT=2, /* Waiting to breakout of the loiter to fly the approach. | */
    FLY_TO_ARC=3, /* Flying to the first arc point to turn around to the landing point. | */
    ARC=4, /* Turning around back to the deepstall landing point. | */
    APPROACH=5, /* Approaching the landing point. | */
    LAND=6, /* Stalling and steering towards the land point. | */
};

//! DEEPSTALL_STAGE ENUM_END
constexpr auto DEEPSTALL_STAGE_ENUM_END = 7;

/** @brief A mapping of plane flight modes for custom_mode field of heartbeat. */
enum class PLANE_MODE
{
    MANUAL=0, /*  | */
    CIRCLE=1, /*  | */
    STABILIZE=2, /*  | */
    TRAINING=3, /*  | */
    ACRO=4, /*  | */
    FLY_BY_WIRE_A=5, /*  | */
    FLY_BY_WIRE_B=6, /*  | */
    CRUISE=7, /*  | */
    AUTOTUNE=8, /*  | */
    AUTO=10, /*  | */
    RTL=11, /*  | */
    LOITER=12, /*  | */
    TAKEOFF=13, /*  | */
    AVOID_ADSB=14, /*  | */
    GUIDED=15, /*  | */
    INITIALIZING=16, /*  | */
    QSTABILIZE=17, /*  | */
    QHOVER=18, /*  | */
    QLOITER=19, /*  | */
    QLAND=20, /*  | */
    QRTL=21, /*  | */
    QAUTOTUNE=22, /*  | */
    QACRO=23, /*  | */
    THERMAL=24, /*  | */
};

//! PLANE_MODE ENUM_END
constexpr auto PLANE_MODE_ENUM_END = 25;

/** @brief A mapping of copter flight modes for custom_mode field of heartbeat. */
enum class COPTER_MODE
{
    STABILIZE=0, /*  | */
    ACRO=1, /*  | */
    ALT_HOLD=2, /*  | */
    AUTO=3, /*  | */
    GUIDED=4, /*  | */
    LOITER=5, /*  | */
    RTL=6, /*  | */
    CIRCLE=7, /*  | */
    LAND=9, /*  | */
    DRIFT=11, /*  | */
    SPORT=13, /*  | */
    FLIP=14, /*  | */
    AUTOTUNE=15, /*  | */
    POSHOLD=16, /*  | */
    BRAKE=17, /*  | */
    THROW=18, /*  | */
    AVOID_ADSB=19, /*  | */
    GUIDED_NOGPS=20, /*  | */
    SMART_RTL=21, /*  | */
    FLOWHOLD=22, /*  | */
    FOLLOW=23, /*  | */
    ZIGZAG=24, /*  | */
    SYSTEMID=25, /*  | */
    AUTOROTATE=26, /*  | */
    AUTO_RTL=27, /*  | */
};

//! COPTER_MODE ENUM_END
constexpr auto COPTER_MODE_ENUM_END = 28;

/** @brief A mapping of sub flight modes for custom_mode field of heartbeat. */
enum class SUB_MODE
{
    STABILIZE=0, /*  | */
    ACRO=1, /*  | */
    ALT_HOLD=2, /*  | */
    AUTO=3, /*  | */
    GUIDED=4, /*  | */
    CIRCLE=7, /*  | */
    SURFACE=9, /*  | */
    POSHOLD=16, /*  | */
    MANUAL=19, /*  | */
};

//! SUB_MODE ENUM_END
constexpr auto SUB_MODE_ENUM_END = 20;

/** @brief A mapping of rover flight modes for custom_mode field of heartbeat. */
enum class ROVER_MODE
{
    MANUAL=0, /*  | */
    ACRO=1, /*  | */
    STEERING=3, /*  | */
    HOLD=4, /*  | */
    LOITER=5, /*  | */
    FOLLOW=6, /*  | */
    SIMPLE=7, /*  | */
    AUTO=10, /*  | */
    RTL=11, /*  | */
    SMART_RTL=12, /*  | */
    GUIDED=15, /*  | */
    INITIALIZING=16, /*  | */
};

//! ROVER_MODE ENUM_END
constexpr auto ROVER_MODE_ENUM_END = 17;

/** @brief A mapping of antenna tracker flight modes for custom_mode field of heartbeat. */
enum class TRACKER_MODE
{
    MANUAL=0, /*  | */
    STOP=1, /*  | */
    SCAN=2, /*  | */
    SERVO_TEST=3, /*  | */
    AUTO=10, /*  | */
    INITIALIZING=16, /*  | */
};

//! TRACKER_MODE ENUM_END
constexpr auto TRACKER_MODE_ENUM_END = 17;

/** @brief The type of parameter for the OSD parameter editor. */
enum class OSD_PARAM_CONFIG_TYPE : uint8_t
{
    NONE=0, /*  | */
    SERIAL_PROTOCOL=1, /*  | */
    SERVO_FUNCTION=2, /*  | */
    AUX_FUNCTION=3, /*  | */
    FLIGHT_MODE=4, /*  | */
    FAILSAFE_ACTION=5, /*  | */
    FAILSAFE_ACTION_1=6, /*  | */
    FAILSAFE_ACTION_2=7, /*  | */
    NUM_TYPES=8, /*  | */
};

//! OSD_PARAM_CONFIG_TYPE ENUM_END
constexpr auto OSD_PARAM_CONFIG_TYPE_ENUM_END = 9;

/** @brief The error type for the OSD parameter editor. */
enum class OSD_PARAM_CONFIG_ERROR : uint8_t
{
    SUCCESS=0, /*  | */
    INVALID_SCREEN=1, /*  | */
    INVALID_PARAMETER_INDEX=2, /*  | */
    INVALID_PARAMETER=3, /*  | */
};

//! OSD_PARAM_CONFIG_ERROR ENUM_END
constexpr auto OSD_PARAM_CONFIG_ERROR_ENUM_END = 4;


} // namespace ardupilotmega
} // namespace mavlink

// MESSAGE DEFINITIONS
#include "./mavlink_msg_sensor_offsets.hpp"
#include "./mavlink_msg_set_mag_offsets.hpp"
#include "./mavlink_msg_meminfo.hpp"
#include "./mavlink_msg_ap_adc.hpp"
#include "./mavlink_msg_digicam_configure.hpp"
#include "./mavlink_msg_digicam_control.hpp"
#include "./mavlink_msg_mount_configure.hpp"
#include "./mavlink_msg_mount_control.hpp"
#include "./mavlink_msg_mount_status.hpp"
#include "./mavlink_msg_fence_point.hpp"
#include "./mavlink_msg_fence_fetch_point.hpp"
#include "./mavlink_msg_ahrs.hpp"
#include "./mavlink_msg_simstate.hpp"
#include "./mavlink_msg_hwstatus.hpp"
#include "./mavlink_msg_radio.hpp"
#include "./mavlink_msg_limits_status.hpp"
#include "./mavlink_msg_wind.hpp"
#include "./mavlink_msg_data16.hpp"
#include "./mavlink_msg_data32.hpp"
#include "./mavlink_msg_data64.hpp"
#include "./mavlink_msg_data96.hpp"
#include "./mavlink_msg_rangefinder.hpp"
#include "./mavlink_msg_airspeed_autocal.hpp"
#include "./mavlink_msg_rally_point.hpp"
#include "./mavlink_msg_rally_fetch_point.hpp"
#include "./mavlink_msg_compassmot_status.hpp"
#include "./mavlink_msg_ahrs2.hpp"
#include "./mavlink_msg_camera_status.hpp"
#include "./mavlink_msg_camera_feedback.hpp"
#include "./mavlink_msg_battery2.hpp"
#include "./mavlink_msg_ahrs3.hpp"
#include "./mavlink_msg_autopilot_version_request.hpp"
#include "./mavlink_msg_remote_log_data_block.hpp"
#include "./mavlink_msg_remote_log_block_status.hpp"
#include "./mavlink_msg_led_control.hpp"
#include "./mavlink_msg_mag_cal_progress.hpp"
#include "./mavlink_msg_ekf_status_report.hpp"
#include "./mavlink_msg_pid_tuning.hpp"
#include "./mavlink_msg_deepstall.hpp"
#include "./mavlink_msg_gimbal_report.hpp"
#include "./mavlink_msg_gimbal_control.hpp"
#include "./mavlink_msg_gimbal_torque_cmd_report.hpp"
#include "./mavlink_msg_gopro_heartbeat.hpp"
#include "./mavlink_msg_gopro_get_request.hpp"
#include "./mavlink_msg_gopro_get_response.hpp"
#include "./mavlink_msg_gopro_set_request.hpp"
#include "./mavlink_msg_gopro_set_response.hpp"
#include "./mavlink_msg_rpm.hpp"
#include "./mavlink_msg_device_op_read.hpp"
#include "./mavlink_msg_device_op_read_reply.hpp"
#include "./mavlink_msg_device_op_write.hpp"
#include "./mavlink_msg_device_op_write_reply.hpp"
#include "./mavlink_msg_adap_tuning.hpp"
#include "./mavlink_msg_vision_position_delta.hpp"
#include "./mavlink_msg_aoa_ssa.hpp"
#include "./mavlink_msg_esc_telemetry_1_to_4.hpp"
#include "./mavlink_msg_esc_telemetry_5_to_8.hpp"
#include "./mavlink_msg_esc_telemetry_9_to_12.hpp"
#include "./mavlink_msg_osd_param_config.hpp"
#include "./mavlink_msg_osd_param_config_reply.hpp"
#include "./mavlink_msg_osd_param_show_config.hpp"
#include "./mavlink_msg_osd_param_show_config_reply.hpp"
#include "./mavlink_msg_obstacle_distance_3d.hpp"
#include "./mavlink_msg_water_depth.hpp"
#include "./mavlink_msg_mcu_status.hpp"

// base include
#include "../common/common.hpp"
#include "../uAvionix/uAvionix.hpp"
#include "../icarous/icarous.hpp"
#include "../cubepilot/cubepilot.hpp"
#include "../csAirLink/csAirLink.hpp"
