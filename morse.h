#ifndef __MORSE_H
#define __MORSE_H

#include <ArduinoGraphics.h>
#include <Arduino_H7_Video.h>

#include "colors.h"

#ifndef SCREEN_WIDTH
#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 480
#endif

#define MORSE_SIZE 40
#define X_COUNT SCREEN_WIDTH / MORSE_SIZE
#define Y_COUNT SCREEN_HEIGHT / MORSE_SIZE

int xCurr;
int yCurr;

void update(Arduino_H7_Video &display)
{
  xCurr++;

  if (xCurr == X_COUNT)
  {
    xCurr = 0;
    yCurr++;
  }
}

void space(Arduino_H7_Video &display)
{
  update(display);
}

void dit(Arduino_H7_Video &display)
{
  int x = xCurr * MORSE_SIZE + MORSE_SIZE * 0.5;
  int y = yCurr * MORSE_SIZE + MORSE_SIZE * 0.5;
  int r = MORSE_SIZE * 0.4;

  display.circle(x, y, r);

  update(display);
}

void dash(Arduino_H7_Video &display)
{
  int x = xCurr * MORSE_SIZE + MORSE_SIZE * 0.1;
  int y = yCurr * MORSE_SIZE + MORSE_SIZE * 0.4;
  int w = MORSE_SIZE * 0.8;
  int h = MORSE_SIZE * 0.2;

  display.rect(x, y, w, h);

  update(display);
}

void sos(Arduino_H7_Video &display)
{
  dit(display);
  dit(display);
  dit(display);
  space(display);
  dash(display);
  dash(display);
  dash(display);
  space(display);
  dit(display);
  dit(display);
  dit(display);
}

void morseDemo(Arduino_H7_Video &display)
{
  display.beginDraw();
  display.clear();
  display.stroke(BLACK);
  display.fill(GRAY);

  for (int x = 0; x < X_COUNT; x++)
  {
    for (int y = 0; y < Y_COUNT; y++)
    {
      display.rect(x * MORSE_SIZE, y * MORSE_SIZE, MORSE_SIZE, MORSE_SIZE);
    }
  }

  display.noStroke();
  display.fill(BLUE);

  sos(display);
  space(display);
  space(display);
  sos(display);

  display.endDraw();
}

#endif