#include <math.h>
#include <stdio.h>
#include "nrutil.h"
#include "nrutil.c"
#include "gaussj.c"

#define n 5
#define m 1

// rotina de gauss-jordan
// Ax=B -> a solucao de x é: A-1Ax = A-1B ==> x = A-1B
// a rotina pede como dados de entrada: Anxn (matriz quadrada de dimensão n x n)
// Bnxn (matriz de dimensão n x m)
// resultados desta função: A-1 e x
// no entanto, a funcão escreve por cima de A e B; portanto, após chamarmos a função gaussj(), A vira A-1 e B vira x

main()
{
  FILE *f;
  int veclen;

  int i,j;
  float x,y;
  float **M,**B; // declara matrizes A e B como ponteiros para ponteiro -- ainda nao se definiu suas dimensões!
  M=matrix(1,n,1,n); // esta parte define as dimensões de A que vão entre 1 até n (inclusive)
  B=matrix(1,n,1,m); // atenção: esta maneira de inicializar as matrizes está definida no arquivo nrutil.c

  for(i=1;i<=n;i++)
    for(j=1;j<=n;j++)
      M[i][j]=0;
  
  for(i=1;i<=n;i++)
    for(j=1;j<=m;j++)
      B[i][j]=0;
  
  f=fopen("dados_g4.dat","r");
  for(veclen=1;
      feof(f)==0;
      veclen++){
    fscanf(f,"%f %f\n",&x,&y);
    for(i=1;i<=n;i++)
      for(j=1;j<=n;j++)
	M[i][j]+=pow(x,i+j-2);
    for(i=1;i<=n;i++)
      for(j=1;j<=m;j++)
	B[i][j]+=pow(x,i+j-2)*y;

    printf("%f %f\n", x, y);
  }
  fclose(f);

  // chama a função que resolve sistema linear de equações
  gaussj(M,n,B,m);

  printf("A matriz inversa de M eh:\n");
  for(i=1;i<=n;i++)
    {
      for(j=1;j<=n;j++)
	printf("%f ",M[i][j]);
      printf("\n");
    }

  printf("\n\n\n");
  printf(" A solucao do problema, o vetor X, eh:\n");
  for(i=1;i<=m;i++)
    {
      for(j=1;j<=n;j++)
	printf("%f ",B[i][j]);
      printf("\n");
    }
}

/*
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
  }
  det = (N*A)-(X*X);
  detalfa0 = (Y*A)-(X*Z);
  detalfa1 = (N*Z)-(Y*X);
  *alfa0 = detalfa0/det;
  *alfa1 = detalfa1/det;
}

int main(){
  return 0;
}

*/
