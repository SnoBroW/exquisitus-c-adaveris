#include <malloc.h>
#include <stdio.h>


#include "derivative.h"

Derivative * createDerivative() {
    Derivative * derivative = malloc(sizeof(Derivative));
    return derivative;
}

Derivative * processDerivative(char * word, char * form) {
    Derivative * derivative = createDerivative();
    derivative->type = getType(form);
    if(derivative->type >= NOM && derivative->type <= PRON) {
        char * formEnd = strtok(form, ":");
        // todo a refaire avec des switch verts razer et des if rouges logitech cherry mx brown du cul
        formEnd = strtok(NULL, ":");
        printf("%s", formEnd);
    }
    strncpy(derivative->word, word, 32);
    return derivative;
}


enum type getType(char * form) {
    // do not work for conj and con
    char identifier[4];
    strncpy(identifier, form, 3);
    if (strcmp(identifier, "Ver") == 0) {
        return VER;
    } else if (strcmp(identifier, "Nom") == 0) {
        return NOM;
    } else if (strcmp(identifier, "Adv") == 0) {
        return ADV;
    } else if (strcmp(identifier, "Adj") == 0) {
        return ADJ;
    }
    // todo: the remaining ones
    return -1;
}
