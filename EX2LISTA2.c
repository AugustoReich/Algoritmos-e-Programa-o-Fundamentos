#include <stdio.h>
int main()
{
    float cotacao_dolar;
    float total_reais;
    float dolares;
    printf("digite a cotacao do dolar ");
    scanf("%f" ,&cotacao_dolar);
    printf("quantos dolares voce deseja comprar? ");
    scanf("%f",&dolares);
    total_reais = dolares * cotacao_dolar;
    printf("voce deve pagar R$ %.2f" , total_reais);
    return 0;
}