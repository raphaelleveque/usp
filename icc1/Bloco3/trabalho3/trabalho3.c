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
void **lerDesenhoAscII(FILE *f_arte_ptr, Desenho *desenhoascii);
void preencherCores(Desenho *desenhoascii, int x, int y, char cor);
void imprimirDesenho(Desenho *desenhoascii);
void enquadra_arte(char *nome_do_arquivo_da_arte, int altura_do_quadro, int largura_do_quadro);

int main()
{
    char *nomeDoArquivo;
    nomeDoArquivo = lerLinha();
    FILE *f_arte_ptr = fopen(nomeDoArquivo, "w");

    Desenho desenhoascii;
    lerDesenhoAscII(f_arte_ptr, &desenhoascii);

    int quantidadePreenchimentos;
    scanf("%d", &quantidadePreenchimentos);

    char cor;
    int x, y;
    printf("Desenho inicial: \n");
    imprimirDesenho(&desenhoascii);
    for (int i = 0; i < quantidadePreenchimentos; i++)
    {
        cor = getchar();
        scanf("%d %d", &x, &y);

        if (x <= desenhoascii.linhas && y <= desenhoascii.colunas)
        {
            desenhoascii.desenho[x][y] = cor;
        }
        preencherCores(&desenhoascii, x, y, cor);

        printf("Arte apos a etapa %d:\n", i);
        imprimirDesenho(&desenhoascii);
    }

    fclose(f_arte_ptr);
    enquadra_arte(nomeDoArquivo, desenhoascii.linhas, desenhoascii.colunas);

    for (int i = 0; i <= desenhoascii.linhas; i++)
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

void **lerDesenhoAscII(FILE *f_arte_ptr, Desenho *desenhoascii)
{
    desenhoascii->desenho = malloc(sizeof(char *));
    desenhoascii->desenho[0] = malloc(sizeof(char));

    int linhas = 0, colunas = 0;
    do
    {
        fscanf(f_arte_ptr, "%c", &desenhoascii->desenho[linhas][colunas]);
        if (desenhoascii->desenho[linhas][colunas] == EOF)
        {
            break;
        }
        
        if (desenhoascii->desenho[linhas][colunas] == '\n')
        {
            desenhoascii->desenho[linhas][colunas] = '\0';
            linhas++;

            desenhoascii->desenho = realloc(desenhoascii->desenho, linhas * sizeof(char *));
            for (int i = 0; i <= linhas; i++)
            {
                if (i != linhas)
                {
                    desenhoascii->desenho[i] = realloc(desenhoascii->desenho[i], colunas * sizeof(char));
                }
                else
                {
                    desenhoascii->desenho[i] = malloc(sizeof(char));
                }
            }

            colunas = 0;
        }
        else
        {
            colunas++;
            desenhoascii->desenho[linhas] = realloc(desenhoascii->desenho[linhas], (colunas + 1) * sizeof(char));
        }

    } while (1);

    desenhoascii->linhas = linhas;
    desenhoascii->colunas = colunas;
}

void preencherCores(Desenho *desenhoascii, int x, int y, char cor)
{
    bool cima = ((x - 1) >= 0);
    bool baixo = ((x + 1) <= desenhoascii->linhas);
    bool esquerda = ((y - 1) >= 0);
    bool direita = ((y + 1) <= desenhoascii->colunas);

    if (cima && desenhoascii->desenho[x - 1][y] == ' ')
    {
        desenhoascii->desenho[x - 1][y] = cor;
        preencherCores(desenhoascii, x - 1, y, cor);
    }
    if (baixo && desenhoascii->desenho[x + 1][y] == ' ')
    {
        desenhoascii->desenho[x + 1][y] = cor;
        preencherCores(desenhoascii, x - 1, y, cor);
    }
    if (esquerda && desenhoascii->desenho[x][y - 1] == ' ')
    {
        desenhoascii->desenho[x + 1][y] = cor;
        preencherCores(desenhoascii, x - 1, y, cor);
    }
    if (direita && desenhoascii->desenho[x][y + 1] == ' ')
    {
        desenhoascii->desenho[x + 1][y] = cor;
        preencherCores(desenhoascii, x - 1, y, cor);
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