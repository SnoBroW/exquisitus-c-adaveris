//
// Created by Gabriel on 10/11/2022.
//

#include <stdlib.h>
#include <stdbool.h>

#include "list.h"
#include "tree.h"

struct Nodelist * createList() {
    struct Nodelist * list = malloc(sizeof(struct Nodelist));
    list->head = NULL;
    return list;
}

struct Nodecell * createCell(Node * node) {
    struct Nodecell * cell = malloc(sizeof(struct Nodecell));
    cell->node = node;
    cell->next = NULL;
    return cell;
}

// check if a char is in a list of nodes
bool isInList(Nodelist * nodelist, char data) {
    Nodecell * head = nodelist->head;
    while(head != NULL) {
        if(head->node->data == data) {
            return true;
        }
        head = head->next;
    }
    return false;
}