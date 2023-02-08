// Romain LANCELOT - 2ESGI A4

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    int x;
    int y;
    float distanceOrigine;
    float distancePointDonne;
} point;

void calculDistanceOrigine(point *p) {
    p->distanceOrigine = sqrt(pow(p->x, 2) + pow(p->y, 2));
}

void calculDistancePointDonne(point *p, point *pointDonne) {
    p->distancePointDonne = sqrt(pow(p->x - pointDonne->x, 2) + pow(p->y - pointDonne->y, 2));
}

int intcmpDistanceOrigine(point *p1, point *p2) {
    return p1->distanceOrigine - p2->distanceOrigine;
}

int intcmpDistancePointDonne(point *p1, point *p2) {
    return p1->distancePointDonne - p2->distancePointDonne;
}

int main() {
    point pointDonne = {3, 3};
    point liste[] = {
        {2, 3},
        {0, 1},
        {-3, 0},
        {0, 3},
        {4, 0}
    };
    int n = sizeof(liste) / sizeof(point);

    for (int i = 0; i < n; i++) {
        calculDistanceOrigine(&liste[i]);
        calculDistancePointDonne(&liste[i], &pointDonne);
    }

    printf("Distance origine :\n");
    qsort(liste, n, sizeof(point), (int (*)(const void *, const void *))intcmpDistanceOrigine);
    for (int i = 0; i < n; i++) {
        printf("(%d, %d) : %g\n", liste[i].x, liste[i].y, liste[i].distanceOrigine);
    }

    printf("Distance (%d, %d)\n", pointDonne.x, pointDonne.y);
    qsort(liste, n, sizeof(point), (int (*)(const void *, const void *))intcmpDistancePointDonne);
    for (int i = 0; i < n; i++) {
        printf("(%d, %d) : %g\n", liste[i].x, liste[i].y, liste[i].distancePointDonne);
    }
    
    exit(EXIT_SUCCESS);
}