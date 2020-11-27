/*
* Author: Naumenko Nikolay
* Email: v-v-vlasov1999@mail.ru
*
* Module description:
* This module contains chunk structure and functions for working with them.
*/

#include <stdlib.h>
#include "world/chunk.h"
#include "graphics/voxel.h"

/* This function creates chunk */
void chunk_create(
        chunk_t* chunk_p,
        vec3d_t  position)
{
    chunk_p->position = position;
    for (size_t i = 0; i < CHUNK_SIZE * CHUNK_SIZE * CHUNK_SIZE; ++i)
        chunk_p->octrees_pp[i] = NULL;
}

/* This function destroys chunk */
void chunk_destroy(
        chunk_t* chunk_p)
{
    for (size_t i = 0; i < CHUNK_SIZE * CHUNK_SIZE * CHUNK_SIZE; ++i)
    {
        octree_destroy(&chunk_p->octrees_pp[i]);
    }
}

/* This function generates chunk */
bool chunk_generate(
        chunk_t*       chunk_p,
        const noise_t* noise_p)
{
    /* Number of voxels */
    size_t number = 0;

    /* Iterating through octrees */
    for (size_t x = 0; x < CHUNK_SIZE; ++x)
    {
        for (size_t y = 0; y < CHUNK_SIZE; ++y)
        {
            for (size_t z = 0; z < CHUNK_SIZE; ++z)
            {
                voxel_t array_fill[CHUNK_OCTREE_SIZE * CHUNK_OCTREE_SIZE * CHUNK_OCTREE_SIZE];
                const vec3f_t octree_position = vec3f_create(
                        (float)x - CHUNK_HALF_SIZE + 0.5f,
                        (float)y - CHUNK_HALF_SIZE + 0.5f,
                        (float)z - CHUNK_HALF_SIZE + 0.5f);

                /* Iterating through octree's voxels */
                for (int i = 0; i < CHUNK_OCTREE_SIZE; ++i)
                {
                    for (int j = 0; j < CHUNK_OCTREE_SIZE; ++j)
                    {
                        for (int k = 0; k < CHUNK_OCTREE_SIZE; ++k)
                        {
                            const vec3f_t voxel_position = vec3f_create(
                                    VOXEL_MIN_SCALE *
                                        (i - CHUNK_OCTREE_HALF_SIZE) + VOXEL_HALF_MIN_SCALE,
                                    VOXEL_MIN_SCALE *
                                        (j - CHUNK_OCTREE_HALF_SIZE) + VOXEL_HALF_MIN_SCALE,
                                    VOXEL_MIN_SCALE * 
                                        (k - CHUNK_OCTREE_HALF_SIZE) + VOXEL_HALF_MIN_SCALE);

                            const vec3d_t voxel_global_position = vec3d_add(
                                    vec3d_add(
                                        chunk_p->position,
                                        vec3f_d(octree_position)),
                                    vec3f_d(voxel_position));

                            const double noise_value = 4.0 + 4 * noise_multioctave_value(
                                    noise_p,
                                    vec2d_mul_n(vec3d_xz(voxel_global_position), 0.2),
                                    4,
                                    0.5);

                            array_fill[i * CHUNK_OCTREE_SIZE * CHUNK_OCTREE_SIZE +
                                       j * CHUNK_OCTREE_SIZE +
                                       k].position = vec3f_add(octree_position, voxel_position);
                            
                            const float color = ((float)y + (float)j / 16.0f) / 5.0f + 0.01f;
                            array_fill[i * CHUNK_OCTREE_SIZE * CHUNK_OCTREE_SIZE +
                                       j * CHUNK_OCTREE_SIZE +
                                       k].color = vec3f_create(color, color, color);

                            if (noise_value >= voxel_global_position.y)
                            {
                                array_fill[i * CHUNK_OCTREE_SIZE * CHUNK_OCTREE_SIZE +
                                           j * CHUNK_OCTREE_SIZE +
                                           k].scale = VOXEL_MIN_SCALE;
                            }
                            else
                            {
                                array_fill[i * CHUNK_OCTREE_SIZE * CHUNK_OCTREE_SIZE +
                                           j * CHUNK_OCTREE_SIZE +
                                           k].scale = 0.0f;
                            }
                        }
                    }
                }

                if (octree_fill(
                        &chunk_p->octrees_pp[x * CHUNK_SIZE * CHUNK_SIZE + y * CHUNK_SIZE + z],
                        array_fill,
                        CHUNK_OCTREE_SIZE,
                        sizeof(voxel_t),
                        voxel_is_not_void) == false)
                    return false;

                number += octree_drawing_array_number(
                        chunk_p->octrees_pp[x * CHUNK_SIZE * CHUNK_SIZE + y * CHUNK_SIZE + z]);
            }
        }
    }

    /* Createing vertex array */
    voxel_t* array_p = calloc(number, sizeof(voxel_t));
    if (array_p == NULL)
        return false;

    for (size_t i = 0, j = 0; i < CHUNK_SIZE * CHUNK_SIZE * CHUNK_SIZE; ++i)
    {
        octree_drawing_array(chunk_p->octrees_pp[i], array_p + j, sizeof(voxel_t));
        j += octree_drawing_array_number(chunk_p->octrees_pp[i]);
    }
    chunk_p->vertex_array = vertex_array_create(array_p, number);

    free(array_p);

    return true;
}

/* This function draws chunk */
void chunk_draw(
        const chunk_t* chunk_p)
{
    vertex_array_draw(&chunk_p->vertex_array);
}
