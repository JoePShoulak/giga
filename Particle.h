#ifndef __PARTICLE_H
#define __PARTICLE_H

#include "Vector2D.h"
#include <Arduino_H7_Video.h>

class Particle
{
public:
  Particle(Arduino_H7_Video &gfx, int x, int y, int diameter, int color);
  Particle();

  void begin(Arduino_H7_Video &gfx);
  void update();
  void reset();

  void applyForce(Vector2D force);
  bool onScreen();

  void draw();
  void print();

  Vector2D pos;
  Vector2D vel;
  Vector2D acc;

  int diameter;
  int color;

  Arduino_H7_Video gfx;

private:
  bool _beenOnScreen;
};

#endif
