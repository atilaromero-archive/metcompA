#include<stdio.h>
#include<math.h>

#define Nmax 100000

double f( double x ) ;
double F( double x ) ;
double derivf( double x );
double newRap( double x_init);
double PRECISAO = 0.001;

main(){
  printf("%1.6lf\n",derivf(-1.570798));
  printf("%1.6lf\n",derivf(0));
  printf("%1.6lf\n",derivf(1.570795));
}

double newRap(double x_init){
  double x, x_old, dx;
  int i ;

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

 if(i<Nmax)
   return x;
 else
   return Nmax;
}

double f( double x )
{
  // neste local você define a função que quer analisar
  return (exp(-0.1*x) * sin(2*x));
}

double F( double x )
{
  // aqui voce define F(x) = f(x) +x
  return f(x)+x;
}

double derivf( double x )
{
  // aqui voce define a derivada de f(x)
  return (exp(-0.1*x) * 2*cos(2*x))+(-0.1*exp(-0.1*x) * sin(2*x));
} 
