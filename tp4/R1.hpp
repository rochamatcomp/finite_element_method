#include <cmath>
#include <cassert>
// Definition de la class R1 
//  sans compilation separe toute les fonctions 
// sont definies dans ce R1.hpp avec des inline 
//  
// definition R (les nombres reals)
// remarque la fonction abort est defini dans 
#include <cstdlib> 
#include <iostream> 
typedef double R;

// The class R1
class R1 {

public:  
  R x;  // declaration de membre 
  // les 3 constructeurs ---
  R1 () :x(0.) {} // rappel : x(0)  sont initialiser via le constructeur de double 
  R1 (R a):x(a)  {}
  R1 (const R1 & a, const R1 & b): x(b.x - a.x) {}
  // le constucteur par defaut est inutile
  /*
  R1 (const R1 & a) : x(a.x) { cout << "  const par copy " << endl;} 
  R1 ( R1 & a) : x(a.x) { cout << "  const pas const  par copy " << endl; } 
  */
  // rappel les operator definis dans une class on un parametre
  // cache qui est la classe elle meme (*this)

  // les operateurs affectation
  //  operateur affection (*this) = P est inutil par defaut il fait le travail correctement
  /*
  R1 &  operator=(const R1 & P)  {x = P.x; return *this;}
  */
  // les autre operateur affectations
  R1 &  operator+=(const R1 & P)  {x += P.x; return *this;}
  R1 &  operator-=(const R1 & P) {x -= P.x; return *this;}
  // operateur binaire + - * , ^ /
  R1   operator+(const R1 & P)const   {return R1(x+P.x);}
  R1   operator-(const R1 & P)const   {return R1(x-P.x);}
  R    operator,(const R1 & P)const  {return  x*P.x;} // produit scalaire
  //???  R    operator^(const R1 & P)const {return  x*P.y-y*P.x;} // produit mixte
  R1   operator*(R c)const {return R1(x*c);}
  R1   operator/(R c)const {return R1(x/c);}
  // operateur unaire 
  R1   operator-()const  {return R1(-x);} 
  const R1 &  operator+()const  {return *this;}
  // un methode
  //??? R1   perp() const {return R1(-y,x);} // la perpendiculaire
  // les operators  tableau
  // version qui peut modifie la class  via l'adresse de x ou y 
  R & operator[](int i) { if(i==0) return x; else {assert(0);exit(1);} ;}
  // version qui retourne une reference const qui ne modifie pas la class
  const R & operator[](int i) const { if(i==0) return x; else {assert(0);exit(1);} ;}

  // les operators  tableaux
  // version qui peut modifie la class  via l'adresse de x ou y 
  R & operator()(int i) { if(i==1) return x; else {assert(0); abort();} ;}
  // version qui retourne une reference const qui ne modifie pas la class
  const R & operator()(int i) const { if(i==1) return x; else {assert(0); abort();} ;}
  R norme() const { return std::sqrt(x*x);}
  //  un variable globale dans la classe donc de nom R1::d 
  static const int  d=1;  // utilisation:  R1::d  (n'ajoute pas de memoire)
};
inline double det(const R1 & A,const R1 & B)
{
  //std::cout << A[0] << ", " << B[0]  << std::endl;
  return R1(A,B)[0];
}
inline std::ostream& operator <<(std::ostream& f, const R1 & P )
{
  f << P.x;
  return f;
}

inline std::istream& operator >>(std::istream& f,  R1 & P)
{
  f >>  P.x;
  return f;
}

inline R1 operator*(R c,const R1 & P) {return P*c;} 
//??? inline R1 perp(const R1 & P) { return R1(-P.y,P.x) ; }
//inline R1 Perp(const R1 & P) { return P.perp(); }  // autre ecriture  de la fonction perp
