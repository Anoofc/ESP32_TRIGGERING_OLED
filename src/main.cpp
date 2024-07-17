#define DEBUG 0

#define BAUDRATE 9600

#define PIN1 19
#define PIN2 14  
#define PIN3 18
#define PIN4 15

#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>


#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

// Declaration for SSD1306 display connected using I2C
#define OLED_RESET     -1 // Reset pin
#define SCREEN_ADDRESS 0x3C
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);


void oledPrint (String text){
  // Changing Font Size
  display.clearDisplay();
  display.setTextColor(WHITE);
  display.setCursor(0,24);
  display.setTextSize(2);
  display.println(text);
  display.display();

}

void setup() {
  Serial.begin(BAUDRATE);
  if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }

  // Clear the buffer.
  display.clearDisplay(); 

  pinMode(PIN1, INPUT_PULLUP);
  pinMode(PIN2, INPUT_PULLUP);
  pinMode(PIN3, INPUT_PULLUP);
  pinMode(PIN4, INPUT_PULLUP);
  
}

void loop() {
  
  if(digitalRead(PIN1) == LOW){
    Serial.println("A");
    oledPrint("PIN1 - A");
  }
  if(digitalRead(PIN2) == LOW){
    Serial.println("B");
    oledPrint("PIN2 - B");
  }
  if(digitalRead(PIN3) == LOW){
    Serial.println("C");
    oledPrint("PIN3 - C");
  }
  if(digitalRead(PIN4) == LOW){
    Serial.println("D");
    oledPrint("PIN4 - D");
  }
  delay(500);
  
}

