/**
 * André ALMEIDA ROCHA
 * 5MM30: Résolution des EDP par MF.
 * TP3: Classes, operator overloading.
 * Exercises: 1 and 2.
 */
#include <iostream>
#include "R2.h"

using namespace std;

int main(int argc, char* argv[])
{
  R2 point1 = R2(3, 4);
  R2 point2 = R2(6, 8);
  R2 point3 = R2(3, 4);
  R2 point4;
  R2 point5(5, 0);
  R2 point6(0, 14);
  R2 point7(0, 1);
  
  double distance = distance_euclidean(point1, point2);
  bool same = comparation(point1, point3);
  bool other = comparation(point1, point2);
  
  cout  << "Distance between point1: " << point1 << " and point2: " << point2 << "is: " << distance << endl << endl;
  cout << boolalpha;
  cout << "point1: "<< point1 << " point3: " <<  point3  << ". The same coordinates: " << same << endl;
  cout << "point1: "<< point1 << " point2: " <<  point2 << ". The same coordinates: " << other << endl;

  cout << endl << "BEFORE Assignment: point2 and point4 value and address:" << endl;
  cout << &point2 << endl;
  cout << point2 << endl;
  cout << &point4 << endl;
  cout << point4 << endl;
  
  point4 = point2;

  cout << endl << "AFTER Assignment: point2 and point4 value and address:" << endl;
  cout << &point2 << endl;
  cout << point2 << endl;
  cout << &point4 << endl;
  cout << point4 << endl;
  
  cout << endl << "Addition oveloading" << endl;
  cout << point1 + point2 << endl;

  cout << endl << "Multiplication oveloading" << endl;
  cout << point1 * 2.5 << endl;
  cout << 3.0 * point2 << endl;

  cout << endl << "Scalar product (virgule oveloading)" << endl;
  cout << (point1,point2) << endl;
  cout << (point5,point6) << endl;
  cout << (point7,point7) << endl;

  cout << endl << "Subscript oveloading, point[index]" << endl;
  cout << point6[0] << endl;
  cout << point6[1] << endl;

  point6[0] = 15;
  point6[1] = 0;
  
  cout << point6[0] << endl;
  cout << point6[1] << endl;

  cout << point6 << endl;

  return 0;
}
