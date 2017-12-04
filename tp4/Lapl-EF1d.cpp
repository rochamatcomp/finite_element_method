#include <cassert>
#include "EF1d-base.hpp"
#include <fstream>
#include <iostream>
#include "GC.h"

#ifndef PI
#define PI 3.141592
#endif

using namespace std;
double tgv = 1e4;

struct MatLap {
public:
  Mesh1d& Th;
  double alpha, beta;
  MatLap(Mesh1d& Thh, double a, double b) : Th(Thh), alpha(a), beta(b){}
  void MatMul(double *x, double *ax);
};

void MatLap::MatMul(double *x, double *ax)
{
  int d = 1;
  int total = d+1; 
  double coefm = alpha/(d+1)/(d+2) ;
  int n = Th.nv;
  double Ak[total][total];
  R1 Gw[total];
    
  for(int i = 0; i < n; ++i)
  {
    ax[i] = 0.;
  }

  for (int k = 0; k < Th.nt; ++k)
  {
    const Simplex& K = Th[k];
    int iK[total] = {Th(k,0), Th(k,1)};
	
    // calcul de la matrice Ak
    double areak = K.mes;
    double betak = beta * areak;
    double coefmk = coefm * areak;
    K.GradLambdaK(Gw);
	
    for(int ip = 0; ip < total; ++ip)
    {
      for(int jp = 0; jp < total; ++jp)
      {
	Ak[ip][jp] = coefmk * (1 + (ip==jp)) + (Gw[ip], Gw[jp]) * betak;
      }
    }
	
    for(int ip = 0; ip < total; ++ip)
    {
      for(int jp = 0; jp < total; ++jp)
      {
	int i = iK[ip]; // numero de sommet ip de triangle k
	int j = iK[jp]; // numero de sommet ip de triangle k
	ax[i] += Ak[ip][jp] * x[j];
      }
    }
  }
  
  for(int i = 0; i< n; ++i)
  {
    if(Th.v[i].OnGamma())
    {
      ax[i] = tgv* x[i];
    }
  }
}

double* PMatMulLap(MatVirt* A, double* x, double* ax)
{
    MatLap* ML = static_cast<MatLap*>(A->data);
    ML->MatMul(x, ax);
    return ax;
}

double f(R1 P)  { return sin(PI * P.x);};
double g(R1 P)  { return 0;};

int main(int argc, const char **argv)
{
    assert(argc > 1);
    Mesh1d Th(argv[1]);
 
    int n = Th.nv;
    MatVirt Id = BuildMatId(n);
    MatVirt A = BuildMatVirt(n, n, new MatLap(Th, 0, 1), PMatMulLap);
    MatVirt M = BuildMatVirt(n, n, new MatLap(Th, 1, 0), PMatMulLap);
    double *u = new double[n];
    double *fh = new double[n];
    double *b = new double[n];
    
    for(int i = 0; i < Th.nv; ++i)
    {
        fh[i] = f(Th.v[i]);
    }
    
    ProduitMatVec(&M, fh, b);
    for(int i = 0; i < Th.nv; ++i)
    {
        cout << i << " " << b[i];
        u[i] = g(Th.v[i]);
        if( Th.v[i].OnGamma())
	{
	  b[i] = tgv * u[i];
	}
        cout << " ::: " << b[i] << " " << Th.v[i] << endl;
    }
    
    int retgc = GradientConjugue(&A, &Id, b, u, n, 1e-8, 10);
    assert(retgc == 1);
    
    {
        ofstream fgp("toto.gp");
        for (int k = 0; k < Th.nt; ++k)
        {
            fgp << Th[k][0] << " " << u[Th(k,0)] <<  endl;
            fgp << Th[k][1] << " " << u[Th(k,1)] <<  "\n\n\n";
        }
    }
}
