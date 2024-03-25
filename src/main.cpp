#include <Arduino.h>
// #include <Arduino_GigaDisplay.h>
#include "led.h"

#define BAUDRATE 9600
#define SERIAL_DELAY 1500

void setup()
{
  rgb.begin(); // void, can't test

  Serial.begin(BAUDRATE); // void, can't test
  delay(SERIAL_DELAY);
  Serial.println("Ready!");
}

void loop()
{
  blink(WHITE);
  blink(RED);
  blink(YELLOW);
  blink(GREEN);
  blink(CYAN);
  blink(BLUE);
  blink(MAGENTA);
}
