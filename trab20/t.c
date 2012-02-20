#include <stdio.h>
#include <math.h>
#define N 100000
int main()
{
  FILE *t;
  FILE *entrada;
  FILE *t2;
  int i,Numero;
  double a0,X[N],Y[N],s=0, a[N],x=0,y=0,j=0,a1,z=0,b,c[N];
  entrada=fopen( "1.dat", "r");
  i=0;
  do{
      fscanf(entrada,"%lf %lf",&X[i],&Y[i]);
      i++;
     }while( feof(entrada)==0 );
  
  Numero= i - 1;
  printf("Nn=%d\n", Numero );
  fclose(entrada);
  t=fopen("1a.dat","w");
  a[0]=0;
  for(i=1;i<=Numero;i++)
    { s+=Y[i]*(X[i]-X[i-1]);
      a[i]=s;
      fprintf(t,"%lf %lf %lf \n",X[i],Y[i],a[i]);
    }
  printf("%lf\n",s);
  fclose(t);
  for(i=0;i<Numero;i++)
    {
      x+=X[i];
      y+=Y[i];
      z+=X[i]*Y[i];
      j+=pow(X[i],2);
    } 
  
  a0=(z-((y*x)/Numero)*Numero)/((-x*x)*(j*Numero));
  a1=(y-a1*x)/Numero;
  printf("%lf \n %lf\n",a0,a1);
  t2=fopen("1b.dat","w");
  for(i=0;i<Numero;i++)
    {
      c[i]=Y[i]-a0*X[i]-a1;
      //if(c[i]>0.0025)
      //{     
 fprintf(t2,"%1.12lf %1.12lf\n",X[i],c[i]);
 //}    
}
  fclose(t2);
 return(0);
}
