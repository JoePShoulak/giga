#include "Particle.h"

Particle::Particle(int x, int y, int diameter, int color) : pos(x, y), diameter(diameter), color(color)
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
  vel += acc;
  pos += vel;
  acc *= 0;
}

void Particle::update(void (*postUpdate)(Particle &))
{
  this->update();

  postUpdate(*this);
}

void Particle::update(void (*preUpdate)(Particle &), void (*postUpdate)(Particle &))
{
  preUpdate(*this);

  this->update(postUpdate);
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
