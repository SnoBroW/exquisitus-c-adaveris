//
// Created by Gabriel on 09/11/2022.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tree.h"
#include "list.h"




int main(int argc, char *argv[]) {

    char toilet[] = "toilet";
    char toiture[] = "toiture";

    Tree * tree = createTree();
    Node * temp = tree->root;

    for(int i = 0; i < strlen(toilet); i++) {
        if(!isInList(temp->children, toilet[i])) {
            Node * node = createNode(toilet[i]);
            addNode(temp, node);
            temp = node;
        } else {
            temp = temp->children->head->node;
        }
    }

    temp = tree->root;

    for(int i = 0; i < strlen(toiture); i++) {
        if(!isInList(temp->children, toiture[i])) {
            Node * node = createNode(toiture[i]);
            addNode(temp, node);
            temp = node;
        } else {
            temp = temp->children->head->node;
        }
    }


    printTreeParenthese(tree->root);


    return 0;
}