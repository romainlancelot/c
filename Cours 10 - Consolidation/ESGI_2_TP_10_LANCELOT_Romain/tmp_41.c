#include <stdio.h>
#include <stdlib.h>

int main() {
    char ** noms = NULL;
    int * numeros = NULL;
    
    char tmpNom[50];
    int tmpNumero;

    int taille = 0, capacite = 0;

    do {
        printf("Nom (None pour arrêter) : ");
        scanf("%s", tmpNom);
        if(strcmp(tmpNom, "None") == 0) {
            break;
        }
        printf("Numeros : ");
        scanf("%d", &tmpNumero);

        if(taille >= capacite) {
            capacite = capacite * 2 + 10;
            if((noms = (char **)realloc(noms, capacite * sizeof(char *))) == NULL) {
                printf("Erreur allocation liste des noms");
                exit(EXIT_FAILURE);
            }
            if((numeros = (int *)realloc(numeros, capacite * sizeof(int))) == NULL) {
                printf("Erreur allocation liste des numeros");
                exit(EXIT_FAILURE);
            }
        }
        numeros[taille] = tmpNumero;
        noms[taille] = alloxStr(tmpNom);
        ++taille;
        

    } while(1);


    exit(EXIT_SUCCESS);
}