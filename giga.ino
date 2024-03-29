#include <ArduinoGraphics.h>
#include <Arduino_H7_Video.h>
#include "led.h"
#include "morse.h"
// #include "fibonacci.h"

Arduino_H7_Video display(SCREEN_WIDTH, SCREEN_HEIGHT, GigaDisplayShield);

void setup()
{
  rgb.begin();
  rgb.off();
  rgb.on(GREEN);

  while (display.begin() == 1)
  {
    errorBlink(0);
  }

  // fibonacciDemo(display, 7);
  morseDemo(display);
}

void loop()
{
}
