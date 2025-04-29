#include <stdio.h>
int main()
{
    float valor_final;
    float peso_prato;
    float preco_por_kg = 40;
    printf("digite o peso do seu prato em quilos: ");
    scanf("%f", &peso_prato);
    valor_final = peso_prato * preco_por_kg;
    printf("o valor do seu prato é: %.1f", valor_final);
    return 0;
}
