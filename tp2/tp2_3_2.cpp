/**
 * André ALMEIDA ROCHA
 * 5MM30: Résolution des EDP par MF.
 * TP2: Local copies and references, classes, STL.
 * Exercises: 3
 */

#include <iostream>
#include <string>
#include <map>

using namespace std;

void display(map <string, string> data)
{ 
  map <string, string>::iterator element;

  cout << endl << "Phone book:" << endl;
  for(element = data.begin(); element != data.end(); element++)
  {
    cout << element->first << endl;
    cout << element->second << endl;
  }
  cout << endl;
}

int main(int argc, char* argv[])
{
  map <string, string> data;
  int i = 0;
  string name = "", phone_number = "";
  
  cout << "Enter a series of 3 pairs of name and phone_number:" << endl;
  for(i = 0; i < 3; i++)
  {
    cin >> name >> phone_number;
    data.insert(pair<string, string>(name, phone_number));
  }

  display(data);
  
  return 0;
}
