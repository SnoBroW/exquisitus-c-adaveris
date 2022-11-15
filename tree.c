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
    tree->size = 0;
    return tree;
}

Node * createNode(char data) {
    Node * node = malloc(sizeof(Node));
    node->data = data;
    node->children = createNodelist();
    node->derivatives = NULL;
    return node;
}

void addNode(Node * parent, Node * child) {
    NodeCell * cell = createNodecell(child);
    if (parent->children->head == NULL) {
        parent->children->head = cell;
    } else {
        NodeCell * temp = parent->children->head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = cell;
    }
}

Node * addWord(Tree * tree, char * word) {
    Node * temp = tree->root;
    NodeCell * tempNodelist = temp->children->head;

    for(int i = 0; i < strlen(word); i++) {
        if(!isInList(temp->children, word[i])) {
            Node * node = createNode(word[i]);
            addNode(temp, node);
            temp = node;
        } else {
            while(tempNodelist->node->data != word[i]) {
                tempNodelist = tempNodelist->next;
            }
            temp = tempNodelist->node;
            tempNodelist = temp->children->head;
        }
    }
    if (temp->derivatives == NULL) {
        temp->derivatives = createDerivativeList();
        tree->size++;
    }
    return temp;
}

// by copilot
void addDerivative(Node * node, Derivative * derivative) {
    DerivativeCell * cell = createDerivativeCell(derivative);
    if (node->derivatives->head == NULL) {
        node->derivatives->head = cell;
    } else {
        DerivativeCell * temp = node->derivatives->head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = cell;
    }
}

void addAll(Tree * tree, char * baseWord, char * derivative, char * derivativeType) {
    Node * currentWord = addWord(tree, baseWord);
    addDerivative(currentWord, processDerivative(derivative, derivativeType));
}



void printTree(Node * node) {
    if(node->data != ' ') {
        printf("%c", node->data);
    }
    int doBracket = 0;
    NodeCell * temp = node->children->head;
    if (temp != NULL) {
        if (temp->next != NULL) {
            doBracket = 1;
            printf("[");
        }
        while (temp != NULL) {
            printTree(temp->node);
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