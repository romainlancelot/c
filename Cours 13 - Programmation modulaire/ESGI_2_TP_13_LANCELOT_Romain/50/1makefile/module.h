// Romain LANCELOT - 2ESGI A4

#ifndef DEF_HEADER_MODULE
#define DEF_HEADER_MODULE
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

typedef struct Triangle Triangle;
struct Triangle {
    Point first;
    Point second;
    Point third;
};

/* Variables publiques du module */
extern Point Point_creer(double x, double y);
extern Triangle Triangle_creer(Point first, Point second, Point third);

/* Fonctionnalités publiques du module */
extern void Point_afficher(const Point * p);
extern double Point_distance(const Point * first, const Point * second);
extern void Triangle_afficher(const Triangle * triangle);
extern double Triangle_perimetre(const Triangle * triangle);

#endif