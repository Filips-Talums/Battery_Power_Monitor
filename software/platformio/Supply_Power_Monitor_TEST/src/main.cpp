#include <Arduino.h>
#include "sensor.h"
#include "config.h"

void setup() {

  Serial.begin(115200);

  bool sensorReady = initialiseSensor();

  if (sensorReady == false) {
    Serial.println("Sensor Not Found");

  }

  else {
      Serial.println("Sensor Initialised");
  }
}

void loop() {

  float voltage = getBusVoltage();
  float current = getCurrent();
  float power = getPower();

  Serial.print("Voltage (V): ");
  Serial.println(voltage);
  
  Serial.print("Current (A): ");
  Serial.println(current);

  
  Serial.print("Power   (W): ");
  Serial.println(power);

  Serial.println();

  delay(1000);

}
