#include <stdlib.h>
#include <stdbool.h>

#include "list.h"
#include "tree.h"

NodeList * createNodelist() {
    NodeList * list = malloc(sizeof(NodeList));
    list->head = NULL;
    return list;
}

NodeCell * createNodecell(Node * node) {
    NodeCell * cell = malloc(sizeof(NodeCell));
    cell->node = node;
    cell->next = NULL;
    return cell;
}

void freeNodelist(NodeList * list) {
    NodeCell * temp = list->head;
    while(temp != NULL) {
        NodeCell * next = temp->next;
        free(temp);
        temp = next;
    }
    free(list);
}

DerivativeList * createDerivativeList() {
    DerivativeList * list = malloc(sizeof(DerivativeList));
    list->head = NULL;
    return list;
}

DerivativeCell * createDerivativeCell(Derivative * derivative) {
    DerivativeCell * cell = malloc(sizeof(DerivativeCell));
    cell->derivative = derivative;
    cell->next = NULL;
    return cell;
}

void freeDerivativeList(DerivativeList * list) {
    DerivativeCell * temp = list->head;
    while(temp != NULL) {
        DerivativeCell * next = temp->next;
        free(temp);
        temp = next;
    }
    free(list);
}

// check if a char is in a list of nodes
bool isInList(NodeList * nodelist, char data) {
    NodeCell * head = nodelist->head;
    while(head != NULL) {
        if(head->node->data == data) {
            return true;
        }
        head = head->next;
    }
    return false;
}