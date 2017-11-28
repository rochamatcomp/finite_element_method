/**
 * André ALMEIDA ROCHA
 * 5MM30: Résolution des EDP par MF.
 * Class R1 (point).
 */

#ifndef R1_HPP
#define R1_HPP

#include <iostream>

class R1
{
private:
  double data;
  void init();
  
public:
  static const int dimension = 1;
  R1();
  R1(const R1&);
  R1(double);
  void set_x(double);
  double get_x() const;
  R1& operator= (const R1&);
  R1 operator+ (const R1&) const;
  R1 operator- (const R1&) const;
  R1 operator* (double) const;
  R1 operator/ (double) const;
  double operator, (const R1&);
  double& operator[](int);
  const double& operator[](int) const;
  friend std::ostream& operator<< (std::ostream& output, const R1& point);
  friend R1 operator*(double, const R1&);
  friend R1 operator/(double, const R1&);
};

#endif
