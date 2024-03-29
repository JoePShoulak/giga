#ifndef __LED_H
#define __LED_H

#include <Arduino_GigaDisplay.h>
#include "colors.h"

#define BLINK_SHORT_DELAY 200
#define BLINK_DELAY 500
#define BLINK_LONG_DELAY 1500

enum ErrorCodes
{
  DISPLAY_ERROR
};

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
  {
    blink(255, 0, 0, BLINK_SHORT_DELAY);
  }

  delay(BLINK_LONG_DELAY);
}

#endif
