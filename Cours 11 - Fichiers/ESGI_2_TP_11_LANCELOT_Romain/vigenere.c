#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void vigenere(char texte[], char cle[], int sign, char message[]) {
	int i, j;
	int value;
	int offset;
	for(i = 0, j = 0; texte[i] != '\0'; ++i) {
		if(texte[i] >= 'A' && texte[i] <= 'Z') {
			value = texte[i] - 'A';
			message[i] = 'A';
		} else if(texte[i] >= 'a' && texte[i] <= 'z') {
			value = texte[i] - 'a';
			message[i] = 'a';
		} else {
			message[i] = texte[i];
			continue;
		}
		if(cle[j] >= 'A' && cle[j] <= 'Z') {
			offset = cle[j] - 'A';
		} else if(cle[j] >= 'a' && cle[j] <= 'z') {
			offset = cle[j] - 'a';
		}
		value = ((value + sign * offset) % 26 + 26) % 26;
		message[i] += value;
		j = (j + 1) % strlen(cle);
	}
	message[i] = '\0';
}

void lire_texte(char texte[]) {
	int c;
	int i;
	c = getchar();
	for(i = 0; c != '\n' && c != EOF; ++i) {
		texte[i] = c;
		c = getchar();
	}
	texte[i] = '\0';
}

int main() {
	char cle[50];
	char choix;
	char texte[500];
	char message[500];
	printf("Entrez une clé : ");
	scanf("%s", cle);
	do {
		printf("Que voulez-vous faire ?\nc - coder\nd - decoder\nq - quitter\nvotre choix : ");
		scanf(" %c ", &choix);
		switch(choix) {
			case 'c' : 
				printf("Entrez un message : ");
				lire_texte(texte);
				printf("texte = \"%s\"\n", texte);
				vigenere(texte, cle, 1, message);
				printf("codage_vigenere(K = \"%s\", M = \"%s\") = \n\"%s\"\n", cle, texte, message);
				break;
			case 'd' :
				printf("Entrez un message : ");
				lire_texte(texte);
				vigenere(texte, cle, -1, message);
				printf("decodage_vigenere(K = \"%s\", M = \"%s\") = \n\"%s\"\n", cle, texte, message);
				break;
		}
	} while(choix != 'q');
	exit(EXIT_SUCCESS);
}