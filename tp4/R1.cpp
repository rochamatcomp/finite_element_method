/**
 * André ALMEIDA ROCHA
 * 5MM30: Résolution des EDP par MF.
 * Explicit definition of the class R1 (point).
 */

#include <cmath>
#include "R1.hpp"

void R1::init()
{
  data = 0.0;
}

R1::R1()
{
  init();
}

R1::R1(const R1 &point)
{
  init();
  data = point[0];
}

R1::R1(double value1)
{
  init();
  data = value1;
}

R1& R1::operator= (const R1& point)
{
  if (this != &point)
  {
    data = point.data;
  }
  return *this;
}

std::ostream& operator<< (std::ostream& output, const R1& point)
{
  output << "(" << point[0] << ")";
  return output;
}

R1 R1::operator+ (const R1& point) const
{
  return R1(data + point[0]);
}

R1 R1::operator- (const R1& point) const
{
  return R1(data - point[0]);
}

R1 R1::operator* (double real) const
{
  return R1(data * real);
}

R1 operator* (double real, const R1& point)
{
  return R1(real * point[0]);
}

R1 R1::operator/ (double real) const
{
  return R1(data / real);
}

R1 operator/ (double real, const R1& point)
{
  return R1(real / point[0]);
}

double R1::operator, (const R1& point)
{
  return data * point[0];
}

R1 R1::operator-() const
{
  return R1(-data);
} 

const R1& R1::operator+() const
{
  return *this;
}

double& R1::operator[](int index)
{
  
  return (&data)[index];
}

const double& R1::operator[](int index) const
{
  return (&data)[index];
}

inline double determinant(const R1& point)
{
  
  return point[0];
}

R1 R1::perp() const
{
  return R1(-data);
}

inline R1 perp(const R1& point)
{
  return R1(-point[0]);
}
