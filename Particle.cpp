#include "Particle.h"

#define GRAVITY 0, 10
#define MIN_DIAMETER 10
#define MAX_DIAMETER 80

Vector2D gravity(GRAVITY);

Particle::Particle(Arduino_H7_Video &gfx, int x, int y, int diameter, int color) : pos(x, y), diameter(diameter), color(color), gfx(gfx)
{
}

Particle::Particle() // TODO: Ask Zach for help
{
}

void Particle::begin(Arduino_H7_Video &gfx)
{
  this->gfx = gfx;
  this->reset();
}

void Particle::update()
{
  this->applyForce(gravity / diameter);

  vel += acc;
  pos += vel;
  acc *= 0;

  if (this->onScreen())
  {
    _beenOnScreen = true;
    this->draw();
    return;
  }

  if (_beenOnScreen)
    this->reset();
}

void Particle::reset()
{
  _beenOnScreen = false;

  vel *= 0;
  diameter = random(MIN_DIAMETER, MAX_DIAMETER);
  color = 0x0f0f0f * 16 * ((float)diameter / MAX_DIAMETER);
  pos.set(random(gfx.width()), -2 * diameter);
}

void Particle::applyForce(Vector2D force)
{
  acc += force;
}

bool Particle::onScreen()
{
  return pos.x < gfx.width() + diameter / 2 &&
         pos.y < gfx.height() + diameter / 2 &&
         pos.x > -diameter / 2 &&
         pos.y > -diameter / 2;
}

void Particle::draw()
{
  gfx.fill(color);
  gfx.circle(pos.x, pos.y, diameter);
}
