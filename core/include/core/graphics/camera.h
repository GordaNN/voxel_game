/*
* Author: Naumenko Nikolay
* Email: v-v-vlasov1999@mail.ru
*
* Module description:
* This module contains struct of camera and functions for calculating camera's matrices.
*/

#ifndef CORE_GRAPHICS_CAMERA_H
#define CORE_GRAPHICS_CAMERA_H

#include "core/math/matrix.h"
#include "core/math/vector.h"

/*
 * This is struct of camera
 * All values besides projection must be set by hand
 */
typedef struct camera_t
{
    mat4f_t projection;
    vec3d_t position;
    vec3f_t rotation;
    float   fov;
    float   screen_proportions;
    float   view_distance;
} camera_t;

/* This function returns relative view matrix */
mat4f_t camera_calculate_view_relative(
        const camera_t* camera_p);

/* This function recalculates projection matrix of camera */
void camera_calculate_projection(
        camera_t* camera_p);

#endif // CORE_GRAPHICS_CAMERA_H
