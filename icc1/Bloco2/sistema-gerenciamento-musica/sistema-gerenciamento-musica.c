#include <stdio.h>
#include <stdlib.h>


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
} Playlist;



char * lerLinha();
void preencherPlaylist(Playlist *playlist1);


int main()
{
    Playlist playlist1;
    playlist1.numeroMusicas = 0;
    playlist1.nome = lerLinha();

    int comando;
    int i = 0;
    do
    {
        scanf("%d", &comando);
        fflush(stdin);
        if (comando == 1)
        {
            preencherPlaylist(&playlist1);
            printf("Musica %s adicionada com sucesso .", playlist1.conjuntoMusicas->nome);
            i++;
        }
        else if (comando == 2)
        {
            printf("Conjunto de Musicas\n");
        }
        else if (comando == 5)
        {
            break;
        }
        
        
    } while (comando != 5);
    
    i = 0;

    printf("%s\n", playlist1.nome);
    printf("%s\n", playlist1.conjuntoMusicas[i].nome);
    printf("%s\n", playlist1.conjuntoMusicas[i].artista);
    printf("%d", playlist1.conjuntoMusicas[i].tempo);




    return 0;
}



char * lerLinha()
{
    char *musicasOuPlaylists = malloc(sizeof(char));
    int caracteres = 0;
    int nmr_max_char = 1;
    do
    {
        scanf("%c", &musicasOuPlaylists[caracteres]);
        if (musicasOuPlaylists[caracteres] == '\n' || musicasOuPlaylists[caracteres] == EOF)
        {
            musicasOuPlaylists[caracteres] = '\0';
        }
        caracteres++;
        if (caracteres == nmr_max_char)
        {
            nmr_max_char *= 2;
            musicasOuPlaylists = realloc(musicasOuPlaylists, (nmr_max_char) * sizeof(char));
        }

    }while (musicasOuPlaylists[caracteres-1] != '\0');

    musicasOuPlaylists = realloc(musicasOuPlaylists, (caracteres + 1) * sizeof(char));

    return musicasOuPlaylists;
}



void preencherPlaylist(Playlist *playlist1)
{
    playlist1->conjuntoMusicas[playlist1->numeroMusicas].nome = lerLinha();
    playlist1->conjuntoMusicas[playlist1->numeroMusicas].artista = lerLinha();
    scanf("%d", playlist1->conjuntoMusicas[playlist1->numeroMusicas].tempo);

    playlist1->numeroMusicas++;
}
