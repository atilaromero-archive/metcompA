#include <stdio.h>
#include <math.h>

float f(float x){
  return sin(x);
}

float f2(float x){
  float E=0.2;
  float M=0.5;
  return (x - (E*sin(x))-M);
}

float g(float t, float resp){
  return 1-(1+t+(t*t)/2)*exp(-t)-resp;
}

float f3(float x){
  return g(x,0.1);
}
float f4(float x){
  return g(x,0.9);
}

float bisseccao(float (*f)(float),float xa, float xb, float precisao, int Nmax){
  int i;
  float fxa,fxm,xm;
  i=0;
  do{
    i++;
    xm=(xa+xb)/2;
    fxm=f(xm);
    fxa=f(xa);
    if (fxa*fxm<0){
      xb=xm;
    }else{
      xa=xm;
    }
  }while((fxm*fxm)>(precisao*precisao) && i<Nmax);
  fprintf(stderr,"Xm: %f\n",xm);
  fprintf(stderr,"i : %i\n",i);
  return xm;
}

main(){
  int Nmax;
  float xa,xb,precisao;
  float g1,g2;
  fscanf(stdin,"%f %f %f %i\n",&xa,&xb,&precisao,&Nmax);

  /* 1)
     $ echo 1.0 4.0 0.0000001 10000 | ./prog 
     Xm: 3.141593
     i : 24
  */
  //bisseccao(&f,xa,xb,precisao,Nmax);

  /*2)
    $ echo -1.0 1.0 0.0000001 1000000 | ./prog 
    Xm: 0.615468
    i : 23
  */
  //bisseccao(&f2,xa,xb,precisao,Nmax);

  /* 3)
     $ echo 0.0 20 0.000001 1000000 | ./prog 
     Xm: 1.102066
     i : 18
     Xm: 5.322323
     i : 20
     tempo: 4.220257
  */
  g1=bisseccao(&f3,xa,xb,precisao,Nmax);
  g2=bisseccao(&f4,xa,xb,precisao,Nmax);
  printf("tempo: %f\n",g2-g1);
}
