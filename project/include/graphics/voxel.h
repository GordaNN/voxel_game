/*
* Author: Naumenko Nikolay
* Email: v-v-vlasov1999@mail.ru
*
* Module description:
* This module has structure of voxel and functions for working with them.
*/

#ifndef GRAPHICS_VOXEL_H
#define GRAPHICS_VOXEL_H

#include "math/vector.h"

#define VOXEL_MIN_SCALE 0.0625
#define VOXEL_HALF_MIN_SCALE 0.03125

/* This is structure of voxel */
typedef struct voxel_t
{
    vec3f_t position;
    vec3f_t color;
    float   scale;
} voxel_t;

/* This function gets voxel void pointer and check */
bool voxel_is_not_void(
        void* voxel_p);

#endif // GRAPHICS_VOXEL_H
