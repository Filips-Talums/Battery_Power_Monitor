#pragma once

// I2C Pins
#define SDA_PIN 19
#define SCL_PIN 18

// Output Pins
#define ALERT_PIN 26 
#define BUZZER_PIN 22
#define LED_PIN 23

// Voltage Limits
const float MAXIMUM_VOLTAGE = 15.0;
const float MINIMUM_VOLTAGE = 5.0;

// Current Limits
const float MAXIMUM_CURRENT = 2.0;

// Battery Warning Threshold
const float WEAK_BATT_PERC = 12.5;

// Shunt Resistor
const float SHUNT_VAL = 0.1;

// Sensor Address

int INA226_ADDRESS = 0x40;


