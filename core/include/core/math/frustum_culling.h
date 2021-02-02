/*
* Author: Naumenko Nikolay
* Email: v-v-vlasov1999@mail.ru
*
* Module description:
* This module contains struct of frustum and functions for clipping invisible geometry.
*/

#ifndef CORE_MATH_FRUSTUM_CULLING_H
#define CORE_MATH_FRUSTUM_CULLING_H

#include <stdbool.h>
#include "core/math/matrix.h"

/* This is frustum structure */
typedef union frustum_t
{
    struct
    {
        vec4f_t right_side;
        vec4f_t left_side;
        vec4f_t bottom_side;
        vec4f_t top_side;
        vec4f_t back_side;
        vec4f_t front_side;
    };
    vec4f_t sides[6];
} frustum_t;

/*
* This function calculates frustum from clip matrix.
* frustum_p - pointer to frustum structure
* clip_p - poiner to value of projection matrix * view matrix
*/
void frustum_create(
        frustum_t*     frustum_p,
        const mat4f_t* clip_p);

/* 
* This function returns true if chunk is in frustum 
* frustum_p - pointer to frustum structure
* position_p - pointer to box position vector
* half_size - half size(width) of box
*/
bool frustum_box_in(
        const frustum_t* frustum_p,
        const vec3f_t*   position_p,
        float            half_size);

#endif // CORE_MATH_FRUSTUM_CULLING_H
