#include <Arduino.h>
#include "sensor.h"
#include "config.h"
#include "oled.h"

bool displayFrozen = false;
bool lastButtonState = HIGH;

void setup() {
  Serial.begin(115200);

  bool sensorReady = initialiseSensor();

  if (!sensorReady) {
    Serial.println("Sensor Not Found");
  } else {
    Serial.println("Sensor Initialised");
  }

  initOLED();
  updateOLED();  

  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(LED_PIN, OUTPUT);

  digitalWrite(BUZZER_PIN, HIGH);
  digitalWrite(LED_PIN, HIGH);

  delay(600);

  digitalWrite(BUZZER_PIN, LOW);
  digitalWrite(LED_PIN, LOW);
}



void loop() {

  updateOLED();
  

  float voltage = getBusVoltage();
  float currentA = getCurrent();
  float currentmA = currentA * 1000.0; 
  float power = getPower();

  Serial.print("Voltage (V): ");
  Serial.println(voltage);
  
  Serial.print("Current (A): ");
  Serial.println(currentA);


  Serial.print("Power   (W): ");
  Serial.println(power, 6);

  Serial.println(); 

  if (currentA >= 2){
    digitalWrite(BUZZER_PIN, HIGH);
    digitalWrite(LED_PIN, HIGH);
  }
  else{
    digitalWrite(BUZZER_PIN, LOW);
    digitalWrite(LED_PIN, LOW);
  }

  delay(1000);

  float shunt_mV = getShuntVoltage_mV();

  Serial.print("Shunt Voltage (mV): ");
  Serial.println(shunt_mV, 6);
  
  Serial.print("Current (A): ");
  Serial.println(currentA, 6);

  Serial.print("Current (mA): ");
  Serial.println(currentmA , 3);




  


}
