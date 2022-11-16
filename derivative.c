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
    } else {
        return -1;
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
        return -1;
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
        return -1;
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
        return -1;
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
        return -1;
    }
}