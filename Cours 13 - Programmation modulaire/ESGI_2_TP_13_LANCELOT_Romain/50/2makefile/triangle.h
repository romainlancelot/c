// Romain LANCELOT - 2ESGI A4

#ifndef DEF_HEADER_TRIANGLE
#define DEF_HEADER_TRIANGLE
/* Protection du module */
#include "point.h"

/**
    Documentation du module et auteurs
*/

/* Macros publiques */

/* Types publiques du module */
typedef struct Triangle Triangle;
struct Triangle {
    Point first;
    Point second;
    Point third;
};

/* Variables publiques du module */
extern Triangle Triangle_creer(Point first, Point second, Point third);

/* Fonctionnalités publiques du module */
extern void Triangle_afficher(const Triangle * triangle);
extern double Triangle_perimetre(const Triangle * triangle);

#endif