#include <stdbool.h>
#include <stdio.h>
#include <malloc.h>
#include "menu.h"
#include "derivative.h"
#include "io.h"

const char *mainElements[] = {"Jouer", "Résoudre", "Générer", "Quitter"};


int multiChoiceMenu(char *elements[], int size, bool title, bool back) {
    int choice;
    size = back ? size - 1 : size;

    if (title) {
        printf("%s\n\n", elements[0]);
        for (int i = 1; i < size; ++i) {
            printf("[%d] -\t%s\n", i, elements[i]);
        }
    } else {
        printf("\n\n");
        for (int i = 0; i < size; ++i) {
            printf("[%d] -\t%s\n", i + 1, elements[i]);
        }
    }

    if (back) {
        printf("\n[0] -\t%s\n", elements[size]);
    }

    printf("\n>\t");
    choice = (fgetc(stdin) - '0');
    getchar(); // je suis obligé de faire ça parce que sinon ça met le bazar partout
    if ((choice < size) && (choice >= 0)) {
        return choice;
    } else {
        return -1;
    }
}

bool isVowel(char c) {
    char vowels[] = {'a', 'e', 'i', 'o', 'u', 'y'};
    for (int i = 0; i < 6; ++i) {
        if (c == vowels[i]) {
            return true;
        }
    }
    return false;
}



char * article(enum number number, enum gender gender, char firstLetter, bool capital) {
    char * article = malloc(4);

    int random = rand() % 2;

    if(number == PL) {
        strcpy(article, random ? "des" : "les");
    } else {
        if(gender == FEM) {
            strcpy(article, random ? "une" : isVowel(firstLetter) ? "l'" : "la");
        } else {
            strcpy(article, random ? "un" : isVowel(firstLetter) ? "l'" : "le");
        }
    }

    if(capital) {
        article[0] = article[0] - 32;
    }
    return article;
}



void pattern1(Dictionary * dict, char * result) {
    Derivative nom1d = createDerivative(NOM, rand() % 2 ? MAS : FEM, dtense, dperson, rand() % 2 ? SG : PL);
    Derivative adjd = createDerivative(ADJ, nom1d.gender, dtense, dperson, nom1d.number);
    Derivative verd = createDerivative(VER, dgender, rand() % 6, P3, nom1d.number);
    Derivative nom2d = createDerivative(NOM, rand() % 2 ? MAS : FEM, dtense, dperson, rand() % 2 ? SG : PL);

    char * nom1 = randomDerivation(dict, nom1d);
    char * adj = randomDerivation(dict, adjd);
    char * ver = randomDerivation(dict, verd);
    char * nom2 = randomDerivation(dict, nom2d);

    sprintf(result, "%s %s %s %s %s %s.", article(nom1d.number, nom1d.gender, nom1[0], true), nom1, adj, ver, article(nom2d.number, nom2d.gender, nom2[0], false), nom2);
}


void pattern2(Dictionary * dict, char * result) {
    Derivative nom1d = createDerivative(NOM, rand() % 2 ? MAS : FEM, dtense, dperson, rand() % 2 ? SG : PL);
    Derivative ver1d = createDerivative(VER, dgender, rand() % 6, P3, nom1d.number);
    Derivative ver2d = createDerivative(VER, dgender, rand() % 6, P3, nom1d.number);
    Derivative nom2d = createDerivative(NOM, rand() % 2 ? MAS : FEM, dtense, dperson, rand() % 2 ? SG : PL);
    Derivative adjd = createDerivative(ADJ, nom2d.gender, dtense, dperson, nom2d.number);

    char * nom1 = randomDerivation(dict, nom1d);
    char * ver1 = randomDerivation(dict, ver1d);
    char * ver2 = randomDerivation(dict, ver2d);
    char * nom2 = randomDerivation(dict, nom2d);
    char * adj = randomDerivation(dict, adjd);

    sprintf(result, "%s %s qui %s %s %s %s %s.", article(nom1d.number, nom1d.gender, nom1[0], true), nom1, ver1, ver2, article(nom2d.number, nom2d.gender, nom2[0], false), nom2, adj);
}


void pattern3(Dictionary * dict, char * result) {

    Derivative ver1d = createDerivative(VER, dgender, rand() % 6, P3, SG);
    Derivative nom1d = createDerivative(NOM, rand() % 2 ? MAS : FEM, dtense, dperson, rand() % 2 ? SG : PL);
    Derivative ver2d = createDerivative(VER, dgender, rand() % 6, P3, nom1d.number);
    Derivative advd = createDerivative(ADV, dgender, dtense, dperson, dnumber);
    Derivative nom2d = createDerivative(NOM, rand() % 2 ? MAS : FEM, dtense, dperson, rand() % 2 ? SG : PL);
    Derivative nom3d = createDerivative(NOM, rand() % 2 ? MAS : FEM, dtense, dperson, SG);

    char * nom1 = randomDerivation(dict, nom1d);
    char * ver1 = randomDerivation(dict, ver1d);
    char * ver2 = randomDerivation(dict, ver2d);
    char * adv = randomDerivation(dict, advd);
    char * nom2 = randomDerivation(dict, nom2d);
    char * nom3 = randomDerivation(dict, nom3d);

    sprintf(result, "Albane %s Gabriel pendant que %s %s %s %s %s %s sans %s.", ver1, article(nom1d.number, nom1d.gender, nom1[0], false), nom1, ver2, adv, article(nom2d.number, nom2d.gender, nom2[0], false), nom2, nom3);
}