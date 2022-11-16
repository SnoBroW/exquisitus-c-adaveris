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
        char * derivativeWord = strtok(line, "\t");
        char * baseWord = strtok(NULL, "\t");
        char * derivativeType = strtok(NULL, "\t");
        char * derivativeTypeCopy = strcpy(malloc(strlen(derivativeType) + 1), derivativeType);
        derivativeTypeCopy = strtok(derivativeTypeCopy, "\n");
        int type = getType(derivativeTypeCopy);
        if(type != dtype) {
            addAll(dict->trees[type], baseWord, derivativeWord, derivativeType);
        }
        free(derivativeTypeCopy);
    }
    fclose(file);
    return dict;
}
