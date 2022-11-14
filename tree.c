//
// Created by Gabriel on 10/11/2022.
//

#include <stdlib.h>
#include <stdio.h>

#include "list.h"
#include "tree.h"


Tree * createTree() {
    Tree * tree = malloc(sizeof(Tree));
    tree->root = createNode(' ');
    return tree;
}

Node * createNode(char data) {
    Node * node = malloc(sizeof(Node));
    node->data = data;
    node->children = createList();
    return node;
}

void addNode(Node * parent, Node * child) {
    Nodecell * cell = createCell(child);
    if (parent->children->head == NULL) {
        parent->children->head = cell;
    } else {
        Nodecell * temp = parent->children->head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = cell;
    }
}

// cette fonction ne sert à rien
void printTree(Node * node) {
    printf("%c", node->data);
    Nodecell * head = node->children->head;
    while(head != NULL) {
        printTree(head->node);
        head = head->next;
    }
}

// cette fonction sert un peu moins à rien
void printTreeParenthese(Node * node) {
    printf("%c", node->data);
    Cell * temp = node->children->head;
    if (temp != NULL) {
        printf("[");
        while (temp != NULL) {
            printTreeParenthese(temp->node);
            temp = temp->next;
            if (temp != NULL) {
                printf(", ");
            }
        }
        printf("]");
    }
}