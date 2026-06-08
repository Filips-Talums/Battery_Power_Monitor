# Testing Results

## Breadboard Prototype Test

The breadboard prototype was tested using a variable DC source, multimeter, INA226 sensor, ESP32, OLED display, and LED load.

## Voltage Calibration

Initial testing showed that the raw INA226 bus voltage reading was consistently higher than the multimeter reading by approximately 5.3%. 

| Test | Multimeter Voltage | Raw INA226 Voltage | Correction Factor |
|---|---:|---:|---:|
| 1 | 12.06 V | 12.71 V | 0.949 |
| 2 | 9.18 V | 9.67 V | 0.949 |
| 3 | 7.70 V | 8.12 V | 0.948 |
| 4 | 6.18 V | 6.51 V | 0.949 |

A software correction factor of 0.949 was applied.

## Current Measurement

A test on the current measurement was done using a constant voltage of 6 V while a varied resistor values used. The multimeter probes where placed between Vout and one leg of resistor while the other went back to Vout ground.

| Resistor Load | Multimeter Current | Raw INA226 Current | Correction Factor |
|---|---:|---:|---:|
| 1 kΩ | 6.13 mA | 5.87 mA | 1.044 |
| 470 Ω | 12.7 mA | 12.2 mA | 1.041 |
| 220 Ω | 26.7 mA | 25.7 mA| 1.039 |
| 100 Ω | 56.8 mA | 54.78 mA | 1.037 |

A software correction factor of 1.04 was applied.

