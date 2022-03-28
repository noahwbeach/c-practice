#ifndef QUEUE_H
#define QUEUE_H

typedef struct node {
    void *value;
    struct node *next;
    struct node *prev;
} node;

typedef struct queue {
    node *front;
    node *rear;
} queue;

void q_enqueue(queue *q, void *value);
void *q_dequeue(queue *q);
int q_empty(queue *q);
void q_free(queue *q);

#endif
