// Romain LANCELOT - 2ESGI A4
// Sujet du PDF, aucune modification n'a été apportée.

#include <stdio.h>
#include <stdlib.h>

int f(int x) {
    return x * x;
}

int main() {
    int a = 42;
    a = f(a);
    printf("a = %d\n", a);
    exit(EXIT_SUCCESS);
    return 0;
}