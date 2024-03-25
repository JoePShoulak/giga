#ifndef __LED_H
#define __LED_H

#include <Arduino_GigaDisplay.h>

#define BLINK_DELAY 500

GigaDisplayRGB rgb;

#define BLACK 0, 0, 0
#define WHITE 255, 255, 255
#define RED 255, 0, 0
#define YELLOW 255, 255, 0
#define GREEN 0, 255, 0
#define CYAN 0, 255, 255
#define BLUE 0, 0, 255
#define MAGENTA 255, 0, 255

void blink(int r, int g, int b)
{
  rgb.on(r, g, b);
  delay(BLINK_DELAY);
  rgb.off();
  delay(BLINK_DELAY);
}

#endif
