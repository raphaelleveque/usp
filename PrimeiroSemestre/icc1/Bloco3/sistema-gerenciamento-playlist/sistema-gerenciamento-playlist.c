// Raphael Leveque 12542522
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum comandos
{
    Adicionar = 1,
    Listar = 2,
    Avancar = 3,
    Retroceder = 4,
    SalvarPlaylist = 5,
    CarregarPlaylist = 6
};

typedef struct musica
{
    char *nome;
    char *artista;
    int tempo;
} Musica;

typedef struct playlist
{
    char *nome;
    int numeroMusicas;
    Musica *conjuntoMusicas;
    Musica *musicaAtual;
} Playlist;

char *lerLinha();
void preencherPlaylist(Playlist *playlist);
void salvandoPlaylist(Playlist *playlist);
void binaryToNum(char *binFilename);
Playlist *carregandoPlaylist(Playlist *playlist);

int main()
{
    Playlist *playlist = malloc(sizeof(Playlist));
    playlist->numeroMusicas = 0;
    playlist->musicaAtual = NULL;
    playlist->conjuntoMusicas = NULL;

    playlist->nome = lerLinha();

    int comando;
    do
    {
        scanf("%d", &comando);
        if (comando == Adicionar)
        {
            if (playlist->numeroMusicas == 15)
            {
                printf("Playlist cheia!\n");
                continue;
            }

            playlist->numeroMusicas++;

            int i;
            for (i = 0; i < playlist->numeroMusicas; i++)
            {
                if (playlist->musicaAtual == &playlist->conjuntoMusicas[i])
                {
                    break;
                }
            }
            playlist->conjuntoMusicas = realloc(playlist->conjuntoMusicas, playlist->numeroMusicas * sizeof(Musica));
            playlist->musicaAtual = &playlist->conjuntoMusicas[i];

            preencherPlaylist(playlist);
        }
        else if (comando == Listar)
        {
            printf("---- Playlist: %s ----\n", playlist->nome);
            printf("Total de musicas: %d\n\n", playlist->numeroMusicas);

            for (int i = 0; i < playlist->numeroMusicas; i++)
            {
                if (playlist->musicaAtual == &playlist->conjuntoMusicas[i])
                {
                    printf("=== NOW PLAYING ===\n");
                }
                printf("(%d). '%s'\n", i + 1, playlist->conjuntoMusicas[i].nome);
                printf("Artista: %s\n", playlist->conjuntoMusicas[i].artista);
                printf("Duracao: %d segundos\n\n", playlist->conjuntoMusicas[i].tempo);
            }
        }
        else if (comando == Avancar)
        {
            playlist->musicaAtual += 1;
        }
        else if (comando == Retroceder)
        {
            playlist->musicaAtual -= 1;
        }
        else if (comando == SalvarPlaylist)
        {
            salvandoPlaylist(playlist);
        }
        else if (comando == CarregarPlaylist)
        {
            playlist = carregandoPlaylist(playlist);
            playlist->musicaAtual = playlist->conjuntoMusicas;
        }

        else
        {
            free(playlist->nome);
            for (int i = 0; i < playlist->numeroMusicas; ++i)
            {
                free(playlist->conjuntoMusicas[i].artista);
                free(playlist->conjuntoMusicas[i].nome);
            }
            free(playlist->conjuntoMusicas);
            break;
        }

    } while (comando != 7);

    free(playlist);

    return 0;
}



char *lerLinha()
{
    scanf("%*[\n\r]s");
    char *musicasOuPlaylists = malloc(sizeof(char));
    int caracteres = 0;
    int nmrMaxChar = 1;
    do
    {
        scanf("%c", &musicasOuPlaylists[caracteres]);
        if (musicasOuPlaylists[caracteres] == '\n' || musicasOuPlaylists[caracteres] == EOF)
        {
            musicasOuPlaylists[caracteres] = '\0';
        }
        caracteres++;
        if (caracteres == nmrMaxChar)
        {
            nmrMaxChar *= 2;
            musicasOuPlaylists = realloc(musicasOuPlaylists, (nmrMaxChar) * sizeof(char));
        }

    } while (musicasOuPlaylists[caracteres - 1] != '\0');

    musicasOuPlaylists = realloc(musicasOuPlaylists, (caracteres + 1) * sizeof(char));

    return musicasOuPlaylists;
}


void preencherPlaylist(Playlist *playlist)
{
    playlist->conjuntoMusicas[playlist->numeroMusicas - 1].nome = lerLinha();
    playlist->conjuntoMusicas[playlist->numeroMusicas - 1].artista = lerLinha();
    scanf("%d", &playlist->conjuntoMusicas[playlist->numeroMusicas - 1].tempo);
    printf("Musica %s de %s adicionada com sucesso.\n", playlist->conjuntoMusicas[playlist->numeroMusicas - 1].nome,
           playlist->conjuntoMusicas[playlist->numeroMusicas - 1].artista);
}


void salvandoPlaylist(Playlist *playlist)
{
    char *nomeArquivo = NULL;
    nomeArquivo = lerLinha();
    FILE *arquivoPlaylist = fopen(nomeArquivo, "wb");

    int tamanhoNomePlaylist = strlen(playlist->nome);
    fwrite(&tamanhoNomePlaylist, sizeof(int), 1, arquivoPlaylist);
    fwrite(playlist->nome, sizeof(char), tamanhoNomePlaylist, arquivoPlaylist);
    fwrite(&playlist->numeroMusicas, sizeof(int), 1, arquivoPlaylist);

    for (int i = 0; i < playlist->numeroMusicas; i++)
    {
        int tamanhoNomeMusica = strlen(playlist->conjuntoMusicas[i].nome);
        fwrite(&tamanhoNomeMusica, sizeof(int), 1, arquivoPlaylist);
        fwrite(playlist->conjuntoMusicas[i].nome, sizeof(char), tamanhoNomeMusica, arquivoPlaylist);

        int tamanhoNomeArtista = strlen(playlist->conjuntoMusicas[i].artista);
        fwrite(&tamanhoNomeArtista, sizeof(int), 1, arquivoPlaylist);
        fwrite(playlist->conjuntoMusicas[i].artista, sizeof(char), tamanhoNomeArtista, arquivoPlaylist);

        fwrite(&playlist->conjuntoMusicas[i].tempo, sizeof(int), 1, arquivoPlaylist);
    }

    printf("Playlist %s salva com sucesso.\n", nomeArquivo);

    fclose(arquivoPlaylist);
    binaryToNum(nomeArquivo);

    free(nomeArquivo);
}


Playlist *carregandoPlaylist(Playlist *playlist)
{
    char *nomeArquivo = NULL;
    nomeArquivo = lerLinha();
    FILE *arquivoPlaylist = fopen(nomeArquivo, "rb");
    if (!arquivoPlaylist){
		printf("Arquivo %s nao existe.\n", nomeArquivo);
        free(nomeArquivo);
		exit(1);
	}

    free(playlist->nome);
    playlist->nome = NULL;
    for (int i = 0; i < playlist->numeroMusicas; ++i)
    {
        free(playlist->conjuntoMusicas[i].artista);
        free(playlist->conjuntoMusicas[i].nome);
    }
    free(playlist->conjuntoMusicas);

    playlist->conjuntoMusicas = NULL;

    int tamanhoNomePlaylist = 0;
    fread(&tamanhoNomePlaylist, sizeof(int), 1, arquivoPlaylist);

    playlist->nome = malloc((tamanhoNomePlaylist + 1) * sizeof(char));
    fread(playlist->nome, sizeof(char), tamanhoNomePlaylist, arquivoPlaylist);
    playlist->nome[tamanhoNomePlaylist] = '\0';
    fread(&playlist->numeroMusicas, sizeof(int), 1, arquivoPlaylist);


    playlist->conjuntoMusicas = malloc(playlist->numeroMusicas * sizeof(Musica));

    for (int i = 0; i < playlist->numeroMusicas; i++)
    {
        int tamanhoNomeMusica;
        fread(&tamanhoNomeMusica, sizeof(int), 1, arquivoPlaylist);
        playlist->conjuntoMusicas[i].nome = malloc((tamanhoNomeMusica + 1) * sizeof(char));
        fread(playlist->conjuntoMusicas[i].nome, sizeof(char), tamanhoNomeMusica, arquivoPlaylist);
        playlist->conjuntoMusicas[i].nome[tamanhoNomeMusica] = '\0';

        
        int tamanhoNomeArtista;
        fread(&tamanhoNomeArtista, sizeof(int), 1, arquivoPlaylist);
        playlist->conjuntoMusicas[i].artista = malloc((tamanhoNomeArtista + 1) * sizeof(char));
        fread(playlist->conjuntoMusicas[i].artista, sizeof(char), tamanhoNomeArtista, arquivoPlaylist);
        playlist->conjuntoMusicas[i].artista[tamanhoNomeArtista] = '\0';

        fread(&playlist->conjuntoMusicas[i].tempo, sizeof(int), 1, arquivoPlaylist);
    }


    fclose(arquivoPlaylist);
    
    printf("Playlist %s carregada com sucesso.\n", nomeArquivo);
    binaryToNum(nomeArquivo);

    free(nomeArquivo);

    return playlist;
}


void binaryToNum(char *binFilename)
{
    FILE *fp = fopen(binFilename, "rb");

    double binValue = 0;
    double accumulator = 0.01;
    char ch;
    while (fread(&ch, sizeof(char), 1, fp))
    {
        binValue += (double)ch * accumulator;
        accumulator += 0.01;
    }

    fclose(fp);
    printf("%lf\n", binValue);
}
