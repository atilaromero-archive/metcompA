#include<stdio.h>
#include<math.h>

double Fdouble(double x){
  return ( exp(x) / (pow(x, 3)-1) );
}

double DCdouble(float x, double h){
  return  ( Fdouble(x+h) - Fdouble(x-h) )/ (2*h) ;
}

void calcula(FILE *file){
  float  i ;
  double h;

  for(i = -2 ; i <= 1; i+=0.01 ){
      h = pow(10, i) ;
      fprintf(file, "%1.1E %f %f %f %f\n", h, DCdouble(-2,h), DCdouble(0.5,h), DCdouble(2,h), DCdouble(5,h) ) ;
    }
}

int main(){
  FILE *file ;

  file = fopen("derivada_float.dat", "w" );
  calcula(file);

  fclose( file );
  return 0;
}
