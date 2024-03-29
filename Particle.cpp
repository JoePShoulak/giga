#include "Particle.h"

Particle::Particle(int x, int y, int diameter, int color) : pos(x, y), diameter(diameter), color(color)
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
