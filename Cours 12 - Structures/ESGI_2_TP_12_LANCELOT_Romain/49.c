#include <stdio.h>
#include <stdlib.h>

typedef struct LinkedList * LinkedList;
struct LinkedList {
    int value;
    LinkedList next;
};

/* Renvoie une liste vide */
LinkedList LL_empty() {
    return NULL;
}

/* Libère la liste */
void LL_free(LinkedList * liste) {
    if (*liste != NULL) {
        LL_free(&(*liste)->next);
        free(*liste);
        *liste = NULL;
    }
}

/* Ajoute un élément en fin */
int LL_add_tail(LinkedList * liste, int value) {
    if (*liste == NULL) {
        *liste = malloc(sizeof(struct LinkedList));
        if (*liste == NULL) {
            return 0;
        }
        (*liste)->value = value;
        (*liste)->next = NULL;
    } else {
        return LL_add_tail(&(*liste)->next, value);
    }
    return 1;
}

/* Ajoute un élément en tête */
int LL_add_head(LinkedList * liste, int value) {
    LinkedList new = malloc(sizeof(struct LinkedList));
    if (new == NULL) {
        return 0;
    }
    new->value = value;
    new->next = *liste;
    *liste = new;
    return 1;
}

/* Ajoute un élément à une position donnée */
int LL_insert(LinkedList * liste, int id, int value) {
    if (id == 0) {
        return LL_add_head(liste, value);
    } else if (*liste == NULL) {
        return 0;
    } else {
        return LL_insert(&(*liste)->next, id - 1, value);
    }
}

/* Supprime l'élément en fin */
int LL_pop_tail(LinkedList * liste, int * value) {
    if (*liste == NULL) {
        return 0;
    } else if ((*liste)->next == NULL) {
        *value = (*liste)->value;
        free(*liste);
        *liste = NULL;
        return 1;
    } else {
        return LL_pop_tail(&(*liste)->next, value);
    }
}

/* Supprime l'élément en tête */
int LL_pop_head(LinkedList * liste, int * value) {
    if (*liste == NULL) {
        return 0;
    } else {
        *value = (*liste)->value;
        LinkedList next = (*liste)->next;
        free(*liste);
        *liste = next;
        return 1;
    }
}

/* Supprime l'élément à une position donnée */
int LL_delete(LinkedList * liste, int id, int * value) {
    if (id == 0) {
        return LL_pop_head(liste, value);
    } else if (*liste == NULL) {
        return 0;
    } else {
        return LL_delete(&(*liste)->next, id - 1, value);
    }
}

/* Affiche la liste */
void LL_print(FILE * flow, const LinkedList * liste) {
    if (*liste != NULL) {
        fprintf(flow, "%d", (*liste)->value);
        if ((*liste)->next != NULL) {
            fprintf(flow, " -> ");
            LL_print(flow, &(*liste)->next);
        }
    }
}


typedef struct ArrayList ArrayList;
struct ArrayList {
    int * values;
    int size;
    int capacite;
};

/* Renvoie une liste vide */
ArrayList AL_empty() {
    ArrayList liste;
    liste.values = NULL;
    liste.size = 0;
    liste.capacite = 0;
    return liste;
}

/* Libère la liste */
void AL_free(ArrayList * liste) {
    free(liste->values);
    liste->values = NULL;
    liste->size = 0;
    liste->capacite = 0;
}

/* Ajoute un élément en fin */
int AL_add_tail(ArrayList * liste, int value) {
    if (liste->size == liste->capacite) {
        int * new = realloc(liste->values, (liste->capacite + 1) * sizeof(int));
        if (new == NULL) {
            return 0;
        }
        liste->values = new;
        liste->capacite++;
    }
    liste->values[liste->size] = value;
    liste->size++;
    return 1;
}

/* Ajoute un élément en tête */
int AL_add_head(ArrayList * liste, int value) {
    if (liste->size == liste->capacite) {
        int * new = realloc(liste->values, (liste->capacite + 1) * sizeof(int));
        if (new == NULL) {
            return 0;
        }
        liste->values = new;
        liste->capacite++;
    }
    for (int i = liste->size; i > 0; i--) {
        liste->values[i] = liste->values[i - 1];
    }
    liste->values[0] = value;
    liste->size++;
    return 1;
}

/* Ajoute un élément à une position donnée */
int AL_insert(ArrayList * liste, int id, int value) {
    if (id == 0) {
        return AL_add_head(liste, value);
    } else if (id == liste->size) {
        return AL_add_tail(liste, value);
    } else if (id < 0 || id > liste->size) {
        return 0;
    } else {
        if (liste->size == liste->capacite) {
            int * new = realloc(liste->values, (liste->capacite + 1) * sizeof(int));
            if (new == NULL) {
                return 0;
            }
            liste->values = new;
            liste->capacite++;
        }
        for (int i = liste->size; i > id; i--) {
            liste->values[i] = liste->values[i - 1];
        }
        liste->values[id] = value;
        liste->size++;
        return 1;
    }
}

/* Supprime l'élément en fin */
int AL_pop_tail(ArrayList * liste, int * value) {
    if (liste->size == 0) {
        return 0;
    } else {
        *value = liste->values[liste->size - 1];
        liste->size--;
        return 1;
    }
}

/* Supprime l'élément en tête */
int AL_pop_head(ArrayList * liste, int * value) {
    if (liste->size == 0) {
        return 0;
    } else {
        *value = liste->values[0];
        for (int i = 0; i < liste->size - 1; i++) {
            liste->values[i] = liste->values[i + 1];
        }
        liste->size--;
        return 1;
    }
}

/* Supprime l'élément à une position donnée */
int AL_delete(ArrayList * liste, int id, int * value) {
    if (id == 0) {
        return AL_pop_head(liste, value);
    } else if (id == liste->size - 1) {
        return AL_pop_tail(liste, value);
    } else if (id < 0 || id >= liste->size) {
        return 0;
    } else {
        *value = liste->values[id];
        for (int i = id; i < liste->size - 1; i++) {
            liste->values[i] = liste->values[i + 1];
        }
        liste->size--;
        return 1;
    }
}

/* Affiche la liste */
void AL_print(FILE * flow, const ArrayList * liste) {
    if (liste->size > 0) {
        fprintf(flow, "%d", liste->values[0]);
        for (int i = 1; i < liste->size; i++) {
            fprintf(flow, " -> %d", liste->values[i]);
        }
    }
}


int main() {
    LinkedList liste = LL_empty();
    int value;
    LL_add_tail(&liste, 1);
    LL_add_tail(&liste, 2);
    LL_add_tail(&liste, 3);
    LL_add_tail(&liste, 4);
    LL_add_tail(&liste, 5);
    LL_add_tail(&liste, 6);
    LL_add_tail(&liste, 7);
    LL_add_tail(&liste, 8);
    LL_add_tail(&liste, 9);
    LL_add_tail(&liste, 10);
    LL_print(stdout, &liste);
    printf(" -> NULL (taille = %d) (capacite = %d) (moyenne = %f) (médiane = %f) (variance = %f) (écart-type = %f) (min = %d) (max = %d) (somme = %d) (produit = %d) (moyenne-pondérée = %f) (médiane-pondérée = %f) (variance-pondérée = %f) (écart-type-pondéré = %f) (somme-pondérée = %d) (produit-pondéré = %d) (moyenne-pondérée-2 = %f) (médiane-pondérée-2 = %f) (variance-pondérée-2 = %f) (écart-type-pondéré-2 = %f) (somme-pondérée-2 = %d) (produit-pondéré-2 = %d)\n", LL_size(&liste), LL_capacity(&liste), LL_mean(&liste), LL_median(&liste), LL_variance(&liste), LL_standard_deviation(&liste), LL_min(&liste), LL_max(&liste), LL_sum(&liste), LL_product(&liste), LL_weighted_mean(&liste), LL_weighted_median(&liste), LL_weighted_variance(&liste), LL_weighted_standard_deviation(&liste), LL_weighted_sum(&liste), LL_weighted_product(&liste), LL_weighted_mean_2(&liste), LL_weighted_median_2(&liste), LL_weighted_variance_2(&liste), LL_weighted_standard_deviation_2(&liste), LL_weighted_sum_2(&liste), LL_weighted_product_2(&liste));
}