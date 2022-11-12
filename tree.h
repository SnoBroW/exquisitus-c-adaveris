//
// Created by Gabriel on 09/11/2022.
//

#ifndef EXQUISITUS_C_ADAVERIS_TREE_H
#define EXQUISITUS_C_ADAVERIS_TREE_H

#include "list.h"


typedef struct Node {
    char data;
    struct List * children;
} Node;

typedef struct Tree {
    struct Node *root;
} Tree;

Tree * createTree();
Node * createNode(char data);
void addNode(Node * parent, Node * child);
void printTree(Node * node);




#endif //EXQUISITUS_C_ADAVERIS_TREE_H
