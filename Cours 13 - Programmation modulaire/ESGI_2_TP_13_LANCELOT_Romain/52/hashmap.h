// Romain LANCELOT - 2ESGI A4

#ifndef DEF_HEADER_HASHMAP
#define DEF_HEADER_HASHMAP
/* Protection du module */
#include <stdio.h>

/**
    Documentation du module et auteurs
*/

/* Macros publiques */

/* Types publiques du module */
/* Table de hachage */
typedef struct HashMap HashMap;
struct HashMap {
    int * keys;
    int * values;
    int capacity;
    int size;
};

/* Variables publiques du module */
/* création d'une table de hachage */
extern HashMap * HashMap_creer(int capacite);

/* Fonctionnalités publiques du module */
/* libération d'une table de hachage */
extern void HashMap_free(HashMap ** hashmap);

/* ajout de 1 à la valeur associée à key, affectation à 1 si non trouvée */
extern int HashMap_ajouter(HashMap * hashmap, int key);

/* affiche la table de hachage dans un flux flow */
extern void HashMap_afficher(FILE * flow, const HashMap * hashmap);

/* renvoie le nombre d'ajouts de la clé key (valeur associée) */
extern int HashMap_compter(const HashMap * hashmap, int key);

#endif
