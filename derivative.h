#ifndef EXQUISITUS_C_ADAVERIS_DERIVATIVE_H
#define EXQUISITUS_C_ADAVERIS_DERIVATIVE_H

#include <string.h>

typedef struct Derivative {
    enum type { ADV, NOM, VER, ADJ, DETR, PRON, PREP, CONJ, ABRV, INTJ, ONOM, QPRO } type;  // /!\ con =/= conj
    enum gender { MAS, FEM, INVGEN, CARD } gender;
    enum tense { IPRE, IPSIM, IIMP, PPRE, SIMP, PPAS, SPRE, IFUT, INF, CPRE, IMPRE, IMP }  tense;
    enum person { P1, P2, P3 } person;
    enum number { SG, PL, INVPL } number;
    char word[32];
} Derivative;

Derivative * createDerivative();
Derivative * processDerivative(char * form, char * word);

enum type getType(char * form);
enum gender getGender(char * gender);
enum number getNumber(char * number);
enum tense getTense(char * tense);
enum person getPerson(char * person);

#endif //EXQUISITUS_C_ADAVERIS_DERIVATIVE_H
