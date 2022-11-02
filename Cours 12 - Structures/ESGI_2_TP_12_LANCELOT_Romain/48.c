// Romain LANCELOT - 2ESGI A4

#include <stdio.h>
#include <stdlib.h>

// Des Stats contenant la vie, l’attaque, la défense et la vitesse.
typedef struct Stats Stats;
struct Stats {
    int vie;
    int attaque;
    int defense;
    int vitesse;
};

// Énumération des stats.
enum enumStats {
    VIE,
    ATTAQUE,
    DEFENSE,
    VITESSE
};

typedef struct Personnage Personnage;
// Des Personnages symbolisés par un nom, des statistiques de base et des statistiques actuelles.
struct Personnage {
    char * nom;
    Stats stats_base;
    Stats stats_actuelles;
};

// Énumération des sorts
enum Sorts {
    COUP,
    REDUIRE_ATTAQUE,
    REDUIRE_DEFENSE,
    REDUIRE_VITESSE,
    SOIN,
    AUGMENTER_ATTAQUE,
    AUGMENTER_DEFENSE,
    AUGMENTER_VITESSE
};

// Énumération des sorts (qui influent sur les stats du joueur et ceux de l’adversaire).
typedef struct Sort Sort;
struct Sort {
    char * nom;
    enum Sorts sortJoueur;
    enum enumStats type;
    int prixJoueur;
    enum enumStats stat;
    int prixEffet;
};

void afficherInterface(Personnage joueur, Personnage adversaire) {
    printf("%20s VS %s\n", joueur.nom, adversaire.nom);
    printf(">>>>>>>>>>>>>>>>>>>> | <<<<<<<<<<<<<<<<<<<<\n");
    printf("Vie : %14d | Vie : %14d\n", joueur.stats_actuelles.vie, adversaire.stats_actuelles.vie);
    printf("Attaque : %10d | Attaque : %10d\n", joueur.stats_actuelles.attaque, adversaire.stats_actuelles.attaque);
    printf("Defense : %10d | Defense : %10d\n", joueur.stats_actuelles.defense, adversaire.stats_actuelles.defense);
    printf("Vitesse : %10d | Vitesse : %10d\n", joueur.stats_actuelles.vitesse, adversaire.stats_actuelles.vitesse);
    printf("---------------------+---------------------\n");
    printf("1. coup               5. soin\n");
    printf("2. reduire attaque    6. augmenter attaque\n");
    printf("3. reduire defense    7. augmenter defense\n");
    printf("4. reduire vitesse    8. augmenter vitesse\n");
    printf("---------------------+---------------------\n");
}

void choixJoueur(Personnage * joueur, Personnage * adversaire, int choix) {
    Sort coup = {"Coup", COUP, ATTAQUE, -10, VIE, -20};
    Sort reduireAttaque = {"Réduire attaque", REDUIRE_ATTAQUE, VITESSE, -10, ATTAQUE, -10};
    Sort reduireDefense = {"Réduire défense", REDUIRE_DEFENSE, VITESSE, -10, DEFENSE, -10};
    Sort reduireVitesse = {"Réduire vitesse", REDUIRE_VITESSE, ATTAQUE, -10, VITESSE, -10};
    Sort soin = {"Soin", SOIN, DEFENSE, -5, VIE, 10};
    Sort augmenterAttaque = {"Augmenter attaque", AUGMENTER_ATTAQUE, DEFENSE, -5, ATTAQUE, 10};
    Sort augmenterDefense = {"Augmenter défense", AUGMENTER_DEFENSE, ATTAQUE, -5, DEFENSE, 10};
    Sort augmenterVitesse = {"Augmenter vitesse", AUGMENTER_VITESSE, DEFENSE, -5, VITESSE, 10};

    switch(choix) {
        case 1:
            joueur->stats_actuelles.vie += coup.prixEffet;
            adversaire->stats_actuelles.vie += coup.prixJoueur;
            break;
        case 2:
            joueur->stats_actuelles.attaque += reduireAttaque.prixEffet;
            adversaire->stats_actuelles.vitesse += reduireAttaque.prixJoueur;
            break;
        case 3:
            joueur->stats_actuelles.defense += reduireDefense.prixEffet;
            adversaire->stats_actuelles.vitesse += reduireDefense.prixJoueur;
            break;
        case 4:
            joueur->stats_actuelles.vitesse += reduireVitesse.prixEffet;
            adversaire->stats_actuelles.attaque += reduireVitesse.prixJoueur;
            break;
        case 5:
            joueur->stats_actuelles.vie += soin.prixEffet;
            adversaire->stats_actuelles.defense += soin.prixJoueur;
            break;
        case 6:
            joueur->stats_actuelles.attaque += augmenterAttaque.prixEffet;
            adversaire->stats_actuelles.defense += augmenterAttaque.prixJoueur;
            break;
        case 7:
            joueur->stats_actuelles.defense += augmenterDefense.prixEffet;
            adversaire->stats_actuelles.attaque += augmenterDefense.prixJoueur;
            break;
        case 8:
            joueur->stats_actuelles.vitesse += augmenterVitesse.prixEffet;
            adversaire->stats_actuelles.defense += augmenterVitesse.prixJoueur;
            break;
    }
}

int main() {
    printf("Bienvenue dans le jeu de combat !\n");

    char nomJoueur1[20];
    char nomJoueur2[20];
    printf("Entrez le nom du joueur 1 : ");
    scanf("%s", nomJoueur1);
    printf("Entrez le nom du joueur 2 : ");
    scanf("%s", nomJoueur2);

    // Création des personnages
    Personnage * joueur = malloc(sizeof(Personnage));
    joueur->nom = nomJoueur1;
    joueur->stats_base = (Stats) {100, 50, 20, 100};
    joueur->stats_actuelles = (Stats) {100, 50, 20, 100};
    // {"Joueur", {100, 50, 20, 100}, {100, 50, 20, 100}};

    Personnage * adversaire = malloc(sizeof(Personnage));
    adversaire->nom = nomJoueur2;
    adversaire->stats_base = (Stats) {100, 50, 20, 100};
    adversaire->stats_actuelles = (Stats) {100, 50, 20, 100};
    // adversaire = {"Adversaire", {100, 50, 20, 100}, {100, 50, 20, 100}};

    int tour = 0, choix;
    while(1) {
        afficherInterface(*joueur, *adversaire);

        if(tour == 0) {
            choix = 0;
            printf("Tour de : %s\nVotre sort : ", joueur->nom);
            scanf("%d", &choix);
            choixJoueur(joueur, adversaire, choix);
            tour = 1;
        } else {
            choix = 0;
            printf("Tour de : %s\nVotre sort : ", adversaire->nom);
            scanf("%d", &choix);
            choixJoueur(adversaire, joueur, choix);
            tour = 0;
        }

        printf("\n\n");
       
        if(adversaire->stats_actuelles.vie <= 0) {
            printf("Vous avez gagné !\n");
            break;
        }
        if(joueur->stats_actuelles.vie <= 0) {
            printf("Vous avez perdu !\n");
            break;
        }
    }

    exit(EXIT_SUCCESS);
}