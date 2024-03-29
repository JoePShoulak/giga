#ifndef __VECTOR2D_H
#define __VECTOR2D_H

#include <Arduino.h>

class Vector2D
{
public:
  Vector2D(double x, double y);

  double x;
  double y;

  double magSq();
  double mag();

  Vector2D &add(double a, double b);
  Vector2D &sub(double a, double b);
  Vector2D &mult(double scalar);
  Vector2D &div(double scalar);

  Vector2D &set(double a);
  Vector2D &set(double a, double b);
  Vector2D &zero();

  Vector2D &add(const Vector2D &vec);
  Vector2D &sub(const Vector2D &vec);

  Vector2D operator+(const Vector2D &vec);
  Vector2D operator-(const Vector2D &vec);
  Vector2D operator*(double scalar);
  Vector2D operator/(double scalar);

  Vector2D &operator+=(const Vector2D &vec);
  Vector2D &operator-=(const Vector2D &vec);
  Vector2D &operator*=(double scalar);
  Vector2D &operator/=(double scalar);

  Vector2D normalized();
  Vector2D &normalize();
};

#endif
