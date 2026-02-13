# WS2812B RGB LED Controller with CH591R MCU

A lightweight, web-controlled RGB LED controller using the **CH591R microcontroller** and **WS2812B LED strip**. Control your LEDs from a browser via a simple web interface (`/WEB.html`).

## Features

* Control **WS2812B RGB LEDs** with **CH591R MCU**
* Web interface hosted on `/WEB.html` for easy control
* Customizable LED colors, patterns, and brightness
* Firmware is based on example BLE code with minor modifications for web control
* Efficient, compact firmware ideal for embedded projects

## Hardware Requirements

* **MCU:** CH591R
* **LEDs:** WS2812B RGB LED strip
* **Connections & Components:**

  * 0.47 µF capacitor between **VINTA** and **GND**
  * 10 µF capacitor between **VCC** and **GND**
  * 32 MHz crystal oscillator with **two 22 pF capacitors**
  * External antenna for wireless communication
  * LED data line connected to the specified MCU GPIO pin
* **USB connection** required for both power and control(follow datasheet)

> ⚠️ Make sure your power supply matches the LED strip requirements. WS2812B LEDs typically require 3.3V-5V and can draw significant current for longer strips.

## Booting / Flashing the MCU

To enter bootloader mode:

1. **Hold the Boot button (PB22)**
2. **Reconnect the USB cable** while holding the button
3. Device will enter bootloader mode, ready for firmware flashing

> Note: **Reset + boot buttons** do not trigger bootloader; the above sequence is required.

## Software

* **Web Page:** `/WEB.html` – user interface for LED control
* **Firmware:** Custom CH591R firmware derived from BLE examples, modified for web-based control, Compile with ``` MounRiver Studio II ```

### How It Works

1. CH591R hosts a small web server serving `/WEB.html`.
2. Connect via browser on the same network.
3. Web page sends control commands to the MCU via BLE V5.4.
4. MCU translates commands into WS2812B protocol to update LED colors and patterns.

## Setup

1. Assemble the hardware with capacitors, crystal, antenna, and connect the LED strip.
2. Enter bootloader mode as described above.
3. Flash the firmware to the CH591R MCU.
4. Power the MCU and LED strip.
5. Open `/WEB.html` in a browser.
6. Adjust colors, patterns, and brightness from the web interface.

## Customization

* Modify `/WEB.html` to update UI or add features
* Adjust firmware for new LED patterns, brightness limits, or GPIO pins

## Notes

* Firmware is based on CH591R BLE example code, but modified for web control
* Web server runs directly on MCU — no external server required
* Longer LED strips may require additional power supply considerations

## License

This project is licensed under the MIT License – see the [LICENSE](LICENSE) file for details.

## Contributing

Contributions are welcome! If you improve firmware, add web features, or enhance hardware design, feel free to submit a pull request.
