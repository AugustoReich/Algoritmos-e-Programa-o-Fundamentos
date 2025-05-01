#include <stdio.h>
int main()
{
   int tablet;
   tablet = 1500;
   int smartphone;
   smartphone = 1000;
   int faturamento;
   printf("quantos smartphones foram vendidos hoje? ");
   scanf("%d",&smartphone);
   printf("quantos tablets foram vendidos hoje? ");
   scanf("%d",&tablet);
   faturamento = (smartphone * 1000) + (tablet* 1500);
   printf("o faturamento da loja foi de: %d" ,faturamento);
    return 0;
}