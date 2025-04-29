#include <stdio.h>
int main()
{
    float grau_a;
    float grau_b;
    float grau_final;
    printf("digite a sua nota do grau a: ");
    scanf("%f", &grau_a);
    printf("digite a sua nota do grau b: ");
    scanf("%f", &grau_b);
    grau_final = (grau_a + grau_b * 2) / 3;
    printf("sua nota final é: %.2f", grau_final);
    return 0;
}