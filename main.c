#include <stdio.h>
#include "tree.h"
#include "io.h"


int main(int argc, char *argv[]) {

    initRand();

    Dictionary * dict = initDict("../dicts/dictionnaire_non_accentue.txt");

    // searchWord(dict->trees[1], "abandonner");
    // printf("j'adore %s les %s %s", randomWord(dict->trees[2])->derivatives->base, randomWord(dict->trees[1])->derivatives->base, randomWord(dict->trees[3])->derivatives->base);
    // printTree(dict->trees[0]->root);

    Node * word = randomWord(dict->trees[2]);


    return 0;
}