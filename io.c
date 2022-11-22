#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "io.h"
#include "derivative.h"
#include "tree.h"


int initRand() {
    time_t seed = time(NULL);
    srand(seed);
    // printf("%ld\n\n", seed);
    return seed;
}

Dictionary * initDict(char * filename) {
    Dictionary * dict = createDictionary();
    FILE * file = fopen(filename, "r");
    if(file == NULL) {
        printf("Erreur d'importation du dictionnaire\n");
        exit(1);
    }
    char line[256];
    while (fgets(line, sizeof(line), file)) {
        char * derivativeWord = strtok(line, "\t");
        char * baseWord = strtok(NULL, "\t");
        char * derivativeType = strtok(NULL, "\t");
        derivativeType[strlen(derivativeType) - 1] = '\0';
        char * derivativeTypeCopy = malloc(strlen(derivativeType) + 1);
        strcpy(derivativeTypeCopy, derivativeType);
        int type = getType(derivativeTypeCopy);
        if(type != dtype) {
            addAll(dict->trees[type], baseWord, derivativeWord, derivativeType);
        }
        free(derivativeTypeCopy);
    }
    fclose(file);
    return dict;
}
