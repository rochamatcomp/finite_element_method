#include "EF1d-base.hpp"
#include <fstream>

Mesh1d::Mesh1d(const char * filename)
{
  std::ifstream  f(filename); 
  assert(f);
  
  int unused;
  int total = 2; // total of vertices in simplex.
  int I[total];
  double mes =0;
  
  f >> nv >> nt >> unused ;
  assert(f.good());
  
  t = new Simplex[nt];
  v = new Vertex[nv];
  assert( t && v); 
  
  for(int i=0;i<nv;++i)
  { 
    f >> v[i];
    assert(f.good());
  }

  for(int k=0;k<nt;++k)
  { 
    for(int i=0; i < total; ++i)
    {
      f >> I[i];
    }
    
    f >> unused;

    assert(f.good());
    t[k].build(v, I, 0);
    mes += t[k].mes;
  }
  
  std::cout<< " End read " << nv << " " << nt << " mes =" << mes << std::endl; 
}
