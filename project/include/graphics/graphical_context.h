/*
* Author: Naumenko Nikolay
* Email: v-v-vlasov1999@mail.ru
*
* Module description:
* This module contains the structure of the graphical context and functions for working with it.
*/

#ifndef GRAPHICS_GRAPHICAL_CONTEXT_H
#define GRAPHICS_GRAPHICAL_CONTEXT_H

#include <stdbool.h>
#include <glad/glad.h>
#include "graphics/camera.h"

/* This is graphical context structure */
typedef struct graphical_context_t
{
    const camera_t* camera_p;
    GLuint          voxel_shader_program;
} graphical_context_t;

/* This function creates graphical context */
bool graphical_context_create(
        graphical_context_t* context_p,
        GLADloadproc         loadproc);

/* This function destroys graphical context */
void graphical_context_destroy(
        graphical_context_t* context_p);

/* This function changes settings of viewport */
void graphical_context_set_viewport(
        GLint x,
        GLint y,
        GLsizei width,
        GLsizei height);

/* This function sets state for rendering */
void graphical_context_begin_drawing(void);

/* This function sets state for voxel rendering */
void graphical_context_begin_drawing_voxels(
        const graphical_context_t* context_p);

#endif // GRAPHICS_GRAPHICAL_CONTEXT_H
