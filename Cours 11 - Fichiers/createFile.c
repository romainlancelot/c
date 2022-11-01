#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE * fichier = NULL;
    if((fichier = fopen("MonFichier.txt", "w")) == NULL) {
        printf("Erreur de création de mon fichier.\n");
        exit(EXIT_FAILURE);
    }
    printf("Fichier créé avec succès.\n");
    
    fprintf(fichier, "Salut mec\n");
    
    // int caractere;
    // while((caractere = fgetc(fichier)) != EOF) {
    //     putchar(caractere);
    // }

    // char reponse[50];
    // fscanf(fichier, "%s", reponse);
    
    
    fclose(fichier);
    fichier = NULL;
    exit(EXIT_SUCCESS);
}