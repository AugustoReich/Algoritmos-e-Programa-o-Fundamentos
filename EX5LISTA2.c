#include <stdio.h>
int main()
{
    float preco_gasolina;
    float dinheiro;
    float litros;
    printf("digite o preco da gasolina: ");
    scanf("%f", &preco_gasolina);
    printf("quantos tu tem de grana? ");
    scanf("%f", &dinheiro);
    litros = dinheiro / preco_gasolina;
    printf("voce consegue encher em litros: %.2f", litros);
    return 0;
}