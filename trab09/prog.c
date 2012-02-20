#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

//Calcula o fatorial, retornando long long
long long lfact(int n){
  int i;
  long long result=1L;
  for(i=n;i>1;i--){
    result*=i;
  }
  return result;
}

//Calcula o fatorial, retornando um long
long fact(int n){
  int i;
  long result=1L;
  for(i=n;i>1;i--){
    result*=i;
  }
  return result;
}

//Faz o mesmo que pow, mas com long double
long double lpow(float x,int y){
  int i;
  long double result=x;
  for(i=y;i>1;i--){
    result*=x;
  }
  return result;
}

//Calcula exp(x), chamando fact e pow
double e(float x){
  double result=1;
  double part=100;
  int i;
  for(i=1;i<12;i++){
    part=pow(x,i)/fact(i);
    result+=part;
  }
  return result;
}

//Calcula exp(x), usando long double, chamando lfact e lpow
long double le(float x){
  long double result=1;
  long double part=100;
  int i;
  for(i=1;i<20;i++){
    part=lpow(x,i)/lfact(i);
    result+=part;
  }
  return result;
}

//Calcula exp(x), mas faz os cálculos aos poucos 
// para não estourar as variaveis
double ex(float x){
  int i,n;
  double part;
  double result;
  part=100;
  result=1;
  for(i=1;part>0.000001;i++){
    part=1;
    for(n=1;n<=i;n++){
      part*=x;
      part/=n;
    }
    result+=part;
  }
  return result;
}

main(){
  //  printf("%d",sizeof(f));
  int n;
  float f;
  fprintf(stderr,"Calcular exp(x) de 0 a : ");
  scanf("%d",&n);
  //fprintf(stderr,"%d!=\t%lld\n",n,fact(n));
  //fprintf(stderr,"exp(%d)=\t%Le\n",n,e(n));
  for(f=0;f<=(n+0.1);f+=0.1){
    printf("%f\t%f\t%f\t%Lf\n",f,e(f),ex(f),le(f));
  }
}
