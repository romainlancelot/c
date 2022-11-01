#include <stdio.h>
#include <stdlib.h>

int main() {
    const char * infos = "Linus Torvalds 52 ans C";
    char prenom[20], nom[20], langue[20];
    int age;

    sscanf(infos, "%s %s %d ans %s", prenom, nom, &age, langue);
    printf("Prénom : %s\nNom : %s\nAge : %d\nParle couramment la langue %s", prenom, nom, age, langue);

    exit(EXIT_SUCCESS);
}