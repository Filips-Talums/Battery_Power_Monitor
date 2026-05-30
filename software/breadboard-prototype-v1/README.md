# Breadboard Prototype V1 Software

This folder contains the PlatformIO software used for the first working breadboard prototype of the DC inline power monitor.

## Purpose

The software reads voltage and shunt voltage from the INA226 power monitoring sensor using the ESP32. The ESP32 calculates current using the R100 shunt resistor value and calculates power using voltage multiplied by current.

The measured voltage, current, and power values are displayed on a 0.96 inch 128x64 I2C OLED display.

## Hardware Used

- ESP32 development board
- INA226 power monitoring module with R100 0.1 Ω shunt resistor
- 0.96 inch 128x64 I2C OLED display
- LM2596S step-down buck converter
- LED test load
- Breadboard wiring

## Features

- Reads INA226 bus voltage
- Reads INA226 shunt voltage
- Calculates current manually using the shunt resistor value
- Calculates power manually using voltage × current
- Displays voltage, current, and power on the OLED display
- Includes voltage correction based on multimeter calibration

## Calibration

During testing, the raw INA226 bus voltage reading was consistently higher than the multimeter reading. A software correction factor was applied to make the displayed voltage match the measured voltage more closely.

Current yet to be verified

## Current Status

This version is confirmed working on the breadboard prototype. It should be treated as the stable software, pre current correction, checkpoint before adding extra features such as warning outputs, improved display layout, buttons, or PCB-specific changes.