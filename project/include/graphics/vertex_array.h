/*
* Author: Naumenko Nikolay
* Email: v-v-vlasov1999@mail.ru
*
* Module description:
* This module contains structure of vertex array and functions for them.
*/

#ifndef GRAPHICS_VERTEX_ARRAY_H
#define GRAPHICS_VERTEX_ARRAY_H

#include <stdbool.h>
#include <stdlib.h>
#include <glad/glad.h>

typedef struct vertex_array_t
{
    GLuint  vertex_array;
    GLuint  vertex_buffer;
    GLsizei number;
} vertex_array_t;

/* This function generates vertex array object */
vertex_array_t vertex_array_create(
        const GLfloat* array_p,
        size_t count);

/* This function generates vertex array object */
void vertex_array_destroy(
        vertex_array_t* vertex_array_p);

/* This function drawes vertex array */
void vertex_array_draw(
        const vertex_array_t* vertex_array_p);

#endif // GRAPHICS_VERTEX_ARRAY_H
