//
// Created by Gabriel on 09/11/2022.
//

#ifndef EXQUISITUS_C_ADAVERIS_TREE_H
#define EXQUISITUS_C_ADAVERIS_TREE_H

#include "list.h"

typedef struct Node {
    char data;
    List children;
} Node;

typedef struct Tree {
    Node *root;
} Tree;



#endif //EXQUISITUS_C_ADAVERIS_TREE_H
