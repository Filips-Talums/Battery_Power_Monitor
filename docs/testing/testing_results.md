# Testing Results

## Breadboard Prototype Test

The breadboard prototype was tested using a variable DC source, multimeter, INA226 sensor, ESP32, OLED display, and LED load.

## Voltage Calibration

Initial testing showed that the raw INA226 bus voltage reading was consistently higher than the multimeter reading by approximately 5.3%. A software correction factor of 0.949 was applied.

| Test | Multimeter Voltage | Raw INA226 Voltage | Correction Factor |
|---|---:|---:|---:|
| 1 | 12.06 V | 12.71 V | 0.949 |
| 2 | 9.18 V | 9.67 V | 0.949 |
| 3 | 7.70 V | 8.12 V | 0.948 |
| 4 | 6.18 V | 6.51 V | 0.949 |

## Current Measurement

(IN PROGRESS)
