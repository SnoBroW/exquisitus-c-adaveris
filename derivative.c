//
// Created by Gabriel on 14/11/2022.
//

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
