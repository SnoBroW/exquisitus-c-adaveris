#ifndef EXQUISITUS_C_ADAVERIS_DERIVATIVE_H
#define EXQUISITUS_C_ADAVERIS_DERIVATIVE_H

#include <string.h>


typedef struct Derivative {
    enum type { ADV, NOM, VER, ADJ, DETR, PRON, PREP, CONJ, ABRV, INTJ, ONOM, QPRO, dtype} type;
    enum gender { MAS, FEM, INVGEN, CARD, dgender } gender;
    enum tense { IPRE, IFUT, IPSIM, IIMP, SIMP, SPRE, INF, CPRE, PPRE, PPAS, IMP, IMPRE, dtense }  tense;
    enum person { P1, P2, P3, dperson } person;
    enum number { SG, PL, INVPL, dnumber } number;
    char word[32];
} Derivative;

Derivative * createEmptyDerivative();
Derivative createDerivative(enum type type, enum gender gender, enum tense tense, enum person person, enum number number);

Derivative * processDerivative(char * form, char * word);

bool checkDerivativeRequirements(Derivative * derivative, Derivative requirements);


enum type getType(char * form);
enum gender getGender(char * gender);
enum number getNumber(char * number);
enum tense getTense(char * tense);
enum person getPerson(char * person);

#endif //EXQUISITUS_C_ADAVERIS_DERIVATIVE_H
