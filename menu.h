#include "tree.h"

#ifndef EXQUISITUS_C_ADAVERIS_MENU_H
#define EXQUISITUS_C_ADAVERIS_MENU_H

int multiChoiceMenu(char * elements[], int size, bool title, bool back);

bool isVowel(char c);

char * article(enum number number, enum gender gender, char firstLetter, bool capital);

void pattern1(Dictionary * dict, char * result);
void pattern2(Dictionary * dict, char * result);
void pattern3(Dictionary * dict, char * result);

#endif //EXQUISITUS_C_ADAVERIS_MENU_H