#ifndef __FIBONACCI_H
#define __FIBONACCI_H

#include <ArduinoGraphics.h>
#include <Arduino_H7_Video.h>

#ifndef SCREEN_WIDTH
#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 480
#endif

#define CIRCLE_DIAMETER 30
#define SCALE 1.9

void printCircles(Arduino_H7_Video &display, int row, int count)
{
  for (int i = 1; i <= count; i++)
  {
    display.circle(CIRCLE_DIAMETER * SCALE * i, CIRCLE_DIAMETER * SCALE * row, CIRCLE_DIAMETER);
  }
}

void fibonacciDemo(Arduino_H7_Video &display, int count)
{
  display.beginDraw();
  display.clear();
  display.noStroke();

  display.fill(BLUE);

  int a;
  int b = 1;
  int swap;

  for (int i = 1; i <= count; i++)
  {
    printCircles(display, i, b);

    swap = b;
    b = a + b;
    a = swap;
  }

  display.endDraw();
}

#endif