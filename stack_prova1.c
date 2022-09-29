#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

void init(Stack *stack) {
    stack->top = NULL;
    stack->size = 0;
}
bool push(Stack *stack, void *data) {
    Node *newNode = (Node *)malloc(sizeof(Node));

    if (stack == NULL) return false;

    newNode->data = data;
    newNode->under = NULL;

    newNode->under = stack->top;
    stack->top = stack->top->under;    

    stack->size++;
    return true;

}
void* pop(Stack *stack) {
    if(isEmpty(stack)) return NULL;

    Node *aux;

    aux = stack->top;
    stack->top = aux->under;

    void *auxData = aux->data;

    free(aux);

    stack->size--;
    return auxData;
}
void* top(Stack *stack) {
    if (isEmpty(stack)) {
        return NULL;
    }
    else {
        return stack->top->data;
    }
}
bool isEmpty(Stack *stack) {
    if (stack->size == 0) {
        return true;
    }
    else {
        return false;
    }
}
void show(Stack *stack) {
    printf("\n( ");

    if (stack != NULL) {
        for (Node *aux = stack->top; aux->under != NULL; aux = aux->under){
            printf("%p ", aux->data);
        }
    }

    printf(")\n\n");
}