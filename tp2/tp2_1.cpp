/**
 * André ALMEIDA ROCHA
 * 5MM30: Résolution des EDP par MF.
 * TP2: Local copies and references, classes, STL.
 * Exercises: 1.1, 1.2, 1.3
 */

#include <iostream>
using namespace std;

// 1.1 and 1.3
void add2(int& value)
{
  value = value + 2;
}

// 1.2
int main(int argc, char *argv[])
{
  int z = 3;
  cout << z << endl;

  add2(z);
  cout << z << endl;

  return 0;
}
