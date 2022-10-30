#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Vecteur2d {
    double x;
    double y;
};

// fonction translation de vecteur :

struct Vecteur2d translation(struct Vecteur2d vecteur, double x, double y) {
    vecteur.x += x;
    vecteur.y += y;
    return vecteur;
}

// fonction rotation de vecteur :

struct Vecteur2d rotation(struct Vecteur2d vecteur, double angle) {
    double x = vecteur.x;
    double y = vecteur.y;
    vecteur.x = x * cos(angle) - y * sin(angle);
    vecteur.y = x * sin(angle) + y * cos(angle);
    return vecteur;
}

// fonction agrandissement de vecteur :

struct Vecteur2d agrandissement(struct Vecteur2d vecteur, double facteur) {
    vecteur.x *= facteur;
    vecteur.y *= facteur;
    return vecteur;
}

int main() {
    struct Vecteur2d vecteur = {1, 1};
    
    vecteur = translation(vecteur, 1, 1);
    vecteur = rotation(vecteur, M_PI / 2);
    vecteur = agrandissement(vecteur, 2);
    
    printf("Vecteur : (%g, %g)", vecteur.x, vecteur.y);
    
    exit(EXIT_SUCCESS);
}