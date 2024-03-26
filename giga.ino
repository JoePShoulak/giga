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
  // rainbowDemo();
  errorDemo();
}

// #include "Arduino_H7_Video.h"
// #include "ArduinoGraphics.h"
// #include "led.h"

// #define SCREEN_WIDTH 800
// #define SCREEN_HEIGHT 480

// Arduino_H7_Video display(SCREEN_WIDTH, SCREEN_HEIGHT, GigaDisplayShield);

// void setup()
// {
//   display.begin();

//   display.beginDraw();
//   display.clear();
//   display.noStroke();
//   display.fill(255, 0, 0);
//   display.rect(0, 0, display.width(), display.height());

//   display.fill(0, 0, 255);
//   display.circle(200, 200, 200);

//   display.fill(0, 255, 0);
//   display.circle(500, 300, 300);

//   display.endDraw();
// }

// void loop()
// {
//   rgb.on(0, 0, 255);
// }
