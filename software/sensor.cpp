#include "sensor.h"
#include "config.h"
#include <Wire.h>
#include <INA226.h>

INA226 ina226(INA226_ADDRESS); 

bool initialiseSensor() {
  Wire.begin(SDA_PIN, SCL_PIN);
  
  if (ina226.begin() == false) {
    return false;
  }
  
  ina226.setMaxCurrentShunt(MAXIMUM_CURRENT, SHUNT_VAL);
  return true;
}


float getVoltage() {
  float voltage = ina226.getVoltage();
  return voltage;
}


float getCurrent() {
  float current = ina226.getCurrent();
  return current;
}

float getPower() {
  float power = ina226.getPower();
  return power;
}
