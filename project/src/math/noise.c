/*
* Author: Naumenko Nikolay
* Email: v-v-vlasov1999@mail.ru
*
* Module description:
* This module contains functions for working with Perlin noise.
*/

#include "math/noise.h"

/* This function returns gradient vector */
vec2d_t noise_get_gradient(
        const noise_t* noise_p,
        long           x,
        long           y);

/* This function creates noise from seed */
void noise_create(
        noise_t*     noise_p,
        unsigned int seed)
{
    srand(seed);
    for (size_t i = 0; i < 1024; ++i)
        noise_p->permutation[i] = rand();
}

/* This function returns gradient vector */
vec2d_t noise_get_gradient(
        const noise_t* noise_p,
        long           x,
        long           y)
{
    const int i = ((x * 1836311903) ^ (y * 2971215073) + 4807526976) & 4095;

    switch (noise_p->permutation[i & 1023] >> ((i & 3072) >> 10) & 3)
    {
    case 0:
        return (vec2d_t)
        {
            .x = 1.0,
            .y = 0.0
        };
    case 1:
        return (vec2d_t)
        {
            .x = -1.0,
            .y = 0.0
        };
    case 2:
        return (vec2d_t)
        {
            .x = 0.0,
            .y = 1.0
        };
    default:
        return (vec2d_t)
        {
            .x = 0.0,
            .y = -1.0
        };
    }
}

/* This function returns noise value in world (x;w) position */
double noise_value(
        const noise_t* noise_p,
        vec2d_t        position)
{
    const vec2d_t quad = vec2d_floor(position);
    const vec2d_t point = vec2d_sub(position, quad);

    const vec2d_t gradient_tl = noise_get_gradient(noise_p, quad.x,       quad.y);
    const vec2d_t gradient_tr = noise_get_gradient(noise_p, quad.x + 1.0, quad.y);
    const vec2d_t gradient_bl = noise_get_gradient(noise_p, quad.x,       quad.y + 1.0);
    const vec2d_t gradient_br = noise_get_gradient(noise_p, quad.x + 1.0, quad.y + 1.0);

    const vec2d_t distance_tl = vec2d_create(point.x,       point.y);
    const vec2d_t distance_tr = vec2d_create(point.x - 1.0, point.y);
    const vec2d_t distance_bl = vec2d_create(point.x,       point.y - 1.0);
    const vec2d_t distance_br = vec2d_create(point.x - 1.0, point.y - 1.0);

    const vec2d_t left = vec2d_create(
            vec2d_dot(distance_tl, gradient_tl),
            vec2d_dot(distance_bl, gradient_bl));

    const vec2d_t right = vec2d_create(
            vec2d_dot(distance_tr, gradient_tr),
            vec2d_dot(distance_br, gradient_br));

    const vec2d_t curve = vec2d_bezier(point);

    return vec2d_lerp_v(vec2d_lerp(left, right, curve.x), curve.y);
}

/* This function returns multi-octave noise value in world (x;w) position */
double noise_multioctave_value(
        const noise_t* noise_p,
        vec2d_t        position,
        size_t         octaves,
        double         persistence)
{
    double max_value = 0.0;
    double value = 0.0;
    double amplitude = 1.0;

    for (; octaves > 0; --octaves)
    {
        value += noise_value(noise_p, position) * amplitude;
        position = vec2d_mul_n(position, 2.0);
        max_value += amplitude;
        amplitude *= persistence;
    }
    return value / max_value;
}
