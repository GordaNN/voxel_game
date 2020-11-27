/*
* Author: Naumenko Nikolay
* Email: v-v-vlasov1999@mail.ru
*
* Module description:
* This module contains struct of frustum and functions for working with it.
*/

#include <stdlib.h>
#include "math/frustum_culling.h"

/*
* This function calculates frustum from clip matrix.
* clip_p - poiner to value of projection matrix * view matrix
*/
void frustum_create(
        frustum_t*     frustum_p,
        const mat4f_t* clip_p)
{
    frustum_p->right_side = vec4f_normalize(vec4f_create(
            clip_p->m41 - clip_p->m11,
            clip_p->m42 - clip_p->m12,
            clip_p->m43 - clip_p->m13,
            clip_p->m44 - clip_p->m14));

    frustum_p->left_side = vec4f_normalize(vec4f_create(
            clip_p->m41 + clip_p->m11,
            clip_p->m42 + clip_p->m12,
            clip_p->m43 + clip_p->m13,
            clip_p->m44 + clip_p->m14));

    frustum_p->top_side = vec4f_normalize(vec4f_create(
            clip_p->m41 - clip_p->m21,
            clip_p->m42 - clip_p->m22,
            clip_p->m43 - clip_p->m23,
            clip_p->m44 - clip_p->m24));

    frustum_p->bottom_side = vec4f_normalize(vec4f_create(
            clip_p->m41 + clip_p->m21,
            clip_p->m42 + clip_p->m22,
            clip_p->m43 + clip_p->m23,
            clip_p->m44 + clip_p->m24));

    frustum_p->back_side = vec4f_normalize(vec4f_create(
            clip_p->m41 - clip_p->m31,
            clip_p->m42 - clip_p->m32,
            clip_p->m43 - clip_p->m33,
            clip_p->m44 - clip_p->m34));
    
    frustum_p->front_side = vec4f_normalize(vec4f_create(
            clip_p->m41 - clip_p->m31,
            clip_p->m42 - clip_p->m32,
            clip_p->m43 - clip_p->m33,
            clip_p->m44 - clip_p->m34));
}

/*
* This function returns true if chunk is in frustum
* frustum_p - pointer to frustum structure
* position_p - pointer to box position vector
* half_size - half size(width) of box
*/
bool frustum_box_in(
        const frustum_t* frustum_p,
        const vec3f_t*   position_p,
        float            half_size)
{
    for (size_t i = 0; i < 6; ++i)
        if (frustum_p->sides[i].x * (position_p->x - half_size) +
            frustum_p->sides[i].y * (position_p->y - half_size) +
            frustum_p->sides[i].z * (position_p->z - half_size) +
            frustum_p->sides[i].w < 0.0f &&
            frustum_p->sides[i].x * (position_p->x + half_size) +
            frustum_p->sides[i].y * (position_p->y - half_size) +
            frustum_p->sides[i].z * (position_p->z - half_size) +
            frustum_p->sides[i].w < 0.0f &&
            frustum_p->sides[i].x * (position_p->x - half_size) +
            frustum_p->sides[i].y * (position_p->y + half_size) +
            frustum_p->sides[i].z * (position_p->z - half_size) +
            frustum_p->sides[i].w < 0.0f &&
            frustum_p->sides[i].x * (position_p->x + half_size) +
            frustum_p->sides[i].y * (position_p->y + half_size) +
            frustum_p->sides[i].z * (position_p->z - half_size) +
            frustum_p->sides[i].w < 0.0f &&
            frustum_p->sides[i].x * (position_p->x - half_size) +
            frustum_p->sides[i].y * (position_p->y - half_size) +
            frustum_p->sides[i].z * (position_p->z + half_size) +
            frustum_p->sides[i].w < 0.0f &&
            frustum_p->sides[i].x * (position_p->x + half_size) +
            frustum_p->sides[i].y * (position_p->y - half_size) +
            frustum_p->sides[i].z * (position_p->z + half_size) +
            frustum_p->sides[i].w < 0.0f &&
            frustum_p->sides[i].x * (position_p->x - half_size) +
            frustum_p->sides[i].y * (position_p->y + half_size) +
            frustum_p->sides[i].z * (position_p->z + half_size) +
            frustum_p->sides[i].w < 0.0f &&
            frustum_p->sides[i].x * (position_p->x + half_size) +
            frustum_p->sides[i].y * (position_p->y + half_size) +
            frustum_p->sides[i].z * (position_p->z + half_size) +
            frustum_p->sides[i].w < 0.0f)
            return false;
    return true;
}
