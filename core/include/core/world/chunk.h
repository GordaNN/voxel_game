/*
* Author: Naumenko Nikolay
* Email: v-v-vlasov1999@mail.ru
*
* Module description:
* This module contains chunk structure and functions for working with them.
*/

#ifndef CORE_WORLD_CHUNCK_H
#define CORE_WORLD_CHUNCK_H

#include <stdbool.h>
#include "core/graphics/vertex_array.h"
#include "core/math/vector.h"
#include "core/math/noise.h"
#include "core/utils/containers/octree.h"

#define CHUNK_SIZE 8
#define CHUNK_HALF_SIZE 4
#define CHUNK_OCTREE_SIZE 16
#define CHUNK_OCTREE_HALF_SIZE 8

typedef struct chunk_t
{
    vec3d_t        position;
    octree_t*      octrees_pp[CHUNK_SIZE * CHUNK_SIZE * CHUNK_SIZE];
    vertex_array_t vertex_array;
} chunk_t;

/* This function creates chunk */
void chunk_create(
        chunk_t* chunk_p,
        vec3d_t position);

/* This function destroys chunk */
void chunk_destroy(
        chunk_t* chunk_p);

/* This function generates chunk */
bool chunk_generate(
        chunk_t*       chunk_p,
        const noise_t* noise_p);

/* This function draws chunk */
void chunk_draw(
        const chunk_t* chunk_p);

#endif // CORE_WORLD_CHUNCK_H
