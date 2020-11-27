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

#ifndef UTILS_CONTAINERS_QUEUE_STATIC_H
#define UTILS_CONTAINERS_QUEUE_STATIC_H

#include <stdbool.h>
#include <stdlib.h>

/* This is structure of static queue */
typedef struct queue_static_t
{
    size_t push_index;
    size_t pop_index;
    size_t number;
    size_t size;
    void*  array_p;
} queue_static_t;

/* This function creates static queue and return false if can't create */
bool queue_static_create(
        queue_static_t* queue_p,
        size_t          number,
        size_t          size);

/* This function copies static queue and return false if can't copy */
bool queue_static_copy(
        queue_static_t*       to_p,
        const queue_static_t* from_p);

/* This function destroy static queue */
void queue_static_destroy(
        queue_static_t* queue_p);

/* This function clear static queue */
void queue_static_clear(
        queue_static_t* queue_p);

/* This function check is static queue if empty */
bool queue_static_is_empty(
        const queue_static_t* queue_p);

/* This function gets top element of static queue */
void* queue_static_get(
        const queue_static_t* queue_p);

/* This function push element to static queue and returns false if top element was overwritten */
bool queue_static_push(
        queue_static_t* queue_p,
        const void*     value_p);

/* This function pop element from static queue and returns false if it's empty */
bool queue_static_pop(
        queue_static_t* queue_p);

#endif // UTILS_CONTAINERS_QUEUE_STATIC_H
