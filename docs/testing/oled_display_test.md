# 0.96-Inch OLED Test

## Wiring

The OLED display arrived without the header pins soldered in place, so the four header pins first had to be attached before the display could be used on a breadboard.

Flux was applied to each solder pad to improve solder flow and joint quality. A pre-tinned soldering iron was then used to heat both the header pin and the solder pad before solder was applied. Any joint that appeared dull, uneven, or poorly formed was reheated until a smooth and reflective finish was achieved. This process was repeated for all four header pins.

Male-to-female jumper wires were then connected between the OLED display and the ESP32.

The connections were:

* SCK/SCL → GPIO 22
* SDA → GPIO 21
* VCC → ESP32 3.3 V
* GND → ESP32 GND

A small test script was uploaded to the ESP32 to display an animated image. This confirmed that the OLED display, solder joints, wiring, and I2C communication were functioning correctly.

The display pins were labelled:

* SCK/SCL
* SDA
* VCC
* GND


## I2C Communication Test

The INA226 module was inserted into the breadboard and connected to the ESP32 using the VCC, GND, SCL and SDA pins according to the predetermined circuit diagram.

An I2C scanner script was uploaded to the ESP32 to verify communication between the ESP32 and the INA226 module. The scanner successfully detected the INA226 at its default I2C address of `0x40`, confirming that the module was powered correctly and communicating with the ESP32.

Once communication had been verified, testing proceeded to the voltage measurement stage.


## Testing Procedure

After all jumper wires had been connected correctly between the ESP32 and the OLED module, a small test script was uploaded to the ESP32.

The script displayed an animation on the OLED screen to verify that the display, wiring and I2C communication were functioning correctly.

The animation was displayed successfully, confirming that the OLED module was operating as intended.


## Conclusion

After confirming that the OLED module was functioning correctly, the next stage of the project involved connecting and integrating all modules into the complete circuit.

