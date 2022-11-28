// Romain LANCELOT - 2ESGI A4

#ifndef DEF_HEADER_HASHMAP
#define DEF_HEADER_HASHMAP

#include <stdio.h>

/* Table de hachage */
typedef struct HashMap HashMap;
struct HashMap {
    int * keys;
    int * values;
    int capacity;
    int size;
};

/* création d'une table de hachage */
HashMap * HashMap_creer(int capacite) {
    HashMap * map = malloc(sizeof(HashMap));
    map->keys = malloc(capacite * sizeof(int));
    map->values = malloc(capacite * sizeof(int));
    map->capacity = capacite;
    map->size = 0;
    return map;
}

/* libération d'une table de hachage */
void HashMap_free(HashMap ** hashmap) {
    free((*hashmap)->keys);
    free((*hashmap)->values);
    free(*hashmap);
    *hashmap = NULL;
}

/* ajout de 1 à la valeur associée à key, affectation à 1 si non trouvée */
int HashMap_ajouter(HashMap * hashmap, int key) {
    int i;
    for(i = 0; i < hashmap->size; ++i) {
        if(hashmap->keys[i] == key) {
            hashmap->values[i]++;
            return hashmap->values[i];
        }
    }
    hashmap->keys[hashmap->size] = key;
    hashmap->values[hashmap->size] = 1;
    hashmap->size++;
    return 1;
}

/* affiche la table de hachage dans un flux flow */
void HashMap_afficher(FILE * flow, const HashMap * hashmap) {
    int i;
    for(i = 0; i < hashmap->size; ++i) {
        fprintf(flow, "%d: %d", hashmap->keys[i], hashmap->values[i]);
        if(i < hashmap->size - 1) {
            fprintf(flow, ", ");
        }
    }
}

/* renvoie le nombre d'ajouts de la clé key (valeur associée) */
int HashMap_compter(const HashMap * hashmap, int key) {
    int i;
    for(i = 0; i < hashmap->size; ++i) {
        if(hashmap->keys[i] == key) {
            return hashmap->values[i];
        }
    }
    return 0;
}

#endif
