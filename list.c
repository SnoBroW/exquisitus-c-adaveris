//
// Created by Gabriel on 10/11/2022.
//

#include <stdlib.h>

#include "list.h"
#include "tree.h"

List * createList() {
    List * list = malloc(sizeof(List));
    list->head = NULL;
    return list;
}

Cell * createCell(Node * node) {
    Cell * cell = malloc(sizeof(Cell));
    cell->node = node;
    cell->next = NULL;
    return cell;
}

void addToList(List * list, Cell * cell){
    int i = 0;
    Cell * head = list->head;
    if(head == NULL) {
        list->head = cell;
        i++;
    } else {
        while(head->next != NULL) {
            i++;
            head = head->next;
        }
        head->next = cell;
    }
}