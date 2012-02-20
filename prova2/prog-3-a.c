#include<stdio.h>
#include<math.h>

#define Nmax 100000

double f( double x ) ;
double F( double x ) ;
double derivf( double x );

main()
{
  double x, x_init, x_old, dx, PRECISAO = 0.001 ;
  int i ;

  x_init=0.200;

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
  return (exp(-1*x*x) -x -x);
}

double F( double x )
{
  // aqui voce define F(x) = f(x) +x
  return f(x)+x;
}

double derivf( double x )
{
  // aqui voce define a derivada de f(x)
  return (-2*x*exp(-1*x*x))-2;
} 
