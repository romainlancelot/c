#include <stdio.h>
#include <stdlib.h>

int main() {
    float nombre, min, max, somme = 0, i = 0;
    
    printf("Entrez des entiers positifs : ");
    scanf("%f", &nombre);
    if(nombre > 0) {
        min = nombre;
        max = nombre;
        somme = nombre;
        i++;
    }

    do {
        scanf("%f", &nombre);
        if(nombre < 0) {
            break;
        }
        if(nombre < min) {
            min = nombre;
        }
        if(nombre > max) {
            max = nombre;
        }
        somme += nombre;
        i++;
    } while(nombre > 0);

    printf("min : %g\nmax : %g\nmoyenne : %g", min, max, somme / i);

    exit(EXIT_SUCCESS);
}