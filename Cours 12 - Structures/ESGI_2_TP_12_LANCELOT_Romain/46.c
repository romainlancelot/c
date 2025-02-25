// Romain LANCELOT - 2ESGI A4

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Vecteur2d Vecteur2d;
struct Vecteur2d {
    double x;
    double y;
};

// fonction translation de vecteur :
Vecteur2d translation(Vecteur2d vecteur, Vecteur2d vTranslation) {
    vecteur.x += vTranslation.x;
    vecteur.y += vTranslation.y;
    return vecteur;
}

// fonction agrandissement de vecteur :
Vecteur2d agrandissement(Vecteur2d vecteur, Vecteur2d vAgrandissement, double rapport) {
    vecteur.x = rapport * (vecteur.x - vAgrandissement.x) + vAgrandissement.x;
    vecteur.y = rapport * (vecteur.y - vAgrandissement.y) + vAgrandissement.y;
    return vecteur;
}

// fonction rotation de vecteur :
Vecteur2d rotation(Vecteur2d vecteur, Vecteur2d vRotation, double angle) {
    Vecteur2d tmp;
    angle = angle * M_PI / 180;
    tmp.x = (vecteur.x - vRotation.x) * cos(angle) - (vecteur.y - vRotation.y) * sin(angle) + vRotation.x;
    tmp.y = (vecteur.x - vRotation.x) * sin(angle) + (vecteur.y - vRotation.y) * cos(angle) + vRotation.y;
    return tmp;
}


int main() {
    Vecteur2d vecteur = {0, 0};
    printf("Vecteur2d : (%g, %g)\n", vecteur.x, vecteur.y);

    Vecteur2d vTranslation = {1, 2};
    printf("Translation par un Vecteur2d : (%g, %g)\n", vTranslation.x, vTranslation.y);
    vTranslation = translation(vecteur, vTranslation);
    printf("(%g, %g)\n", vTranslation.x, vTranslation.y);

    vecteur = vTranslation;

    Vecteur2d vAgrandissement = {1, 0};
    double rapport = 0.5;
    printf("Agrandissement de rapport %g et de centre un Vecteur2d : (%g, %g)\n", rapport, vAgrandissement.x, vAgrandissement.y);    
    vAgrandissement = agrandissement(vecteur, vAgrandissement, rapport);
    printf("(%g, %g)\n", vAgrandissement.x, vAgrandissement.y);

    vecteur = vAgrandissement;

    Vecteur2d vRotation = {0, 2};
    double angle = 135;
    printf("Rotation d'angle %g deg et de centre un Vecteur2d : (%g, %g)\n", angle, vRotation.x, vRotation.y);    
    vRotation = rotation(vecteur, vRotation, angle);
    printf("(%e, %f)\n", vRotation.x, vRotation.y);
    
    exit(EXIT_SUCCESS);
}