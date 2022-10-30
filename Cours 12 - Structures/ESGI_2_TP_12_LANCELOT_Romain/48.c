#include <stdio.h>
#include <stdlib.h>

// Permettre à deux personnages de s’aﬀronter. On vous demande de mettre en place :
// • Des Stats contenant la vie, l’attaque, la défense et la vitesse.
struct Stats {
    int vie;
    int attaque;
    int defense;
    int vitesse;
};

// • Énumération des stats.
enum Stats {
    VIE,
    ATTAQUE,
    DEFENSE,
    VITESSE
};

// • Des Personnages symbolisés par un nom, des statistiques de base et des
// statistiques actuelles.
struct Personnage {
    char * nom;
    Stats stats_base;
    Stats stats_actuelles;
};

// • Énumération des sorts
enum Sorts {
    COUP,
    REDUIRE ATTAQUE,
    REDUIRE DEFENSE,
    REDUIRE VITESSE,
    SOIN,
    AUGMENTER ATTAQUE,
    AUGMENTER DEFENSE,
    AUGMENTER VITESSE
};


int main() {



}