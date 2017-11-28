#include "R1.hpp"
#include <cassert>

class Label
{
public:
  int lab; 

  int  OnGamma() const
  {
    return lab;
  }
  
  Label(int l = 0) : lab(l) {} 
};

class Vertex: public R1, public Label
{
public:
  Vertex() {}   
};

inline std::ostream& operator << (std::ostream& file, const  Vertex& point)
{
  return  file << point.data << ' ' << point.lab << ' ';
}

inline  std::istream& operator >>(std::istream& file,  Vertex& point)
{
  return file >> point.data >> point.lab;
}

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

    for(int index = 0; index < nbv; index++)
    {
      vertex[i] = initial + vertex_number[i] + offset;
    } 
    
    mesure = det(*vertex[0], *vertex[1]) * 0.5; 
    assert(mesure > 0) ;
  }
  
  void GradLambdaK(R1* G) const
  {
    double K2 = mesure * 2; 
    G[0] = R1(*vertex[1], *vertex[0]).perp() / K2;
    G[1] = R1(*vertex[0], *vertex[1]).perp() / K2;
  }
  
  Vertex& operator[](int index)
  {
    assert(index >= 0 && index < vertexes);
    return *(vertex[i]);
  }
  
  const Vertex& operator[](int index) const
  {
    assert(index >= 0 && index < vertexes);
    return *(vertex[i]);
  }
};  

class Mesh2d 
{
public:
  int vertexes = 0;
  int edges = 0; 
  Vertex* vertex; 
  Simplex* simplex;
  
  Mesh1d(const char *  filename); 
  
  // destuctor => careful with copie operator
  ~Mesh1d()
  {
    delete [] vertex;
    delete [] simplex;
  }  

  // no copy operator

  // chech index number
  int CheckVertexes(int index) const
  {
    assert( index >= 0 && index < vertexes);
    return index;
  }
 
  int CheckEdges(int index) const
  {
    assert( index >= 0 && index < edges);
    return index;
  } 

  int operator()(const Vertex& vertex) const
  {
    return CheckVertexes(&vertex - this->vertex);
  }

  int operator()(const  Simplex& simplex) const
  {
    return CheckEdges(&simplex - this->simplex);
  }
  
  int operator()(const Vertex* vertex) const
  {
    return CheckVertexes(vertex - this->vertex);
  }  // (1)
  
  int operator()(const  Simplex* simplex) const
  {
    return CheckEdges(simplex - this->simplex);
  }

  Simplex & operator[](int k)
  {
    return simplex[CheckEdges(k)]; 
  }

  const Simplex & operator[](int k) const
  {
    return simplex[CheckEdges(k)];
  }

  int operator()(int k, int i) const
  {
    return operator()(simplex[k].vertex[i]);
  }// call (1)

private:
  Mesh1d(const Mesh1d &);
  Mesh1d & operator=(const Mesh1d &);
};
