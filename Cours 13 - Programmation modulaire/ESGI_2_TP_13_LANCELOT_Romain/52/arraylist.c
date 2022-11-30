// Romain LANCELOT - 2ESGI A4

#include "arraylist.h"
/* Inclusion des déclarations du module */

#include <stdio.h>
#include <stdlib.h>
/* Autres inclusions */

/* Définition des variables globales relatives au module */
/* création d'une liste */
ArrayList * ArrayList_creer(int capacite) {
    ArrayList * liste = malloc(sizeof(ArrayList));
    liste->tableau = malloc(capacite * sizeof(int));
    liste->taille = 0;
    liste->capacite = capacite;
    return liste;
}

/* Fonctionnalité privée au module par le mot clé static */


/* Définistion des fonctionnalités annoncées par l'entête */
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
void ArrayList_afficher(FILE * flow, const ArrayList * liste);

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