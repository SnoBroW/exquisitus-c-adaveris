#include <malloc.h>


#include "derivative.h"

Derivative * createDerivative() {
    Derivative * derivative = malloc(sizeof(Derivative));
    return derivative;
}

// todo process form
Derivative * processDerivative(char * form, char * word) {
    Derivative * derivative = createDerivative();
    return derivative;
}


enum type getType(char * form) {
    // do not work for conj and con
    char identifier[3];
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
