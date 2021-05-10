#include <stdio.h>

int main(){
    float velocidade;
    int limite = 80;
    float multa;

    scanf("%f", &velocidade);

    if (velocidade > limite){
        multa = 2 * (velocidade - limite);

        printf("Limite de velocidade excedido! Multado no valor de R$%.2f!", multa);
        
    }
    else{
        printf("Velocidade dentro do limite permitido. \n");
    }
    


    return 0;
}