/**
 * André ALMEIDA ROCHA
 * 5MM30: Résolution des EDP par MF.
 * Explicit definition of the class R2 (point).
 */

#include <cmath>
#include "R2.h"

void R2::init(){
  data = std::vector<double>(2, 0.0);
}

R2::R2(){
  init();
}

R2::R2(const R2 &point){
  init();
  data[0] = point.data[0];
  data[1] = point.data[1];
}

R2::R2(double value1, double value2){
  init();
  data[0] = value1;
  data[1] = value2;
}

void R2::set_x(double value1){
  data[0] = value1;
}

void R2::set_y(double value2){
  data[1] = value2;
}

double R2::get_x() const{
  return data[0];
}

double R2::get_y() const{
  return data[1];
}

R2& R2::operator= (const R2& point){
  if (this != &point){
    data[0] = point.data[0];
    data[1] = point.data[1];
  }
  
  return *this;
}

std::ostream& operator<< (std::ostream& output, const R2& point){
  output << "(" << point.get_x() << ", " << point.get_y() << ")";

  return output;
}

R2 R2::operator+ (const R2& point){
  R2 new_point(data[0] + point.get_x(), data[1] + point.get_y());
  return new_point;
}

R2 R2::operator* (double real){
  R2 new_point(data[0] * real, data[1] * real);
  return new_point;
}

R2 operator* (double real, const R2& point){
  R2 new_point(real * point.get_x(), real * point.get_y());
  return new_point;
}

double R2::operator, (const R2& point){
  double result = data[0] * point.get_x() + data[1] * point.get_y();
  return result;
}

double& R2::operator[] (int index){
  return data[index];
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
bool comparation(R2 point1, R2 point2)
{
  bool equals_x = (point1.get_x() == point2.get_x());
  bool equals_y = (point1.get_y() == point2.get_y());

  return equals_x && equals_y;
}
