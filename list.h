//
// Created by Gabriel on 10/11/2022.
//

#ifndef EXQUISITUS_C_ADAVERIS_LIST_H
#define EXQUISITUS_C_ADAVERIS_LIST_H

#include <stdbool.h>

#include "tree.h"


typedef struct Nodecell {
    struct Node * node;
    struct Nodecell * next;
} Nodecell;

typedef struct Nodelist {
    struct Nodecell * head;
} Nodelist;

typedef struct Derivativecell {
    struct Derivative * derivative;
    struct Derivativecell * next;
} DerivativeCell;

typedef struct Derivativelist {
    struct Derivativecell * head;
} DerivativeList;

Nodelist * createList();
Nodecell * createCell(struct Node * node);
bool isInList(Nodelist * nodelist, char data);

#endif //EXQUISITUS_C_ADAVERIS_LIST_H
