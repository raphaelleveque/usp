#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct desenhoAscII
{
    int linhas;
    int colunas;
    char **desenho;
} Desenho;

char *lerLinha();
void lerDesenhoAscII(char *nomeDpArquivo, Desenho *desenhoascii);
void preencherCores(Desenho *desenhoascii, int x, int y, char cor, char corInicial);
void imprimirDesenho(Desenho *desenhoascii);
void transferirDesenhoParaArquivo(Desenho *desenhoAscII, char *nomeDoArquivo);
void enquadra_arte(char *nome_do_arquivo_da_arte, int altura_do_quadro, int largura_do_quadro);

int main()
{
    char *nomeDoArquivo;
    nomeDoArquivo = lerLinha();
    Desenho desenhoascii;
    lerDesenhoAscII(nomeDoArquivo, &desenhoascii);


    int quantidadePreenchimentos;
    scanf("%d", &quantidadePreenchimentos);

    char cor, corInicial;
    int x, y;
    printf("Arte inicial: \n");
    imprimirDesenho(&desenhoascii);
    for (int i = 0; i < quantidadePreenchimentos; i++)
    {
        scanf("%*[\n]");
        cor = getchar();
        scanf("%d %d", &x, &y);
        

        if (x < desenhoascii.linhas && y < desenhoascii.colunas)
        {
            corInicial = desenhoascii.desenho[x][y];
            desenhoascii.desenho[x][y] = cor;
        }
        preencherCores(&desenhoascii, x, y, cor, corInicial);

        printf("Arte apos a etapa %d:\n", i);
        imprimirDesenho(&desenhoascii);
    }

    transferirDesenhoParaArquivo(&desenhoascii, nomeDoArquivo);

    for (int i = 0; i < desenhoascii.linhas; i++)
    {
        free(desenhoascii.desenho[i]);
    }
    free(desenhoascii.desenho);
    free(nomeDoArquivo);

    return 0;
}

char *lerLinha()
{
    scanf("%*[\n\r]s");
    char *string = malloc(sizeof(char));
    int caracteres = 0;
    int nmrMaxChar = 1;
    do
    {
        scanf("%c", &string[caracteres]);
        if (string[caracteres] == '\n' || string[caracteres] == EOF)
        {
            string[caracteres] = '\0';
        }
        caracteres++;
        if (caracteres == nmrMaxChar)
        {
            nmrMaxChar *= 2;
            string = realloc(string, (nmrMaxChar) * sizeof(char));
        }

    } while (string[caracteres - 1] != '\0');

    string = realloc(string, (caracteres + 1) * sizeof(char));

    return string;
}

void lerDesenhoAscII(char *nomeDoArquivo, Desenho *desenhoascii)
{
    FILE *f_arte_ptr = fopen(nomeDoArquivo, "r");

    desenhoascii->desenho = malloc(sizeof(char *));
    desenhoascii->desenho[0] = malloc(sizeof(char));

    int linhas = 0, colunas = 0;
    while (fscanf(f_arte_ptr, "%c", &desenhoascii->desenho[linhas][colunas]) != EOF)
    {
        colunas++;
        if (desenhoascii->desenho[linhas][colunas - 1] == '\n')
        {
            desenhoascii->desenho[linhas][colunas - 1] = '\0';
            linhas++;

            desenhoascii->desenho = realloc(desenhoascii->desenho, (linhas + 1) * sizeof(char *));
            for (int i = 0; i <= linhas; i++)
            {
                if (i != linhas)
                {
                    desenhoascii->desenho[i] = realloc(desenhoascii->desenho[i], colunas * sizeof(char));
                }
                else
                {
                    desenhoascii->desenho[i] = malloc(colunas * sizeof(char));
                }
            }

            colunas = 0;
            continue;
        }

        if(linhas == 0)
        {
            desenhoascii->desenho[linhas] = realloc(desenhoascii->desenho[linhas], (colunas + 1) * sizeof(char));
        }
    } 

    desenhoascii->desenho[linhas][colunas] = '\0';
    desenhoascii->linhas = linhas + 1;
    desenhoascii->colunas = colunas;

    fclose(f_arte_ptr);
}

void preencherCores(Desenho *desenhoascii, int x, int y, char cor, char corInicial)
{
    bool cima = ((x - 1) >= 0);
    bool baixo = ((x + 1) < desenhoascii->linhas);
    bool esquerda = ((y - 1) >= 0);
    bool direita = ((y + 1) < desenhoascii->colunas);

    if (cima && desenhoascii->desenho[x - 1][y] == corInicial)
    {
        desenhoascii->desenho[x - 1][y] = cor;
        preencherCores(desenhoascii, x - 1, y, cor, corInicial);
    }
    if (baixo && desenhoascii->desenho[x + 1][y] == corInicial)
    {
        desenhoascii->desenho[x + 1][y] = cor;
        preencherCores(desenhoascii, x + 1, y, cor, corInicial);
    }
    if (esquerda && desenhoascii->desenho[x][y - 1] == corInicial)
    {
        desenhoascii->desenho[x][y - 1] = cor;
        preencherCores(desenhoascii, x, y - 1, cor, corInicial);
    }
    if (direita && desenhoascii->desenho[x][y + 1] == corInicial)
    {
        desenhoascii->desenho[x][y + 1] = cor;
        preencherCores(desenhoascii, x, y + 1, cor, corInicial);
    }
}

void imprimirDesenho(Desenho *desenhoascii)
{
    for (int i = 0; i < desenhoascii->linhas; i++)
    {
        for (int j = 0; j < desenhoascii->colunas; j++)
        {
            printf("%c", desenhoascii->desenho[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void transferirDesenhoParaArquivo(Desenho *desenhoascii, char *nomeDoArquivo)
{
    FILE *f_arte_ptr = fopen(nomeDoArquivo, "w");
    for (int i = 0; i < desenhoascii->linhas; i++)
    {
        if (i == desenhoascii->linhas - 1)
        {
            fprintf(f_arte_ptr, "%s", desenhoascii->desenho[i]);
        }
        else
        {
            fprintf(f_arte_ptr, "%s\n", desenhoascii->desenho[i]);
        }
        
    }
    fclose(f_arte_ptr);
    printf("Arte enquadrada: \n");
    enquadra_arte(nomeDoArquivo, desenhoascii->linhas, desenhoascii->colunas);
}

void enquadra_arte(char *nome_do_arquivo_da_arte, int altura_do_quadro, int largura_do_quadro)
{
    FILE *f_arte_ptr = fopen(nome_do_arquivo_da_arte, "r");
    if (f_arte_ptr == NULL)
    {
        printf(
            "Erro na abertura do arquivo, "
            "Você esqueceu de fechar o arquivo antes? "
            "Ou deu free na string com o nome sem querer?\n");

        exit(EXIT_FAILURE);
    }

    int qtd_espc_comeco;
    const char *apoio;
    if (largura_do_quadro % 2 == 0)
    {
        qtd_espc_comeco = largura_do_quadro / 2;
        apoio = "/\\";
    }
    else
    {
        qtd_espc_comeco = largura_do_quadro / 2 + 1;
        apoio = "Ʌ";
    }

    for (int i = 0; i < qtd_espc_comeco; i++)
        printf(" ");
    printf("%s\n", apoio);

    printf("╭");
    for (int i = 0; i < largura_do_quadro; i++)
        printf("—");
    printf("╮\n");

    for (int i = 0; i < altura_do_quadro; i++)
    {
        printf("|");
        for (int j = 0; j < largura_do_quadro; j++)
        {
            char pixel_atual = fgetc(f_arte_ptr);
            printf("%c", pixel_atual);
        }
        printf("|");

        char quebra = fgetc(f_arte_ptr);
        if (quebra != EOF)
            printf("%c", quebra);
    };
    fclose(f_arte_ptr);

    printf("\n╰");
    for (int i = 0; i < largura_do_quadro; i++)
        printf("—");
    printf("╯\n");
}