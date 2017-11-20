/**
 * André ALMEIDA ROCHA
 * 5MM30: Résolution des EDP par MF.
 * Explicit definition of the class matR2 (matrix 2x2).
 */

#include <iostream>
#include <vector>
#include "matR2.h"

matR2::matR2()
{
  a11 = 0;
  a21 = 0;
  a12 = 0;
  a22 = 0;
}

matR2::matR2(const matR2& matrix)
{
  a11 = matrix.a11;
  a21 = matrix.a21;
  a12 = matrix.a12;
  a22 = matrix.a22;
}

/**
 * Matrix 2x2 constructor by columns.
 */
matR2::matR2(double value1, double value2,
	     double value3, double value4)
{
  a11 = value1;
  a21 = value2;
  a12 = value3;
  a22 = value4;
}
  
void matR2::display()
{
  std::cout << "[ " ;
  std::cout << a11;
  std::cout << "  " ;
  std::cout << a12 << std::endl;
  std::cout << "  " ;
  std::cout << a21;
  std::cout << "  " ;
  std::cout << a22;
  std::cout << " ]" << std::endl;
}

double matR2::get_element(double row, double col){
  if((row < 1) || (row > 2)){
    std::cout << "Row index out of range [1, 2]: " << row << std::endl;
    exit(1);
  }

  if((col < 1) || (col > 2)){
    std::cout << "Column index out of range [1, 2]: " << col << std::endl;
    exit(1);
  }

  if(row == 1){
    if(col == 1){
      return a11;
    }
    else{
      return a12;
    }
  }
  else{
    if(col == 1){
      return a21;
    }
    else{
      return a22;
    }
  }
}

double determinant(matR2 matrix){
  double a11, a12, a21, a22;

  a11 = matrix.get_element(1, 1);
  a12 = matrix.get_element(1, 2);
  a21 = matrix.get_element(2, 1);
  a22 = matrix.get_element(2, 2);

  return a11 * a22 - a12 * a21;
}

double trace(matR2 matrix){
  double a11, a22;

  a11 = matrix.get_element(1, 1);
  a22 = matrix.get_element(2, 2);

  return a11 + a22;
}
