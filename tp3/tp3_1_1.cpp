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

int main(int argc, char* argv[])
{
  R2 point1 = R2(3, 4);
  R2 point2 = R2(6, 8);
  R2 point3 = R2(3, 4);
  
  double distance = distance_euclidean(point1, point2);
  bool same = comparation(point1, point3);
  bool other = comparation(point1, point2);
  
  cout << distance << endl;
  cout << same << endl;
  cout << other << endl;
  
  return 0;
}
