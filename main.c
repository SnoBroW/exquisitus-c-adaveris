//
// Created by Gabriel on 09/11/2022.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tree.h"
#include "list.h"




int main(int argc, char *argv[]) {

    Tree * tree = createTree();

    FILE * file = fopen("../dicts/dico_raisonnable.txt", "r");
    char line[256];
    while (fgets(line, sizeof(line), file)) {
        char * derivative = strtok(line, "\t");
        char * baseWord = strtok(NULL, "\t");
        char * derivativeType = strtok(NULL, "\t");
        // todo make all 4 trees
        // todo select tree depending on derivative type
        addWord(tree, baseWord);
    }


    printTree(tree->root);


    return 0;
}