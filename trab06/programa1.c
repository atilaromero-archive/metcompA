#include<stdio.h>

multiplos(int n,int a, int b){
  int x;
  for(x=a;x<=b;x++){
    if (x%n==0){
      printf("%d é múltiplo de %d.\n",x,n);
    }
  }
}

main()
{
  int n,a,b;
  printf("Escolha os valores de N, A e B: ");
  scanf("%d %d %d",&n,&a,&b);
  multiplos(n,a,b);
}
