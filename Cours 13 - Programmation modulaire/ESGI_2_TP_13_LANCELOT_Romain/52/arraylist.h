// Romain LANCELOT - 2ESGI A4

/* fichier arraylist.h */
#ifndef DEF_HEADER_LISTE
#define DEF_HEADER_LISTE

#include <stdio.h>
#include <stdlib.h>

/* Liste sous forme d'un tableau de valeurs */
typedef struct ArrayList ArrayList;
struct ArrayList {
    int * tableau;
    int taille;
    int capacite;
};

/* création d'une liste */
ArrayList * ArrayList_creer(int capacite) {
    ArrayList * liste = malloc(sizeof(ArrayList));
    liste->tableau = malloc(capacite * sizeof(int));
    liste->taille = 0;
    liste->capacite = capacite;
    return liste;
}

/* libération d'une liste */
void ArrayList_free(ArrayList ** arraylist) {
    free((*arraylist)->tableau);
    free(*arraylist);
    *arraylist = NULL;
}

/* ajout d'un élément dans la liste */
int ArrayList_ajouter(ArrayList * liste, int valeur) {
    if (liste->taille == liste->capacite) {
        return 0;
    }
    liste->tableau[liste->taille] = valeur;
    liste->taille++;
    return 1;
}

/* affiche la liste dans un flux flow */
void ArrayList_afficher(FILE * flow, const ArrayList * liste) {
    int i;
    for (i = 0; i < liste->taille; i++) {
        fprintf(flow, "%d ", liste->tableau[i]);
    }
    fprintf(flow, " (taille = %d, capacite = %d)", liste->taille, liste->capacite);
}

/* compte le nombre d'occurrences d'une valeur dans la liste */
int ArrayList_compter(const ArrayList * liste, int valeur) {
    int i, compteur = 0;
    for (i = 0; i < liste->taille; i++) {
        if (liste->tableau[i] == valeur) {
            compteur++;
        }
    }
    return compteur;
}

#endif