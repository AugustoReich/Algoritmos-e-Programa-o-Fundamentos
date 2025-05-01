#include <stdio.h>
int main()
{
    int passaros;
    int consumo_racao;
    int racao_total;
    consumo_racao = 30;
    printf("quantos passaros voce possui? ");
    scanf("%d",&passaros);
    racao_total = passaros * consumo_racao;
    printf("os passaros iram consumir em racao: %d",racao_total);
    return 0;
}