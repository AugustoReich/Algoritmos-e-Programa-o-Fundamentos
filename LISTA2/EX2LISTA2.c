#include <stdio.h>
int main()
{
    float real;
    float dolar;
    float cotacao;
    printf("digite a cotação do dólar: ");
    scanf("%f", &cotacao);
    printf("quantos dolares voce deseja comprar: ");
    scanf("%f", &dolar);
    dolar = real * cotacao;
    printf("voce precisa pagar esse valor em reais: ");
    return 0;
}