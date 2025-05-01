#include <stdio.h>
int main()
{
    float preco_gasolina;
    float dinheiro;
    float litros;
    printf("quanto esta o preco da gasolina? ");
    scanf("%f" ,&preco_gasolina);
    printf("quantos reais voce tem? ");
    scanf("%f" ,&dinheiro);
    litros = dinheiro / preco_gasolina;
    printf("a quantidade de litros de gasolina que voce consegue comprar é: %.2f" ,litros);
    return 0;
}