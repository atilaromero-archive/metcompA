#include <math.h>
#include <stdio.h>

#define MAX_N 5

float neville(float a[MAX_N][MAX_N],float x[MAX_N], int N, float z){
  int i,j;
  float cima1,cima2,baixo;
  for(j=2;j<=N;j++){
    for(i=1;i<=(N-j+1);i++){
      cima1=(z-x[i+j-1])*a[i][j-1];
      cima2=(z-x[i])*a[i+1][j-1];
      baixo=x[i]-x[i+j-1];
      a[i][j]=cima1/baixo-cima2/baixo;
    }
  }
  return a[1][N];
}

main(){
  float a[MAX_N][MAX_N];
  float x[MAX_N];
  float z;
  int N;
  int i;
  for(i=1;i<=4;i++){
    N=i;
    fscanf(stdin,"%f %f\n",&x[i],&a[i][1]);
  }
  for(z=0;z<=6;z+=0.1){
    printf("%f %f\n",z,neville(a,x,N,z));
  }
}
