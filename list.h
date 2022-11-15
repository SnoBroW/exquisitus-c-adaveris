#ifndef EXQUISITUS_C_ADAVERIS_LIST_H
#define EXQUISITUS_C_ADAVERIS_LIST_H

#include <stdbool.h>

#include "tree.h"
#include "derivative.h"


typedef struct NodeCell {
    struct Node * node;
    struct NodeCell * next;
} NodeCell;

typedef struct NodeList {
    struct NodeCell * head;
} NodeList;

typedef struct DerivativeCell {
    struct Derivative * derivative;
    struct DerivativeCell * next;
} DerivativeCell;

typedef struct DerivativeList {
    struct DerivativeCell * head;
    char base[32];
} DerivativeList;

NodeList * createNodelist();
NodeCell * createNodecell(struct Node * node);
DerivativeList * createDerivativeList();
DerivativeCell * createDerivativeCell(struct Derivative * derivative);

bool isInList(NodeList * nodelist, char data);


#endif //EXQUISITUS_C_ADAVERIS_LIST_H
