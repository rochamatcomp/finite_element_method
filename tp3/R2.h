/**
 * André ALMEIDA ROCHA
 * 5MM30: Résolution des EDP par MF.
 * Class R2 (point).
 */

#ifndef R2_h
#define R2_h

class R2
{
private:
  double x, y;
  
public:
  R2();
  R2(const R2&);
  R2(double, double);
  void display();
  void set_x(double);
  void set_y(double);
  double get_x();
  double get_y();
};

double distance_euclidean(R2 point1, R2 point2);
double comparation(R2 point1, R2 point2);

#endif
