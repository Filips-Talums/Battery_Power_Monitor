# Design Process

## 1. Project Aim

The aim of this project is to work as a power monitor between the source voltage and load, being an external project. The monitor will display useful information like the incoming voltage, current and the power the load is taking in. It'll be designed to be compact and be an addition to my electronics workbench where i can use it to create and diagnose, if needed, future projects.


## 2. Problem / Need

When testing small electronics projects, it can be difficult to know how much current the circuit is drawing from the power source. If a project draws more current than expected, it may indicate a wiring fault, short circuit, damaged component, or incorrect design. In many cases, the problem is only noticed after a component becomes hot, behaves incorrectly, or fails completely.

This project is designed to make voltage, current, and power usage visible in real time. By placing the monitor between the power source and the external load, faults can be spotted earlier and diagnosed more quickly. This should reduce the chance of damaging components and make testing small electronics projects safer and easier.


## 3. Design Requirements

The design requirements for this project are as follows:

### Compact Design

The device should be small enough to be easily stored, carried, and used on a desk or workbench without taking up too much space.

### Stable Physical Design

The device should sit securely on a table during use. It should not be easily knocked over or pulled off the table when wires are connected.

### Easy-to-Read Display

The voltage, current, and power readings should be clearly shown on the OLED display. The user interface should be simple and readable from normal viewing angles while working at a desk.

### Accurate Readings

The device should measure voltage, current, and power with enough accuracy for testing small electronics projects. The readings should be compared against a multimeter during testing to check for error.

### Safety Features

The circuit should include basic protection features such as a fuse or polyfuse to protect against excessive current. Reverse polarity protection should also be considered to reduce the risk of damaging the device if the input is connected incorrectly.

### Quick Usability

The device should be simple to use. The user should be able to connect a power source and external load using screw terminals, power the device on, and quickly view live voltage, current, and power readings.


### 3.1 Input Voltage Range






### 3.2 Current Range

### 3.3 Measurements Required

### 3.4 Display Requirements

### 3.5 Safety Requirements

### 3.6 Size and Usability Requirements

## 4. System Overview

### 4.1 Block Diagram

### 4.2 Power Flow

### 4.3 Data Flow

## 5. Component Selection

### 5.1 ESP32 Microcontroller

### 5.2 INA226 Power Monitoring Sensor

### 5.3 OLED Display

### 5.4 Buck Converter

### 5.5 Fuse / Polyfuse

### 5.6 Capacitors

### 5.7 Input and Output Terminals

## 6. Circuit Design

### 6.1 Input Power Path

### 6.2 Load Measurement Path

### 6.3 ESP32 Power Supply

### 6.4 I2C Communication

### 6.5 Display Output

### 6.6 Protection and Filtering

## 7. Software Design

### 7.1 Sensor Reading

### 7.2 Power Calculation

### 7.3 OLED Display Layout

### 7.4 Warning / Error Messages

## 8. Prototype Testing

### 8.1 Breadboard Test

### 8.2 Buck Converter Test

### 8.3 INA226 Voltage Test

### 8.4 INA226 Current Test

### 8.5 OLED Display Test

## 9. Calibration

### 9.1 Multimeter Comparison

### 9.2 Voltage Accuracy

### 9.3 Current Accuracy

### 9.4 Error Correction

## 10. Problems and Fixes

### 10.1 Power Supply Issues

### 10.2 Sensor Reading Issues

### 10.3 Display Issues

### 10.4 Wiring / Connection Issues

## 11. Final Design

### 11.1 Final Circuit Layout

### 11.2 Final Component List

### 11.3 Final Operating Range

## 12. Future Improvements
