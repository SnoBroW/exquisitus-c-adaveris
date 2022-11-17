#include <stdio.h>
#include <stdlib.h>
#include "tree.h"
#include "io.h"
#include "menu.h"


int main(int argc, char *argv[]) {

    initRand();


    char word[128];
    pattern3(dict, word);
    printf("%s", word);

    return 0;
}