/*
* Author: Naumenko Nikolay
* Email: v-v-vlasov1999@mail.ru
*
* Module description:
* This module contains structure of vertex array and functions for them.
*/

#ifndef CORE_GRAPHICS_VERTEX_ARRAY_H
#define CORE_GRAPHICS_VERTEX_ARRAY_H

#include <stdbool.h>
#include <stdlib.h>

typedef struct vertex_array_t
{
    unsigned int vertex_array;
    unsigned int vertex_buffer;
    unsigned int number;
} vertex_array_t;

/* This function generates vertex array object */
vertex_array_t vertex_array_create(
        const float* array_p,
        size_t       count);

/* This function generates vertex array object */
void vertex_array_destroy(
        vertex_array_t* vertex_array_p);

/* This function drawes vertex array */
void vertex_array_draw(
        const vertex_array_t* vertex_array_p);

#endif // CORE_GRAPHICS_VERTEX_ARRAY_H
