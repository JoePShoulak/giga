#include <ArduinoGraphics.h>
#include <Arduino_H7_Video.h>
#include "Particle.h"

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 480
#define FRAME_DURATION 40
#define FLAKE_COUNT 10

Arduino_H7_Video gfx(SCREEN_WIDTH, SCREEN_HEIGHT, GigaDisplayShield);

Particle flakes[FLAKE_COUNT];
unsigned long prevFrameTime;

void setup()
{
  gfx.begin();
  gfx.noStroke();
  gfx.beginDraw();
  gfx.clear();
  gfx.endDraw();

  for (Particle &flake : flakes)
    flake.begin(gfx);
}

void loop()
{
  if (millis() < prevFrameTime + FRAME_DURATION)
    return;

  gfx.beginDraw();
  gfx.clear();

  for (Particle &flake : flakes)
    flake.update();

  gfx.endDraw();

  prevFrameTime = millis();
}
