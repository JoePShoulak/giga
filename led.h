#ifndef __LED_H
#define __LED_H

#include <Arduino_GigaDisplay.h>

#define BLINK_SHORT_DELAY 200
#define BLINK_DELAY 500
#define BLINK_LONG_DELAY 1500

#define WHITE 0xffffff
#define RED 0xff0000
#define YELLOW 0xffff00
#define GREEN 0x00ff00
#define CYAN 0x00ffff
#define BLUE 0x0000ff
#define MAGENTA 0xff00ff

GigaDisplayRGB rgb;

void rgbOn(unsigned int color)
{
  unsigned int r = (color >> 16) & 0xff;
  unsigned int g = (color >> 8) & 0xff;
  unsigned int b = color & 0xff;

  rgb.on(r, g, b);
}

void blink(int color, int time = BLINK_DELAY)
{
  rgbOn(color);
  delay(time);
  rgb.off();
  delay(time);
}

void blink(int r, int g, int b, int time = BLINK_DELAY)
{
  rgb.on(r, g, b);
  delay(time);
  rgb.off();
  delay(time);
}

void errorBlink(int errorCode)
{
  for (int i = 0; i <= errorCode; i++)
    blink(RED, BLINK_SHORT_DELAY);

  delay(BLINK_LONG_DELAY);
}

// Demos
void rainbowDemo()
{
  blink(WHITE);
  blink(RED);
  blink(YELLOW);
  blink(GREEN);
  blink(CYAN);
  blink(BLUE);
  blink(MAGENTA);
}

void errorDemo()
{
  errorBlink(0);
  errorBlink(0);
  errorBlink(1);
  errorBlink(2);
}

#endif
