#include<stdio.h>
#include<math.h>

float Ffloat(float x){
  return ( sin(x) * pow(x, 3) );
}

double Fdouble(double x){
  return ( sin(x) * pow(x, 3) );
}

float DDfloat(float x, float h){
  return  ( Ffloat(x+h) - Ffloat(x) )/ h ;
}

float DCfloat(float x, float h){
  return  ( Ffloat(x+h) - Ffloat(x-h) )/ (2*h) ;
}

double DDdouble(float x, double h){
  return  ( Fdouble(x+h) - Fdouble(x) )/ h ;
}

double DCdouble(float x, double h){
  return  ( Fdouble(x+h) - Fdouble(x-h) )/ (2*h) ;
}

int main(){
  float  x,i ;
  double h;

  FILE *file ;

  file = fopen("derivada_float.dat", "w" );
  x = 6 ;
  for(i = -10 ; i <= 1; i+=0.2 ){
      h = pow(10, i) ;
      fprintf(file, "%1.1E %f %f %f %f\n", h, DDfloat(x,h),DCfloat(x,h), DDdouble(x,h),DCdouble(x,h) ) ;
    }

  fclose( file );
  return 0;
}
