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

    if(*list == NULL) {
        *list = newNode;
    }
    else {
        Node *aux = NULL;
        for(aux = *list; aux->next != NULL; aux = aux->next);
        aux->next = newNode;
    }

    log_trace("addAtom <-");
    return 1;
}
int addList(Node **list, Node **subList) {
    log_info("Adicionando lista");
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

    if(*list == NULL) {
        *list = newNode;
    }
    else {
        Node *aux = NULL;
        for(aux = *list; aux->next != NULL; aux = aux->next);
        aux->next = newNode;
    }

    log_trace("addList <-");
    return 1;
}
Node* head(Node *list) {
    log_info("Retornado a cabeça da lista");
    log_trace("head ->");
    
    if(list == NULL) {
        log_trace("head <-");
        return list;
    }
    else {
        Node *headAux = NULL;
        if(list->type == 0) {
            headAux = (Node *)malloc(sizeof(Node));
            if(headAux == NULL) {   
                log_trace("head <-");
                return headAux;
            }
            headAux->type = 1;
            headAux->atomList.list = list->atomList.list;
            headAux->next = NULL;
        }
        else {
            headAux = list->atomList.list;    
        }
        log_trace("head <-");
        return headAux;
    }   
}
Node* tail(Node *list) {
    log_info("Retornado a cauda da lista");
    log_trace("tail ->");

    if(list == NULL) {
        log_trace("tail <-");
        return list;
    }
    else {
        log_trace("tail <-");
        return list->next;
    }   
}
void show(Node *list) {
    log_info("Mostrando toda a lista");
    log_trace("show ->");
    printf("( ");
    Node *aux = NULL;
    for(aux = list; aux != NULL; aux = aux->next) {
        if (aux->type == 0) {
            printf("%d ",aux->atomList.atom);
        } else {
            show(aux->atomList.list);
        }
    }
    printf(")");
    log_trace("show <-");
}
bool search(Node *list, int atom) {
    log_info("Buscando existência de átomo na lista");
    log_trace("search ->");
    bool currentBool = false;
    if(list != NULL) {
        Node *aux = NULL;
        for(aux = list; aux != NULL; aux = aux->next) {
            if (aux->type == 1) {
                bool newBool = search(aux->atomList.list, atom);
                if(newBool == true) {
                    currentBool = true;
                    log_trace("search <-");
                    return currentBool;
                }
            }
            else {
                if(aux->atomList.atom == atom) {
                    currentBool = true;
                    log_trace("search <-");
                    return currentBool;
                }
            }
        }
    }
    log_trace("search <-");
    return currentBool;
}
int depth(Node *list) {
    log_info("Buscando profindidade da lista");
    log_trace("depth ->");
    int currentDepth = 0;
    if(list == NULL) {
        log_trace("depth <-");
        return 0;
    }
    Node *aux = NULL;
    for(aux = list; aux != NULL; aux = aux->next) {
        if(aux->type == 1) {
            int newDepth = depth(aux->atomList.list);
            if(newDepth > currentDepth) {
            currentDepth = newDepth;
            }
        }
    }
    log_trace("depth <-");
    return currentDepth + 1;
}