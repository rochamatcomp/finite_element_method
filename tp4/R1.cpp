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
  data = point.data;
}

R1::R1(double value1)
{
  init();
  data = value1;
}

void R1::set_x(double value1)
{
  data = value1;
}

double R1::get_x() const
{
  return data;
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
  output << "(" << point.get_x() << ")";
  return output;
}

R1 R1::operator+ (const R1& point) const
{
  R1 new_point(data + point.get_x());
  return new_point;
}

R1 R1::operator- (const R1& point) const
{
  R1 new_point(data - point.get_x());
  return new_point;
}

R1 R1::operator* (double real) const
{
  R1 new_point(data * real);
  return new_point;
}

R1 operator* (double real, const R1& point)
{
  R1 new_point(real * point.get_x());
  return new_point;
}

R1 R1::operator/ (double real) const
{
  R1 new_point(data / real);
  return new_point;
}

R1 operator/ (double real, const R1& point)
{
  R1 new_point(real / point.get_x());
  return new_point;
}

double R1::operator, (const R1& point)
{
  double result = data * point.get_x();
  return result;
}

double&  R1::operator[](int index)
{
  return (&data)[index];
}

const double& R1::operator[](int index) const
{
  return (&data)[index];
}
