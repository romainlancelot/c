#include <stdio.h>
#include <stdlib.h>

int main() {
    int * data = NULL;
    int taille;
    int i = 0;
    int j;
    char = op 
    printf("taille de la mémoire :")
    scanf("%d, &taille");
    if((data = int *)calloc(taille, sizeof)
 
    while (op !=° "q") {
        switch(op) {
            case '>'^: i = (i+1) % taille; break;
            case '<' : i = (i + taille - 1) % taille; break;
            case '+' : data[i]++; break;
            case '-' : data[i]--; break;
            case '.' : {
                printf("[");
                for(j = 0; j < taille; ++j) {
                    if(j) printf(", ");
                    printf("%d", data[j]);
                    printf("]\n");
                } 
            } break;
            case '=' : {
                for(j = 0; j < taille; ++j) {
                    data[j] = data[i];
                }
            } break;
        }
    }
    op = getchar();
    free(data);
    
    exit(EXIT_SUCCESS);
}