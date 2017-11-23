/**
 * André ALMEIDA ROCHA
 * 5MM30: Résolution des EDP par MF.
 * TP3: Classes, operator overloading.
 * Exercises: 1.
 */
#include <iostream>
#include "matR2.h"

using namespace std;

int main(int argc, char* argv[])
{
  matR2 matrix1 = matR2();
  matR2 matrix2 = matR2(3, 4, 6, 8);
  R2 point1(3, 4);

  cout << matrix1 << endl;
  cout << matrix2 << endl;

  cout << "Elements: " << endl;
  cout << matrix2.get_element(0, 0) << endl;
  cout << matrix2.get_element(0, 1) << endl;
  cout << matrix2.get_element(1, 0) << endl;
  cout << matrix2.get_element(1, 1) << endl;
  
  cout << "Determinant: " << determinant(matrix2) << endl;
  cout << "Trace: " << trace(matrix2) << endl;

  cout << "Assignment: " << endl;
  matrix1 = matrix2;
  cout << matrix1 << endl;

  cout << "Sum: " << endl;
  cout << matrix1 + matrix2 << endl;
  
  cout << "Matrix multiplication: " << endl;
  cout << matrix1 * matrix2 << endl;

  cout << "Matrix and point multiplication: " << endl;
  cout << matrix1 * point1 << endl;

  cout << "Point and matrix multiplication: " << endl;
  cout <<  point1 * matrix1 << endl;

  cout << endl << "Subscript oveloading, matrix[row][col]" << endl;
  cout <<  matrix2(0, 0) << endl;
  cout <<  matrix2(1, 0) << endl;
  cout <<  matrix2 << endl;

  matrix2(0, 0) = 5;
  matrix2(1, 0) = 16;

  cout <<  matrix2(0, 1) << endl;
  cout <<  matrix2(1, 1) << endl;
  cout <<  matrix2 << endl;
  
  return 0;
}
