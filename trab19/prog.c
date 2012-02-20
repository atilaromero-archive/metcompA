/*
 C1 e C2 são:
0.088200 -1.119890 

 q e C são:
-0.098774 e -0.011199 

 */

#include <math.h>
#include <stdio.h>
#include "nrutil.h"
#include "nrutil.c"
#include "gaussj.c"

#define n 2
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
  
  f=fopen("dados.dat","r");
  for(veclen=1;
      feof(f)==0;
      veclen++){
    fscanf(f,"%f %f\n",&x,&y);
    for(i=1;i<=n;i++)
      for(j=1;j<=n;j++)
	M[i][j]+=pow(x,i+j-2);
    for(i=1;i<=n;i++)
      for(j=1;j<=m;j++)
	B[i][j]+=pow(x,i+j-2)*log(y);

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
  printf(" C1 e C2 são:\n");
  for(i=1;i<=m;i++)
    {
      for(j=1;j<=n;j++)
	printf("%f ",B[i][j]);
      printf("\n");
    }
  
  printf(" q e C são:\n");
  printf(" %f e %f \n",B[1][1]*B[1][2],B[1][2]/100);
}

