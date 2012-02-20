#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float f(float x){
  FILE *out;
  float result=0;
  int n;
  int max=200;
  out=fopen("dados.dat","w");
  for(n=1; n<=max; n++){
    result+=n*pow(x,n);
    fprintf(out,"%d\t%f\n",n,result);
  }
  fclose(out);
  return result;
}

main(){
  float x;
  for(x=2;pow(x,2)>1;){
    fprintf(stderr,"Digite x (|x|< 1) : ");
    scanf("%f",&x);
  }
  printf("%f\n",f(x));
}
