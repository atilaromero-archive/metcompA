#include<stdio.h>
#include<math.h>

#define Nmax 100000

double f( double x ) ;
double F( double x ) ;
double derivf( double x );

double R = 3.2;

main()
{
  double x, x_init, x_old, dx, PRECISAO = 0.001 ;
  int i ;

  x_init=0.200;

  x=x_init ;

  // usando o método de iteração simples
  i=0;
  x_old = F(x) ;
  do{
    i++;
    x_old = x ;
    x = F(x) ;
    dx = x-x_old ;
  }while( (fabs(dx)> PRECISAO )&& (i<Nmax) ) ;

  printf("\n *** Usando o método de iteração simples:***\n");
  if(i<Nmax)
    printf(" Encontrei a raiz %1.6lf em %d iterações !\n", x, i);
  else
    printf("não consigo encontrar esta raiz (#iter=%d) \n", i);


  x=x_init ;
  dx = -f(x)/derivf(x);
  i=0;
do
  {
    x += dx;
    dx = -f(x)/derivf(x);
    i++;
  }
 while( ( fabs(dx) > PRECISAO ) && (i<Nmax) ) ;

 printf("\n *** Usando o método de Newton-Raphson:***\n");
 if(i<Nmax)
   printf(" Encontrei a raiz %1.6lf em %d iterações !\n", x, i);
 else
   printf("não consigo encontrar esta raiz (#iter=%d) \n", i);

}

double f( double x )
{
  // neste local você define a função que quer analisar
  return R*x*(1-x)-x;
}

double F( double x )
{
  // aqui voce define F(x) = f(x) +x
  return f(x)+x;
}

double derivf( double x )
{
  // aqui voce define a derivada de f(x)
  return R-(2*R*x)-1;
} 
