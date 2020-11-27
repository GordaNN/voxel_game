/*
* Author: Naumenko Nikolay
* Email: v-v-vlasov1999@mail.ru
*
* Module description:
* This module contains struct of camera and functions for calculating camera's matrices.
*/

#include "graphics/camera.h"

/* This function returns view matrix */
mat4f_t camera_calculate_view_relative(
        const camera_t* camera_p)
{
    const mat4f_t rotation_matrix = mat4f_mul(
            mat4f_rotation_x(mat4f_set(1.0f), camera_p->rotation.pitch),
            mat4f_rotation_y(mat4f_set(1.0f), camera_p->rotation.yaw));

    const vec4f_t target = vec4f_normalize(vec4f_mul_mat(
            vec4f_create(0.0f, 0.0f, 1.0f, 0.0f),
            rotation_matrix));
    
    return mat4f_look_at(
            vec3f_create(0.0f, 0.0f, 0.0f),
            vec4f_xyz(target),
            vec3f_create(0.0f, 1.0f, 0.0f));
}

/* This function recalculates projection matrix of camera */
void camera_calculate_projection(
        camera_t* camera_p)
{
    camera_p->projection = mat4f_perspective(
            camera_p->fov,
            camera_p->screen_proportions,
            0.01f,
            camera_p->view_distance);
}
