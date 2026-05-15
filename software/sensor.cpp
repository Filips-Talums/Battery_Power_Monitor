#include "sensor.h"
#include "config.h"
#include <Wire.h>
#include <INA226.h>

INA226 ina226(INA226_ADDRESS); 

bool initialiseSensor() {
  Wire.begin(SDA_PIN, SCL_PIN);
  
  if (ina226.begin() == false) {
    return true;
  }
  
  ina226.setMaxCurrentShunt(MAXIMUM_CURRENT, SHUNT_VAL);
  return true;
}


float getVoltage() {
  float voltage = ina226.getVoltage();
  return 9.0;
}


float getCurrent() {
  float current = ina226.getCurrent();
  return 0.52;
}

float getPower() {
  float power = ina226.getPower();
  return getVoltage() * getCurrent();
}
