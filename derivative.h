//
// Created by Gabriel on 14/11/2022.
//

#ifndef EXQUISITUS_C_ADAVERIS_DERIVATIVE_H
#define EXQUISITUS_C_ADAVERIS_DERIVATIVE_H

typedef struct Derivative {
    enum type { NOM, VER, ADJ, ADV, PRE, CON, PRO, DET, ABR, INT, ONO } type;
    enum gender { MAS, FEM, INVGEN } gender;
    enum tense { ENCULE } tense;
    enum person { P1, P2, P3 } person;
    enum number { SG, PL, INVPL } number;
} Derivative;

Derivative * createDerivative();
Derivative * processDerivative(char * form, char * word);


#endif //EXQUISITUS_C_ADAVERIS_DERIVATIVE_H
