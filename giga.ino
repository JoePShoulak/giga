#include <ArduinoGraphics.h>
#include <Arduino_H7_Video.h>
#include "led.h"
#include "Particle.h"

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 480
#define BAUDRATE 9600
#define FRAME_DELAY 40

Arduino_H7_Video display(SCREEN_WIDTH, SCREEN_HEIGHT, GigaDisplayShield);

Particle ball(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 10, 0xff0000);
Vector2D gravity(0, 1);

void printParticle(Particle p)
{
  Serial.print("Pos: ");
  Serial.print((int)p.pos.x);
  Serial.print(", ");
  Serial.print((int)p.pos.y);
  Serial.print("; Vel: ");
  Serial.print(p.vel.x);
  Serial.print(", ");
  Serial.print(p.vel.y);
  Serial.print("; Acc: ");
  Serial.print(p.acc.x);
  Serial.print(", ");
  Serial.println(p.acc.y);
}

void pPreUpdate(Particle &p)
{
  p.applyForce(gravity);
}

void pPostUpdate(Particle &p)
{
  // check bounds
  if (p.pos.y > SCREEN_HEIGHT)
  {
    p.pos.set(random(SCREEN_WIDTH), 0);
    p.vel *= 0;
    p.color = random(0xffffff);
    p.diameter = random(10, 100);
  }

  // draw
  display.fill(p.color);
  display.noStroke();
  display.circle(p.pos.x, p.pos.y, p.diameter);
}

void setup()
{
  rgb.begin();
  rgb.off();
  rgb.on(GREEN);

  while (display.begin() == 1)
    errorBlink(DISPLAY_ERROR);

  Serial.begin(BAUDRATE);
  while (!Serial)
    ;

  display.beginDraw();
  display.clear();
  display.endDraw();

  printParticle(ball);
}

void loop()
{
  display.beginDraw();
  display.clear();

  ball.update(pPreUpdate, pPostUpdate);

  display.endDraw();

  delay(FRAME_DELAY);
}
