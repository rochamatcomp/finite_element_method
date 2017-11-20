/**
 * André ALMEIDA ROCHA
 * 5MM30: Résolution des EDP par MF.
 * Class point (R2).
 */

#ifndef point_h
#define point_h

class point
{
private:
  double x, y;
  
public:
  point();
  point(const point&);
  point(double, double);
  void display();
  void set_x(double);
  void set_y(double);
};

#endif
