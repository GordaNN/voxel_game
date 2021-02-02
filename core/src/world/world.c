/*
* Author: Naumenko Nikolay
* Email: v-v-vlasov1999@mail.ru
*
* Module description:
* This module contains world structure and function for working with them.
*/

#include "core/graphics/shader/shader_program.h"
#include "core/math/frustum_culling.h"
#include "core/world/world.h"

/* This function creates world */
void world_create(
        world_t*     world_p,
        unsigned int seed)
{
    noise_create(&world_p->noise, seed);
}

/* This function destroys world */
void world_destroy(
        world_t* world_p)
{
    chunk_destroy(&world_p->chunk);
}

/* This function generates world */
bool world_generate(
        world_t* world_p)
{
    chunk_create(&world_p->chunk, vec3d_set(CHUNK_HALF_SIZE));
    return chunk_generate(&world_p->chunk, &world_p->noise);
}

/* This function draws world */
void world_draw(
        world_t*             world_p,
        graphical_context_t* context_p)
{
    const mat4f_t camera_matrix = mat4f_mul(
            context_p->camera_p->projection,
            camera_calculate_view_relative(context_p->camera_p));

    frustum_t frustum;
    frustum_create(&frustum, &camera_matrix);
    
    const vec3f_t displacement = vec3d_f(vec3d_sub(
            world_p->chunk.position,
            context_p->camera_p->position));

    if (frustum_box_in(&frustum, &displacement, CHUNK_HALF_SIZE))
    {
        const mat4f_t matrix = mat4f_mul(
                camera_matrix,
                mat4f_translate(mat4f_set(1.0f), displacement));

        const vec3f_t camera_position = vec3f_negative(displacement);

        shader_program_uniform_matrix_4fv(
                context_p->voxel_shader_program,
                "matrix_mvp",
                matrix.pointer);

        shader_program_uniform3fv(
                context_p->voxel_shader_program, 
                "camera_position",
                camera_position.pointer);

        chunk_draw(&world_p->chunk);
    }
}
