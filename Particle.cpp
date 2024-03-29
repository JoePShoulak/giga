#include "Particle.h"

#define GRAVITY 0, 10
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

  gfx.fill(color);
  gfx.noStroke();
  gfx.circle(pos.x, pos.y, diameter);
}

void Particle::update(void (*postUpdate)(Particle &))
{
  this->update();

  postUpdate(*this);
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
