// Romain LANCELOT - 2ESGI A4

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char * argv[]) {
    if(argc < 3) {
        printf("Attendu : %s -o [FICHIER]\n\t%s -i [FICHIER]", argv[0], argv[0]);
        exit(EXIT_FAILURE);
    }

    char ** noms;
    int * numeros;
    char tmpNom[50], nomCherche[50];
    int tmpNumero, taille = 0, i = 0, success;
    
    if(strcmp(argv[1], "-o") == 0) {
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

        FILE * fichier = fopen(argv[2], "a");

        for(i = 0; i < taille; i++) {
            fprintf(fichier, "%s:%d;", noms[i], numeros[i]);
        }
        
        free(fichier);
        fichier = NULL;
    }

    if(strcmp(argv[1], "-i") == 0) {
        FILE * fichier = NULL;
        if((fopen(argv[2], "r")) == NULL) {
            printf("Le fichier %s n'existe pas.\nCreer le avec la commande : %s -o %s\n", argv[2], argv[0], argv[2]);
            exit(EXIT_FAILURE);
        }

        do {
            printf("Nom à rechercher (None pour arrêter) :\n>>> ");
            scanf("%s", nomCherche);
            if(strcmp(nomCherche, "None") == 0) {
                break;
            }

            success = 0;
            fichier = fopen(argv[2], "r");

            while(fscanf(fichier, "%[^:]:%d;", tmpNom, &tmpNumero) != EOF) {
                if(strcmp(nomCherche, tmpNom) == 0) {
                    printf("Le numéro de \"%s\" est %d\n", tmpNom, tmpNumero);
                    success = 1;
                    break;
                }
            }
            if(success != 1) {
                printf("\"%s\" non trouvé.\n", nomCherche);
            }
        } while(1);

        free(fichier);
        fichier = NULL;
    }

    free(noms);
    noms = NULL;
    free(numeros);
    numeros = NULL;
    
    exit(EXIT_SUCCESS);
}