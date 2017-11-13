/**
 * André ALMEIDA ROCHA
 * 5MM30: Résolution des EDP par MF.
 * TP2: Local copies and references, classes, STL.
 * Exercises: 3
 */

#include <iostream>
#include <vector>

using namespace std;

void display(vector <int> data)
{
  int total = data.size();
  for(int i = 0; i < total; i++)
  {
    cout << "\n" << data[i];
  }  
}

vector <int> sort(vector <int>& data)
{
  int total = data.size();

  int i, j , temp;
  for (i = 0; i < total-1; i++)  
  {
    for(int j = 0; j < total-i-1; j++)
      {
	if (data[j] > data[j+1])
	  {
	    temp = data[j];
	    data[j] = data[j+1];
	    data[j+1] = data[temp];
	  }
      }
  }
}

int main(int argc, char* argv[])
{
  vector <int> data;
  int typed = 0;
  
  cout << "Type 10 integers:"  << endl;
  for(int i = 0; i < 10; i++)
  {
    cin >> typed;
    data.push_back(typed);
  }

  display(data);
  sort(data);
  display(data);
  
  return 0;
}
