/**
 * André ALMEIDA ROCHA
 * 5MM30: Résolution des EDP par MF.
 * TP2: Local copies and references, classes, STL.
 * Exercises: 1.4
 */

#include <iostream>
using namespace std;

void add1(int value)
{
  value = value + 1;
}

void add2(int& value)
{
  value = value + 2;
}

void add3(int* value)
{
  *value = *value + 2;
}

void show(int* data)
{
  cout << data[0] << "\t" << data[1] << "\t";
  cout << data[2] << "\t"<< data[3] << endl;
  cout << endl;
}


// 1.2
int main(int argc, char* argv[])
{
  int* p;
  p = new int[4];

  p[0] = 0;
  p[1] = 1;
  p[2] = 2;
  p[3] = 3;
  show(p);

  add1(p[2]);
  show(p);

  int*& s = p;
  add2(s[1]);
  show(p);

  int** t = &s;
  (*t)++;
  (**t)++;
  show(p);

  (*t)++;
  s = (*t) + 1;
  cout << p[0] << endl;
  cout << endl;

  p = s - 2;
  cout << s[0] << "\t" << s[1] << "\t";
  cout << s[2] << endl;
  cout << endl;

  s = s - 1;
  add3(*t + 3);
  show(p);

  return 0;
}
