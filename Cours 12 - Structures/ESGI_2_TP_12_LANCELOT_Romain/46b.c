#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Vecteur2d Vecteur2d;

struct Vecteur2d {
    double x;
    double y;
};

// void Translation()

int main() {
    // Vecteur2d vecteurV = {0, 0};
    // printf("Vecteur2d : (%d, %d)\n", vecteurV.x, vecteurV.y);

    Vecteur2d vecteurT = {1, 2};
    printf("Translation par un Vacteur2d : (%d, %d)\n", vecteurT.x, vecteurT.y);

    exit(EXIT_SUCCESS);
}