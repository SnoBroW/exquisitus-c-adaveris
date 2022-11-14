//
// Created by Gabriel on 09/11/2022.
//

#ifndef EXQUISITUS_C_ADAVERIS_TREE_H
#define EXQUISITUS_C_ADAVERIS_TREE_H

#include "list.h"


typedef struct Node {
    char data;
    struct Nodelist * children;
    struct DerivativeList * derivatives;
} Node;

typedef struct Tree {
    struct Node *root;
} Tree;

typedef struct Derivative {
    // rien sa mère
} Derivative;

Tree * createTree();
Node * createNode(char data);
void addNode(Node * parent, Node * child);
void addWord(Tree * tree, char * word);

void printTree(Node * node);
void printTreeParenthese(Node * node);



#endif //EXQUISITUS_C_ADAVERIS_TREE_H
