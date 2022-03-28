#ifndef LINKED_LIST_H
#define LINKED_LIST_H

typedef struct node {
    void *value;
    struct node *next;
} node;

typedef struct llist {
    node *head;
    node *tail;
    int size;
} llist;;

void l_init(llist *list);
int l_empty(llist *list);
int l_size(llist *list);
void *l_front(llist *list);
void *l_back(llist *list);
void l_push_front(llist *list, void *value);
void l_push_back(llist *list, void *value);
void l_insert(llist *list, int index, void *value);
void *l_value_at(llist *list, int index);
void l_erase(llist *list, int index);
void *l_value_n_from_end(llist *list, int index);
void l_reverse(llist *list);
void l_remove_value(llist *list, void *value);
void l_free(llist *list);

#endif
