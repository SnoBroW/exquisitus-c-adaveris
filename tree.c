//
// Created by Gabriel on 10/11/2022.
//

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

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

void addWord(Tree * tree, char * word) {
    Node * temp = tree->root;

    for(int i = 0; i < strlen(word); i++) {
        if(!isInList(temp->children, word[i])) {
            Node * node = createNode(word[i]);
            addNode(temp, node);
            temp = node;
        } else {
            temp = temp->children->head->node;
        }
    }
}


void printTree(Node * node) {
    Nodecell * temp = node->children->head;
    while (temp != NULL) {
        printf("%c ", temp->node->data);
        printTree(temp->node);
        if (temp->next != NULL) {
            printf("\t");
        }
        temp = temp->next;
    }

}


void printTreeParenthese(Node * node) {
    if(node->data != ' ') {
        printf("%c", node->data);
    }
    int doBracket = 0;
    Nodecell * temp = node->children->head;
    if (temp != NULL) {
        if (temp->next != NULL) {
            doBracket = 1;
            printf("[");
        }
        while (temp != NULL) {
            printTreeParenthese(temp->node);
            temp = temp->next;
            if (temp != NULL) {
                printf(", ");
            }
        }
        if (doBracket) {
            printf("]");
        }
    }
}