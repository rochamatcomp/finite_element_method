/**
 * André ALMEIDA ROCHA
 * 5MM30: Résolution des EDP par MF.
 * Explicit definition of the class point (R2).
 */

#include <iostream>
#include "point.h"

using namespace std;

point::point()
{
  x = 0;
  y = 0;
}

point::point(const point& p)
{
  x = p.x;
  y = p.y;
}

point::point(double a, double b)
{
  x = a;
  y = b;
}
  
void point::display()
{
  cout << "x: " << x << endl;
  cout << "y: " << y << endl;
}

void point::set_x(double a)
{
  x = a;
}

void point::set_y(double b)
{
  y = b;
}
