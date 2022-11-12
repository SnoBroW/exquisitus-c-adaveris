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
    Node * temp = NULL;

    for(int i = 0; i < strlen(toilet); i++) {
        Node * node = createNode(toilet[i]);
        if (tree->root == NULL) {
            tree->root = node;
            temp = node;
        } else {
            addNode(temp, node);
            temp = node;
        }
    }

    printTree(tree->root);


    return 0;
}