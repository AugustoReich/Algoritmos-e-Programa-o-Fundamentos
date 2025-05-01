#include <stdio.h>
int main()
{
   int valor_a, valor_b, valor_c, valor_final;
   printf("digite um valor: ");
   scanf("%d",&valor_a);
   printf("digite outro valor: ");
   scanf("%d",&valor_b);
   printf("digite mais um valor: ");
   scanf("%d",&valor_c);
   if (valor_a + valor_b < valor_a + valor_c)
   {
       valor_final = valor_a + valor_b;
       printf("o valor final é: %d" ,valor_final);
   }
   else
   {
       printf("nao foi possivel efetuar o calculo.");
   }
   return 0;
}