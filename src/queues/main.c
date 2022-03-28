#include <stdio.h>
#include <stdlib.h>

#include "queue.c"

int main() {
    queue q;
    q_init(&q);

    if (q_empty(&q))
        printf("Queue is empty");

    q_free(&q);
    return 0;
}
