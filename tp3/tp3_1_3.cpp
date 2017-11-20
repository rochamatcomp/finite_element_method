/**
 * André ALMEIDA ROCHA
 * 5MM30: Résolution des EDP par MF.
 * TP2: Local copies and references, classes, STL.
 * Exercises: 2
 * Class definition
 */
#include <iostream>
#include "matR2.h"

using namespace std;

int main(int argc, char* argv[])
{
  matR2 matrix1 = matR2();
  matrix1.display();
  
  matR2 matrix2 = matR2(3, 4, 6, 8);  
  matrix2.display();

  cout << matrix2.get_element(1, 1) << endl;
  cout << matrix2.get_element(1, 2) << endl;
  cout << matrix2.get_element(2, 1) << endl;
  cout << matrix2.get_element(2, 2) << endl;

  cout << determinant(matrix2) << endl;
  cout << trace(matrix2) << endl;  
  
  return 0;
}
