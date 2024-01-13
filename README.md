# MAVLink Lights v0.1.0
### Turn a RaspberryPI Pico into a MAVLink Component that controls LED Strips.

Use [MAVLink](https://mavlink.io/en/) Messages to control up to 8 WS2812 LED strips.

Messages defined [here](https://github.com/DanielAdelodun/mavlink/tree/4572d651e692b19bdf09f8df81033451e7060399).
Specfically, in [`ledstrip.xml`](https://github.com/DanielAdelodun/mavlink/blob/4572d651e692b19bdf09f8df81033451e7060399/message_definitions/v1.0/ledstrip.xml)

## Table of Contents
- [Installation](#installation)
- [Usage](#usage)
- [Contributing](#contributing)
- [License](#license)

## Installation
The simplest way to reprogram the Pico’s Flash is to use the USB mode. To do this, depower the board, then hold the
BOOTSEL button down during board power-up (e.g. hold BOOTSEL down while connecting the USB). The Pico will then
appear as a USB Mass Storage Device. Drag [`MAVLink_Lights.uf2`](https://github.com/DanielAdelodun/MAVLink_Lights/releases/download/v0.1.0/MAVLink_Lights.uf2) onto the disk, and this will write the file to flash and
restart the Pico.

See the [RaspberryPi Pico Documentation](https://datasheets.raspberrypi.com/pico/getting-started-with-pico.pdf) for more.

## Usage
You need a source of MAVLink LED Strip messages. `send_rgb.py` uses pymavlink. \
You will need to [generate a custom dialect](https://mavlink.io/en/mavgen_python/) from the [message definitions](https://github.com/DanielAdelodun/mavlink/blob/4572d651e692b19bdf09f8df81033451e7060399/message_definitions/v1.0/ledstrip.xml).

See [here](https://github.com/DanielAdelodun/MAVSDK/tree/Lights/examples/lights) for example MAVSDK programs, built using the Lights plugin. \
(The example uses an out-of-tree branch of MAVSDK, and a custom dialect).

Connect your source of MAVLink LED Strip messages to the Pico. \
Use GPIO_4 (Pico UART1 TX)(Pin 6) and GPIO_5 (RX)(Pin 7).

Connect the data line(s) of your WS2821 LED(s) to one of GPIO_6 - GPIO_13. \
_(Note: Pin 13, between GPIO_9 and GPIO_10, is GND)._

Strips can be indexed using the MAVLink LED Strip `strip_id` parameter. Set to 0-7. \
Individual LEDs can indexed with `led_index`. Set up to 8 LEDs at a time using the `colors` array and `length`.

By default, the Component will have the LEDs change colour according to the flightmode. \
You can reenable this behaviour on any strip by setting `fill_mode` = `LED_FILL_MODE_FOLLOW_FLIGHT_MODE`.

## Contributing
Please feel free to make an issue or a pull request.

## License
MIT
