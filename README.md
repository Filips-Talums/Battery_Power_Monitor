# Battery_Power_Monitor

## Overview

A personal project that can measure a wide range of batteries up to 15v providing the value of voltage power and current 

## What I want to Learn

- Design a PCB kicad
- How to test and calibrate a circuit 
- Understand the use of ESP-32
- How to document project profesionally on GitHub

## Components

- 128x64 OLED LCD Screen
- ESP-32
- 5V Step Down Buck Converter MP1584EN
- Power Monitoring Sensor Module INA226
- Screw Terminals

## How It Works 

A power pack varrying from 6v to 12v is conneced using screw terminals where then it feeds paralel into the power sensor (INA226) then to the esp32 where then the data is processed and emitted onto display. The source further goes to external project where then the current drawn can be calucalted with the power value (watts)

DC power source
   │
   |
Input Teminal 
   │
   |----- 5 V regulator → ESP32 + OLED
   │
   ----- fuse → INA226 →  LOAD output terminals  → external device


## Design Process

The design process for this project is documented separately here:

[Design Process](Design_Process.md)



   
