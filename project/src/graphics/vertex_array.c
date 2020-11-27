/*
* Author: Naumenko Nikolay
* Email: v-v-vlasov1999@mail.ru
*
* Module description:
* This module contains structure of vertex array and functions for them.
*/

#include "graphics/vertex_array.h"

/* This function generates vertex array object */
vertex_array_t vertex_array_create(
        const GLfloat* array_p,
        size_t number)
{
    vertex_array_t vertex_array =
    {
        .vertex_array  = 0,
        .vertex_buffer = 0,
        .number        = number
    };

    glGenVertexArrays(1, &vertex_array.vertex_array);
    glBindVertexArray(vertex_array.vertex_array);

    glGenBuffers(1, &vertex_array.vertex_buffer);
    glBindBuffer(GL_ARRAY_BUFFER, vertex_array.vertex_buffer);
    glBufferData(GL_ARRAY_BUFFER, 7 * sizeof(GLfloat) * number, array_p, GL_STATIC_COPY);

    glVertexAttribPointer(
            0,
            3,
            GL_FLOAT,
            GL_FALSE,
            7 * sizeof(GLfloat),
            (GLvoid*)0);
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(
            1,
            3,
            GL_FLOAT,
            GL_FALSE,
            7 * sizeof(GLfloat),
            (GLvoid*)(3 * sizeof(GLfloat)));
    glEnableVertexAttribArray(1);

    glVertexAttribPointer(
            2,
            1,
            GL_FLOAT,
            GL_FALSE,
            7 * sizeof(GLfloat),
            (GLvoid*)(6 * sizeof(GLfloat)));
    glEnableVertexAttribArray(2);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

    return vertex_array;
}

/* This function generates vertex array object */
void vertex_array_destroy(
        vertex_array_t* vertex_array_p)
{
    glDeleteVertexArrays(1, &vertex_array_p->vertex_array);
    glDeleteBuffers(1, &vertex_array_p->vertex_buffer);
    vertex_array_p->number = 0;
}

/* This function drawes vertex array */
void vertex_array_draw(
        const vertex_array_t* vertex_array_p)
{
    glBindVertexArray(vertex_array_p->vertex_array);
    glDrawArrays(GL_POINTS, 0, vertex_array_p->number);
    glBindVertexArray(0);
}
