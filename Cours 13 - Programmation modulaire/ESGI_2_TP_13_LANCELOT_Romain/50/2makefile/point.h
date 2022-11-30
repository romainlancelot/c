// Romain LANCELOT - 2ESGI A4

#ifndef DEF_HEADER_POINT
#define DEF_HEADER_POINT
/* Protection du module */

/**
    Documentation du module et auteurs
*/

/* Macros publiques */

/* Types publiques du module */
typedef struct Point Point;
struct Point {
    double x;
    double y;
};

/* Variables publiques du module */
extern Point Point_creer(double x, double y);

/* Fonctionnalités publiques du module */
extern void Point_afficher(const Point * p);
extern double Point_distance(const Point * first, const Point * second);

#endif