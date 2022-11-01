#include <stdio.h>
#include <stdlib.h>

int main() {
    int * data = NULL;
    int taille, i = 0;
    char op;

    printf("taille de la mémoire : ");
    scanf("%d", &taille);
    if((data = (int *)calloc(taille, sizeof(int))) == NULL) {
        printf("Erreur d'allocation mémoire\n");
        exit(EXIT_FAILURE);
    }

    // afficher la mémoire :
    // printf("[");
    // for(int j = 0; j < taille; ++j) {
    //     if(j) { 
    //         printf(", ");
    //     }
    //     printf("%d", data[j]);
    // }
    // printf("]\n");

    op = getchar();
    while(op != 'q') {
        switch(op) {
            case '+' : data[i]++; break;
            case '-' : data[i]--; break;
            case '=' : {
                for(int j = 0; j < taille; ++j) {
                    data[j] = data[i];
                }
            } break;
            case '>' : i = (i+1) % taille; break;
            case '<' : i = (i + taille - 1) % taille; break;
            case '.' : {
                printf("[");
                for(int j = 0; j < taille; ++j) {
                    if(j) {
                        printf(", ");
                    }
                    printf("%d", data[j]);
                }
                printf("]\n");
            } break;
        }
        op = getchar();
    }
    free(data);

    exit(EXIT_SUCCESS);
}