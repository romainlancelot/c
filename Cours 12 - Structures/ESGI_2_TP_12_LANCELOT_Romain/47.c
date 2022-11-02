// Romain LANCELOT - 2ESGI A4

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
    for(int y = 1; y < hauteur - 1; y++) {
        for(int x = 1; x < largeur - 1; x++) {
            *Grille_case(&grille, x, y) = ' ';
        }
    }

    for(int x = 0; x < largeur; x++) {
        *Grille_case(&grille, x, 0) = '#';
        *Grille_case(&grille, x, hauteur - 1) = '#';
    }

    for(int y = 0; y < hauteur; y++) {
        *Grille_case(&grille, 0, y) = '#';
        *Grille_case(&grille, largeur - 1, y) = '#';
    }

    *Grille_case(&grille, 1, 1) = '@';
    return grille;
}

/* affiche une grille à l'écran */
void Grille_afficher(const Grille * grille) {
    int x, y;
    for(y = 0; y < grille->hauteur; y++) {
        for(x = 0; x < grille->largeur; x++) {
            printw("%c", *Grille_case(grille, x, y));
        }
        printw("\n");
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
        switch(getch()) {
            case 'z':
                y--;
                break;
            case 's':
                y++;
                break;
            case 'q':
                x--;
                break;
            case 'd':
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