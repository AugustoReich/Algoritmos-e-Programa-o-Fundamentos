#include <stdio.h>
int main()
{
    float celcius;
    float fahrenheit;
    printf("quantos graus celsius: ");
    scanf("%f" ,&celcius);
    fahrenheit = (celcius * 1.8) + 32;
    printf("o valor em fahrenheit é de: %.2f" ,fahrenheit);
    return 0;
}