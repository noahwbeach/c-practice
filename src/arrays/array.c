#include <stdio.h>
#include <stdlib.h>

typedef struct vector {
    void **items;
    int size;
    int capacity;
} vector;

void v_init(vector *v)
{
    v->size = 0;
    v->capacity = 16;
    v->items = malloc(sizeof(void *) * v->capacity);
}

int v_is_empty(vector *v)
{
    if (v->size == 0)
        return 1;
    return 0;
}

int v_size(vector *v)
{
    return v->size;
}

int v_capacity(vector *v)
{
    return v->capacity;
}

void *v_at(vector *v, int index)
{
    if (index >= 0 && index <= v->capacity)
        return v->items[index];
    return NULL;
}

void v_insert(vector *v, int index, void *value)
{
    if (index >= 0 && index <= v->capacity)
        v->items[index] = value;
}

void v_resize(vector *v, int capacity)
{
    void **items = realloc(v->items, sizeof(void *) * capacity);
    if (items) {
        v->items = items;
        v->capacity = capacity;
    }
}

void v_prepend(vector *v, void *value)
{
    if (v->size == v->capacity)
        v_resize(v, v->capacity * 2);
    for (int i = v->capacity - 1; i >= 0; i--) {
        v->items[i] = v->items[i - 1];
    }
    v->items[0] = value;
    v->size++;
}

void *v_pop(vector *v)
{
    void *pop_value = v->items[v->size - 1];
    v->items[v->size - 1] = NULL;
    v->size--;
    if (v->size <= v->capacity / 4)
        v_resize(v, v->capacity / 2);
    return pop_value;
}

void v_append(vector *v, void *value)
{
    if (v->size == v->capacity)
        v_resize(v, v->capacity * 2);
    v->items[v->size++] = value;
}

void v_delete(vector *v, int index)
{
    if (index < 0 || index >= v->size)
        return;

    v->items[index] = NULL;
    for (int i = index; i <= v->size - 1; i++) {
        v->items[i] = v->items[i + 1];
        v->items[i + 1] = NULL;
    }
    v->size--;
    if (v->size <= v->capacity / 4)
        v_resize(v, v->capacity / 2);
}

void v_remove(vector *v, void *item)
{
    for (int i = 0; i < v->size; i++)
        if (v->items[i] == item)
            v_delete(v, i);
}

int v_find(vector *v, void *item)
{
    for (int i = 0; i < v->size; i++)
        if (v->items[i] == item)
            return i;
    return -1;
}

void v_free(vector *v)
{
    free(v->items);
}

