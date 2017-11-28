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

/**
 * Filling the mesh file with the uniform grid.
 * @param file Stream of the file to writing.
 * @param total Number of grid points. 
 * @return  
 */
void fill(ofstream& file, double total)
{
  int vertices = total + 1; // quantity of the vertices.
  int edges = total; // quantity of the edges.
  int label = 0; // label of the grid element.
  int index = 0;
  int left = 0; // number of edge vertice, in the left side.
  int right = 0; // number of edge vertice, in the right side.
  int start = 0; // number of start vertice.
  int end = total ; // number end vertice.
  double element = 0.0; // element of the grid (xi).
 
  // Writing header
  file << vertices << "\t" << edges << "\t" << 2 << endl;

  // Writing the elements
  for(index = 0; index < vertices; index++)
  {
    element = index / total;

    // Label 1 to limits elements and label 0 to inside elements.
    label = (element == 0 || element == 1) ? 1 : 0;
    
    file << element << "\t" << label << endl;
  }

  // Writing the numbers of vertices of each edge.
  for(index = 0; index < edges; index++)
  {
    left = index;
    right = index + 1;
    file << left << "\t" << right << "\t" << 0 << endl;
  }

  // Writing the number of the limits vertices.
  file << start << "\t" << 0 << endl;
  file << end << "\t" << 0;
}

int main(int argc, char* argv[])
{
  double total = 0.0; // Number of grid points
  string filename = "mesh.msh";
  ofstream file;
  
  if(argc < 2)
  {
    // Help
    cout <<"Usage: "<< argv[0] <<" <number of grid points> [<mesh filename>]" << endl;
    exit(0);
  }
  
  total = atof(argv[1]);
    
  if(total <= 0.0)
  {
    cout << "Impossible create the mesh with non positive size." << endl;
    exit(1);
  }

  if(argc == 3)
  {
    filename = string(argv[2]) + ".msh";
  }
  
  file.open(filename);
  if(file.is_open())
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
