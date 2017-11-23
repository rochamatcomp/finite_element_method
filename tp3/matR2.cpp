/**
 * André ALMEIDA ROCHA
 * 5MM30: Résolution des EDP par MF.
 * Explicit definition of the class matR2 (matrix 2x2).
 */

#include <iostream>
#include "matR2.h"

void matR2::init(){
  data = std::vector<std::vector<double>> (2, std::vector<double> (2, 0.0));
}

matR2::matR2(){
  init();
}

matR2::matR2(const matR2& matrix){
  init();
  data[0][0] = matrix.data[0][0];
  data[1][0] = matrix.data[1][0];
  data[0][1] = matrix.data[0][1];
  data[1][1] = matrix.data[1][1];
}

/**
 * Matrix 2x2 constructor by columns.
 */
matR2::matR2(double value1, double value2,
	     double value3, double value4){
  init();
  data[0][0] = value1;
  data[1][0] = value2;
  data[0][1] = value3;
  data[1][1] = value4;
}

double matR2::get_element(int row, int col) const{
  if((row < 0) || (row > 1)){
    std::cout << "Row index out of range [0, 1]: " << row << std::endl;
    exit(1);
  }

  if((col < 0) || (col > 1)){
    std::cout << "Column index out of range [0, 1]: " << col << std::endl;
    exit(1);
  }

  return data[row][col];
}

matR2& matR2::operator= (const matR2& matrix){
  if (this != &matrix){
    data[0][0] = matrix.data[0][0];
    data[1][0] = matrix.data[1][0];
    data[0][1] = matrix.data[0][1];
    data[1][1] = matrix.data[1][1];
  }
  
  return *this;
}

std::ostream& operator<< (std::ostream& output, const matR2& matrix){
  output << "[ " ;
  output << matrix.data[0][0];
  output << "  " ;
  output << matrix.data[0][1] << std::endl;
  output << "  " ;
  output << matrix.data[1][0];
  output << "  " ;
  output << matrix.data[1][1];
  output << " ]" << std::endl;

  return output;
}

matR2 matR2::operator+ (const matR2& matrix){
  matR2 new_matrix(data[0][0] + matrix.data[0][0],
		   data[1][0] + matrix.data[1][0],
		   data[0][1] + matrix.data[0][1],
		   data[1][1] + matrix.data[1][1]);
  return new_matrix;
}

matR2 matR2::operator* (const matR2& matrix){
  matR2 new_matrix(
		   data[0][0] * matrix.data[0][0] + data[0][1] * matrix.data[1][0],
		   data[1][0] * matrix.data[0][0] + data[1][1] * matrix.data[1][0],
		   data[0][0] * matrix.data[0][1] + data[0][1] * matrix.data[1][1],
		   data[1][0] * matrix.data[0][1] + data[1][1] * matrix.data[1][1]);
  return new_matrix;
}

R2 matR2::operator* (const R2& point){
  R2 new_point(data[0][0] * point.get_x() + data[0][1] * point.get_y(),
	       data[1][0] * point.get_x() + data[1][1] * point.get_y());
  
  return new_point;
}

R2 operator* (const R2& point, const matR2& matrix){
  R2 new_point(point.get_x() * matrix.get_element(0, 0) + point.get_y() * matrix.get_element(1, 0),
	       point.get_x() * matrix.get_element(0, 1) + point.get_y() * matrix.get_element(1, 1));
  return new_point;
}

double& matR2::operator() (int row, int col){
  return data[row][col];
}

double determinant(matR2 matrix){
  double a11, a12, a21, a22;

  a11 = matrix.get_element(0, 0);
  a12 = matrix.get_element(0, 1);
  a21 = matrix.get_element(1, 0);
  a22 = matrix.get_element(1, 1);

  return a11 * a22 - a12 * a21;
}

double trace(matR2 matrix){
  double a11, a22;

  a11 = matrix.get_element(0, 0);
  a22 = matrix.get_element(1, 1);

  return a11 + a22;
}
