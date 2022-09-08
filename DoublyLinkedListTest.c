#include <stdio.h>
#include <stdlib.h>
#include "DoublyLinkedList.h"
#include "log.h"

bool compara(void *data1, void *data2) {
    int *d1 = (int*)data1;
    int *d2 = (int*)data2;

    return (*d1 == *d2)?true:false;
}   

void impressao(void *data) {
    int *num = (int*)data;
    printf("Nun: %d\n", *num);
}

int main()  {
    log_set_level(LOG_TRACE);

    DoublyLinkedList list;
    init(&list);

    int *aux = (int *)malloc(sizeof(int));
    *aux = 1;
    enqueue(&list, aux);
    aux = (int *)malloc(sizeof(int));
    *aux = 2;
    enqueue(&list, aux);
    aux = (int *)malloc(sizeof(int));
    *aux = 3;
    enqueue(&list, aux);

    show(&list, impressao);    
    showMem(&list);

    printf("first: %d\n",*((int*)first(&list)));
    printf("aux: %d pos: %d\n",*aux, indexOf(&list,aux,compara));
    printf("%d\n",*((int*)getPos(&list,2)));
    printf("%d\n",*((int*)dequeue(&list)));
    printf("%d\n",*((int*)dequeue(&list)));
    printf("%d\n",*((int*)dequeue(&list)));

    return EXIT_SUCCESS;
}