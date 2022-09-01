#include <stdio.h>
#include <stdlib.h>
#include "DoublyLinkedList.h"
#include "log.h"

int main()  {
    log_set_level(LOG_TRACE);

    DoublyLinkedList list;
    init(&list);

    int *num = (int *)malloc(sizeof(int));
    *num = 1;
    enqueue(&list, num);

    showMem(&list);

    int *dequeuenum = (int*)dequeue(&list);
    printf("\nTest: %d\n\n", *dequeuenum);

    return EXIT_SUCCESS;
}