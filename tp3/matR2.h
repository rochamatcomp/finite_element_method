/**
 * André ALMEIDA ROCHA
 * 5MM30: Résolution des EDP par MF.
 * Class matR2 (matrix 2x2).
 */

#ifndef matR2_h
#define matR2_h

class matR2
{
private:
  double a11, a12, a21, a22;
  
public:
  matR2();
  matR2(const matR2&);
  matR2(double, double, double, double);
  void display();
  double get_element(double, double);
};

double determinant(matR2);
double trace(matR2 matrix);

#endif
