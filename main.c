//
// Created by Gabriel on 09/11/2022.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tree.h"


List * createList() {
    List * list = malloc(sizeof(List));
    list->head = NULL;
    return list;
}

Tree * createTree() {
    Tree * tree = malloc(sizeof(Tree));
    tree->root = NULL;
    return tree;
}

Node * createNode(char data) {
    Node * node = malloc(sizeof(Node));
    node->data = data;
    node->children = *createList();
    return node;
}

void freeList(List * list) {
    Cell * current = list->head;
    while (current != NULL) {
        Cell * next = current->next;
        free(current);
        current = next;
    }
    free(list);
}

void freeNode(Node * node) {
    freeList(&node->children);
    free(node);
}

void freeTree(Tree * tree) {
    freeNode(tree->root);
    free(tree);
}


int main() {

    char word[] = "toilet";

    Tree * tree = createTree();
    List * list = createList();

    freeList(list);
    freeTree(tree);

    return 0;
}