#include "R1.hpp"
#include <cassert>

class Label {
public:
  int lab; 
  int  OnGamma() const { return lab;}
  Label(int l=0) : lab(l) {} 
};

class Vertex :public R1, public  Label
{
 public:
  Vertex() {}   
};

inline std::ostream& operator <<(std::ostream& f, const  Vertex & P )
{ return  f << P.x << ' ' << P.lab << ' ' ;}
inline  std::istream& operator >>(std::istream& f,  Vertex & P)
{ return f >>  P.x >> P.lab ;  }

class Simplex {
private:
  double calculate_mesure()
  {
    return det(*v[0], *v[1]);
  }
  
public: 
  static const int nbv = 2; 
  Vertex * v[nbv]; 
  double mes;
  Simplex(){ (v[0]=(v[1]=0));}

  // I array of vertex number
  void build(Vertex *v0, int * I, int offset=0)
  {
    for(int i=0; i < nbv; ++i)
    {
      v[i] =  v0 + I[i] + offset;
    }
    
    mes = calculate_mesure();
    //std::cout << *v[0] << ", " << *v[1] << ": " << mes << std::endl;
    assert(mes > 0) ;
  }
  
  void GradLambdaK(R1 *G) const
  {
    double K = mes; 
    G[0] = R1(*v[0],*v[1])/K;
  }
  
  Vertex & operator[](int i)
  {
    assert(i>=0 && i < nbv);
    return *(v[i]);
  }
  
  const Vertex & operator[](int i) const
  {
    assert(i>=0 && i < nbv);
    return *(v[i]);
  }

};  

class Mesh1d 
{
public:
  int nv,nt; 
  Vertex * v; 
  Simplex *t;
  Mesh1d(const char *  filename); 
  ~Mesh1d() { delete [] v; delete [] t; }
  // destuctor => careful with copie operator  
  // no copy operator
  // chech index number
  int CheckV(int i) const { assert( i>=0 && i < nv); return i; } 
  int CheckT(int i) const { assert( i>=0 && i < nt); return i; } 
  int operator()(const Vertex & vv) const { return CheckV(&vv-v);}
  int operator()(const  Simplex & tt) const  { return CheckT(&tt-t);}
  int operator()(const Vertex * vv)const  { return CheckV(vv-v);}  // (1)
  int operator()(const  Simplex * tt) const { return CheckT(tt-t);}
  Simplex & operator[](int k) { return t[CheckT(k)]; }
  const Simplex & operator[](int k) const { return t[CheckT(k)]; }
  int  operator()(int k,int i) const { return  operator()(t[k].v[i]); }// call (1)

private:
  Mesh1d(const Mesh1d &);
  Mesh1d & operator=(const Mesh1d &); 
};
