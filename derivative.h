//
// Created by Gabriel on 14/11/2022.
//

#ifndef EXQUISITUS_C_ADAVERIS_DERIVATIVE_H
#define EXQUISITUS_C_ADAVERIS_DERIVATIVE_H

#include <string.h>

typedef struct Derivative {
    enum type { NOM, VER, ADJ, ADV, PREP, CONJ, PRON, DETR, ABRV, INTJ, ONOM } type;  // /!\ con =/= conj
    enum gender { MAS, FEM, INVGEN, CARD } gender;
    enum tense { IPRE, IPSIM, IIMP, PPRE, SIMP, PPAS, SPRE, IFUT, INF, CPRE, IMPRE, IMP }  tense;
    enum person { P1, P2, P3 } person;
    enum number { SG, PL, INVPL } number;
} Derivative;

Derivative * createDerivative();
Derivative * processDerivative(char * form, char * word);
enum type getType(char * form);

#endif //EXQUISITUS_C_ADAVERIS_DERIVATIVE_H
