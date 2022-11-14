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

    FILE * file = fopen("../dico_10_lignes.txt", "r");
    char line[256];
    while (fgets(line, sizeof(line), file)) {
        char * word = strtok(line, "\t");
        word = strtok(NULL, "\t");
        printf("%s\n", word);
        addWord(tree, word);
    }


    printTreeParenthese(tree->root);


    return 0;
}