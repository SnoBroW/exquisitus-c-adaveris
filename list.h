//
// Created by Gabriel on 10/11/2022.
//

#ifndef EXQUISITUS_C_ADAVERIS_LIST_H
#define EXQUISITUS_C_ADAVERIS_LIST_H

#include "tree.h"


typedef struct Cell {
    struct Node * node;
    struct Cell * next;
} Cell;

typedef struct List {
    struct Cell * head;
} List;


List * createList();
Cell * createCell(struct Node * node);
void addToList(struct List * list, struct Cell * cell);



#endif //EXQUISITUS_C_ADAVERIS_LIST_H
