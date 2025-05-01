#include <stdio.h>
int main()
{
    int numero1;
    int numero2;
    float resultado;
    printf("digite um numero: ");
    scanf("%d",&numero1);
    printf("digite outro numero: ");
    scanf("%d",&numero2);
    if (numero2 > 0)
    {
        resultado = numero1 / numero2;
        printf("o resultado é: %.2f" ,resultado);
    }
    else
    {
        printf("erro: nao pode ser 0 ");
    }
    return 0;
}