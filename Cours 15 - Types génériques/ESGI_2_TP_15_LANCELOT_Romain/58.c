// Romain LANCELOT - 2ESGI A4

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
qsort n'est pas toujours la solution la plus rapide, cela dépend de :
 - la taille de la liste à trier
 - la distribution des données
 - la complexité de la fonction de comparaison
*/

#define BENCHMARKS
// #undef BENCHMARKS


void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void heapify(int *tab, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && tab[left] > tab[largest])
        largest = left;

    if (right < n && tab[right] > tab[largest])
        largest = right;

    if (largest != i) {
        swap(&tab[i], &tab[largest]);
        heapify(tab, n, largest);
    }
}

void heapSort(int *tab, int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(tab, n, i);

    for (int i = n - 1; i >= 0; i--) {
        swap(&tab[0], &tab[i]);
        heapify(tab, i, 0);
    }
}

int fcmp(int *a, int *b) {
    return *a - *b;
}

int createArray(int **tab, int size) {
    *tab = malloc(size * sizeof(int));
    if (*tab == NULL) {
        fprintf(stderr, "Error: malloc failed\n");
        return 1;
    }

    for (int i = 0; i < size; ++i) {
        (*tab)[i] = rand() % 100;
    }
    return 0;
}

void mixArray(int *tab, int n) {
    for (int i = 0; i < n; ++i) {
        int j = rand() % n;
        swap(&tab[i], &tab[j]);
    }
}

void printArray(int *tab, int n) {
    printf("{ ");
    for (int i = 0; i < n; ++i) {
        if (i == n - 1) {
            printf("%d }\n", tab[i]);
            break;
        }
        printf("%d, ", tab[i]);
    }
}

int main() {
    // int tab[] = {12, 11, 13, 5, 6, 7};
    // int n = sizeof(tab) / sizeof(int);
    int n, *tab;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    createArray(&tab, n);

    printf("Array before sorting : ");
    printArray(tab, n);

    #ifdef BENCHMARKS
        fprintf(stderr, "Filling tri tas générique\n");
        clock_t start, stop;
        start = clock();
    #endif

    heapSort(tab, n);

    #ifdef BENCHMARKS
        stop = clock();
        fprintf(stderr, "Filling completed in %g s\n", (double)(stop - start) / CLOCKS_PER_SEC);
    #endif

    printf("Array after sorting : ");
    printArray(tab, n);


    mixArray(tab, n);
    printf("\nArray before sorting : ");
    printArray(tab, n);

    #ifdef BENCHMARKS
        fprintf(stderr, "Filling qsort\n");
        start = clock();
    #endif

    qsort(tab, n, sizeof(int), (int (*)(const void *, const void *))&fcmp);

    #ifdef BENCHMARKS
        stop = clock();
        fprintf(stderr, "Filling completed in %g s\n", (double)(stop - start) / CLOCKS_PER_SEC);
    #endif

    printf("Array after sorting : ");
    printArray(tab, n);
    

    exit(EXIT_SUCCESS);
}
