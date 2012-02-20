#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 1000

main(){
  FILE *out;
  float matriz[N];
  int i; 

  srand(time(NULL));
  fprintf(stderr,"RAND_MAX: %d\n",RAND_MAX);
  
  out=fopen("saida.dat","w");

  for(i=0; i<N; i++){
    matriz[i]=((float)rand())/RAND_MAX;
    fprintf(out,"%d\t%f\n",i,matriz[i]);
  }
  fclose(out);
}
