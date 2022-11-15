#include "tree.h"
#include "io.h"


int main(int argc, char *argv[]) {

    initRand();

    Dictionary * dict = initDict("../dicts/dico_bien.txt");

    // ça on sait faire
    // searchWord(dict->trees[1], "abandonner");
    // randomWord(dict->trees[1])->derivatives->base;

    printTree(dict->trees[0]->root);



    return 0;
}