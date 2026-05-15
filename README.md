# Battery_Power_Monitor

## Overview

Battery_Power_Monitor is a personal electronics project designed to measure and display the voltage, current, and power consumption of external DC-powered devices.

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
- MP1584EN 5 V Buck Converter
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
