
#include <stdio.h>
#include <stdlib.h>

struct playlist;
struct musicas;

struct playlist
{
    char * nome;
    int numeroMusicas;
    struct musicas ** conjuntoMusicas;
};

struct musicas
{
    char * nome;
    char * artista;
    int tempo;
};


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


int main()
{

    struct playlist playlist1;
    playlist1.nome = lerLinha();

    struct musicas musica1;
    int comando;
    int i = 0;
    do
    {
        scanf("%d", &comando);
        fflush(stdin);
        if (comando == 1)
        {
            musica1.nome = lerLinha();
            musica1.artista = lerLinha();
            scanf("%d", &musica1.tempo);
            printf("Musica %s adicionada com sucesso .", musica1.nome);
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
    printf("%s\n", musica1.nome);
    printf("%s\n", musica1.artista);
    printf("%d", musica1.tempo);




    return 0;
}
