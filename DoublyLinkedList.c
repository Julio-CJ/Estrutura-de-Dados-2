#include <stdio.h>
#include <stdlib.h>
#include "DoublyLinkedList.h"
#include "log.h"

void init(DoublyLinkedList *list) {
    log_info("Iniciando lista");
    log_trace("init ->");
    Node *trashNode=(Node*)malloc(sizeof(Node));
    if(trashNode == NULL) {
        log_error("Memória insuficiente!");
    }
    trashNode->data = NULL;
    trashNode->previous = trashNode;
    trashNode->next = trashNode;
    log_debug("trashNode->(previous, data, next): (%p, %p, %p)", trashNode->previous, trashNode->data, trashNode->next);
    list->first=trashNode;
    list->size = 0;
    log_debug("list->first: %p", list->first);
    log_debug("list->size: %d", list->size);
    log_trace("init <-");
}
int enqueue(DoublyLinkedList *list, void *data) {
    log_info("Enfilerando elemento");
    log_trace("enqueue ->");
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode==NULL) {
        log_error("Memória insuficiente!");
        return -1;
    } 
    newNode->data = data;
    newNode->next = list->first;
    newNode->previous = list->first->previous;
    log_debug("newNode->(previous, data, next): (%p, %p, %p)", newNode->previous, newNode->data, newNode->next);
    list->first->previous->next = newNode;
    list->first->previous = newNode;
    list->size++;
    log_debug("list->size: %d", list->size);
    log_trace("enqueue <-");
    return 1;
}
void* dequeue(DoublyLinkedList *list) {
    log_info("Desenfileirando/desempilhando elemento");
    log_trace("dequeue ->");
    if(isEmpty(list)) return NULL;
    Node *trash = list->first;
    Node *first = list->first->next;
    first->next->previous = trash;
    trash->next = first->next;
    void *auxData = first->data;
    free(first);
    list->size--;
    log_trace("dequeue <-");
    return auxData;
}
void* first(DoublyLinkedList *list) {
    log_info("Retornando elemeno do inicio/topo");
    log_trace("first ->");
    log_trace("first <-");
    return list->first->next->data;
}
void* last(DoublyLinkedList *list) {
    log_info("Retornando elemento do final/fundo");
    log_trace("last ->");
    log_trace("last <-");
    return list->first->previous->data;
}
int push(DoublyLinkedList *list, void *data) {
    log_info("Empilhando elemento");
    log_trace("push ->");
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode==NULL) {
        log_error("Memória insuficiente!");
        return -1;
    }
    newNode->data = data;
    newNode->previous = list->first;
    newNode->next = list->first->next;
    log_debug("newNode->(previous, data, next): (%p, %p, %p)", newNode->previous, newNode->data, newNode->next);
    list->first->next->previous = newNode;
    list->first->next = newNode;
    list->size++;
    log_trace("push <-");
    return 1;
}
void* pop(DoublyLinkedList *list) {
    log_trace("pop ->");
    void *data = dequeue(list);
    log_trace("pop <-");
    return data;
}
void* top(DoublyLinkedList *list) {
    log_trace("top ->");
    void *data = first(list);
    log_trace("top <-");
    return data;
}
bool isEmpty(DoublyLinkedList *list) {
    log_info("Verificando se a lista está vazia");
    log_trace("isEmpty ->");
    log_trace("isEmpty <-");
    return (list->size == 0);
}
int indexOf(DoublyLinkedList *list, void *data, compare equal) {
    log_info("Buscando posição do elemento");
    log_trace("indexOf ->");
    log_trace("indexOf <-");    
    if (isEmpty(list)) return -1;
    int count=0;
    Node *aux = list->first->next;
   
    while(aux!=list->first && !equal(aux->data,data)) {
        aux=aux->next;
        count++;
    }
    log_trace("indexOf <-");    
    return (aux==list->first)?-1:count;
}
void* getPos(DoublyLinkedList *list, int pos) {
    log_info("Retornando dados na posição %d", pos);
    log_trace("getPos ->");
    if(isEmpty(list) || pos < 0 || pos >= list->size) return NULL;
    Node *aux = getNodeByPos(list,pos);
    log_trace("getPos <-");
    if (aux==NULL) 
        return NULL;
    else
        return aux->data;
}
Node* getNodeByPos(DoublyLinkedList *list, int pos) {
    log_info("Retornando nó na posição %d", pos);
    log_trace("getNodeByPos ->");
    if(isEmpty(list) || pos < 0 || pos >= list->size) return NULL;

    Node *aux = list->first;

    for (int count=0;(aux!=NULL && count<pos);count++,aux=aux->next);

    log_trace("getNodeByPos <-");
    return aux;
}
int add(DoublyLinkedList *list, int pos, void *data)  {
    log_info("Adicionando elemento na posição %d", pos);
    log_trace("add ->");

    if (pos <= 0) return push(list,data);

    Node *aux = getNodeByPos(list, (pos-1));
    if (aux==NULL) return -2;

    Node *newNode = (Node *)malloc(sizeof(Node));
    if(newNode==NULL) {
        log_error("Memória insuficiente!");
        return -1;
    } 
    
    newNode->data = data;
    newNode->next = NULL;
    log_debug("newNode->(data, next): (%p, %p)", newNode->data, newNode->next);
    newNode->next = aux->next;
    aux->next = newNode;
    
    list->size++;
    log_trace("add <-");
    return 1;
}
int addAll(DoublyLinkedList *listDest, int pos, DoublyLinkedList *listSource)   {
    log_info("Adicionando lista de elementos na posição %d", pos);
    log_trace("addAll ->");
    if (listDest==NULL || isEmpty(listDest)) return -1;
    if (listSource==NULL || isEmpty(listSource)) return -2;

    Node *last = NULL;
    for (last = listSource->first;last->next!=NULL;last=last->next);
    if (pos == 0) {
        last->next = listDest->first;
        listDest->first = listSource->first;
    } else {
        Node *aux = getNodeByPos(listDest, (pos-1));
        if (aux==NULL) return -3;        
        last->next = aux->next; 
        aux->next = listSource->first;
    }
    listDest->size+=listSource->size;
    log_trace("addAll ->");
    return listSource->size;   
}
void* removePos(DoublyLinkedList *list, int pos)  {
    log_info("Removendo elemento na posição %d", pos);
    log_trace("removePos ->");
    if (isEmpty(list) || pos>=list->size) return NULL;
    
    Node *nodeRemove = NULL;
    Node *aux = NULL;
       
    if (pos<=0)
        return dequeue(list);
    else
        aux = getNodeByPos(list, pos-1);

    nodeRemove = aux->next;
    aux->next = nodeRemove->next;
    
    void* dataRemove = nodeRemove->data;
    free(nodeRemove);
    list->size--;
    log_trace("removePos <-");    
    return dataRemove;
}
bool removeData(DoublyLinkedList *list, void *data, compare equal)    {
    log_info("Removendo elemento");
    log_trace("removeData ->");
    if (isEmpty(list)) return -1;

    Node *nodeRemove = NULL;
    if (equal(list->first->data,data)) {
        nodeRemove = list->first;
        list->first = list->first->next;
        free(nodeRemove->data);
        free(nodeRemove);
        list->size--;
        log_trace("removeData <-");
        return true;
    } else {
        Node *aux = list->first;
        while(aux->next!=NULL && !equal(aux->next->data,data))
            aux=aux->next;
    
        if (aux->next!=NULL) {
            Node *nodeRemove = aux->next;
            aux->next = nodeRemove->next;
            free(nodeRemove->data);
            free(nodeRemove);
            list->size--;
            log_trace("removeData <-");
            return true;
        } else {
            log_trace("removeData <-");
            return false;
        }
    }
}
void show(DoublyLinkedList *list, printNode print){
    log_info("Mostrando os elementos na ordem da lista");
    log_trace("show ->");
    Node *aux = list->first->next;
    while(aux->next != list->first){
        print(aux->data);
        aux = aux->next;
    }
    log_trace("show <-");
}
void showMem(DoublyLinkedList *list){
    log_info("Mostrando os endereços da lista");
    log_trace("showMem ->");

    printf("Trash node: %p\n\n", list->first);
    Node *aux = list->first->next;
    printf("Node addr: Previous - Date - Next\n");
    while(aux != list->first){
        printf("%p: %p - %p - %p\n", aux, aux->previous,aux->data, aux->next);
        aux = aux->next;
    }
    log_trace("showMem <-");
}