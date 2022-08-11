#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "log.h"

int main()  {
    log_set_level(LOG_TRACE);

    LinkedList list;
    init(&list);

    int *num = (int *)malloc(sizeof(int));
    *num = 1;
    enqueue(&list, num);

    int *dequeuenum = dequeue(&list);
    printf("\nTest: %d\n\n", *dequeuenum);

    return EXIT_SUCCESS;
}