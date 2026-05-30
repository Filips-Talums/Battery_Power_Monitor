# Breadboard Prototype V1 Software

This folder contains the PlatformIO software used for the first working breadboard prototype of the DC inline power monitor.

## Purpose

The software reads bus voltage and shunt voltage from the INA226 power monitoring sensor using the ESP32. Current is calculated manually using the R100 shunt resistor value, and power is calculated using voltage multiplied by current.

The measured voltage, current, and power values are displayed on a 0.96 inch 128x64 I2C OLED display.

## Hardware Used

- ESP32 development board
- INA226 power monitoring module with R100 0.1 Ω shunt resistor
- 0.96 inch 128x64 I2C OLED display
- LM2596S step-down buck converter
- Resistor loads for current testing
- Breadboard wiring

## Features

- Reads INA226 bus voltage
- Reads INA226 shunt voltage
- Calculates current manually using the shunt resistor value
- Calculates power manually using voltage × current
- Displays voltage, current, and power on the OLED display
- Displays low current values in milliamps
- Includes voltage correction based on multimeter calibration
- Includes current correction based on resistor load testing

## Calibration

During voltage testing, the raw INA226 bus voltage reading was consistently higher than the multimeter reading. A software correction factor was applied to make the displayed voltage match the measured voltage more closely.

Current testing was carried out using resistor loads and a multimeter. The monitor initially under-read current slightly, so a current correction factor was added in software.

Current is calculated using:

```text
Current = Shunt Voltage / Shunt Resistance
```

## Current Status

This version is confirmed working on the breadboard prototype. It should be treated as the stable calibrated software checkpoint before adding extra features such as warning outputs, improved display layout, buttons, or PCB-specific changes.

## Next Steps

- Test with higher-current loads
- Add overvoltage warning logic
- Add overcurrent warning logic
- Improve OLED display layout
- Move the circuit from breadboard to a soldered prototype or PCB