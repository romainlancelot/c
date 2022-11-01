#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 2 tableaux
// 1 tableau de chaines de caractere -> sauvegarde les noms -> char ** 
// 1 tableud de int -> sauvegarde les numéros -> int *

char * alloxStr(const char * texte) {
    char * res = NULL;
    if((res = (char *)malloc((1 + strlen(texte)) * sizeof(char))) == NULL) {
        return NULL;
    }
    strcpy(res, texte);
    return res;
}

int rechercher(const char * texte, char ** noms, int taille) {
    int i;
    for(i = 0; i < taille; ++i) {
        if(strcmp(texte, noms[i]) == 0) {
            return 1;
        }
    }
    return -1; 
}

int main() {
    char ** noms = NULL;
    long * numeros = NULL;
    char tmpNom[50];
    int tmpNumero;
    int taille = 0, capacite = 0;

    for(;;) {
        printf("Nom (None pour arrêter) : ");
        scanf("%s", tmpNom);
        if(strcmp(tmpNom, "None") == 0) {
            break;
        }
        printf("Numeros : ");
        scanf("%d", &tmpNumero);
    }
    if(taille >= capacite) {
        capacite = capacite * 2 + 10;
        if((noms = (char **)realloc(noms, capacite * sizeof(char *))) == NULL) {
            printf("Erreur allocation liste des noms\n");
            exit(EXIT_FAILURE);
        }
        if((numeros = (long *)realloc(numeros, capacite * sizeof(long))) == NULL) {
            printf("Erreur allocation liste des numeros\n");
            exit(EXIT_FAILURE);
        }
        numeros[taille = tmpNumero];
        ++taille;
    }

    exit(EXIT_SUCCESS);
}