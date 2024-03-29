#include "Vector2D.h"

Vector2D::Vector2D(double x, double y) : x(x), y(y)
{
}

double Vector2D::magSq()
{
  return pow(x, 2) + pow(y, 2);
}

double Vector2D::mag()
{
  return pow(this->magSq(), 0.5);
}

Vector2D &Vector2D::add(double a, double b)
{
  x += a;
  y += b;
  return *this;
}

Vector2D &Vector2D::sub(double a, double b)
{
  x -= a;
  y -= b;
  return *this;
}

Vector2D &Vector2D::mult(double scalar)
{
  x *= scalar;
  y *= scalar;
  return *this;
}

Vector2D &Vector2D::div(double scalar)
{
  x /= scalar;
  y /= scalar;
  return *this;
}

Vector2D &Vector2D::set(double a, double b)
{
  x = a;
  y = b;
  return *this;
}

Vector2D &Vector2D::set(double a)
{
  this->set(a, a);
  return *this;
}

Vector2D &Vector2D::zero()
{
  this->set(0);
  return *this;
}

Vector2D &Vector2D::add(const Vector2D &vec)
{
  this->add(vec.x, vec.y);
  return *this;
}

Vector2D &Vector2D::sub(const Vector2D &vec)
{
  this->sub(vec.x, vec.y);
  return *this;
}

Vector2D Vector2D::operator+(const Vector2D &vec)
{
  return Vector2D(x + vec.x, y + vec.y);
}

Vector2D Vector2D::operator-(const Vector2D &vec)
{
  return Vector2D(x - vec.x, y - vec.y);
}

Vector2D Vector2D::operator*(double scalar)
{
  return Vector2D(x * scalar, y * scalar);
}

Vector2D Vector2D::operator/(double scalar)
{
  return Vector2D(x / scalar, y / scalar);
}

Vector2D &Vector2D::operator+=(const Vector2D &vec)
{
  return this->add(vec);
}

Vector2D &Vector2D::operator-=(const Vector2D &vec)
{
  return this->sub(vec);
}

Vector2D &Vector2D::operator*=(double scalar)
{
  return this->mult(scalar);
}

Vector2D &Vector2D::operator/=(double scalar)
{
  return this->div(scalar);
}

Vector2D Vector2D::normalized()
{
  double m = this->mag();

  return Vector2D(x / m, y / m);
}

Vector2D &Vector2D::normalize()
{
  this->div(this->mag());

  return *this;
}
