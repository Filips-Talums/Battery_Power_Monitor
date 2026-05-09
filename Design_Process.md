# Design Process

## 1. Project Aim

The aim of this project is to work as a power monitor between the source voltage and load, being an external project. The monitor will display useful information like the incoming voltage, current and the power the load is taking in. It'll be designed to be compact and be an addition to my electronics workbench where i can use it to create and diagnose, if needed, future projects.


## 2. Problem / Need

When testing small electronics projects, it can be difficult to know how much current the circuit is drawing from the power source. If a project draws more current than expected, it may indicate a wiring fault, short circuit, damaged component, or incorrect design. In many cases, the problem is only noticed after a component becomes hot, behaves incorrectly, or fails completely.

This project is designed to make voltage, current, and power usage visible in real time. By placing the monitor between the power source and the external load, faults can be spotted earlier and diagnosed more quickly. This should reduce the chance of damaging components and make testing small electronics projects safer and easier.


## 3. Design Requirements

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

The device should support a DC input voltage range of **5 V to 12 V**, which suits small electronics projects such as microcontroller circuits, sensors, LEDs, and low-power modules.

A **5 V buck-boost converter** is required to provide a stable 5 V supply for the ESP32 and OLED display, even when the input voltage varies between 5 V and 12 V. This is needed because a standard buck converter may not reliably output 5 V when the input is also 5 V.

If an adjustable buck-boost converter is used, the adjustment screw or control point should be accessible without needing to disassemble the device. This allows the output voltage to be checked or adjusted during setup and maintenance.

### 3.2 Current Range

The first iteration of the power monitor will be designed for small electronics projects with a current range of **0–3 A**. This range is suitable for low-power sensor circuits, microcontroller projects, LED modules, and small single-board computer projects.

A 3 A limit gives more headroom than a 1 A design, as some devices can draw short current spikes during startup or when extra peripherals are connected. For example, a Raspberry Pi or similar board may draw around 1 A or more depending on the connected accessories and workload.

The fuse/polyfuse and INA226 module should be selected so they can safely support the chosen **0–3 A** current range.

### 3.3 Measurements Required

The power monitor is required to display **voltage**, **current**, and **power** in real time.

- **Voltage** should be displayed in volts (V).
- **Current** should be displayed in amps (A), or milliamps (mA) for lower current readings.
- **Power** should be displayed in watts (W).

Power will be calucalted using the measured voltage and current

Power = Current x Voltage

The displayed values should use a suitable number of decimal places so the readings are clear and easy to understand.

### 3.4 Display Requirements

The display should be clear and readable from a normal working distance when the device is being used on a desk or workbench. The readings should also be visible from different viewing angles so the user does not need to position themselves directly above the display.

The user interface should be simple and easy to understand at a glance. Voltage, current, and power readings should be clearly labelled with their correct units, such as V, A, mA, and W.

### 3.5 Safety Requirements

The power monitor should include basic safety features to reduce the risk of damage to the monitor itself and the connected load.

- **Overcurrent protection:** A fuse or resettable polyfuse should be used on the input/load path. This protects the circuit if the external load draws too much current or if a short circuit occurs.

- **Reverse polarity protection:** The input should include protection against the power source being connected the wrong way around. This reduces the risk of damaging the ESP32, INA226, OLED display, and connected load.

- **Overvoltage warning:** The INA226 should be used to detect if the input voltage is above the specified operating range. If the voltage exceeds the safe limit, the ESP32 should display a warning on the OLED screen.

- **Accurate readings:** The device should provide reliable voltage and current readings so the user can identify abnormal current draw or voltage issues before damage occurs.


### 3.6 Size and Usability Requirements

The device should be compact enough for easy storage, transport, and use on a desk or workbench. The target size is approximately the size of three 9 V batteries placed together.

The internal layout should be designed to use space efficiently. Modules may be stacked or arranged in layers inside the chassis if this does not cause overheating, wiring strain, or difficulty accessing key components.

The device should have a stable physical design so it does not move around easily when wires are connected. The weight should be distributed evenly across the chassis to reduce the risk of the device being pulled or knocked off the table during use.

The device should be simple to use and operate as a plug-and-play monitor. It should be powered from the same input source being measured, so no separate external power supply is required for the ESP32, OLED display, or sensor circuit.

## 4. System Overview

### 4.1 Block Diagram

```text
6–12 V DC Input
        │
        ▼
Input Screw Terminals
        │
        ├──→ Buck/Buck-Boost Converter → 5 V → ESP32
        │                                      │
        │                                      ├──→ OLED Display
        │                                      ├──→ LED Warning
        │                                      └──→ Buzzer Warning
        │
        └──→ INA226 Power Sensor → Load Output Terminals → External Load
                         │
                         └── I2C Data → ESP32



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
