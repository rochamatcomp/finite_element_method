#include "EF1d-base.hpp"
#include <fstream>

Mesh1d::Mesh1d(const char* filename)
{
  std::ifstream file(filename); 
  assert(file);
  
  int unused;
  int vertex_number[2];
  int vertex = 0;
  int edge = 0;
  double mesure = 0;
  
  file >> vertexes >> edges >> unused;
  assert(file.good());
  
  set_edge = new Simplex[edges];
  set_vertex = new Vertex[vertexes];
  assert(set_edge && set_vertex);
  
  for(vertex = 0; vertex < vertexes; vertex++)
  { 
    file >> set_vertex[vertex]; 
    assert(file.good());
  }

  for(edge = 0; edge < edges; edge++)
  { 
      for(vertex = 0; vertex < 2; vertex++)
      {
	file >> vertex_number[vertex];
      }
      
      assert(file.good());
      set_edge[edge].build(set_vertex, vertex_number, -1);
      mesure += set_edge[edge].mesure; 
  }

  std::cout<< " End read " << vertexes << " " << edges << " mesure =" << mesure << std::endl; 
}
