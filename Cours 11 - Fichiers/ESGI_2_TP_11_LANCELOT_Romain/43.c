// Romain LANCELOT - 2ESGI A4

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// fonction correction de l'année passée
void vigenere(char texte[], char cle[], int sign, char message[]) {
	int i, j;
	int value;
	int offset;
	for(i = 0, j = 0; texte[i] != '\0'; ++i) {
		if(texte[i] >= 'A' && texte[i] <= 'Z') {
			value = texte[i] - 'A';
			message[i] = 'A';
		} else if(texte[i] >= 'a' && texte[i] <= 'z') {
			value = texte[i] - 'a';
			message[i] = 'a';
		} else {
			message[i] = texte[i];
			continue;
		}
		if(cle[j] >= 'A' && cle[j] <= 'Z') {
			offset = cle[j] - 'A';
		} else if(cle[j] >= 'a' && cle[j] <= 'z') {
			offset = cle[j] - 'a';
		}
		value = ((value + sign * offset) % 26 + 26) % 26;
		message[i] += value;
		j = (j + 1) % strlen(cle);
	}
	message[i] = '\0';
}

int main(int argc, char * argv[]) {
    if(argc <= 1) {
        printf("Attendu :\n\t%s [FICHIER MESSAGE] [CLE]\n\t%s [FICHIER MESSAGE] [CLE] decode", argv[0], argv[0]);
        exit(EXIT_FAILURE);
    }

    char * message = NULL;
    char * cle = NULL;
    int decode = 0;

    if(argc == 4) {
        if(strcmp(argv[3], "decode") == 0) {
            decode = 1;
        } else {
            printf("Attendu :\n\t%s [FICHIER MESSAGE] [CLE]\n\t%s [FICHIER MESSAGE] [CLE] decode", argv[0], argv[0]);
            exit(EXIT_FAILURE);
        }
    }

    FILE * input = fopen(argv[1], "r");
    if(input == NULL) {
        printf("Erreur d'ouverture du fichier %s", argv[1]);
        exit(EXIT_FAILURE);
    }

    fseek(input, 0, SEEK_END);
    int taille = ftell(input);
    rewind(input);

    message = malloc(taille * sizeof(char));
    if(message == NULL) {
        printf("Erreur d'allocation de mémoire");
        exit(EXIT_FAILURE);
    }

    fread(message, sizeof(char), taille, input);
    fclose(input);

    cle = argv[2];

    char * resultat = malloc(taille * sizeof(char));
    if(resultat == NULL) {
        printf("Erreur d'allocation de mémoire");
        exit(EXIT_FAILURE);
    }

    vigenere(message, cle, decode ? -1 : 1, resultat);

    printf("%s", resultat);

    free(message);
    exit(EXIT_SUCCESS);
}