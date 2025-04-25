#include <stdio.h>
int main()
{
    int segundos;
    int minutos;
    printf("digite os segundos: ");
    scanf("%d",&minutos);
    segundos = minutos * 60;
    printf("o resultado em segundos é: %d",segundos);
    return 0;
}