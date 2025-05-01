#include <stdio.h>
int main()
{
   float valor, convertido;
   char opcao;
   float valor_dolar, valor_euro;
   printf("insira a cotacao do dolar: ");
   scanf("%f",&valor_dolar);
   printf("insira a cotacao do euro: ");
   scanf("%f",&valor_euro);
   printf("escolha uma opcao:\n");
   printf("1- Converter de Real para Euro\n");
   printf("2- Converter de Real para Dólar\n");
   printf("3- Converter de Euro para Dólar\n");
   printf("4- Converter de Euro para Real\n");
   printf("5- Converter de Dólar para Euro\n");
   printf("6- Converter de Dólar para Real\n");
   printf("opcao: ");
   scanf(" %c",&opcao);
   printf("digite o valor que deseja converter: ");
   scanf("%f", &valor);
   
   switch (opcao) {
       case '1':
       convertido = (valor / valor_euro);
       printf("R$ %.2f equivalem a € %.2f", valor, convertido);
       break;
       
       case '2':
       convertido = (valor / valor_dolar);
       printf("R$ %.2f equivalem a US$ %.2f", valor, convertido);
       break;
       
       case '3':
       convertido = (valor * valor_euro) / valor_dolar;
       printf("€ %.2f equivalem a US$ %.2f", valor, convertido);
       break;
       
       case '4':
       convertido = valor * valor_euro;
       printf("€ %.2f equivalem a R$ %.2f", valor, convertido);
       break;
       
       case '5':
       convertido = (valor * valor_dolar) / valor_euro;
       printf("R$ %.2f equivalem a € %.2f", valor, convertido);
       break;
       
       case '6':
       convertido = (valor * valor_dolar);
       printf("US$ %.2f equivalem a R$ %.2f", valor, convertido);
       break;
       default:
       printf("opcao invalida");
   }
   return 0;
}