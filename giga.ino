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

Arduino_H7_Video display(SCREEN_WIDTH, SCREEN_HEIGHT, GigaDisplayShield);
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
  // check bounds
  if (flake.pos.y > SCREEN_HEIGHT)
    resetFlake(flake);

  // draw
  display.fill(flake.color);
  display.noStroke();
  display.circle(flake.pos.x, flake.pos.y, flake.diameter);
}

void setup()
{
  while (display.begin() == 1)
    ;

  Serial.begin(BAUDRATE);
  // while (!Serial)
  //   ;

  for (Particle &flake : flakes)
    resetFlake(flake);

  display.beginDraw();
  display.clear();
  display.endDraw();
}

void loop()
{
  display.beginDraw();
  display.clear();

  for (Particle &flake : flakes)
    flake.update(pPostUpdate);

  display.endDraw();

  delay(FRAME_DELAY);
}
