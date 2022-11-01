#include <stdio.h>
#include <stdlib.h>

void vigenere(FILE * input, char * cle, int sign, FILE * output) {
    int i, j, value, offset, texte, message;

    for(i = 0, j = 0; (texte = fgetc(input)) != EOF; ++i) {
        if(texte >= "A" && texte <= "Z") {
            value = texte - "A";
            message = "A";
        } else if(texte >= "a" && texte <= "z") {
            value = texte - "a";
            message = "a";
        } else {
            fputc(texte, output);
        }
    }
    if(cle[j] >= "A" && cle[j] <= "Z") {
        offset = cle[j] - "A";
    } else if(cle[j] >= "a" && cle[j] <= "Z") {
        offset = cle[j] - "a";
    }
    value = ((value + sign * offset % 26 + 26) % 26);
    message += value;
    j = (j + 1) % strlen(cle);
    fputc(message, output);
}


int main(int argc, char * argv[]) {
    if(argc <= 2) {
        printf("Attendu %s", argv[0]);
        printf("Attendu %s", argv[0]);
        exit(EXIT_FAILURE);
    }

    char * path= argv[1];
    char * cle = argv[2];
    int sign = (argc > 3 && strcmp(argv[3], "decode") == 0) ? -1 : 1;
    FILE * input = NULL;
    FILE * output = stdout;
    if((input = fopen(path, "r")) == NULL) {
        fprintf(stderr, "Erreur ouverture \"%s\"\n", path);
        exit(EXIT_FAILURE);
    }
    vigenere(input, cle, sign, output);
    fclose(input);

    exit(EXIT_SUCCESS);
}