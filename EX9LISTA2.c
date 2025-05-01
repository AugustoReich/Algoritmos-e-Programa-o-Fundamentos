#include <stdio.h>
int main()
{
    float valor_compra;
    float valor_com_desconto;
    printf("digite o valor da sua compra: ");
    scanf("%f" ,&valor_compra);
    valor_com_desconto = valor_compra * 0.85;
    printf("o valor com desconto é: %.2f" ,valor_com_desconto);
    return 0;
}