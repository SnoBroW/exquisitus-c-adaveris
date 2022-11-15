#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "io.h"
#include "derivative.h"
#include "tree.h"


void initRand() {
    time_t seed = time(NULL);
    srand(seed);
    // printf("%ld\n\n", seed);
}

Dictionary * initDict(char * filename) {
    Dictionary * dict = createDictionary();
    FILE * file = fopen(filename, "r");
    char line[256];
    while (fgets(line, sizeof(line), file)) {
        char * derivative = strtok(line, "\t");
        char * baseWord = strtok(NULL, "\t");
        char * derivativeType = strtok(NULL, "\t");

        int type = getType(derivativeType);
        if(type != -1) {
            addAll(dict->trees[type], baseWord, derivative, derivativeType);
        }
    }
    fclose(file);
    return dict;
}
