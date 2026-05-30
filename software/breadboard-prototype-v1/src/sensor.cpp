#include "sensor.h"
#include "config.h"
#include <Wire.h>
#include <INA226.h>

INA226 ina226(INA226_ADDRESS); 

bool initialiseSensor() {
  Wire.begin(SDA_PIN, SCL_PIN);
  delay(100);

  if (!ina226.begin()){
    return false;
  }

  ina226.setMaxCurrentShunt(MAXIMUM_CURRENT, SHUNT_VAL);


  return true;

}


float getBusVoltage() {
  float rawVoltage = ina226.getBusVoltage();
  return rawVoltage * VOLTAGE_CORRECTION;
}


float getCurrent() {
  float shuntVoltage_mV = ina226.getShuntVoltage_mV();
  float shuntVoltage_V = shuntVoltage_mV / 1000.0;

  float current_A = shuntVoltage_V / SHUNT_VAL;

  return current_A;
}

float getPower() {
  float voltage = getBusVoltage();
  float current = getCurrent();

  return voltage * current;
}

float getShuntVoltage_mV() {
  return ina226.getShuntVoltage_mV();
}