#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define N 1000

main(){
  FILE *in;
  float num;
  float media;
  float quad;
  float desv;
  int i; 

  //  srand(time(NULL));
  //  fprintf(stderr,"RAND_MAX: %d\n",RAND_MAX);
  
  in=fopen("dados.dat","r");
  
  for(i=0; (!feof(in)); i++){
    fscanf(in,"%f",&num);
    media+=num;
    quad+=pow(num,2);
  }
  media/=i;
  desv=sqrt(quad/i-pow(media,2));
  fclose(in);
  printf("Média:\t%f\n",media);
  printf("Desvio:\t%f\n",desv);
}
