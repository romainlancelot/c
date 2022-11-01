// Romain LANCELOT - 2ESGI A4

#include <stdio.h>
#include <stdlib.h>

int main() {
    int i;

    FILE * fichier = NULL;
    if((fichier = fopen("exo42.txt", "r")) == NULL) {
        fichier = fopen("exo42.txt", "w");
        fprintf(fichier, "%d", i = 0);
    } else {
        fscanf(fichier, "%d", &i);
    }
    fclose(fichier);
    fichier = NULL;

    printf("Programme lancé %d fois", i);

    fichier = fopen("exo42.txt", "w");
    fprintf(fichier, "%d", ++i);
    fclose(fichier);
    fichier = NULL;
    
    exit(EXIT_SUCCESS);
}