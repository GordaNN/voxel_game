/*
* Author: Naumenko Nikolay
* Email: v-v-vlasov1999@mail.ru
*
* Module description:
* This module has structure of voxel and functions for working with them.
*/

#include "graphics/voxel.h"

bool voxel_is_not_void(
        void* voxel_p)
{
    if (((voxel_t*)voxel_p)->scale == 0.0f)
        return false;
    return true;
}
