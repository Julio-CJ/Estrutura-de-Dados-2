#include <stdlib.h>
#include <stdio.h>
#include "GeneralizedLinkedList.h"
#include "log.h"

int addAtom(Node **list, int atom) {
    log_info("Adicionando átomo");
    log_trace("addAtom ->");
    Node *newNode = (Node *)malloc(sizeof(Node));

    if(newNode == NULL) {
        log_error("Memória insuficiente!");
        return -1;
    }

    newNode->type = 0;
    newNode->next = NULL;
    newNode->atomList.atom = atom;

    log_debug("newNode->(type, atomList, next): (%d, %p, %p)", newNode->type, newNode->atomList.atom, newNode->next);

    Node *aux = *list;
    while(aux->next!=NULL) {
        aux = aux->next;
    }
    aux->next = newNode;

    log_trace("addAtom <-");
}
int addList(Node **list, Node **subList) {
    log_info("Adicionando Lista");
    log_trace("addList ->");
    Node *newNode = (Node *)malloc(sizeof(Node));

    if(newNode == NULL) {
        log_error("Memória insuficiente!");
        return -1;
    }

    newNode->type = 1;
    newNode->next = NULL;
    newNode->atomList.list = *subList;

    log_debug("newNode->(type, atomList, next): (%d, %p, %p)", newNode->type, newNode->atomList.list, newNode->next);

    Node *aux = *list;
    while(aux->next!=NULL) {
        aux = aux->next;
    }
    aux->next = newNode;

    log_trace("addList <-");
}
Node* head(Node *list) {

}
Node* tail(Node *list) {

}
void show(Node *list) {

}
bool search(Node *list, int atom) {

}
int depth(Node *list) {

}