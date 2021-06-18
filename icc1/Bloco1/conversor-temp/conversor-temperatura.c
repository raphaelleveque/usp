#include <stdio.h>

int main(){
    float celcius;
    float fahrenheit;

    scanf("%f", &fahrenheit);

    celcius = (fahrenheit - 32)* 5/9;

    printf("%.2f \n", celcius);

    return 0;
}