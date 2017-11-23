/**
 * André ALMEIDA ROCHA
 * 5MM30: Résolution des EDP par MF.
 * Class matR2 (matrix 2x2).
 */

#ifndef matR2_h
#define matR2_h

#include <vector>
#include "R2.h"

class matR2
{
private:
   std::vector<std::vector<double>> data;
   void init();
  
public:
  matR2();
  matR2(const matR2&);
  matR2(double, double, double, double);
  double get_element(int, int) const;
  matR2& operator= (const matR2&);
  matR2 operator+ (const matR2&);
  matR2 operator* (const matR2&);
  R2 operator* (const R2&);
  double& operator() (int, int);
  
  
  friend std::ostream& operator<< (std::ostream& output, const matR2& point);
};


R2 operator*(const R2&, const matR2&);

double determinant(matR2);
double trace(matR2 matrix);

#endif
