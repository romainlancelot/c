// Romain LANCELOT - 2ESGI A4

#include "point.h"
/* Inclusion des déclarations du module */

#include <stdio.h>
#include <math.h>
/* Autres inclusions */

/* Définition des variables globales relatives au module */
Point Point_creer(double x, double y) {
    Point p = {x, y};
    return p;
}

/* Fonctionnalité privée au module par le mot clé static */


/* Définistion des fonctionnalités annoncées par l'entête */
void Point_afficher(const Point * p) {
    printf("(%g, %g)", p->x, p->y);
}

double Point_distance(const Point * first, const Point * second) {
    return sqrt(pow(second->x - first->x, 2) + pow(second->y - first->y, 2));
}
