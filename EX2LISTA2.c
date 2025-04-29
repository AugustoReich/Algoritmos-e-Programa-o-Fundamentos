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
    real = dolar * cotacao;
    printf("voce precisa pagar esse valor em reais: %.2f", real);
    return 0;
}