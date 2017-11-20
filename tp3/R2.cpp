/**
 * André ALMEIDA ROCHA
 * 5MM30: Résolution des EDP par MF.
 * Explicit definition of the class R2 (point).
 */

#include "R2.h"

R2::R2()
{
  x = 0;
  y = 0;
}

R2::R2(const R2& p)
{
  x = p.x;
  y = p.y;
}

R2::R2(double a, double b)
{
  x = a;
  y = b;
}
  
void R2::set_x(double a)
{
  x = a;
}

void R2::set_y(double b)
{
  y = b;
}

double R2::get_x()
{
  return x;
}

double R2::get_y()
{
  return y;
}
