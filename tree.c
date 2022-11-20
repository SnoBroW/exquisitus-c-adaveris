#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "list.h"
#include "tree.h"


Dictionary * createDictionary() {
    Dictionary * dict = malloc(sizeof(Dictionary));
    for(int i = 0; i < 4; i++) {
        dict->trees[i] = createTree();
    }
    return dict;
}

void freeDictionary(Dictionary * dict) {
    for(int i = 0; i < 4; i++) {
        freeTree(dict->trees[i]);
    }
    free(dict);
}

Tree * createTree() {
    Tree * tree = malloc(sizeof(Tree));
    tree->root = createNode(' ');
    tree->size = 0;
    return tree;
}

void freeTree(Tree * tree) {
    freeNode(tree->root);
    free(tree);
}

Node * createNode(char data) {
    Node * node = malloc(sizeof(Node));
    node->data = data;
    node->children = createNodelist();
    node->derivatives = NULL;
    return node;
}

void freeNode(Node * node) {
    freeNodelist(node->children);
    if(node->derivatives != NULL) {
        freeDerivativeList(node->derivatives);
    }
    free(node);
}

void addNode(Node * parent, Node * child) {
    NodeCell * cell = createNodecell(child);
    if (parent->children->head == NULL) {
        parent->children->head = cell;
    } else {
        NodeCell * temp = parent->children->head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = cell;
    }
}

Node * addWord(Tree * tree, char * word) {
    Node * temp = tree->root;
    NodeCell * tempNodelist = temp->children->head;

    for(int i = 0; i < strlen(word); i++) {
        if(!isInList(temp->children, word[i])) {
            Node * node = createNode(word[i]);
            addNode(temp, node);
            temp = node;
        } else {
            while(tempNodelist->node->data != word[i]) {
                tempNodelist = tempNodelist->next;
            }
            temp = tempNodelist->node;
            tempNodelist = temp->children->head;
        }
    }
    if (temp->derivatives == NULL) {
        temp->derivatives = createDerivativeList();
        strcpy(temp->derivatives->base, word);
        tree->size++;
    }
    return temp;
}


void addDerivative(Node * node, Derivative * derivative) {
    DerivativeCell * cell = createDerivativeCell(derivative);
    if (node->derivatives->head == NULL) {
        node->derivatives->head = cell;
    } else {
        DerivativeCell * temp = node->derivatives->head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = cell;
    }
}

void addAll(Tree * tree, char * baseWord, char * derivativeWord, char * derivativeType) {
    Node * currentWord = addWord(tree, baseWord);
    addDerivative(currentWord, processDerivative(derivativeWord, derivativeType));
}

Node * searchWord(Tree * tree, char * word) {
    Node * temp = tree->root;
    NodeCell * tempNodelist = temp->children->head;

    for(int i = 0; i < strlen(word); i++) {
        if(!isInList(temp->children, word[i])) {
            return NULL;
        } else {
            while(tempNodelist->node->data != word[i]) {
                tempNodelist = tempNodelist->next;
            }
            temp = tempNodelist->node;
            tempNodelist = temp->children->head;
        }
    }
    return temp;
}


char * searchDerivation(Tree * tree, char * baseword, Derivative derivative) {
    return applyDerivative(searchWord(tree, baseword), derivative);
}

Node * randomWord(Tree * tree) {
    int i = 0;
    return recursiveRandomWord(tree->root, &i);
}

char * randomDerivation(Dictionary * dict, Derivative derivative) {
    Tree * tree = dict->trees[derivative.type];
    Node * node;
    char * word;
    do {
        node = randomWord(tree);
        word = applyDerivative(node, derivative);
    } while (word == NULL);
return word;
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


Node * recursiveRandomWord(Node * node, int * i) {
    Node * selected = NULL;
    Node * recursiveResult = NULL;
    NodeCell * temp = node->children->head;

    if (node->derivatives != NULL) {
        (*i)++;
        if(rand() % (*i) == 0) {
            selected = node;
        }
    }
    while(temp != NULL) {
        recursiveResult = recursiveRandomWord(temp->node, i);
        if(recursiveResult != NULL) {
            selected = recursiveResult;
        }
        temp = temp->next;
    }
    return selected;
}



void printTree(Node * node) {
    if(node->data != ' ') {
        printf("%c", node->data);
    }
    int doBracket = 0;
    NodeCell * temp = node->children->head;
    if (temp != NULL) {
        if (temp->next != NULL) {
            doBracket = 1;
            printf("[");
        }
        while (temp != NULL) {
            printTree(temp->node);
            temp = temp->next;
            if (temp != NULL) {
                printf(", ");
            }
        }
        if (doBracket) {
            printf("]");
        }
    }
}