#include <stdio.h>
#include <stdlib.h>

int main() {
    char morpion[3][3] = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}
    };
    int x, y, joueur = 1;
    char symbole;

    do {
        printf("Joueur %d, entrez les coordonnées de votre coup : ", joueur);
        scanf("%d %d", &x, &y);

        if(joueur == 1) {
            symbole = 'X';
        } else {
            symbole = 'O';
        }

        if(morpion[x][y] == ' ') {
            morpion[x][y] = symbole;
            joueur = 3 - joueur;
        } else {
            printf("Case déjà occupée !\n");
        }
        
        printf("+---+---+---+\n");
        printf("| %c | %c | %c |\n+---+---+---+\n", morpion[0][0], morpion[0][1], morpion[0][2]);
        printf("| %c | %c | %c |\n+---+---+---+\n", morpion[1][0], morpion[1][1], morpion[1][2]);
        printf("| %c | %c | %c |\n+---+---+---+\n", morpion[2][0], morpion[2][1], morpion[2][2]);

        if(morpion[0][0] == symbole && morpion[0][1] == symbole && morpion[0][2] == symbole) {
            printf("Le joueur %d a gagné !\n", joueur);
            break;
        } else if(morpion[1][0] == symbole && morpion[1][1] == symbole && morpion[1][2] == symbole) {
            printf("Le joueur %d a gagné !\n", joueur);
            break;
        } else if(morpion[2][0] == symbole && morpion[2][1] == symbole && morpion[2][2] == symbole) {
            printf("Le joueur %d a gagné !\n", joueur);
            break;
        } else if(morpion[0][0] == symbole && morpion[1][0] == symbole && morpion[2][0] == symbole) {
            printf("Le joueur %d a gagné !\n", joueur);
            break;
        } else if(morpion[0][1] == symbole && morpion[1][1] == symbole && morpion[2][1] == symbole) {
            printf("Le joueur %d a gagné !\n", joueur);
            break;
        } else if(morpion[0][2] == symbole && morpion[1][2] == symbole && morpion[2][2] == symbole) {
            printf("Le joueur %d a gagné !\n", joueur);
            break;
        } else if(morpion[0][0] == symbole && morpion[1][1] == symbole && morpion[2][2] == symbole) {
            printf("Le joueur %d a gagné !\n", joueur);
            break;
        } else if(morpion[0][2] == symbole && morpion[1][1] == symbole && morpion[2][0] == symbole) {
            printf("Le joueur %d a gagné !\n", joueur);
            break;
        } else if(morpion[0][0] != ' ' && morpion[0][1] != ' ' && morpion[0][2] != ' ' && morpion[1][0] != ' ' && morpion[1][1] != ' ' && morpion[1][2] != ' ' && morpion[2][0] != ' ' && morpion[2][1] != ' ' && morpion[2][2] != ' ') {
            printf("Match nul !\n");
            break;
        } else {
            continue;
        }
    } while(1);

    exit(EXIT_SUCCESS);
}