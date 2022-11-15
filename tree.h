//
// Created by Gabriel on 09/11/2022.
//

#ifndef EXQUISITUS_C_ADAVERIS_TREE_H
#define EXQUISITUS_C_ADAVERIS_TREE_H

#include "list.h"
#include "derivative.h"


typedef struct Node {
    char data;
    struct NodeList * children;
    struct DerivativeList * derivatives;
} Node;

typedef struct Tree {
    struct Node *root;
    int size;
} Tree;

Tree * createTree();
Node * createNode(char data);
void addNode(Node * parent, Node * child);
Node * addWord(Tree * tree, char * word);
void addDerivative(Node * node, Derivative * derivative);
void addAll(Tree * tree, char * baseWord, char * derivative, char * derivativeType);

void printTree(Node * node);



#endif //EXQUISITUS_C_ADAVERIS_TREE_H
