// Romain LANCELOT - 2ESGI A4

#include "triangle.h"
/* Inclusion des déclarations du module */

#include <stdio.h>
/* Autres inclusions */

/* Définition des variables globales relatives au module */
Triangle Triangle_creer(Point first, Point second, Point third) {
    Triangle triangle = {first, second, third};
    return triangle;
}

/* Fonctionnalité privée au module par le mot clé static */


/* Définistion des fonctionnalités annoncées par l'entête */
void Triangle_afficher(const Triangle * triangle) {
    printf("{Triangle : ");
    Point_afficher(&(triangle->first));
    printf(", ");
    Point_afficher(&(triangle->second));
    printf(", ");
    Point_afficher(&(triangle->third));
    printf("}");
}

double Triangle_perimetre(const Triangle * triangle) {
    return
        Point_distance(&(triangle->first), &(triangle->second))
        + Point_distance(&(triangle->second), &(triangle->third))
        + Point_distance(&(triangle->third), &(triangle->first));
}