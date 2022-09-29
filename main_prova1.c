#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int main(){

    Stack *stack;

    init(stack);
    int *num = malloc(sizeof(int));
    *num = 1;
    push(stack, num);
    show(stack);

    return 0;
}