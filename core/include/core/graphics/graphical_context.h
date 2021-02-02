/*
* Author: Naumenko Nikolay
* Email: v-v-vlasov1999@mail.ru
*
* Module description:
* This module contains the structure of the graphical context and functions for working with it.
*/

#ifndef CORE_GRAPHICS_GRAPHICAL_CONTEXT_H
#define CORE_GRAPHICS_GRAPHICAL_CONTEXT_H

#include <stdbool.h>
#include "core/graphics/camera.h"
#include "core/math/vector.h"

/* This is graphical context structure */
typedef struct graphical_context_t
{
    const camera_t* camera_p;
    unsigned int    voxel_shader_program;
} graphical_context_t;

/* This function creates graphical context */
bool graphical_context_create(
        graphical_context_t* context_p);

/* This function destroys graphical context */
void graphical_context_destroy(
        graphical_context_t* context_p);

/* This function changes settings of viewport */
void graphical_context_set_viewport(
        int          x,
        int          y,
        unsigned int width,
        unsigned int height);

/* This function sets state for rendering */
void graphical_context_clear_buffer(
        const vec4f_t* clear_color_p);

/* This function sets state for voxel rendering */
void graphical_context_begin_drawing_voxels(
        const graphical_context_t* context_p);

#endif // CORE_GRAPHICS_GRAPHICAL_CONTEXT_H
