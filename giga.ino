#include <ArduinoGraphics.h>
#include <Arduino_H7_Video.h>
#include "Particle.h"
#include "colors.h"

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 480
#define BAUDRATE 9600
#define FRAME_DELAY 40
#define FLAKE_COUNT 10

Arduino_H7_Video gfx(SCREEN_WIDTH, SCREEN_HEIGHT, GigaDisplayShield);
Particle flakes[FLAKE_COUNT];

void setup()
{
  while (gfx.begin() == 1)
    ;

  Serial.begin(BAUDRATE);
  // while (!Serial)
  //   ;

  for (Particle &flake : flakes)
  {
    flake.gfx = gfx;
    flake.reset();
  }

  gfx.beginDraw();
  gfx.clear();
  gfx.endDraw();
}

void loop()
{
  gfx.beginDraw();
  gfx.clear();

  for (Particle &flake : flakes)
    flake.update();

  gfx.endDraw();

  delay(FRAME_DELAY);
}
