#include <Arduino.h>

#define BAUDRATE 9600

void setup()
{
  Serial.begin(BAUDRATE);
  while (!Serial)
    ;
  Serial.println("Ready!");
}

void loop()
{
}
