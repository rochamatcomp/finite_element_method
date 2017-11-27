
struct  MatVirt;
typedef struct MatVirt MatVirt;
// type du pointeur sur la fonction produit matrice vecteur ..
typedef double *  (*P_func_PMat)( MatVirt *, double *,double *);

struct  MatVirt {
  P_func_PMat Pmat;
  int n,m;
  void * data; 
}  ;

#ifdef __cplusplus
extern "C" {
#endif
int GradientConjugue(MatVirt *A, // fonction et pointeur data pour A
		     MatVirt *C, // fonction et pointeur data pour C
		     double * b, // second membre
		     double * x, // solution qui contient une initialisation
		     int nbitermax,double eps,
                     int niveauimpression)
;

// constructeur de class MatVirt 
MatVirt BuildMatVirt(int n,int m,void* a,P_func_PMat f);
MatVirt BuildMatId(int n);
MatVirt BuildMatVirtFullRowMajor(int n,int m,double *a);
MatVirt BuildMatVirtFullColMajor(int n,int m,double *a);

double * ProduitMatVec(MatVirt *A,double *x, double *Ax);
double mysdot(int n,double *x,double *y);
double * mysaxpy(int n,double a,double *x,double *y);
double * myscal(int n,double a,double *x);
#ifdef __cplusplus
}
#endif