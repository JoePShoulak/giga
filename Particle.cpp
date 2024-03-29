#include "Particle.h"

#define GRAVITY 0, 10
#define MIN_DIAMETER 10
#define MAX_DIAMETER 80

Vector2D gravity(GRAVITY);

Particle::Particle(Arduino_H7_Video &gfx, int x, int y, int diameter, int color) : pos(x, y), diameter(diameter), color(color), gfx(gfx)
{
}

Particle::Particle()
{
}

void Particle::applyForce(Vector2D force)
{
  acc += force;
}

void Particle::update()
{
  this->applyForce(gravity / diameter);

  vel += acc;
  pos += vel;
  acc *= 0;

  if (pos.y > gfx.height())
    this->reset();

  gfx.fill(color);
  gfx.noStroke();
  gfx.circle(pos.x, pos.y, diameter);
}

void Particle::reset()
{
  vel *= 0;
  diameter = random(MIN_DIAMETER, MAX_DIAMETER);
  color = 0x0f0f0f * 16 * ((float)diameter / MAX_DIAMETER);
  pos.set(random(gfx.width()), -2 * diameter);
}

void Particle::print()
{
  Serial.print("Pos: ");
  Serial.print((int)pos.x);
  Serial.print(", ");
  Serial.print((int)pos.y);
  Serial.print("; Vel: ");
  Serial.print(vel.x);
  Serial.print(", ");
  Serial.print(vel.y);
  Serial.print("; Acc: ");
  Serial.print(acc.x);
  Serial.print(", ");
  Serial.println(acc.y);
}
