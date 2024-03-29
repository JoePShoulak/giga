#ifndef __PARTICLE_H
#define __PARTICLE_H

#include "Vector2D.h"

class Particle
{
public:
  Particle(int x, int y, int diameter, int color);

  void applyForce(Vector2D force);
  void update();
  void update(void (*postUpdate)(Particle &));
  void update(void (*preUpdate)(Particle &), void (*postUpdate)(Particle &));

  Vector2D pos;
  Vector2D vel;
  Vector2D acc;

  int diameter;
  int color;
};

#endif
