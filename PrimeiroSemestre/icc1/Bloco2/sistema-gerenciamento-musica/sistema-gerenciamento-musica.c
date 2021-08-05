#include <stdio.h>
#include <stdlib.h>

enum comandos
{
    Adicionar = 1,
    Listar = 2,
    Avancar = 3,
    Retroceder = 4
};


typedef struct musica
{
    char * nome;
    char * artista;
    int tempo;
} Musica;

typedef struct playlist
{
    char * nome;
    int numeroMusicas;
    Musica conjuntoMusicas[15];
    Musica * musicaAtual;
} Playlist;



char * lerLinha();
void preencherPlaylist(Playlist *playlist1);


int main()
{
    Playlist playlist1;
    playlist1.numeroMusicas = 0;
    playlist1.musicaAtual = NULL;
    playlist1.nome = lerLinha();

    int comando;
    do
    {
        scanf("%d", &comando);
        if (comando == Adicionar)
        {
            if (playlist1.numeroMusicas == 15)
            {
                printf("Playlist cheia!\n");
                continue;
            }
            
            preencherPlaylist(&playlist1);
            printf("Musica %s de %s adicionada com sucesso.\n", playlist1.conjuntoMusicas[playlist1.numeroMusicas - 1].nome,
                                                                playlist1.conjuntoMusicas[playlist1.numeroMusicas - 1].artista);
            if (playlist1.musicaAtual == NULL)
            {
                playlist1.musicaAtual = &playlist1.conjuntoMusicas[0];
            }
        }
        else if (comando == Listar)
        {
            printf("---- Playlist: %s ----\n", playlist1.nome);
            printf("Total de musicas: %d\n\n", playlist1.numeroMusicas);

            for (int i = 0; i < playlist1.numeroMusicas; i++)
            {
                if (playlist1.musicaAtual == &playlist1.conjuntoMusicas[i])
                {
                    printf("=== NOW PLAYING ===\n");
                }
                printf("(%d). '%s'\n", i + 1, playlist1.conjuntoMusicas[i].nome);
                printf("Artista: %s\n", playlist1.conjuntoMusicas[i].artista);
                printf("Duracao: %d segundos\n\n", playlist1.conjuntoMusicas[i].tempo);
            }
        }
        else if (comando == Avancar)
        {
            playlist1.musicaAtual += 1;
        }
        else if (comando == Retroceder)
        {
            playlist1.musicaAtual -= 1;
        }
        else
        {
            free(playlist1.nome);
            for (int i = 0; i < playlist1.numeroMusicas; ++i)
            {
                free(playlist1.conjuntoMusicas[i].artista);
                free(playlist1.conjuntoMusicas[i].nome);                
            }
            break;
        }
        
    } while (comando != 5);



    return 0;
}



char * lerLinha()
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

    }while (musicasOuPlaylists[caracteres-1] != '\0');

    musicasOuPlaylists = realloc(musicasOuPlaylists, (caracteres + 1) * sizeof(char));

    return musicasOuPlaylists;
}



void preencherPlaylist(Playlist *playlist1)
{
    playlist1->conjuntoMusicas[playlist1->numeroMusicas].nome = lerLinha();
    playlist1->conjuntoMusicas[playlist1->numeroMusicas].artista = lerLinha();
    scanf("%d", &playlist1->conjuntoMusicas[playlist1->numeroMusicas].tempo);

    playlist1->numeroMusicas++;
}
