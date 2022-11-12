//
// Created by Gabriel on 10/11/2022.
//

#include <stdlib.h>
#include <stdio.h>

#include "list.h"
#include "tree.h"


Tree * createTree() {
    Tree * tree = malloc(sizeof(Tree));
    tree->root = NULL;
    return tree;
}

Node * createNode(char data) {
    Node * node = malloc(sizeof(Node));
    node->data = data;
    node->children = createList();
    node->children->head = NULL;
    return node;
}

void addNode(Node * parent, Node * child) {
    addToList(parent->children, createCell(child));
}

void printTree(Node * node) {
    printf("%c", node->data);
    Cell * head = node->children->head;
    while(head != NULL) {
        printTree(head->node);
        head = head->next;
    }
}