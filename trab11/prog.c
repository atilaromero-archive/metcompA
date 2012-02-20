#include <stdio.h>
#include <math.h>

double Fdouble(double x){
  return ( sin(x) * pow(x, 3) );
}

double DA(double x){
    return ( (sin(x) * 3 * pow(x, 2)) + 
	     (cos(x) * pow(x, 3) ));
}

double DD(double x, double h){
  return  ( Fdouble(x+h) - Fdouble(x) )/ h ;
}

double DC(double x, double h){
  return  ( Fdouble(x+h) - Fdouble(x-h) )/ (2*h) ;
}

double erroDC(double x, double h){
  return fabs((DC(x,h)-DA(x))/DA(x));
}

double erroDD(double x, double h){
  return fabs((DD(x,h)-DA(x))/DA(x));
}

void calcula(FILE *file, double hei, double hef, double hestep,double x){
  double  i ;
  double h;

  for(i = hei ; i <= hef; i+=hestep ){
      h = pow(10, i) ;
      fprintf(file, "%1.3E %1.3E %1.3E \n", h, erroDC(x,h), erroDD(x,h)) ;
    }
}

int main(){
  FILE *file ;

  file = fopen("derivada_float.dat", "w" );
  calcula(file,-10,1,0.1,9);

  fclose( file );
  return 0;
}
