/**
 * André ALMEIDA ROCHA
 * 5MM30: Résolution des EDP par MF.
 * TP4: FEM in 1-Dimension.
 * Exercises 1: creates the mesh file.
 */
#include <cstdlib>
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

void fill(ofstream& file, double total)
{
  int vertices = total + 1;
  int edges = total;
  int label = 0; // label of the element of the grid.
  int index = 0;
  int left = 0; // number of vertices of a edge, in the left side.
  int right = 0; // number of vertices of a edge, in the right side.
  int border0 = 0; // number of vertices of a edge (0, 1), in the 0 side.
  int border1 = 0; // number of vertices of a edge (0, 1), in the 1 side.
  double element = 0.0; // element of the grid (xi).
  
  // Writing header
  file << vertices << "\t" << edges << "\t" << 2;

  // Writing the elements
  for(index = 0; index < vertices; index++)
  {
    element = index / total;
    label = (element == 0 || element == 1) ? 1 : 0;
    file << element << "\t" << label;
  }

  // Writing the numbers of vertices of each edge.
  for(index = 0; index < edges; index++)
  {
    left = index;
    right = index + 1;
    file << left << "\t" << right << "\t" << 0;
  }

  file << border0 << "\t" << 0;
  file << border1 << "\t" << 0;
}

int main(int argc, char* argv[])
{
  int size = 0; // mesh size
  double total = 0.0;
  string filename = "mesh.msh";
  ofstream file;
  
  if(argc < 2)
  {
    // Help
    cout <<"Usage: "<< argv[0] <<" <mesh size> [<mesh filename>]" << endl;
  }

  size = atoi(argv[1]);
  
  if(argc == 3)
  {
    filename = argv[2] + ".msh";
  }
    
  if(size <= 0)
  {
    cout << "Impossible create the mesh with non positive size." << endl;
    exit(1);
  }

  // Total of the elements on the regular grid.
  total = 1 / (double)size;
  
  if(file.open (filename))
  {
    fill(file, total);
    file.close();
  }
  else
  {
    cout << "Impossible open the file: " << filename << "" << endl;
    exit(1);
  }

  return 0;
}
