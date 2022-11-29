// Romain LANCELOT - 2ESGI A4

/* fichier arraylist.h */
#ifndef DEF_HEADER_LISTE
#define DEF_HEADER_LISTE
/* Protection du module */
#include <stdio.h>

/**
    Documentation du module et auteurs
*/

/* Macros publiques */

/* Types publiques du module */
/* Liste sous forme d'un tableau de valeurs */
typedef struct ArrayList ArrayList;
struct ArrayList {
    int * tableau;
    int taille;
    int capacite;
};

/* Variables publiques du module */
/* création d'une liste */
extern ArrayList * ArrayList_creer(int capacite);

/* Fonctionnalités publiques du module */
/* libération d'une liste */
extern void ArrayList_free(ArrayList ** arraylist);

/* ajout d'un élément dans la liste */
extern int ArrayList_ajouter(ArrayList * liste, int valeur);

/* affiche la liste dans un flux flow */
extern void ArrayList_afficher(FILE * flow, const ArrayList * liste);

/* compte le nombre d'occurrences d'une valeur dans la liste */
extern int ArrayList_compter(const ArrayList * liste, int valeur);

#endif