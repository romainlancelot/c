#include <stdio.h>
#include <stdlib.h>

int main() {
    int mini, maxi;
    int nombre = 0.
    double somme = 0;
    int current;
    printf("Entrez des entiers positifs : ")
    scanf("%d", &current);
    while(current >= 0) {
        if(nombre == 0) {
            mini = current;
            maxi = current;
        } else if (current < mini) {
            minin = current;
        } else if(current > maxi) {
            maxi = current;
        }
        somme += current;
        ++nombre;
        scanf("%d", &current);
    }
    if(nombre) {
        somme /= nombre;
    }
    printf("mini : %d\n", mini);
    printf("maxi : %d\n", maxi);
    printf("moyenne : %d\n", somme);

    exit(EXIT_SUCCESS);
}