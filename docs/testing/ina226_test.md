# INA226 Sensor Test

## Wiring

IMG_2550 IMG_2546

The INA226 module arrived with the header pins unsoldered; therefore, soldering was required before testing could begin. The pin headers were inserted perpendicular to the module and held in position while soldering was performed.

Flux was first applied to each solder pad to improve solder flow and joint quality. A pre-tinned soldering iron was then used to heat both the pin and solder pad before solder was applied to form the joint. If a solder joint appeared dull or uneven, reflow soldering was performed until a smooth and reflective finish was achieved. This process was repeated for all eight pins.

Once soldering was completed, the module was visually inspected to ensure that no solder bridges or poor joints were present before testing began.

## I2C Communication Test

## Get Picture of The I2C found ##

The INA226 module was inserted into the breadboard and connected to the ESP32 using the VCC, GND, SCL, and SDA pins according to the predetermined circuit diagram.

An I2C scanner script was uploaded to the ESP32 to verify communication between the ESP32 and the INA226 module. Once the module was successfully detected on the I2C bus, testing proceeded to voltage measurement verification.

## Testing Procedure (FIX SPELLING)

IMG_2578 IMG_2579
IMG_2581 IMG_2582

For voltage multimeter in V dc prongs placed on the positive and negatvie terminals of the output screw terminal this data was compared to the INA226 readings in the serial monitor where then a correction factor can be calcultaed if needed.

To verify the current readings jumpers were placed intot the screw terminal then placed on a breadboard where then from the postiive went to the postive probe of multimter and the negative probe when to a known resistor and back to the ground of the output terminal. The multimeter was placed in seiries in current mode. The data was taken and again compared to the serial monitor reading of the INA226 module. Finally the diffreence is claculated and a appropriet correction factor is applied. 

## Voltage Measurement Test

Initially, the onboard 5 V supply from the ESP32 was used as the voltage source, bypassing the buck converter during the first stage of testing. The ESP32 was then flashed with INA226 measurement software to verify that voltage readings could be successfully obtained.

Voltage readings were immediately displayed through the serial monitor; however, the measured values differed slightly from the multimeter readings by approximately 0.5%. To improve measurement accuracy, a correction factor was applied in software before displaying the voltage value. The measured voltage was multiplied by a factor of 0.949, resulting in readings that closely matched those observed on the digital multimeter.

The corrected INA226 voltage readings were then compared against the multimeter readings to verify measurement accuracy before proceeding to further testing.

## Current Measurement Test

A test on the current measurement was done using a constant voltage of 6 V while a varied resistor values used. The multimeter probes where placed between Vout and one leg of resistor while the other went back to Vout ground.

A software correction factor of 1.04 was applied.

## Current Testing Results 

| Resistor Load | Multimeter Current | Raw INA226 Current | Correction Factor |
|---|---:|---:|---:|
| 1 kΩ | 6.13 mA | 5.87 mA | 1.044 |
| 470 Ω | 12.7 mA | 12.2 mA | 1.041 |
| 220 Ω | 26.7 mA | 25.7 mA| 1.039 |
| 100 Ω | 56.8 mA | 54.78 mA | 1.037 |

## Voltage Testing Results

| Test | Multimeter Voltage | Raw INA226 Voltage | Correction Factor |
|---|---:|---:|---:|
| 1 | 12.06 V | 12.71 V | 0.949 |
| 2 | 9.18 V | 9.67 V | 0.949 |
| 3 | 7.70 V | 8.12 V | 0.948 |
| 4 | 6.18 V | 6.51 V | 0.949 |

## Conclusion

One the data measured by the INA226 was verified as accurate the final step in the breadboard design face of the project was to have the oled screen display the data effectivly.