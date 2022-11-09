//
// Created by Gabriel on 09/11/2022.
//

#ifndef EXQUISITUS_C_ADAVERIS_TREE_H
#define EXQUISITUS_C_ADAVERIS_TREE_H

typedef struct Cell Cell;
typedef struct List List;
typedef struct Node Node;
typedef struct Tree Tree;

typedef struct Cell {
    Node * data;
    struct Cell * next;
} Cell;

typedef struct List {
    Cell * head;
} List;

typedef struct Node {
    char data;
    List children;
} Node;

typedef struct Tree {
    Node *root;
} Tree;






#endif //EXQUISITUS_C_ADAVERIS_TREE_H
