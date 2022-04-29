#include "funcoesAuxiliares.h"
#include <string.h>

void read_line(char* string){
    char c = 0;
    do{
        c = (char) getchar();

    } while(c == '\n' || c == '\r');

    int i = 0;

    do{
        string[i] = c;
        i++;
        c = getchar();
    } while(c != '\n' && c != '\r' && c != EOF);

    string[i]  = '\0';
}

void binary_on_screen(const char *file_name) { /* Você não precisa entender o código dessa função. */

	/* Use essa função para comparação no run.codes. Lembre-se de ter fechado (fclose) o arquivo anteriormente.
	*  Ela vai abrir de novo para leitura e depois fechar (você não vai perder pontos por isso se usar ela). */

	unsigned long i, cs;
	unsigned char *mb;
	size_t fl;
	FILE *fs;
	if(file_name == NULL || !(fs = fopen(file_name, "rb"))) {
		fprintf(stderr, "ERRO AO ESCREVER O BINARIO NA TELA (função binarioNaTela): não foi possível abrir o arquivo que me passou para leitura. Ele existe e você tá passando o nome certo? Você lembrou de fechar ele com fclose depois de usar?\n");
		return;
	}
	fseek(fs, 0, SEEK_END);
	fl = ftell(fs);
	fseek(fs, 0, SEEK_SET);
	mb = (unsigned char *) malloc(fl);
	fread(mb, 1, fl, fs);

	cs = 0;
	for(i = 0; i < fl; i++) {
		cs += (unsigned long) mb[i];
	}
	printf("%lf\n", (cs / (double) 100));
	free(mb);
	fclose(fs);
}

// Essa função serve para substituir o lixo de memória do resto do registro com '$'
void fill_with_dollars(FILE *fp, int len) {
    char *garbage = malloc(len * sizeof(char));
    for (int i = 0; i < len; i++)
        garbage[i] = '$';
    
    fwrite(garbage, sizeof(char), len, fp);
    free(garbage);
}


// Essa função escreve no arquivo os dados da pessoa, um por um
void write_in_file(FILE *fp, Person_t *person) {
    fwrite(person->first_name, sizeof(char), strlen(person->first_name) + 1, fp);
    fill_with_dollars(fp, 51 - (strlen(person->first_name) + 1));

    fwrite(person->last_name, sizeof(char), strlen(person->last_name) + 1, fp);
    fill_with_dollars(fp, 51 - (strlen(person->last_name) + 1));

    fwrite(person->email, sizeof(char), strlen(person->email) + 1, fp);
    fill_with_dollars(fp, 81 - (strlen(person->email) + 1));

    fwrite(person->nationality, sizeof(char), strlen(person->nationality) + 1, fp);
    fill_with_dollars(fp, 51 - (strlen(person->nationality) + 1)); 

    fwrite(&person->age, sizeof(int), 1, fp);
}


char* read_from_file(FILE *fp, int len, char *string) {
    if(fread(string, sizeof(char), len, fp) == 0 ) {
        printf("Não foi possível ler um campo do registro\n");
        exit(EXIT_SUCCESS);
    }
    return string;
}


void print_person(const Person_t* person) {
    printf("Firstname: %s\n", person->first_name);
    printf("Lastname: %s\n", person->last_name);
    printf("Email: %s\n", person->email);
    printf("Nationality: %s\n", person->nationality);
    printf("Age: %d\n\n", person->age);
}

