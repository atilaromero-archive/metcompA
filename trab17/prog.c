
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int POSX=0;
int POSY=1;

void calculalinha(double vec[100][2],int veclen,  double *alfa0,  double *alfa1){
  double X,Y,Z,A,N,x,y;
  double det,detalfa0,detalfa1;
  int pos;
  X=0;
  Y=0;
  Z=0;
  A=0;
  N=veclen;
  for(pos=0;pos<veclen;pos++){
    x=vec[pos][POSX];
    y=vec[pos][POSY];
    X += x;
    Y += y;
    A += x*x;
    Z += y*x;
  }
  det = (N*A)-(X*X);
  detalfa0 = (Y*A)-(X*Z);
  detalfa1 = (N*Z)-(Y*X);
  *alfa0 = detalfa0/det;
  *alfa1 = detalfa1/det;
}

int main(){
  FILE *f;
  float x,y;
  double vec[100][2];
  int veclen;
  double alfa0, alfa1;
  
  f=fopen("dados.dat","r");
  for(veclen=0;
      feof(f)==0;
      veclen++){
    fscanf(f,"%f %f\n",&x,&y);
    vec[veclen][POSX]=x;
    vec[veclen][POSY]=y;
  }
  fclose(f);
  calculalinha(vec, veclen, &alfa0, &alfa1);
  printf("%lf %lf\n",alfa0,alfa1);
  return 0;
}

