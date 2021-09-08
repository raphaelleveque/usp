/*
    Raphael Leveque
    12542522
    SCC-02001
    Campo Minado
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

enum Opcoes{
    Imprime = 1,
    Imprime_com_dicas = 2,
    Controle_usuario = 3
};

typedef struct campoMinado{
    int linhas;
    int colunas;
    char **matrizCampoMinado;
    char **matrizCopia;
} CampoMinado;

char *lerLinha(FILE *fluxo, bool *possuiEOF);
void imprimirCampoMinado(CampoMinado *campoMinado, bool matrizCopia);
void matrizDicas(CampoMinado *campoMinado);
int verificandoBombasProximas(CampoMinado *campoMinado, int i, int j);
void dicaSelecionada(CampoMinado *campoMinado, int linha, int coluna, bool espacoVazio);
void verificandoEspacosVazios(CampoMinado *campoMinado, int linha, int coluna);

int main(){
    int opcao;
    scanf("%d", &opcao);

    bool possuiEOF = false;
    char *nomeArquivo = lerLinha(stdin, &possuiEOF);

    CampoMinado campoMinado;
    campoMinado.matrizCampoMinado = NULL;
    campoMinado.matrizCopia = NULL;
    campoMinado.linhas = 0;
    campoMinado.colunas = 0;

    FILE *arquivo = fopen(nomeArquivo, "r");
    do
    {
        campoMinado.matrizCampoMinado = realloc(campoMinado.matrizCampoMinado, (campoMinado.linhas + 1) * sizeof(char *));
        campoMinado.matrizCampoMinado[campoMinado.linhas] = lerLinha(arquivo, &possuiEOF);
        campoMinado.colunas = strlen(campoMinado.matrizCampoMinado[0]);

        campoMinado.linhas++;
    } while (!possuiEOF);
    campoMinado.matrizCopia = malloc(campoMinado.linhas * sizeof(char *));
    for (int i = 0; i < campoMinado.linhas; i++)
        campoMinado.matrizCopia[i] = malloc(campoMinado.colunas * sizeof(char));

    if (opcao == Imprime)
        imprimirCampoMinado(&campoMinado, false);
    else if (opcao == Imprime_com_dicas){
        matrizDicas(&campoMinado);
        imprimirCampoMinado(&campoMinado, false);
    }
    else if (opcao == Controle_usuario){
        int linha, coluna;
        scanf("%d %d", &linha, &coluna);
        matrizDicas(&campoMinado);
        if (campoMinado.matrizCampoMinado[linha][coluna] == '*'){
            imprimirCampoMinado(&campoMinado, false);
        }
        else if (campoMinado.matrizCampoMinado[linha][coluna] >= '1' && campoMinado.matrizCampoMinado[linha][coluna] <= '9'){
            dicaSelecionada(&campoMinado, linha, coluna, false);
            imprimirCampoMinado(&campoMinado, false);
        }
        else if (campoMinado.matrizCampoMinado[linha][coluna] == '.'){
            dicaSelecionada(&campoMinado, linha, coluna, true);
            verificandoEspacosVazios(&campoMinado, linha, coluna);
            imprimirCampoMinado(&campoMinado, true);
        }
    }
    fclose(arquivo);
    free(nomeArquivo);
    for (int i = 0; i < campoMinado.linhas; i++){
        free(campoMinado.matrizCampoMinado[i]);
        free(campoMinado.matrizCopia[i]);
    }
    free(campoMinado.matrizCampoMinado);
    free(campoMinado.matrizCopia);

    return 0;
}

char *lerLinha(FILE *fluxo, bool *possuiEOF){
    if (fluxo == stdin)
        scanf("%*[\n]s");

    char *string = malloc(sizeof(char));
    int caracteres = 0;
    int nmrMaxChar = 1;
    do{
        string[caracteres] = getc(fluxo);
        if (string[caracteres] == '\n' || string[caracteres] == EOF){
            if (fluxo != stdin){
                char proximoDoBuffer = getc(fluxo);
                if (proximoDoBuffer == EOF)
                    *possuiEOF = true;
                else
                    ungetc(proximoDoBuffer, fluxo);
            }
            string[caracteres] = '\0';
        }
        caracteres++;
        if (caracteres == nmrMaxChar){
            nmrMaxChar *= 2;
            string = realloc(string, (nmrMaxChar) * sizeof(char));
        }

    } while (string[caracteres - 1] != '\0');
    string = realloc(string, (caracteres + 1) * sizeof(char));

    return string;
}

void imprimirCampoMinado(CampoMinado *campoMinado, bool matrizCopia){
    for (int i = 0; i < campoMinado->linhas; i++){
        for (int j = 0; j < campoMinado->colunas; j++){
            if (matrizCopia)
                printf("%c", campoMinado->matrizCopia[i][j]);
            else
                printf("%c", campoMinado->matrizCampoMinado[i][j]);
        }
        printf("\n");
    }
}

// Esta funcao adiciona as dicas na matriz
void matrizDicas(CampoMinado *campoMinado){
    for (int i = 0; i < campoMinado->linhas; i++){
        for (int j = 0; j < campoMinado->colunas; j++){
            int quantidadeDeBombas = verificandoBombasProximas(campoMinado, i, j);

            if (quantidadeDeBombas > 0)
                campoMinado->matrizCampoMinado[i][j] = quantidadeDeBombas + '0';
        }
    }
}

// Esta funcao funciona ajudando a funcao matrizDicas a encontrar quantas bombas existem em sua adjacencia
int verificandoBombasProximas(CampoMinado *campoMinado, int i, int j){
    bool cima = (i == 0);
    bool baixo = (i == campoMinado->linhas - 1);
    bool esquerda = (j == 0);
    bool direita = (j == campoMinado->colunas - 1);

    int quantidadeDeBombas = 0;
    if (campoMinado->matrizCampoMinado[i][j] == '.'){
        if (!cima && !esquerda && campoMinado->matrizCampoMinado[i - 1][j - 1] == '*')
            quantidadeDeBombas++;

        if (!cima && campoMinado->matrizCampoMinado[i - 1][j] == '*')
            quantidadeDeBombas++;

        if (!cima && !direita && campoMinado->matrizCampoMinado[i - 1][j + 1] == '*')
            quantidadeDeBombas++;

        if (!esquerda && campoMinado->matrizCampoMinado[i][j - 1] == '*')
            quantidadeDeBombas++;

        if (!direita && campoMinado->matrizCampoMinado[i][j + 1] == '*')
            quantidadeDeBombas++;

        if (!baixo && !esquerda && campoMinado->matrizCampoMinado[i + 1][j - 1] == '*')
            quantidadeDeBombas++;

        if (!baixo && campoMinado->matrizCampoMinado[i + 1][j] == '*')
            quantidadeDeBombas++;

        if (!baixo && !direita && campoMinado->matrizCampoMinado[i + 1][j + 1] == '*')
            quantidadeDeBombas++;
    }
    return quantidadeDeBombas;
}

// Esta funcao adiciona X em todos os pontos, menos o ponto selecionado
// Caso o booleano espacoVazio seja verdadeiro, cria uma matriz copia inteiramente de X
void dicaSelecionada(CampoMinado *campoMinado, int linha, int coluna, bool espacoVazio){
    for (int i = 0; i < campoMinado->linhas; i++){
        for (int j = 0; j < campoMinado->colunas; j++){
            if (!(i == linha && j == coluna)){
                if (espacoVazio)
                    campoMinado->matrizCopia[i][j] = 'X';
                else
                    campoMinado->matrizCampoMinado[i][j] = 'X';
            }
        }
    }
}

// Esta e a funcao recursiva, verifica onde ela ja passou
// Lugares que são pontos são convertidos para P na matriz original, e numero para N, para, dessa forma, nao conta-los novamente
void verificandoEspacosVazios(CampoMinado *campoMinado, int linha, int coluna)
{
    bool cima = (linha == 0);
    bool baixo = (linha == campoMinado->linhas - 1);
    bool esquerda = (coluna == 0);
    bool direita = (coluna == campoMinado->colunas - 1);

    if (!cima){
        if (campoMinado->matrizCampoMinado[linha - 1][coluna] == '.'){
            campoMinado->matrizCopia[linha - 1][coluna] = campoMinado->matrizCampoMinado[linha - 1][coluna];
            campoMinado->matrizCampoMinado[linha - 1][coluna] = 'P';
            verificandoEspacosVazios(campoMinado, linha - 1, coluna);
        }
        else if (campoMinado->matrizCampoMinado[linha - 1][coluna] >= '0' && campoMinado->matrizCampoMinado[linha - 1][coluna] <= '9'){
            campoMinado->matrizCopia[linha - 1][coluna] = campoMinado->matrizCampoMinado[linha - 1][coluna];
            campoMinado->matrizCampoMinado[linha - 1][coluna] = 'N';
        }
    }
    if (!cima && !esquerda){
        if (campoMinado->matrizCampoMinado[linha - 1][coluna - 1] == '.'){
            campoMinado->matrizCopia[linha - 1][coluna - 1] = campoMinado->matrizCampoMinado[linha - 1][coluna - 1];
            campoMinado->matrizCampoMinado[linha - 1][coluna - 1] = 'P';
            verificandoEspacosVazios(campoMinado, linha - 1, coluna - 1);
        }
        else if (campoMinado->matrizCampoMinado[linha - 1][coluna - 1] >= '0' && campoMinado->matrizCampoMinado[linha - 1][coluna - 1] <= '9'){
            campoMinado->matrizCopia[linha - 1][coluna - 1] = campoMinado->matrizCampoMinado[linha - 1][coluna - 1];
            campoMinado->matrizCampoMinado[linha - 1][coluna - 1] = 'N';
        }
    }
    if (!cima && !direita){
        if (campoMinado->matrizCampoMinado[linha - 1][coluna + 1] == '.'){
            campoMinado->matrizCopia[linha - 1][coluna + 1] = campoMinado->matrizCampoMinado[linha - 1][coluna + 1];
            campoMinado->matrizCampoMinado[linha - 1][coluna + 1] = 'P';
            verificandoEspacosVazios(campoMinado, linha - 1, coluna + 1);
        }
        else if (campoMinado->matrizCampoMinado[linha - 1][coluna + 1] >= '0' && campoMinado->matrizCampoMinado[linha - 1][coluna + 1] <= '9'){
            campoMinado->matrizCopia[linha - 1][coluna + 1] = campoMinado->matrizCampoMinado[linha - 1][coluna + 1];
            campoMinado->matrizCampoMinado[linha - 1][coluna + 1] = 'N';
        }
    }
    if (!baixo){
        if (campoMinado->matrizCampoMinado[linha + 1][coluna] == '.'){
            campoMinado->matrizCopia[linha + 1][coluna] = campoMinado->matrizCampoMinado[linha + 1][coluna];
            campoMinado->matrizCampoMinado[linha + 1][coluna] = 'P';
            verificandoEspacosVazios(campoMinado, linha + 1, coluna);
        }
        else if (campoMinado->matrizCampoMinado[linha + 1][coluna] >= '0' && campoMinado->matrizCampoMinado[linha + 1][coluna] <= '9'){
            campoMinado->matrizCopia[linha + 1][coluna] = campoMinado->matrizCampoMinado[linha + 1][coluna];
            campoMinado->matrizCampoMinado[linha + 1][coluna] = 'N';
        }
    }
    if (!baixo && !esquerda){
        if (campoMinado->matrizCampoMinado[linha + 1][coluna - 1] == '.'){
            campoMinado->matrizCopia[linha + 1][coluna - 1] = campoMinado->matrizCampoMinado[linha + 1][coluna - 1];
            campoMinado->matrizCampoMinado[linha + 1][coluna - 1] = 'P';
            verificandoEspacosVazios(campoMinado, linha + 1, coluna - 1);
        }
        else if (campoMinado->matrizCampoMinado[linha + 1][coluna - 1] >= '0' && campoMinado->matrizCampoMinado[linha + 1][coluna - 1] <= '9'){
            campoMinado->matrizCopia[linha + 1][coluna - 1] = campoMinado->matrizCampoMinado[linha + 1][coluna - 1];
            campoMinado->matrizCampoMinado[linha + 1][coluna - 1] = 'N';
        }
    }
    if (!baixo && !direita){
        if (campoMinado->matrizCampoMinado[linha + 1][coluna + 1] == '.'){
            campoMinado->matrizCopia[linha + 1][coluna + 1] = campoMinado->matrizCampoMinado[linha + 1][coluna + 1];
            campoMinado->matrizCampoMinado[linha + 1][coluna + 1] = 'P';
            verificandoEspacosVazios(campoMinado, linha + 1, coluna + 1);
        }
        else if (campoMinado->matrizCampoMinado[linha + 1][coluna + 1] >= '0' && campoMinado->matrizCampoMinado[linha + 1][coluna + 1] <= '9'){
            campoMinado->matrizCopia[linha + 1][coluna + 1] = campoMinado->matrizCampoMinado[linha + 1][coluna + 1];
            campoMinado->matrizCampoMinado[linha + 1][coluna + 1] = 'N';
        }
    }
    if (!esquerda){
        if (campoMinado->matrizCampoMinado[linha][coluna - 1] == '.'){
            campoMinado->matrizCopia[linha][coluna - 1] = campoMinado->matrizCampoMinado[linha][coluna - 1];
            campoMinado->matrizCampoMinado[linha][coluna - 1] = 'P';
            verificandoEspacosVazios(campoMinado, linha, coluna - 1);
        }
        else if (campoMinado->matrizCampoMinado[linha][coluna - 1] >= '0' && campoMinado->matrizCampoMinado[linha][coluna - 1] <= '9'){
            campoMinado->matrizCopia[linha][coluna - 1] = campoMinado->matrizCampoMinado[linha][coluna - 1];
            campoMinado->matrizCampoMinado[linha][coluna - 1] = 'N';
        }
    }
    if (!direita){
        if (campoMinado->matrizCampoMinado[linha][coluna + 1] == '.'){
            campoMinado->matrizCopia[linha][coluna + 1] = campoMinado->matrizCampoMinado[linha][coluna + 1];
            campoMinado->matrizCampoMinado[linha][coluna + 1] = 'P';
            verificandoEspacosVazios(campoMinado, linha, coluna + 1);
        }
        else if (campoMinado->matrizCampoMinado[linha][coluna + 1] >= '0' && campoMinado->matrizCampoMinado[linha][coluna + 1] <= '9'){
            campoMinado->matrizCopia[linha][coluna + 1] = campoMinado->matrizCampoMinado[linha][coluna + 1];
            campoMinado->matrizCampoMinado[linha][coluna + 1] = 'N';
        }
    }
}