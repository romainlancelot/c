#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>

typedef struct Grille Grille;
struct Grille {
    char * grille;
    int largeur;
    int hauteur;
};

/* donne un pointeur sur une case de la grille */
char * Grille_case(const Grille * grille, int x, int y) {
    return grille->grille + y * grille->largeur + x;
}

/* crée une grille de taille donnée */
Grille Grille_creer(int largeur, int hauteur) {
    Grille grille;
    grille.grille = malloc(largeur * hauteur * sizeof(char));
    grille.largeur = largeur;
    grille.hauteur = hauteur;
    return grille;
}

/* affiche une grille à l'écran */
void Grille_afficher(const Grille * grille) {
    int x, y;
    for (y = 0; y < grille->hauteur; y++) {
        for (x = 0; x < grille->largeur; x++) {
            printf("%c", *Grille_case(grille, x, y));
        }
        printf("#");
    }
}

/* libère une grille */
void Grille_free(Grille * grille) {
    free(grille->grille);
}

int main() {
    int largeur = 60, hauteur = 20;
    Grille grille = Grille_creer(largeur, hauteur);
    int x = 1, y = 1;
    initscr();
    noecho();
    cbreak();
    do {
        clear();
        Grille_afficher(&grille);
        mvprintw(y, x, "@");
        mvprintw(y, x, " ");
        refresh();
        getch();
        /* gestion des événements */
        switch (getch()) {
            case KEY_UP:
                y--;
                break;
            case KEY_DOWN:
                y++;
                break;
            case KEY_LEFT:
                x--;
                break;
            case KEY_RIGHT:
                x++;
                break;
        }
    } while(1);
    refresh();
    clrtoeol();
    refresh();
    endwin();
    Grille_free(&grille);
    exit(EXIT_SUCCESS);
}