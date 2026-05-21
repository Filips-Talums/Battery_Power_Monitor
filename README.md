# Supply_Power_Monitor

## Overview

Battery_Power_Monitor is an ESP32-based DC inline power monitor designed to measure voltage, current, and power while a DC source powers an external load.

The system is designed to support a wide range of DC input sources from 5 V to 15 V and aims to act as a compact monitoring tool for electronics development and testing.

---

## Project Goals

Through this project I aim to learn:

- PCB design using KiCad
- Circuit testing and calibration
- ESP32 microcontroller development
- Embedded systems programming using C++
- Professional project documentation using GitHub
- Power monitoring and sensor integration

---

## Components Used

- ESP32 Development Board
- INA226 Power Monitoring Sensor
- 128x64 I2C OLED Display
- 5 V buck-boost converter module for powering the ESP32 from a 5–12 V input
- Screw Terminals
- Electrolytic and Ceramic Capacitors
- Fuse Protection

---

## How It Works

An external DC power source between 5 V and 15 V is connected through screw terminals.

The input power is split into two sections:

- A regulated 5 V supply powers the ESP32 and OLED display
- The main power line passes through the INA226 current and voltage sensor before reaching the external load

The INA226 measures:

- Bus Voltage
- Current Draw
- Power Consumption

The ESP32 processes this data and displays the measured values on the OLED screen.

The device is intended to help monitor power usage, diagnose faults, and test small electronics projects safely.

---

## System Diagram

![System Diagram](docs/images/Supply_Power_Monitor.png)

### Power Flow

```text
DC Input (5 V - 15 V)
        │
        ├──→ Buck Converter (5 V)
        │          │
        │          └──→ ESP32 ──→ OLED Display
        │                        └──→ Buzzer Warning
        │
        └──→ Fuse Protection
                   │
                   └──→ INA226 Power Monitor
                                │
                                └──→ Load Output
```
## Current Status

- Project requirements defined
- Main components selected
- System block diagram drafted
- PlatformIO project created
- INA226 library added
- INA226 with ESP32 Software Created

- OLED display integration in progress
- Circuit design and testing pending




## Project Documentation

- [Design Process](Design_Process.md)
- [Hardware Files](hardware/)
- [Software](software/)
- [Examples](examples/)
- [Learning Notes](learning/)
