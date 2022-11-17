#include <malloc.h>
#include <stdio.h>
#include <stdbool.h>


#include "derivative.h"

Derivative * createEmptyDerivative() {
    Derivative * derivative = malloc(sizeof(Derivative));
    derivative->type = dtype;
    derivative->gender = dgender;
    derivative->tense = dtense;
    derivative->person = dperson;
    derivative->number = dnumber;
    return derivative;
}

Derivative createDerivative(enum type type, enum gender gender, enum tense tense, enum person person, enum number number) {
    Derivative derivative ;
    derivative.type = type;
    derivative.gender = gender;
    derivative.tense = tense;
    derivative.person = person;
    derivative.number = number;
    return derivative;
}

Derivative * processDerivative(char * word, char * form) {
    Derivative * derivative = createEmptyDerivative();
    char * currentDerivation, * currentParameter;
    derivative->type = getType(form);
    if(derivative->type >= NOM && derivative->type <= PRON) {
        while((currentDerivation = strtok(NULL, ":"))) {
            currentParameter = strtok(currentDerivation, "+");
            do {
                switch (derivative->type) {
                    case VER:
                        derivative->tense = derivative->tense == dtense ? getTense(currentParameter) : derivative->tense;
                        derivative->person = derivative->person == dperson ? getPerson(currentParameter) : derivative->person;
                    case NOM:
                    case ADJ:
                    case DETR:
                        derivative->gender = derivative->gender == dgender ? getGender(currentParameter) : derivative->gender;
                        derivative->number = derivative->number == dnumber ? getNumber(currentParameter) : derivative->number;
                        break;
                    default:
                        // ici atterit tout ce qui est sans paramètres avancés
                        // ADV, PREP, INTJ, CONJ, CONN, ABRV, ONOM, QPRO
                        break;
                }
            } while ((currentParameter = strtok(NULL, "+")));
        }
    }
    strncpy(derivative->word, word, 32);
    return derivative;
}

bool checkDerivativeRequirements(Derivative * derivative, Derivative requirements) {
    bool result = true;
    result = derivative->type == requirements.type && result;
    result = (derivative->gender == requirements.gender || requirements.gender == dgender || derivative->gender == INVGEN) && result;
    result = (derivative->number == requirements.number || requirements.number == dnumber || derivative->number == INVPL) && result;
    result = (derivative->tense == requirements.tense || requirements.tense == dtense || derivative->tense == dtense) && result;
    result = (derivative->person == requirements.person || requirements.person == dperson || derivative->person == dperson) && result;
    return result;
}

char * applyDerivative(Node * node, Derivative derivative) {
    DerivativeCell * tempCell = node->derivatives->head;
    while(tempCell != NULL) {
        if(checkDerivativeRequirements(tempCell->derivative, derivative)) {
            return tempCell->derivative->word;
        }
        tempCell = tempCell->next;
    }
    return NULL;
}


enum type getType(char * type) {
    // does not work for conj and con
    char * identifier = strtok(type, ":");
    if (strcmp(identifier, "Ver") == 0) {
        return VER;
    } else if (strcmp(identifier, "Nom") == 0) {
        return NOM;
    } else if (strcmp(identifier, "Adv") == 0) {
        return ADV;
    } else if (strcmp(identifier, "Adj") == 0) {
        return ADJ;
    } else {
        return dtype;
    }
}


enum gender getGender(char * gender) {
    if (strcmp(gender, "Mas") == 0) {
        return MAS;
    } else if (strcmp(gender, "Fem") == 0) {
        return FEM;
    } else if (strcmp(gender, "InvGen") == 0) {
        return INVGEN;
    } else if (strcmp(gender, "Card") == 0) {
        return CARD;
    } else {
        return dgender;
    }
}


enum number getNumber(char * number) {
    if (strcmp(number, "SG") == 0) {
        return SG;
    } else if (strcmp(number, "PL") == 0) {
        return PL;
    } else if (strcmp(number, "InvPL") == 0) {
        return INVPL;
    } else {
        return dnumber;
    }
}


enum tense getTense(char * tense) {
    if (strcmp(tense, "IPre") == 0) {
        return IPRE;
    } else if (strcmp(tense, "IPSim") == 0) {
        return IPSIM;
    } else if (strcmp(tense, "IImp") == 0) {
        return IIMP;
    } else if (strcmp(tense, "PPre") == 0) {
        return PPRE;
    } else if (strcmp(tense, "SImp") == 0) {
        return SIMP;
    } else if (strcmp(tense, "PPas") == 0) {
        return PPAS;
    } else if (strcmp(tense, "SPre") == 0) {
        return SPRE;
    } else if (strcmp(tense, "IFut") == 0) {
        return IFUT;
    } else if (strcmp(tense, "Inf") == 0) {
        return INF;
    } else if (strcmp(tense, "CPre") == 0) {
        return CPRE;
    } else if (strcmp(tense, "ImPre") == 0) { // impératifs des verbes LAMBDA, NULS
        return IMPRE;
    } else if (strcmp(tense, "Imp") == 0) { // imperatif des verbes pronominaux, les BG
        return IMP;
    } else {
        return dtense;
    }
}

enum person getPerson(char * person) {
    if (strcmp(person, "P1") == 0) {
        return P1;
    } else if (strcmp(person, "P2") == 0) {
        return P2;
    } else if (strcmp(person, "P3") == 0) {
        return P3;
    } else {
        return dperson;
    }
}

