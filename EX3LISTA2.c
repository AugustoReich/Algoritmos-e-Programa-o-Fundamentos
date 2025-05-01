#include <stdio.h>
int main()
{
    float peso_prato;
    float valor_final;
    float preco_kilo;
    preco_kilo = 40;
    printf("peso do seu prato: ");
    scanf("%f" ,&peso_prato);
    valor_final = peso_prato * preco_kilo;
    printf("o valor final é: %.2f" ,valor_final);
    return 0;
}