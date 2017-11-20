/**
 * André ALMEIDA ROCHA
 * 5MM30: Résolution des EDP par MF.
 * TP2: Local copies and references, classes, STL.
 * Exercises: 2
 * Class definition
 */
#include <iostream>
#include <cmath>
#include "R2.h"

using namespace std;

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
 * 
 */
double comparation(R2 point1, R2 point2)
{
  double equal_x = (point1.get_x() == point2.get_x());
  double equal_y = (point1.get_y() == point2.get_y());

  return equal_x && equal_y;
}

int main(int argc, char* argv[])
{
  R2 point1 = R2(3, 4);
  R2 point2 = R2(6, 8);
  R2 point3 = R2(3, 4);
  
  double distance = distance_euclidean(point1, point2);
  bool same = compatation(point1, point3);
  
  cout << distance << endl;
  cout << same << endl;
  return 0;
}
