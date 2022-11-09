//
// Created by Gabriel on 09/11/2022.
//

#ifndef EXQUISITUS_C_ADAVERIS_LIST_H
#define EXQUISITUS_C_ADAVERIS_LIST_H

#include "tree.h"

typedef struct Cell {
    Node * data;
    struct Cell * next;
} Cell;

typedef struct List {
    Cell * head;
} List;



#endif //EXQUISITUS_C_ADAVERIS_LIST_H
