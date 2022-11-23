#include "module.h"
/* Inclusion des déclarations du module */

#include <stdio.h>
#include <math.h>
/* Autres inclusions */

/* Définition des variables globales relatives au module */
Point Point_creer(double x, double y) {
    Point p = {x, y};
    return p;
}

Triangle Triangle_creer(Point first, Point second, Point third) {
    Triangle triangle = {first, second, third};
    return triangle;
}

/* Fonctionnalité privée au module par le mot clé static */


/* Définistion des fonctionnalités annoncées par l'entête */
void Point_afficher(const Point * p) {
    printf("(%g, %g)", p->x, p->y);
}

double Point_distance(const Point * first, const Point * second) {
    return sqrt(pow(second->x - first->x, 2) + pow(second->y - first->y, 2));
}

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