#include <stdio.h>
#include <stdlib.h>

typedef struct attributes
{
    int hp;
    int attack;
    int defense;
    int specialAttack;
    int specialDefense;
    int speed;
} Attributes;

typedef struct attacks
{
    char attackName[20];
    int basePower;
    double accuracy;
    char class;
} Attacks;

typedef struct pokedex
{
    char name[50];
    char primaryType[20];
    char secundaryType[20];
    Attributes attributeList;
    Attacks attackList[4];
} Pokedex;

void addNewPokemon(Pokedex *pokemon);
void addAttack(Pokedex *pokemon);
void printPokemon(Pokedex *pokemon);
void printPokemonAttack(Pokedex *pokemon);

int main()
{
    Pokedex *pokemons = malloc(sizeof(Pokedex));

    int command, numberOfPokemons = 0;

    do
    {
        scanf("%d", &command);
        switch (command)
        {
        case 1:
            addNewPokemon(&pokemons[numberOfPokemons]);
            numberOfPokemons++;
            pokemons = realloc(pokemons, (numberOfPokemons + 1) * sizeof(Pokedex));
            break;

        case 2:
            addAttack(pokemons);
            break;

        case 3:
            printPokemon(pokemons);
            break;
        
        case 4:
            printPokemonAttack(pokemons);
            break;
        }
    } while (command != 0);

    free(pokemons);
    return 0;
}


void addNewPokemon(Pokedex *pokemon)
{
    scanf("%s", pokemon->name);
    scanf("%s", pokemon->primaryType);
    scanf("%s", pokemon->secundaryType);
    scanf("%d", &pokemon->attributeList.hp);
    scanf("%d", &pokemon->attributeList.attack);
    scanf("%d", &pokemon->attributeList.defense);
    scanf("%d", &pokemon->attributeList.specialAttack);
    scanf("%d", &pokemon->attributeList.specialDefense);
    scanf("%d", &pokemon->attributeList.speed);
}

void addAttack(Pokedex *pokemon)
{
    int pokemonIndex;
    scanf("%d", &pokemonIndex);
    int attackIndex;
    scanf("%d", &attackIndex);

    scanf("%s", pokemon[pokemonIndex].attackList[attackIndex].attackName);
    scanf("%d", &pokemon[pokemonIndex].attackList[attackIndex].basePower);
    scanf("%lf", &pokemon[pokemonIndex].attackList[attackIndex].accuracy);
    scanf("%*[\n]");
    scanf("%c", &pokemon[pokemonIndex].attackList[attackIndex].class);
}

void printPokemon(Pokedex *pokemon)
{
    int pokemonIndex;
    scanf("%d", &pokemonIndex);

    printf("Nome do Pokemon: %s\n", pokemon[pokemonIndex].name);
    printf("Tipo primario: %s\n", pokemon[pokemonIndex].primaryType);
    printf("Tipo secundario: %s\n", pokemon[pokemonIndex].secundaryType);
    printf("Status:\n");
    printf("\tHP: %d\n", pokemon[pokemonIndex].attributeList.hp);
    printf("\tAtaque: %d\n", pokemon[pokemonIndex].attributeList.attack);
    printf("\tDefesa: %d\n", pokemon[pokemonIndex].attributeList.defense);
    printf("\tAtaque Especial: %d\n", pokemon[pokemonIndex].attributeList.specialAttack);
    printf("\tDefesa Especial: %d\n", pokemon[pokemonIndex].attributeList.specialDefense);
    printf("\tVelocidade: %d\n\n", pokemon[pokemonIndex].attributeList.speed);
}

void printPokemonAttack(Pokedex *pokemon)
{
    int pokemonIndex;
    scanf("%d", &pokemonIndex);
    int attackIndex;
    scanf("%d", &attackIndex);

    printf("Nome do Ataque: %s\n", pokemon[pokemonIndex].attackList[attackIndex].attackName);
    printf("Poder base: %d\n", pokemon[pokemonIndex].attackList[attackIndex].basePower);
    printf("Acuracia: %lf\n", pokemon[pokemonIndex].attackList[attackIndex].accuracy);
    printf("Classe: %c\n\n", pokemon[pokemonIndex].attackList[attackIndex].class);
}