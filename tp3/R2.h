/**
 * André ALMEIDA ROCHA
 * 5MM30: Résolution des EDP par MF.
 * Class R2 (point).
 */

#ifndef R2_h
#define R2_h

#include <iostream>
#include <vector>

class R2
{
private:
  std::vector<double> data;
  void init();
  
public:
  R2();
  R2(const R2&);
  R2(double, double);
  void display();
  void set_x(double);
  void set_y(double);
  double get_x() const;
  double get_y() const;
  R2& operator= (const R2&);
  R2 operator+ (const R2&);
  R2 operator* (double);
  double operator, (const R2&);
  double& operator[] (int);
  friend std::ostream& operator<< (std::ostream& output, const R2& point);
};

R2 operator*(double, const R2&);

double distance_euclidean(R2 point1, R2 point2);
bool comparation(R2 point1, R2 point2);

#endif
