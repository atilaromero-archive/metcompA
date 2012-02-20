#include<stdio.h>
#include<math.h>

#define Nmax 100000

double f( double x ) ;
double F( double x ) ;
double derivf( double x );
double newRap( double x_init);
double PRECISAO = 0.001;

main()
{
  double x_init;
  double result;
  double r[100];
  int i, pos;
  for(i=0; i<100; i++){
    r[i]=0;
  }
  pos=0;
  
  for(x_init=-2; x_init<=2; x_init+=0.200){
    result=newRap(x_init);
    if (result>=-2 && result<=2){
      for(i=0; i<pos && pos<100; i++){
	if ((result-r[i])*(result-r[i])<PRECISAO*PRECISAO){
	  result=Nmax;
	  break;
	}	  
      }
      if (result>=-2 && result<=2){
	r[pos]=result;
	pos++;
      }
    }
  }
  
  FILE *f = fopen("raizes.dat","w");
  for(i=0; i<pos; i++){
    fprintf(f,"%1.6lf\n",r[i]);
  }
  fclose(f);
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
