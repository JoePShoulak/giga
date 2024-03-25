#ifndef __LED_H
#define __LED_H

#include <Arduino_GigaDisplay.h>

#define BLINK_SHORT_DELAY 200
#define BLINK_DELAY 500
#define BLINK_LONG_DELAY 1500

#define WHITE 255, 255, 255
#define RED 255, 0, 0
#define YELLOW 255, 255, 0
#define GREEN 0, 255, 0
#define CYAN 0, 255, 255
#define BLUE 0, 0, 255
#define MAGENTA 255, 0, 255

GigaDisplayRGB rgb;

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
  errorBlink(2);
  errorBlink(4);
}

#endif
