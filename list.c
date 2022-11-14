//
// Created by Gabriel on 10/11/2022.
//

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