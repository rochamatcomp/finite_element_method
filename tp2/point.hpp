/**
 * André ALMEIDA ROCHA
 * 5MM30: Résolution des EDP par MF.
 * TP2: Local copies and references, classes, STL.
 * Exercises: 2
 * Class definition
 */

class point
{
private:
  double x, y;
  
public:
  point();
  point(const point&);
  point(double a, double b);
  void display();
  void set_x(double);
  void set_y(double);
};
