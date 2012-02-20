#include <math.h>
#include <stdio.h>

#define MAX_N 100

float neville(float a[MAX_N][MAX_N],float x[MAX_N], int N, float z){
  int i,j;
  float cima1,cima2,baixo;
  for(j=1;j<N;j++){
    for(i=0;i<(N-j);i++){
      //      printf("a[%i][%i]\n",i,j);
      cima1=(z-x[i+j])*a[i][j-1];
      cima2=(z-x[i])*a[i+1][j-1];
      baixo=x[i]-x[i+j];
      a[i][j]=cima1/baixo-cima2/baixo;
    }
  }
  return a[0][N-1];
}

main(){
  float a[MAX_N][MAX_N];
  float x[MAX_N];
  float z;
  int N;
  int i;
  for(i=0;feof(stdin)==0;i++){
    fscanf(stdin,"%f %f\n",&x[i],&a[i][0]);
  }
  //  printf("linhas: %i\n",i);
  for(z=0;z<=10;z+=0.1){
    printf("%f %f\n",z,neville(a,x,i,z));
  }
}
