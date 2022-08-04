#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

void init(LinkedList *list) {
    list->first=NULL;
    list->size=0;
}
int enqueue(LinkedList *list, void *data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if(newNode==NULL) return -1;
    newNode->data = data;
    newNode->next = NULL;

    if(isEmpty(list))
        list->first = newNode;
    else {
        Node *aux = list->first;
        while(aux->next!=NULL)
            aux = aux->next;
        aux->next = newNode;
    }

    list->size++;
    return 1;
}
void* dequeue(LinkedList *list) {
    if(isEmpty(list)) return NULL;

    Node *aux = list->first;
    list->first = list->first->next;
    void *auxData = aux->data;
    free(aux);

    list->size--;
    return auxData;
}
void* first(LinkedList *list) {
    return isEmpty(list)?NULL:list->first->data;
}
void* last(LinkedList *list) {
    if(isEmpty(list)) return NULL;

    Node *aux = list->first;
    while(aux->next!=NULL)
        aux = aux->next;
    return aux->data;
}
int push(LinkedList *list, void *data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if(newNode==NULL) return -1;
    newNode->data = data;

    newNode->next = isEmpty(list)?NULL:list->first;
    list->first = newNode;

    list->size++;
    return 1;
}
void* pop(LinkedList *list) {
    return dequeue(list);
}
void* top(LinkedList *list) {
    return first(list);
}
bool isEmpty(LinkedList *list)  {
    return list->first==NULL;
}
int indexOf(LinkedList *list, void *data, compare equal)    {

}
void* getPos(LinkedList *list, int pos) {
    if(isEmpty(list) || pos < 0 || pos >= list->size) return NULL;

    Node *aux = (Node *)malloc(sizeof(Node));
    int i = 0;

    aux = list->first;
    while(i != pos) {
        i++;
        aux = aux->next; 
    }
    return aux->data;
}
Node* getNodeByPos(LinkedList *list, int pos) {
    if(isEmpty(list) || pos < 0 || pos >= list->size) return NULL;

    Node *aux = (Node *)malloc(sizeof(Node));
    int i = 0;

    aux = list->first;
    while(i != pos) {
        i++;
        aux = aux->next; 
    }
    return aux;
}
int add(LinkedList *list, int pos, void *data)  {

}
int addAll(LinkedList *listDest, int pos, LinkedList *listSource)   {

}
void* removePos(LinkedList *list, int pos)  {

}
bool removeData(LinkedList *list, void *data, compare equal)    {

}