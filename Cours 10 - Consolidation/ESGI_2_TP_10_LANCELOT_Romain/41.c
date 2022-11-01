#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ajouter nom à noms :
// (char **)malloc(sizeof(char *) * taille));
// noms[i] = (char*)malloc(sizeof(char) * (strlen(tmpNom) + 1));
// strcpy(noms[i], tmpNom);

int main() {
    char ** noms;
    int * numeros;
    char tmpNom[50];
    int tmpNumero, taille = 0, i = 0, success;
    
    do {
        printf("Nom (None pour arrêter) : ");
        scanf("%s", tmpNom);
        if(strcmp(tmpNom, "None") == 0) {
            break;
        }
        printf("Numéros : ");
        scanf("%d", &tmpNumero);

        if(taille == 0) {
            noms = (char **)malloc(sizeof(char *));
            numeros = (int *)malloc(sizeof(int));
        } else {
            noms = (char **)realloc(noms, sizeof(char *) * (taille + 1));
            numeros = (int *)realloc(numeros, sizeof(int) * (taille + 1));
        } 
        noms[i] = (char*)malloc(sizeof(char) * (strlen(tmpNom) + 1));
        strcpy(noms[i], tmpNom);
        numeros[i] = tmpNumero;
        taille++;
        i++;       
    } while(1);

    // afficher la liste :
    // for(int j = 0; j < i; j++) {
    //     printf("\nNom    : %s\nNumero : %d\n", noms[j], numeros[j]);
    // }

    do {
        printf("Nom à rechercher (None pour arrêter) :\n>>> ");
        scanf("%s", tmpNom);
        if(strcmp(tmpNom, "None") == 0) {
            break;
        }
        success = 0;
        for(int j = 0; j < i; j++) {
            if(strcmp(noms[j], tmpNom) == 0) {
                printf("Le numéro de \"%s\" est %d\n", tmpNom, numeros[j]);
                success = 1;
                break;
            }
        }
        if(success != 1) {
            printf("\"%s\" non trouvé.\n", tmpNom);
        }
    } while(1);

    free(noms);
    noms = NULL;
    free(numeros);
    numeros = NULL;
    
    exit(EXIT_SUCCESS);
}