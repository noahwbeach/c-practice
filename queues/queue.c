#include <stdio.h>
#include <stdlib.h>

#include "queue.h"

void q_init(queue *q)
{
    q->front = NULL;
    q->rear = NULL;
}

void q_enqueue(queue *q, int value)
{
    node *new_node = malloc(sizeof(node));
    new_node->value = value;

    if (q->front == NULL) {
        q->rear = new_node;
    } else {
        q->front->prev = new_node;
    }
        
    new_node->next = q->front;
    new_node->prev = NULL;
    q->front = new_node;

    if (q->rear == NULL)
        q->rear = new_node;
}


int q_dequeue(queue *q)
{
    if (q->front == NULL) {
        printf("ERROR: Cannot dequeue from empty queue.\n");
        exit(1);
    }

    int value = q->rear->value;

    return value;
}

int q_empty(queue *q)
{
    if (q->front == NULL)
        return 1;
    return 0;
}

void q_free(queue *q) 
{
    node *tmp;
    while (q->front != NULL) {
        tmp = q->front;
        q->front = q->front->next;
        free(tmp);
    }
}
