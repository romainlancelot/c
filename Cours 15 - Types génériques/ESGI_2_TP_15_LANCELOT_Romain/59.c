// Romain LANCELOT - 2ESGI A4

#include <stdio.h>
#include <stdlib.h>


typedef struct {
    char *name;
    float (*f)(float x);
} functions;

float carre(float x) { return x * x; }
float cube(float x) { return x * x * x; }
float inverse(float x) { return 1.f / x; }
float oppose(float x) { return -x; }

int main() {
    functions liste[] = {
        {"carre", carre},
        {"cube", cube},
        {"inverse", inverse},
        {"oppose", oppose}
    };

    float targets[] = {
        -2.f,
        -0.5f,
        0.5f,
        2.f
    };

    int i, j;
    for(i = 0; i < 4; ++i) {
        // pas réussi à sortir la fonction de comparaison du main... 
        int fcmp(functions *f1, functions *f2) {
            return f1->f(targets[i]) - f2->f(targets[i]);
        }
        qsort(liste, 4, sizeof(functions), (int (*)(const void *, const void *))fcmp);
        printf("for %g :\n", targets[i]);
        for(j = 0; j < 4; ++j) {
            printf(" - %s(%g) = %g\n", liste[j].name, targets[i], liste[j].f(targets[i]));
        }
    }

    exit(EXIT_SUCCESS);
}