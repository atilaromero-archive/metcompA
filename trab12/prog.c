#include <math.h>
#include <stdio.h>

float funcaoF( float x )
{
  return sin(x);
  // return ( 1 / (pow(x,2)-1) ) ;
}

float funcaoF2( float x )
{
  return ( 1 / (pow(x,2)-1) ) ;
}

float integral(float xmin, float xmax, int N, float (*f)(float)){
  int i; 
  float integral, xi , deltaX ;
  deltaX = ( xmax - xmin ) / N ;
  integral = 0;
  for( i = 0 ; i < N; i++ )
    {
      xi = xmin + i * deltaX ;
      integral += ( f(xi) + f(xi+deltaX) ) * deltaX / 2 ;
    }
  return integral;
}

oldmain()
{
  int N ;
  float xmin, xmax;

  printf("Entre xmin, xmax, N: ");
  scanf("%f %f %d",&xmin, &xmax, &N);
  printf("A integral eh: %f \n", integral(xmin,xmax,N,funcaoF));
}

float erro(float xmin, float xmax, int N,float (*f)(float)){
  float a = integral(xmin,xmax,N,f);
  float b = integral(xmin,xmax,(N-1),f);
  return 1-b/a;
}

main(){
  int N, Nmax;
  float xmin, xmax;
  float err, resultado;
  float err2, resultado2;
  xmin=2;
  xmax=5;
  Nmax=2000;
  for(N=2;N<=Nmax;N++){
    err = erro(xmin, xmax, N, funcaoF);
    resultado = integral(xmin,xmax,N,funcaoF);
    err2 = erro(xmin, xmax, N, funcaoF2);
    resultado2 = integral(xmin,xmax,N,funcaoF2);
    printf("%i %1.3E %1.3E %1.3E %1.3E\n",N,resultado,err,resultado2,err2);
    if (err==0.0){
      break;
    }
  }
}
