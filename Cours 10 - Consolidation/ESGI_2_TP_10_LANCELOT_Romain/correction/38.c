#include <stdio.h>
#include <stdlib.h>

int main() {
    const char * infos = "Linux Tornalds 52 ans C";

    char prenom[50];
    char nom[50];
    int age;
    char langage[50];

    sscanf(infos, "%s %s %d ans %s", prenom, nom, &age, langage);
    printf("Prenom :%s\n%s\n%d\n%s\n", prenom, nom, age, langage);

    exit(EXIT_SUCCESS);
}