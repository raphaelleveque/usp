#include <stdio.h>



int main(){

    int largura, comprimento, temp, res;

    scanf("%d %d", &largura, &comprimento);

    temp = largura * comprimento;

    if(temp % 2 == 0){
        printf("%d", temp/2);
    }
    else printf("%d", temp/2 + 1);

}