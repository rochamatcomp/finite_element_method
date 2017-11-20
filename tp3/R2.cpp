/**
 * André ALMEIDA ROCHA
 * 5MM30: Résolution des EDP par MF.
 * Explicit definition of the class R2 (point).
 */

#include <cmath>
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

/**
 * Euclidean distance between two elements of R2.
 */
double distance_euclidean(R2 point1, R2 point2)
{
  double delta_x = point1.get_x() - point2.get_x();
  double delta_y = point1.get_y() - point2.get_y();

  return sqrt(delta_x*delta_x + delta_y*delta_y);
}

/**
 * Comparation between two elements of R2.
 */
double comparation(R2 point1, R2 point2)
{
  double equal_x = (point1.get_x() == point2.get_x());
  double equal_y = (point1.get_y() == point2.get_y());

  return equal_x && equal_y;
}
