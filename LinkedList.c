#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "log.h"

void init(LinkedList *list) {
    log_info("Iniciando lista");
    log_trace("init ->");
    list->first=NULL;
    list->size=0;
    log_debug("lis->first: %p", list->first);
    log_debug("list->size: %d", list->size);
    log_trace("init ->");
}
int enqueue(LinkedList *list, void *data) {
    log_info("Enfilerando elemento");
    log_trace("enqueue ->");
    Node *newNode = (Node *)malloc(sizeof(Node));
    if(newNode==NULL) {
        log_error("Memória insuficiente!");
        return -1;
    } 
    newNode->data = data;
    newNode->next = NULL;
    log_debug("newNode->(data, next): (%p, %p)", newNode->data, newNode->next);
    if(isEmpty(list)) {
        list->first = newNode;
        log_debug("list->firt: %p", list->first);
    }
    else {
        Node *aux = list->first;
        log_debug("(Node)aux: %p", aux);
        while(aux->next!=NULL) {
            aux = aux->next;
            log_debug("(Node)aux: %p", aux);
        }
        aux->next = newNode;
        log_debug("(Node)aux->next: %p", aux->next);
    }
    list->size++;
    log_debug("list->size: %d", list->size);
    log_trace("enqueue <-");
    return 1;
}
void* dequeue(LinkedList *list) {
    log_info("Desenfileirando/desempilhando elemento");
    log_trace("dequeue ->");
    if(isEmpty(list)) return NULL;

    Node *aux = list->first;
    list->first = list->first->next;
    void *auxData = aux->data;
    free(aux);

    list->size--;
    log_trace("dequeue <-");
    return auxData;
}
void* first(LinkedList *list) {
    log_info("Retornando elemeno do inicio/topo");
    log_trace("first ->");
    log_trace("first <-");
    return isEmpty(list)?NULL:list->first->data;
}
void* last(LinkedList *list) {
    log_info("Retornando elemento do final/fundo");
    log_trace("last ->");
    if(isEmpty(list)) return NULL;

    Node *aux = list->first;
    while(aux->next!=NULL)
        aux = aux->next;
    log_trace("last <-");
    return aux->data;
}
int push(LinkedList *list, void *data) {
    log_info("Empilhando elemento");
    log_trace("push ->");
    Node *newNode = (Node *)malloc(sizeof(Node));
    if(newNode==NULL) return -1;
    newNode->data = data;

    newNode->next = isEmpty(list)?NULL:list->first;
    list->first = newNode;

    list->size++;
    log_trace("push <-");
    return 1;
}
void* pop(LinkedList *list) {
    log_trace("pop ->");
    void *data = dequeue(list);
    log_trace("pop <-");
    return data;
}
void* top(LinkedList *list) {
    log_trace("top ->");
    void *data = first(list);
    log_trace("top <-");
    return data;
}
bool isEmpty(LinkedList *list) {
    log_info("Verificando se a lista está vazia");
    log_trace("isEmpty ->");
    log_trace("isEmpty <-");
    return list->first==NULL;
}
int indexOf(LinkedList *list, void *data, compare equal) {
    log_info("Buscando posição do elemento");
    log_trace("indexOf ->");
    log_trace("indexOf <-");
}
void* getPos(LinkedList *list, int pos) {
    log_info("Retornando dados na posição %d", pos);
    log_trace("getPos ->");
    if(isEmpty(list) || pos < 0 || pos >= list->size) return NULL;

    Node *aux = (Node *)malloc(sizeof(Node));
    int i = 0;

    aux = list->first;
    while(i != pos) {
        i++;
        aux = aux->next; 
    }
    log_trace("gotPos <-");
    return aux->data;
}
Node* getNodeByPos(LinkedList *list, int pos) {
    log_info("Retornando nó na posição %d", pos);
    log_trace("getNodeByPos ->");
    if(isEmpty(list) || pos < 0 || pos >= list->size) return NULL;

    Node *aux = (Node *)malloc(sizeof(Node));
    int i = 0;

    aux = list->first;
    while(i != pos) {
        i++;
        aux = aux->next; 
    }
    log_trace("getNodeByPos <-");
    return aux;
}
int add(LinkedList *list, int pos, void *data)  {
    log_info("Adicionando elemento na posição %d", pos);
    log_trace("add ->");

    Node *newNode = (Node *)malloc(sizeof(Node));
    if(newNode==NULL) {
        log_error("Memória insuficiente!");
        return -1;
    } 
    newNode->data = data;
    newNode->next = NULL;
    log_debug("newNode->(data, next): (%p, %p)", newNode->data, newNode->next);

    Node *aux = list->first;
    for(int count=0; aux->next!=NULL && count<pos; count++, aux = aux->next);
    newNode->next = aux->next;
    aux->next = newNode;

    list->size++;

    log_trace("add <-");
    return 1;
}
int addAll(LinkedList *listDest, int pos, LinkedList *listSource)   {
    log_info("Adicionando lista de elementos na posição %d", pos);
    log_trace("addAll ->");

    log_trace("addAll <-");
    return 1;    
}
void* removePos(LinkedList *list, int pos)  {
    log_info("Removendo elemento na posição %d", pos);
    log_trace("removePos ->");
    if(isEmpty(list) || pos < 0 || pos >= list->size) return NULL;

    log_trace("removePos <-");
}
bool removeData(LinkedList *list, void *data, compare equal)    {
    log_info("Removendo elemento");
    log_trace("removeData ->");
    log_trace("removeData <-");
}