# INA226 Sensor Test

## Wiring

The INA226 module arrived with the header pins unsoldered; therefore, soldering was required before testing could begin. The pin headers were inserted perpendicular to the module and held in position while soldering was performed.

Flux was first applied to each solder pad to improve solder flow and joint quality. A pre-tinned soldering iron was then used to heat both the pin and solder pad before solder was applied to form the joint. If a solder joint appeared dull or uneven, reflow soldering was performed until a smooth and reflective finish was achieved. This process was repeated for all eight pins.

Once soldering was completed, the module was visually inspected to ensure that no solder bridges or poor joints were present before testing began.

## I2C Communication Test

The INA226 module was inserted into the breadboard and connected to the ESP32 using the VCC, GND, SCL, and SDA pins according to the predetermined circuit diagram.

An I2C scanner script was uploaded to the ESP32 to verify communication between the ESP32 and the INA226 module. Once the module was successfully detected on the I2C bus, testing proceeded to voltage measurement verification.

## Voltage Measurement Test

Initially, the onboard 5 V supply from the ESP32 was used as the voltage source, bypassing the buck converter during the first stage of testing. The ESP32 was then flashed with INA226 measurement software to verify that voltage readings could be successfully obtained.

Voltage readings were immediately displayed through the serial monitor; however, the measured values differed slightly from the multimeter readings by approximately 0.5%. To improve measurement accuracy, a correction factor was applied in software before displaying the voltage value. The measured voltage was multiplied by a factor of 0.949, resulting in readings that closely matched those observed on the digital multimeter.

The corrected INA226 voltage readings were then compared against the multimeter readings to verify measurement accuracy before proceeding to further testing.

## Current Measurement Test

## Serial Monitor Output

## Testing Procedure

## Testing Results

## Conclusion
