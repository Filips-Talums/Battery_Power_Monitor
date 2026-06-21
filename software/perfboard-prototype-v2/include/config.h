#pragma once

// I2C Pins
#define SCL_PIN 22
#define SDA_PIN 21

// Output Pins
#define ALERT_PIN 26 
#define BUZZER_PIN 25
#define LED_PIN 27
#define FREEZE_PIN 16

// Voltage Limits
const float MAXIMUM_VOLTAGE = 15.0;
const float MINIMUM_VOLTAGE = 5.0;

// Current Limits
const float MAXIMUM_CURRENT = 2.0;

// Battery Warning Threshold
const float WEAK_BATT_PERC = 12.5;

// Shunt Resistor
const float SHUNT_VAL = 0.1;

// Addreses

const int INA226_ADDRESS = 0x40;
const int OLED_ADDRESS = 0x3C;

// Calibration

const float VOLTAGE_CORRECTION = 0.949;
const float CURRENT_CORRECTION = 1.04;
// OLED Config

const int SCREEN_WIDTH = 128;
const int SCREEN_HEIGHT = 32;
const int text_size = .5;


