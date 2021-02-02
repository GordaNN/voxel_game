/*
* Author: Naumenko Nikolay
* Email: v-v-vlasov1999@mail.ru
*
* Module description:
* This module contains functions for working with Perlin noise.
*/

#ifndef CORE_MATH_NOISE_H
#define CORE_MATH_NOISE_H

#include <stdint.h>
#include <stdlib.h>
#include "core/math/vector.h"

/* Struct of Perline noise */
typedef struct noise_t
{
    unsigned char permutation[1024];
} noise_t;

/* This function creates noise from seed */
void noise_create(
        noise_t* noise_p,
        uint32_t seed);

/* This function returns noise value in world (x;w) position */
double noise_value(
        const noise_t* noise_p,
        vec2d_t        position);

/* This function returns multi-octave noise value in world (x;w) position */
double noise_multioctave_value(
        const noise_t* noise_p,
        vec2d_t        position,
        uint8_t        octaves,
        double         persistence);

#endif // CORE_MATH_NOISE_H
