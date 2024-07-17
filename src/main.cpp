#define DEBUG 0

#define BAUDRATE 9600

#define PIN1 14
#define PIN2 15
#define PIN3 18
#define PIN4 19

#include <Arduino.h>
#include <U8g2lib.h>
#include <Wire.h>

U8G2_SSD1306_128X64_NONAME_1_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE);

void setup() {
  Serial.begin(BAUDRATE);
  u8g2.begin();  

  pinMode(PIN1, INPUT_PULLUP);
  
  
}

void loop() {
  
}

