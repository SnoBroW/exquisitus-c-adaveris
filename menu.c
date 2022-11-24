#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "derivative.h"
#include "io.h"

const char * mainElements[] = {"Menu principal", "Generer des phrases", "Rechercher un mot", "Autocompletion", "Fonctionnalites maudites /!\\", "Quitter"};
const char * genElements[] = {"Selection de modele de phrase", "Modele 1", "Modele 2", "La surprise du Chef", "Retour"};
const char * searchElements[] = {"Rechercher dans le dictionnaire", "Rechercher un mot", "Rechercher un mot et ses forme flechies", "Retour"};
const char * cursedElements[] = {"ATTENTION ZONE DANGEREUSE", "Afficher arbre /!\\", "Afficher la seed /!\\", "Retour"};

const char * typeEnumString[] = {"Adverbes", "Noms", "Verbes", "Adjectifs"};


void banner() {
    printf("\n"
           "\n"
           "                          .__       .__  __                                                   \n"
           "  ____ ___  ___________ __|__| _____|__|/  |_ __ __  ______                                   \n"
           "_/ __ \\\\  \\/  / ____/  |  \\  |/  ___/  \\   __\\  |  \\/  ___/                                   \n"
           "\\  ___/ >    < <_|  |  |  /  |\\___ \\|  ||  | |  |  /\\___ \\                                    \n"
           " \\___  >__/\\_ \\__   |____/|__/____  >__||__| |____//____  >                                   \n"
           "     \\/      \\/  |__|             \\/                    \\/                    processDerivative                \n"
           "                       ___          ___                .___                        .__        \n"
           "                      /  /   ____   \\  \\   _____     __| _/____ ___  __ ___________|__| ______\n"
           "                     /  /  _/ ___\\   \\  \\  \\__  \\   / __ |\\__  \\\\  \\/ // __ \\_  __ \\  |/  ___/\n"
           "                    (  (   \\  \\___    )  )  / __ \\_/ /_/ | / __ \\\\   /\\  ___/|  | \\/  |\\___ \\ \n"
           "                     \\  \\   \\___  >  /  /  (____  /\\____ |(____  /\\_/  \\___  >__|  |__/____  >\n"
           "                      \\__\\      \\/  /__/        \\/      \\/     \\/          \\/              \\/ \n"
           "\n\n");
}

void mainMenu() {
    // Dictionary * dict = initDict("dicts/dictionnaire_non_accentue.txt");

    Dictionary * dict = initDict("../dicts/dictionnaire.txt");

    banner();
    int seed = initRand();

    Node * node;
    DerivativeCell * derivativeCell;
    bool found = false;
    char word[256];
    int x = 0;

    splashscreen(dict, word);
    printf("\t\"%s\"\n\t\t\t - %s\n\n", word, rand() % 3 ? "Pol" : rand() % 2 ? "Gab" : "Banane");

    while(!strcmp("magnifique", "magnifique")) { // boucle infinie très sophistiquée
        switch (multiChoiceMenu((char **) mainElements, 6, true, true)) {
            case 1:
                switch (multiChoiceMenu((char **) genElements, 5, true, true)) {
                    case 1:
                        printf("\n");
                        for (int i = 0; i < 5; i++) {
                            pattern1(dict, word);
                            printf("%s\n", word);
                        }
                        break;
                    case 2:
                        printf("\n");
                        for (int i = 0; i < 5; i++) {
                            pattern2(dict, word);
                            printf("%s\n", word);
                        }
                        break;
                    case 3:
                        printf("\n");
                        for (int i = 0; i < 5; i++) {
                            pattern3(dict, word);
                            printf("%s\n", word);
                        }
                        break;
                    default:
                        break;
                }
                printf("\n");
                break;
            case 2:
                switch (multiChoiceMenu((char **) searchElements, 4, true, true)) {
                    case 1:
                        printf("Entrez le mot a rechercher :\n>");
                        fgets(word, 256, stdin);
                        word[strlen(word) - 1] = '\0';
                        x = 0;
                        found = false;
                        while (x < 4) {
                            node = searchWord(dict->trees[x], word);
                            if (node != NULL && node->derivatives != NULL) {
                                found = true;
                                printf("\n\t\"%s\" found @ 0x%lx", node->derivatives->base, (long) &node);
                                printf("\n\ttree: %s\n", typeEnumString[x]);
                            }
                            x++;
                        }
                        if (!found) {
                            printf("\n\tMot introuvable\n\n");
                        } else {
                            printf("\n\n");
                        }
                        break;
                    case 2:
                        printf("Entrez le mot a rechercher :\n>");
                        fgets(word, 256, stdin);
                        word[strlen(word) - 1] = '\0';
                        x = 0;
                        found = false;
                        while (x < 4) {
                            node = searchWord(dict->trees[x], word);
                            if (node != NULL && node->derivatives != NULL) {
                                found = true;
                                printf("\n\t%s -->\t", node->derivatives->base);
                                derivativeCell = node->derivatives->head;
                                while (derivativeCell != NULL) {
                                    printf("%s ", derivativeCell->derivative->word);
                                    derivativeCell = derivativeCell->next;
                                }
                                printf("\n\ttree: %s\n", typeEnumString[x]);
                            }
                            x++;
                        }
                        if (!found) {
                            printf("\n\tMot introuvable\n\n");
                        } else {
                            printf("\n\n");
                        }
                        break;
                    default:
                        break;
                }
                break;
            case 3:
                printf("Work in progress...\n\n");
                break;
            case 4:
                switch (multiChoiceMenu((char **) cursedElements, 4, true, true)) {
                    case 1:
                        for (int j = 0; j < 4; j++) {
                            printTree(dict->trees[j]->root);
                            printf("\n\n");
                        }
                        break;
                    case 2:
                        printf("seed: %d\n\n", seed);
                    default:
                        break;
                }
                break;
            case 0:
                freeDictionary(dict);
                printf("Merci et au plaisir\n\n");
                return;
            default:
                printf("Choix invalide\n\n");
                break;
        }
    }
}


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



char * article(enum number number, enum gender gender, char firstLetter) {
    int random = rand() % 2;
    char * article = NULL;

    if(number == PL) {
        article = (random ? "des" : "les");
    } else {
        if(gender == FEM) {
            article = (random ? "une" : isVowel(firstLetter) ? "l'" : "la");
        } else {
            article = (random ? "un" : isVowel(firstLetter) ? "l'" : "le");
        }
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

    sprintf(result, "%s %s %s %s %s %s.", article(nom1d.number, nom1d.gender, nom1[0]), nom1, adj, ver, article(nom2d.number, nom2d.gender, nom2[0]), nom2);
    result[0] = result[0] - 32;
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

    sprintf(result, "%s %s qui %s %s %s %s %s.", article(nom1d.number, nom1d.gender, nom1[0]), nom1, ver1, ver2, article(nom2d.number, nom2d.gender, nom2[0]), nom2, adj);
    result[0] = result[0] - 32;
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

    sprintf(result, "Albane %s Gabriel pendant que %s %s %s %s %s %s sans %s.", ver1, article(nom1d.number, nom1d.gender, nom1[0]), nom1, ver2, adv, article(nom2d.number, nom2d.gender, nom2[0]), nom2, nom3);
}

void splashscreen(Dictionary * dict, char * result) {

    Derivative nomd = createDerivative(NOM, rand() % 2 ? MAS : FEM, dtense, dperson, rand() % 2 ? SG : PL);
    Derivative advd = createDerivative(ADV, dgender, dtense, dperson, dnumber);

    char * nom = randomDerivation(dict, nomd);
    char * adv = randomDerivation(dict, advd);

    adv[0] = adv[0] - 32;

    sprintf(result, "%s %s ? %s.", article(nomd.number, nomd.gender, nom[0]), nom, adv);
    result[0] = result[0] - 32;
}
