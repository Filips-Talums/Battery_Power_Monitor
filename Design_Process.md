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
```
### 4.2 Power Flow

The DC input first enters the device through the input screw terminals. From there, the input power is split into two paths.

The first path goes to the buck-boost converter. The buck-boost converter provides a stable 5 V output, which is used to power the ESP32, OLED display, LED, and buzzer.

At the same time, the second path goes through the INA226 power monitoring sensor and then continues to the load output terminals. The external load is connected to these output terminals. This allows the INA226 to measure the voltage supplied to the load and the current drawn by the load.


### 4.3 Data Flow

The INA226 power monitoring sensor sends voltage and current readings to the ESP32 using I2C communication. The ESP32 receives this data, processes it in software, and calculates the power value in watts.

The processed data is then sent to the OLED display, where the voltage, current, and power readings are shown to the user. The ESP32 can also control the LED and buzzer based on the measured values, such as activating a warning if the voltage or current goes outside the safe operating range.

## 5. Component Selection

### 5.1 ESP32-WROOM-32E Microcontroller

The ESP32-WROOM-32E was chosen because it gives the project enough processing power and input/output pins for the power monitor without making the design too expensive or complicated.

Compared to an Arduino Uno, the ESP32 has a much faster clock speed and a dual-core processor. This allows it to read data from the INA226 sensor, calculate voltage, current, and power values, update the OLED display, and control the warning LED and buzzer without slowing down.

The ESP32 also uses I2C communication, which is useful because both the INA226 sensor and OLED display can share the same SDA and SCL lines. This reduces wiring and keeps the circuit layout simpler.

Although the project does not currently require wireless features, the built-in WiFi and Bluetooth are useful advantages of the ESP32. They allow the design to be expanded later for data logging, wireless monitoring, or sending readings to a phone or computer.

Overall, the ESP32 was selected because it is low cost, powerful, widely supported, and suitable for real-time monitoring in this project

### 5.2 INA226 Power Monitoring Sensor

The INA226 power monitoring sensor was selected because it is capable of accurately measuring both bus voltage and current while remaining suitable for the scale of this project. It provides a good balance between performance, cost, and simplicity without being unnecessarily complex.

The INA226 can measure bus voltages up to 36 V and current levels depending on the value of the shunt resistor used on the module. The module purchased is rated for up to approximately 3 A, however the exact current limit will depend on the installed shunt resistor. As the specifications of the included shunt resistor were not provided in the product listing, the exact rating will be confirmed once the module arrives.

If required, the shunt resistor can be replaced using soldering equipment to better suit the current range and accuracy requirements of the project.


### 5.3 OLED Display

A 0.96 inch 128x64 I2C OLED display was chosen to show the live voltage, current, and power readings. The display only requires four connections: VCC, GND, SDA, and SCL, making it simple to connect to the ESP32.

The 128x64 resolution provides enough space to display all key readings at the same time, allowing the user to quickly check the power source and load behaviour during testing.

### 5.4 Buck Converter

The input voltage for the project is expected to vary between 5 V and 12 V. As the ESP32 requires a stable 5 V supply, a buck converter is needed to safely reduce and regulate the input voltage. Supplying the ESP32 with a voltage above its rated input could damage the microcontroller and other components.

The LM2596S DC-DC Step Down Buck Converter was selected because it is suitable for the voltage range required in this project. The module can accept an input voltage between approximately 3 V and 40 V and regulate it down to a lower stable output voltage.

For this project, the buck converter will be adjusted to provide a stable 5 V output to power the ESP32 and connected components safely and reliably.


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
