/*
* Author: Naumenko Nikolay
* Email: v-v-vlasov1999@mail.ru
*
* Module description:
* This module contains the movement functions
*/

#ifndef CORE_PHYSICS_MOVEMENT_H
#define CORE_PHYSICS_MOVEMENT_H

#include <math.h>
#include "core/math/vector.h"

/* This function move point by speed and direction's rotation */
vec3d_t physics_move_point(
        vec3d_t point,
        vec3f_t rotation,
        vec3f_t speed,
        float   delta_time);

#endif // CORE_PHYSICS_MOVEMENT_H
