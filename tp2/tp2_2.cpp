/**
 * André ALMEIDA ROCHA
 * 5MM30: Résolution des EDP par MF.
 * TP2: Local copies and references, classes, STL.
 * Exercises: 2
 */

#include <iostream>
#include "point.h"

using namespace std;

int main(int argc, char* argv[])
{
  point p;
  p.display();

  point p2 = point(p);
  p2.display();

  point p3 = point(3, 2);
  p3.display();

  point p4 = point(p);
  p4.display();
  
  p.set_x(6);
  p.set_y(8);
  p.display();

  p4.display();
  
  return 0;
}
