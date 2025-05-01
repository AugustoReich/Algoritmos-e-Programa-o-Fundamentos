#include <stdio.h>
int main()
{
    float camisetas, calcas, cintos;
    float preco_camiseta = 25, preco_cinto = 40, preco_calca = 100;
    float valor_final, desconto, final_com_desconto;
    printf("quantas camisetas voce comprou? ");
    scanf("%f" ,&camisetas);
    printf("quantas calcas voce comprou? ");
    scanf("%f" ,&calcas);
    printf("quantos cintos voce comprou? ");
    scanf("%f" ,&cintos);
    valor_final = camisetas * preco_camiseta + calcas * preco_calca + cintos * preco_cinto;
    desconto = valor_final * 0.10;
    final_com_desconto = valor_final - desconto;
    printf("o valor final com desconto ficou R$: %.2f" ,final_com_desconto);
    return 0;
}