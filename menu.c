#include <stdbool.h>
#include <stdio.h>
#include "menu.h"

const char * mainElements[] = {"Jouer", "Résoudre", "Générer", "Quitter"};
const char * playElements[] = {"Mode de jeu:", "Masque manuel", "Masque aléatoire", "Entraînement", "Retour"};

int multiChoiceMenu(char * elements[], int size, bool title, bool retour) {
    int choice;
    size = retour ? size - 1 : size;

    if(title) {
        printf("%s\n\n", elements[0]);
        for (int i = 1; i < size; ++i) {
            printf("[%d] -\t%s\n", i, elements[i]);
        }
    }
    else {
        printf("\n\n");
        for (int i = 0; i < size; ++i) {
            printf("[%d] -\t%s\n", i + 1, elements[i]);
        }
    }

    if(retour) {
        printf("\n[0] -\t%s\n", elements[size]);
    }

    printf("\n>\t");
    choice = (fgetc(stdin) - '0');
    getchar(); //je suis obligé de faire ça parce que sinon ça met le bazar partout
    if((choice < size) && (choice >= 0)) {
        return choice;
    }
    else {
        return -1;
    }
}