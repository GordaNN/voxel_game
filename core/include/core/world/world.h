/*
* Author: Naumenko Nikolay
* Email: v-v-vlasov1999@mail.ru
*
* Module description:
* This module contains world structure and function for working with them.
*/

#ifndef CORE_WORLD_WORLD_H
#define CORE_WORLD_WORLD_H

#include <stdbool.h>
#include "core/graphics/graphical_context.h"
#include "core/math/noise.h"
#include "core/world/chunk.h"

typedef struct world_t
{
    noise_t noise;
    chunk_t chunk;
} world_t;

/* This function creates world */
void world_create(
        world_t*     world_p,
        unsigned int seed);

/* This function destroys world */
void world_destroy(
        world_t* world_p);

/* This function generates world */
bool world_generate(
        world_t* world_p);

/* This function draws world */
void world_draw(
        world_t*             world_p,
        graphical_context_t* context_p);

#endif // CORE_WORLD_WORLD_H
