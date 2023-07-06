/* Implementação de Programação Dinâmica do problema LCS */
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;

/* Retorna o tamanho do LCS para X[0..m-1] e Y[0..n-1] */
void LCS(string X, string Y)
{
    int tamanhoX = X.size();
    int tamanhoY = Y.size();
    int matrizLCS[tamanhoX + 1][tamanhoY + 1];

    /* Os passos a seguir constroem a matrizLCS[tamanhoX + 1][tamanhoY + 1] de baixo para cima.
    Observe que matrizLCS[i][j] contém o tamanho do LCS de X[0..i-1] e Y[0..j-1] */
    for (int i = 0; i <= tamanhoX; i++) {
        for (int j = 0; j <= tamanhoY; j++) {
            if (i == 0 || j == 0)
                matrizLCS[i][j] = 0;
            else if (X[i - 1] == Y[j - 1])
                matrizLCS[i][j] = matrizLCS[i - 1][j - 1] + 1;
            else
                matrizLCS[i][j] = max(matrizLCS[i - 1][j], matrizLCS[i][j - 1]);
        }
    }

    // O código a seguir é usado para imprimir o LCS
    int indice = matrizLCS[tamanhoX][tamanhoY];

    // Crie um array de caracteres para armazenar a string do LCS
    char lcs[indice + 1];
    lcs[indice] = '\0'; // Define o caractere de terminação

    // Comece do canto inferior direito e armazene os caracteres em lcs[] um por um
    int i = tamanhoX, j = tamanhoY;
    while (i > 0 && j > 0) {
        // Se o caractere atual em X[] e Y forem iguais, então
        // o caractere atual faz parte do LCS
        if (X[i - 1] == Y[j - 1]) {
            lcs[indice - 1] = X[i - 1]; // Coloque o caractere atual no resultado
            i--;
            j--;
            indice--; // reduza os valores de i, j e indice
        }

        // Se não forem iguais, então encontre o maior entre os dois e
        // vá na direção do valor maior
        else if (matrizLCS[i - 1][j] > matrizLCS[i][j - 1])
            i--;
        else
            j--;
    }

    // Imprima o LCS
    cout << lcs << endl;
}

/* Função principal para testar a função acima */
int main()
{
    string texto1, texto2;
    cin >> texto1 >> texto2;
    LCS(texto1, texto2);
    return 0;
}
