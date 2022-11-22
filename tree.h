#ifndef EXQUISITUS_C_ADAVERIS_TREE_H
#define EXQUISITUS_C_ADAVERIS_TREE_H

#include "list.h"
#include "derivative.h"

typedef struct dictionary {
    struct Tree * trees[4];
} Dictionary;


typedef struct Node {
    char data;
    struct NodeList * children;
    struct DerivativeList * derivatives;
} Node;

typedef struct Tree {
    struct Node *root;
    int size;
} Tree;

Dictionary * createDictionary();
void freeDictionary(Dictionary * dict);

Tree * createTree();
void freeTree(Tree * tree);

Node * createNode(char data);
void freeNode(Node * node);

void addNode(Node * parent, Node * child);
Node * addWord(Tree * tree, char * word);
void addDerivative(Node * node, Derivative * derivative);
void addAll(Tree * tree, char * baseWord, char * derivativeWord, char * derivativeType);

Node * searchWord(Tree * tree, char * word);
char * searchDerivation(Tree * tree, char * baseword, Derivative derivative);

Node * recursiveRandomWord(Node * node, int * i);
Node * randomWord(Tree * tree);
char * randomDerivation(Dictionary * dict, Derivative derivative);

char * applyDerivative(Node * node, Derivative derivative);

void printTree(Node * node);



#endif //EXQUISITUS_C_ADAVERIS_TREE_H
