#include <stdio.h>
#include <stdlib.h>

#include "linked-list.h"

void l_init(llist *list)
{
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
}

int l_empty(llist *list)
{
    if (list->head == NULL)
        return 1;
    return 0;
}

int l_size(llist *list)
{
    return list->size;
}

void *l_front(llist *list)
{
    if (list->head != NULL)
        return list->head->value;
    return NULL;
}

void *l_back(llist *list)
{
    if (list->tail != NULL)
        return list->tail->value;
    return NULL;
}

void l_push_front(llist *list, void *value)
{
    node *new_node = malloc(sizeof(node));
    new_node->value = value;
    new_node->next = list->head;

    if (list->tail == NULL)
        list->tail = new_node;
    list->head = new_node;
    list->size++;
}

void l_push_back(llist *list, void *value)
{
    node *new_node = malloc(sizeof(node));
    new_node->value = value;
    new_node->next = NULL;

    if (list->tail != NULL)
        list->tail->next = new_node;
    list->tail = new_node;
    list->size++;
}

void l_insert(llist *list, int index, void *value)
{
    node *new_node = malloc(sizeof(node));
    new_node->value = value;

    if (index == 0) {
        new_node->next = list->head;
        list->head = new_node;
    } else {
        node *current = list->head;
        node *previous;
        for (int i = 0; i <= index; i++) {
            if (i == index) {
                previous->next = new_node;
                if (current == NULL) 
                    list->tail = new_node;
                new_node->next = current;
                list->size++;
                return;
            }
            previous = current;
            current = current->next;
        }
    }
}

void *l_value_at(llist *list, int index)
{
    node *current = list->head;
    if (index == 0) {
        return list->head->value;
    } else {  
        for (int i = 0; i <= index; i++) {
            if (i == index)
                return current->value;
            current = current->next;
        }
    }
    return NULL;
}

void l_erase(llist *list, int index)
{
    if (index == 0) {
        node *tmp = list->head->next;
        free(list->head);
        list->head = tmp;
    } else {
        node *previous;
        node *current = list->head;
        node *next;
        for (int i = 0; i <= index; i++) {
            if (i == index) {
                if (next == NULL) 
                    list->tail = previous;
                previous->next = next;
                free(current);
                list->size--;
                return;
            }
            previous = current;
            current = current->next;
            next = current->next;
        }
    }
}

void *l_value_n_from_end(llist *list, int index)
{
    int target = l_size(list) - index - 1;
    return l_value_at(list, target);
}

void l_reverse(llist *list)
{
    if (list->head != NULL) {
        node *previous;
        node *current;
        node *next;

        previous = list->head;
        current = list->head->next;
        list->head->next = NULL;
        while (current != NULL) {
            next = current->next;
            current->next = previous;
            previous = current;
            current = next;
        }
        
        next = list->head;
        list->head = list->tail;
        list->tail = next;
    }
}

void l_remove_value(llist *list, void *value)
{
    node *current;
    node *previous;
    current = list->head;
    while (current != NULL) {
        if (current->value == value) {
            if (current->next == NULL)
                list->tail = previous;           
            if (current == list->head)
                list->head = current->next;
            previous->next = current->next;
            free(current);
            list->size--;
        }

        previous = current;
        current = current->next;
    }
}

void l_free(llist *list)
{
    node *tmp;
    while (list->head != NULL) {
        tmp = list->head;
        list->head = list->head->next;
        free(tmp);
    }
}

