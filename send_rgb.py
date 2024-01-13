#/bin/python3

import os
import sys
from time import sleep
import signal

from pymavlink import mavutil
from pymavlink.dialects.v20 import stemstudios

os.environ['MAVLINK20'] = '1'

if len(sys.argv) < 2:
    print("Usage: python3 send_rgb.py <connection-url>")
    sys.exit(0)

try:
    mavlinkConnection = mavutil.mavlink_connection(
        sys.argv[1], 
        dialect='stemstudios', 
        source_system=1, 
        source_component=135,
        baud=115200
    )
except Exception as error:
    print("PyMAVLink Error Connecting to Drone: " + str(error))

def RotateRGB(RGB):
    RGB.insert(0, RGB.pop())
    return RGB        

RGB = [0xFF0000, 0x00FF00, 0x0000FF, 0xFFFFFF]

# Send LED_FILL_MODE_CLEAR on ctrl+c
def signal_handler(sig, frame):
    for i in range(0, 4):
        mavlinkConnection.mav.led_strip_config_send(
            1, 134, 
            stemstudios.LED_FILL_MODE_CLEAR, 
            0, 8, i, 
            [0x000000 for _ in range(0, 8)]
        )
    sys.exit(0)

signal.signal(signal.SIGINT, signal_handler)



while True:
    for i in range(0, 4):
        mavlinkConnection.mav.led_strip_config_send(
            1, 134, 
            stemstudios.LED_FILL_MODE_ALL, 
            0, 8, i, 
            [RGB[i] for _ in range(0, 8)]
        )
    RGB = RotateRGB(RGB)
    sleep(0.5)
    
