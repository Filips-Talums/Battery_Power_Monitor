#include <Arduino.h>
#include "sensor.h"
#include "config.h"
#include "oled.h"

bool displayFrozen = false;
bool lastButtonState = HIGH;

void setup() {

  Serial.begin(115200);

  bool sensorReady = initialiseSensor();

  if (sensorReady == false) {
    Serial.println("Sensor Not Found");

  }

  else {
      Serial.println("Sensor Initialised");
  }

  pinMode(FREEZE_PIN, INPUT_PULLUP);


  initOLED();


}



void loop() {

  bool currentButtonState = digitalRead(FREEZE_PIN);

  if(currentButtonState == LOW && lastButtonState == HIGH)
  {
    displayFrozen = !displayFrozen;

    delay(200);
  }
  lastButtonState = currentButtonState;



  float voltage = getBusVoltage();
  float current = getCurrent();
  float power = getPower();

  Serial.print("Voltage (V): ");
  Serial.println(voltage);
  
  Serial.print("Current (A): ");
  Serial.println(current);

  
  Serial.print("Power   (W): ");
  Serial.println(power, 6);

  Serial.println();

  delay(1000);

  float shunt_mV = getShuntVoltage_mV();

  Serial.print("Shunt Voltage (mV): ");
  Serial.println(shunt_mV, 6);


  if (displayFrozen == false)
  {
  updateOLED();
  }
  


}
