#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "config.h"
#include "sensor.h"
#include <Wire.h>

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);


void initOLED() {


    if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C))
    {
        Serial.println("OLED FAILED");

        while(true)
        {
        }
    }
    
    display.clearDisplay();
    
    display.setTextSize(text_size);
    
    display.setTextColor(SSD1306_WHITE);

    display.display();


}





void updateOLED() {

    
    float voltage = getBusVoltage();
    float currentA = getCurrent();
    float currentmA = currentA * 1000.0; 
    float power = getPower();

    display.clearDisplay();

    // VOLTAGE
    display.setCursor(20,0);
    display.print("VOLTAGE: ");
    display.print(voltage);
    display.println(" V");

    // CURRENT

    display.setCursor(20,11);
    display.print("CURRENT: ");

    if (currentA <= 0.0) {
        display.println("N/A");
    }
    else if (currentA < 1.0) {
        display.print(currentmA, 2);
        display.println(" mA");
    }
    else {
        display.print(currentA, 3);
        display.println(" A");
    }

    
    
    // POWER
    display.setCursor(20,21);
    display.print("POWER:   ");
   
    if (power <= 0 )
    {
        display.println("N/A");
    }
    else
    {
        display.print(power);
        display.println(" W");

    }

    display.display();

    


}