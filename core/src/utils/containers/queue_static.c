/*
* Author: Naumenko Nikolay
* Email: v-v-vlasov1999@mail.ru
*
* Module description:
* This module contains the structure of the queue and functions for working with it.
* This queue has constant size.
* When queue is full, the top element is overwritten.
* When queue is empty, the top element is NULL.
*/

#include <memory.h>
#include "core/utils/containers/queue_static.h"

/* This function increments index */
void queue_static_index_inc(
        size_t* i_p,
        size_t  size,
        size_t  number);

/* This function creates static queue and return false if can't create */
bool queue_static_create(
        queue_static_t* queue_p,
        size_t          number,
        size_t          size)
{
    queue_p->push_index = 0;
    queue_p->pop_index  = 0;
    queue_p->number     = (number + 1) * size;
    queue_p->size       = size;
    queue_p->array_p    = malloc(queue_p->number);
    return queue_p->array_p != NULL;
}

/* This function copies static queue and return false if can't copy */
bool queue_static_copy(
        queue_static_t*       to_p,
        const queue_static_t* from_p)
{
    to_p->push_index = from_p->push_index;
    to_p->pop_index  = from_p->pop_index;
    to_p->number     = from_p->number;
    to_p->size       = from_p->size;
    to_p->array_p    = malloc(from_p->number);
    return to_p->array_p != NULL;
}

/* This function destroy static queue */
void queue_static_destroy(
        queue_static_t* queue_p)
{
    free(queue_p->array_p);
    queue_p->array_p = NULL;
}

/* This function clear static queue */
void queue_static_clear(
        queue_static_t* queue_p)
{
    memset(queue_p->array_p, 0, queue_p->number);
    queue_p->push_index = 0;
    queue_p->pop_index  = 0;
}

/* This function check is static queue if empty */
bool queue_static_is_empty(
        const queue_static_t* queue_p)
{
    return queue_p->push_index == queue_p->pop_index;
}

/* This function gets top element of static queue */
void* queue_static_get(
        const queue_static_t* queue_p)
{
    return ((char*)queue_p->array_p) + queue_p->pop_index;
}

/* This function push element to static queue and returns false if top element was overwritten */
bool queue_static_push(
        queue_static_t* queue_p,
        const void*     value_p)
{
    memcpy(((char*)queue_p->array_p) + queue_p->push_index, value_p, queue_p->size);
    queue_static_index_inc(&queue_p->push_index, queue_p->size, queue_p->number);
    if (queue_p->push_index == queue_p->pop_index)
    {
        queue_static_index_inc(&queue_p->pop_index, queue_p->size, queue_p->number);
        return false;
    }
    return true;
}

/* This function pop element from static queue and returns false if it's empty */
bool queue_static_pop(
        queue_static_t* queue_p)
{
    if (queue_p->push_index != queue_p->pop_index)
    {
        queue_static_index_inc(&queue_p->pop_index, queue_p->size, queue_p->number);
        if (queue_p->push_index == queue_p->pop_index)
            memset(((char*)queue_p->array_p) + queue_p->pop_index, 0, queue_p->size);
        else
            return true;
    }
    return false;
}

/* This function increments index */
void queue_static_index_inc(
        size_t* i_p,
        size_t  size,
        size_t  number)
{
    *i_p = (*i_p + size == number) ? 0 : *i_p + size;
}
