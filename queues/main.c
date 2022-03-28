#include <stdio.h>
#include <stdlib.h>

#include "queue.c"

int main() {
    queue q;
    q_init(&q);

    q_enqueue(&q, 2);

    if (q_empty(&q)) {
        printf("Queue is empty");
    } else {
        printf("Queue has at least one entry\n");
    }

    q_free(&q);
    return 0;
}
