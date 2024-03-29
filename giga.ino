#include <ArduinoGraphics.h>
#include <Arduino_H7_Video.h>
#include "Particle.h"
#include "colors.h"

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 480
#define BAUDRATE 9600
#define FRAME_DELAY 40
#define FLAKE_COUNT 10
#define MIN_DIAMETER 10
#define MAX_DIAMETER 80

Arduino_H7_Video gfx(SCREEN_WIDTH, SCREEN_HEIGHT, GigaDisplayShield);
Particle flakes[FLAKE_COUNT];

void resetFlake(Particle &flake)
{
  flake.vel *= 0;
  flake.diameter = random(MIN_DIAMETER, MAX_DIAMETER);
  flake.color = 0x0f0f0f * 16 * ((float)flake.diameter / MAX_DIAMETER);
  flake.pos.set(random(SCREEN_WIDTH), -2 * flake.diameter);
}

void pPostUpdate(Particle &flake)
{
  if (flake.pos.y > SCREEN_HEIGHT)
    resetFlake(flake);
}

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
    resetFlake(flake);
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
    flake.update(pPostUpdate);

  gfx.endDraw();

  delay(FRAME_DELAY);
}
