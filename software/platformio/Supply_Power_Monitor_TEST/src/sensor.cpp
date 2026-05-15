#include "sensor.h"
#include "config.h"
#include <Wire.h>
#include <INA226.h>

INA226 ina226(INA226_ADDRESS); 

bool initialiseSensor() {
  return true;
}


float getBusVoltage() {
  //float voltage = ina226.getBusVoltage();
  return 9.0;
}


float getCurrent() {
  //float current = ina226.getCurrent();
  return 0.52;
}

float getPower() {
  //float power = ina226.getPower();
  return getBusVoltage() * getCurrent();
}
