#include <stdio.h>
int main()
{
    int tablet;
    tablet = 1500;
    int smartphone;
    smartphone = 1000;
    int dinheiro_total;
    printf("quantos tablets foram vendidos hoje? ");
    scanf("%d", &tablet);
    printf("quantos smartphones foram vendidos hoje? ");
    scanf("%d", &smartphone);
    dinheiro_total = (smartphone * 1000) + (tablet* 1500);
    printf("a loja arrecadou hoje R$ %.d" ,dinheiro_total);
    return 0;
}