// Romain LANCELOT - 2ESGI A4

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// taille du nom du perso : int taille = strlen(nom);
// fwrite(&taille, sizeof(int), 1, output);
// fwrite(nom, sizeof(char), taille, output);
// return 1;

// fread(&taille, sizeof(int), 1, input);
// fread(*nom, sizeof(char), taille, input);
// fread(vie, sizeof(int), 1, input);
// return 1


int main(int argc, char * argv[]) {
    if(argc <= 1) {
        printf("Attendu \n\t%s -create [FICHIER] [NOM] [VIE] [ATK] [DEF] [VIT]\n\t%s -read [FICHIER]", argv[0], argv[0]);
        exit(EXIT_FAILURE);
    }

    if(strcmp(argv[1], "-create") == 0) {
        if(argc != 8) {
            printf("Attendu \n\t%s -create [FICHIER] [NOM] [VIE] [ATK] [DEF] [VIT]", argv[0]);
            exit(EXIT_FAILURE);
        }

        FILE * output = fopen(argv[2], "w");
        if(output == NULL) {
            printf("Erreur d'ouverture du fichier %s", argv[2]);
            exit(EXIT_FAILURE);
        }

        char * nom = argv[3];
        int vie = atoi(argv[4]);
        int atk = atoi(argv[5]);
        int def = atoi(argv[6]);
        int vit = atoi(argv[7]);

        int taille = strlen(nom);
        fwrite(&taille, sizeof(int), 1, output);
        fwrite(nom, sizeof(char), taille, output);
        fwrite(&vie, sizeof(int), 1, output);
        fwrite(&atk, sizeof(int), 1, output);
        fwrite(&def, sizeof(int), 1, output);
        fwrite(&vit, sizeof(int), 1, output);

        fclose(output);
    } 
    
    if(strcmp(argv[1], "-read") == 0) {
        if(argc != 3) {
            printf("Attendu \n\t%s -read [FICHIER]", argv[0]);
            exit(EXIT_FAILURE);
        }

        FILE * input = fopen(argv[2], "r");
        if(input == NULL) {
            printf("Erreur d'ouverture du fichier %s", argv[2]);
            exit(EXIT_FAILURE);
        }

        int taille;
        fread(&taille, sizeof(int), 1, input);
        char * nom = malloc(taille * sizeof(char));
        fread(nom, sizeof(char), taille, input);
        int vie;
        fread(&vie, sizeof(int), 1, input);
        int atk;
        fread(&atk, sizeof(int), 1, input);
        int def;
        fread(&def, sizeof(int), 1, input);
        int vit;
        fread(&vit, sizeof(int), 1, input);

        printf("Peronnage : {\n\tNom : %s\n\tVie : %d\n\tAttaque : %d\n\tDefense : %d\n\tVitesse : %d\n}", nom, vie, atk, def, vit);

        fclose(input);
    }

    exit(EXIT_SUCCESS);
}