#include <stdio.h>
#include <stdlib.h>

#include "queue.c"

int main() {
    queue q;
    q_init(&q);

    q_enqueue(&q, 1);
    q_enqueue(&q, 2);
    q_enqueue(&q, 3);
    q_enqueue(&q, 4);
    q_enqueue(&q, 5);

    printf("dequeue: %i\n", q_dequeue(&q));
    printf("dequeue: %i\n", q_dequeue(&q));
    printf("dequeue: %i\n", q_dequeue(&q));
    printf("dequeue: %i\n", q_dequeue(&q));
    printf("dequeue: %i\n", q_dequeue(&q));

    q_free(&q);
    return 0;
}
