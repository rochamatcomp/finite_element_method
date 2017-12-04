#include "R1.hpp"
#include <cmath> 
#include <cassert>

class Label
{
public:
  int label; 

  int  OnGamma() const
  {
    return label;
  }
  
  Label(int lab = 0) : label(lab) {} 
};

class Vertex: public R1, public Label
{
public:
  Vertex() {}   
};

inline std::ostream& operator << (std::ostream& file, const  Vertex& point)
{
  return  file << point.data << ' ' << point.label << ' ';
}

inline  std::istream& operator >>(std::istream& file,  Vertex& point)
{
  return file >> point.data >> point.label;
}

/**
 * Generalization of the notion of a triangle or tetrahedron to arbitrary dimensions. 1-simplex is a line segment.
 */
class Simplex
{
public: 
  static const int vertexes = 2;
  Vertex* data[vertexes]; 
  double mesure = 0.0;

  Simplex()
  {
    data[0] = 0;
    data[1] = 0;
  }

  /**
   * Building the simplex.
   * @initial Initial vertex.
   * @param vertex_number Array of vertex number.
   * @offset Offset value to vertex data.
   */
  void build(Vertex* initial, int* vertex_number, int offset = 0)
  {

    for(int vertex = 0; vertex < vertexes; vertex++)
    {
      data[vertex] = initial + vertex_number[vertex] + offset;
    } 
    
    mesure = (*data[0] - *data[1]); 
    assert(mesure > 0);
  }
  
  void GradLambdaK(R1* G) const
  {
    double K2 = mesure * 2; 
    G[0] = R1(*data[0]).perp() / K2;
  }
  
  Vertex& operator[](int vertex)
  {
    assert(vertex >= 0 && vertex < vertexes);
    return *(data[vertex]);
  }
  
  const Vertex& operator[](int vertex) const
  {
    assert(vertex >= 0 && vertex < vertexes);
    return *(data[vertex]);
  }
};  

class Mesh1d 
{
public:
  int vertexes = 0;
  int edges = 0; 
  Vertex* set_vertex;
  Simplex* set_edge;
  
  Mesh1d(const char* filename); 
  
  // destuctor => careful with copie operator
  ~Mesh1d()
  {
    delete [] set_vertex;
    delete [] set_edge;
  }  

  // no copy operator

  // chech index number
  int CheckVertexes(int vertex) const
  {
    assert(vertex >= 0 && vertex < vertexes);
    return vertex;
  }
 
  int CheckEdges(int edge) const
  {
    assert(edge >= 0 && edge < edges);
    return edge;
  } 

  int operator()(const Vertex& set_vertex) const
  {
    return CheckVertexes(&set_vertex - this->set_vertex);
  }

  int operator()(const  Simplex& set_edge) const
  {
    return CheckEdges(&set_edge - this->set_edge);
  }
  
  int operator()(const Vertex* set_vertex) const
  {
    return CheckVertexes(set_vertex - this->set_vertex);
  }  // (1)
  
  int operator()(const  Simplex* set_edge) const
  {
    return CheckEdges(set_edge - this->set_edge);
  }

  Simplex& operator[](int edge)
  {
    return set_edge[CheckEdges(edge)]; 
  }

  const Simplex& operator[](int edge) const
  {
    return set_edge[CheckEdges(edge)];
  }

  int operator()(int edge, int vertex) const
  {
    return operator()(set_edge[edge].set_vertex[vertex]);
  }// call (1)

private:
  Mesh1d(const Mesh1d&);
  Mesh1d& operator=(const Mesh1d&);
};
