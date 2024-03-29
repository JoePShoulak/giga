#include <ArduinoGraphics.h>
#include <Arduino_H7_Video.h>
#include "led.h"
#include "Particle.h"

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 480
#define BAUDRATE 9600

Arduino_H7_Video display(SCREEN_WIDTH, SCREEN_HEIGHT, GigaDisplayShield);

void printVector(Vector2D vec)
{
  Serial.print("X: ");
  Serial.print(vec.x);
  Serial.print(", Y: ");
  Serial.println(vec.y);
}

void setup()
{
  rgb.begin();
  rgb.off();
  rgb.on(GREEN);

  while (display.begin() == 1)
    errorBlink(DISPLAY_ERROR);

  Serial.begin(BAUDRATE);
  while (!Serial)
    ;

  display.beginDraw();
  display.clear();
  display.endDraw();

  Vector2D a(3, 4);
  Vector2D b(1, 2);

  printVector(a);

  a += b;
  Serial.println("a+b: ");
  printVector(a);
  a -= b;

  a -= b;
  Serial.println("a-b: ");
  printVector(a);
  a += b;

  a *= 2;
  Serial.println("a*2: ");
  printVector(a);
  a /= 2;

  a /= 2;
  Serial.println("a/2: ");
  printVector(a);
  a *= 2;
}

void loop()
{
}
