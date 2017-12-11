/*
   GradientConjugue :
   correction: F. Hecht 17 oct 2016
       - GradienConjugue -> GradientConjugue
       - fuite de memoire :  => un seul return
       - Pb initialisation tableau G et CG si produit matrice vecteur incomplet
         => initialisation avec NaN pour voir l'erreur via un assert ...
 */
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "GC.h"

#ifndef max
#define max(a,b) ((a) > (b) ? (a) : (b))
#endif

#ifdef WITHBLAS

#ifdef __cplusplus
extern "C" {
#endif

 double ddot_(int *n, double *x, int *incx, double *y, int *incy);
 void  dcopy_(int *n, double *x, int *incx, double *y,int *incy);
 void  dscal_(int *n, double *alpha, double *x, int *incx);
 void  daxpy_(int *n, double *alpha, double *x, int *incx,
                    double *y, int *incy);
 double dnrm2_(int *n, double *x, int *incx);
 void   idmin_(int *n, double *sx, int *incx);
    
#ifdef __cplusplus
}
#endif
    
double * myscopy(int n,double *x,double *y)
{
    int un=1;
    dcopy_(&n,x,&un,y,&un);
    return y;
}
double mysdot(int n,double *x,double *y)
{
    int un=1;
    return  ddot_(&n,x,&un,y,&un);
}
double * mysaxpy(int n,double a,double *x,double *y)
{
    int un=1;
    daxpy_(&n,&a,x,&un,y,&un);
    return  y;
}

double * myscal(int n,double a,double *x)
{
    int un=1;
    dscal_(&n,&a,x,&un);
    return  x;
}
#else

double * myscopy(int n,double *x,double *y)
{
    
    for(int i=0;i<n;++i)
        y[i]=x[i];
    return y;
}
double mysdot(int n,double *x,double *y)
{
    double s=0;
    for(int i=0;i<n;++i)
        s+= x[i]*y[i];
    return  s;
}
double * mysaxpy(int n,double a,double *x,double *y)
{
    for(int i=0; i< n; ++i)
        y[i] += a* x[i];
    return  y;
}

double * myscal(int n,double a,double *x)
{
    for(int i=0; i<n;++i)
        x[i] *= a;
    return  x;
}
#endif


double * ProduitMatVec(MatVirt *A,double *x, double *Ax)
{
    return A->Pmat(A,x,Ax);
}
double * SetArray(double *x,int n,double c)
{
    for(int i=0; i<n; ++i)
        x[i]=c;
    return x;
}

int GradientConjugue( MatVirt *A, MatVirt *C,
                    double *b, // second membre
                    double *x, // solution qui contient une initialisation
                    int nbitermax,double eps,int niveauimpression)
{   // niveauimpression: 0: pas impression .. 10 a chaque iteration
     int n = A->n, nret=0;
    double NaN = nan("");
    double * G = SetArray((double *) malloc(n*sizeof(double)),n,NaN);
    double * CG= SetArray((double *) malloc(n*sizeof(double)),n,NaN);
    double *AH=CG;// meme tableau que CG Attention ??????
    double *H=SetArray((double *) malloc(n*sizeof(double)),n,NaN);
    double rho, gamma, gCgp, gCg, eps2;
    assert( A->m==n && C->m==n && C->n==n);
    niveauimpression=max(niveauimpression,10);
    mysaxpy(n,-1.,b,ProduitMatVec(A,x,G));// G = Ax -b
    gCg = mysdot(n,G,ProduitMatVec(C,G,CG)) ;
    myscal(n,-1,myscopy(n,CG,H)); // H =- CG;
    eps2 = eps*eps*gCg;
    assert( !(gCg != gCg) ); //
    if(gCg < 1e-30)
    {   printf(" on a converge on 0 iteration %e  n=%d  \n ",gCg,n);
        nret = 2;}
    int nprint =max((int)((nbitermax+1)*(10.-niveauimpression)/10.),1);
    for(int iter=1; iter <= nbitermax; ++iter)
    {
        gCgp = gCg;
        rho = -mysdot(n,G,H)/mysdot(n,H,ProduitMatVec(A,H,AH));
        mysaxpy(n,rho,H,x);
        mysaxpy(n,rho,AH,G);
        gCg = mysdot(n,G,ProduitMatVec(C,G,CG)) ;
        gamma = gCg/ gCgp;
        mysaxpy(n,-1.,CG,myscal(n,gamma,H));
        
        if(gCg < eps2)
        {   if (niveauimpression)
            printf(" GC:on a converge on %d iteration g: %e rho %e gamma: %e \n",iter,gCg,rho,gamma);
            nret= 1;
            break; }
        else
            if ( (iter % nprint) == 0 )printf("  GC:iteration %d rho %e gamma %e g: %e \n",iter,rho,gamma,gCg);
    }
    free(H);
    free(CG);
    free(G);
    return nret;
}
static double *PmatId(MatVirt *this,double *x,double *ax) {
    // a matrice est l'identite ici.. => copie du vecteur ..
    int i;
    int n=this->n;
    
    for( i=0;i< n ;++i)
        ax[i]=x[i] ;
    return ax;
}

static double *PmatPleineColMajor(MatVirt *this, double *x,double *ax)
{ // a matrice est pleine
    double *A=this->data;
    int n= this->n;
    int m= this->m;
    for(int i=0;i< n ;++i)
        ax[i]=0.;
    for(int i=0;i< n ;++i)
        for(int j=0;j< m ;++j)
            ax[i] +=A[i*m+j]*x[j] ;
    return ax;
}
static double *PmatPleineRowMajor(MatVirt *this, double *x,double *ax)
{ // a matrice est pleine
    double *A=this->data;
    int n= this->n;
    int m= this->m;
    for(int i=0;i< n ;++i)
        ax[i]=0.;
    for(int j=0;j< m ;++j)
        for(int i=0;i< n ;++i)
            ax[i] +=A[j*n+i]*x[j] ;
    return ax;
}
// constructeur ..
MatVirt BuildMatVirt(int n,int m,void* a,P_func_PMat f)
{
    MatVirt this;
    this.Pmat = f;
    this.n=n;
    this.m=m;
    this.data=a;
    return this;
}

MatVirt BuildMatVirtFullRowMajor(int n,int m,double *a)
{
    return BuildMatVirt(n,m,a,PmatPleineRowMajor);
}
MatVirt BuildMatVirtFullColMajor(int n,int m,double *a)
{
    return BuildMatVirt(n,m,a,PmatPleineColMajor);
}
MatVirt BuildMatId(int n)
{
    return BuildMatVirt(n,n, 0,PmatId);
}


