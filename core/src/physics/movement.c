/*
* Author: Naumenko Nikolay
* Email: v-v-vlasov1999@mail.ru
*
* Module description:
* This module contains the movement functions
*/

#include "core/physics/movement.h"

/* This function move point by speed and direction's rotation */
vec3f_t move_point(
        vec3f_t point,
        vec3f_t rotation,
        vec3f_t speed,
        float   delta_time)
{
    const vec3f_t delta_position = vec3f_mul_n(speed, delta_time);

    point.x += cosf(rotation.yaw) * delta_position.x - sinf(rotation.yaw) * delta_position.z;
    point.y += delta_position.y;
    point.z += cosf(rotation.yaw) * delta_position.z + sinf(rotation.yaw) * delta_position.x;

    return point;
}
