#include "sensor.h"
#include "config.g"
#include <Wire.h>
#include <INA226.h>

boot initaliseSensor() {
  Wire.begin(SDA_PIN, SCL_PIN);

  if (ina226.begin() == false) {
    return flase;

  }

  ina226.setMaxCurrentShunt(MAXIMUM_CURRENT, SHUNT_VAL);

  return true;

}
