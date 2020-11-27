/*
* Author: Naumenko Nikolay
* Email: v-v-vlasov1999@mail.ru
*
* Module description:
* This module contains structs of vectors and functions for working with them.
*/

#include <math.h>
#include "math/vector.h"

/* This function creates vector */
vec2f_t vec2f_create(
        float x,
        float y)
{
    return (vec2f_t)
    {
        .x = x,
        .y = y
    };
}

/* This function converts float vector to double */
vec2d_t vec2f_d(
        vec2f_t v0)
{
    return (vec2d_t)
    {
        .x = (double)v0.x,
        .y = (double)v0.y
    };
}

/* This function set vector's values */
vec2f_t vec2f_set(
        float n)
{
    return (vec2f_t)
    {
        .x = n,
        .y = n
    };
}

/* This function adds vectors */
vec2f_t vec2f_add(
        vec2f_t v0,
        vec2f_t v1)
{
    return (vec2f_t)
    {
        .x = v0.x + v1.x,
        .y = v0.y + v1.y
    };
}

/* This function adds vector and number */
vec2f_t vec2f_add_n(
        vec2f_t v0,
        float   n)
{
    return (vec2f_t)
    {
        .x = v0.x + n,
        .y = v0.y + n
    };
}

/* This function subtracts a vector from a vector */
vec2f_t vec2f_sub(
        vec2f_t v0,
        vec2f_t v1)
{
    return (vec2f_t)
    {
        .x = v0.x - v1.x,
        .y = v0.y - v1.y
    };
}

/* This function subtracts a number from a vector */
vec2f_t vec2f_sub_n(
        vec2f_t v0,
        float   n)
{
    return (vec2f_t)
    {
        .x = v0.x - n,
        .y = v0.y - n
    };
}

/* This function multiplies two vectors */
vec2f_t vec2f_mul(
        vec2f_t v0,
        vec2f_t v1)
{
    return (vec2f_t)
    {
        .x = v0.x * v1.x,
        .y = v0.y * v1.y
    };
}

/* This function multiplies vector and number */
vec2f_t vec2f_mul_n(
        vec2f_t v0,
        float   n)
{
    return (vec2f_t)
    {
        .x = v0.x * n,
        .y = v0.y * n
    };
}

/* This function divides vector by vector */
vec2f_t vec2f_div(
        vec2f_t v0,
        vec2f_t v1)
{
    return (vec2f_t)
    {
        .x = v0.x / v1.x,
        .y = v0.y / v1.y
    };
}

/* This function divides vector by number */
vec2f_t vec2f_div_n(
        vec2f_t v0,
        float   n)
{
    return (vec2f_t)
    {
        .x = v0.x / n,
        .y = v0.y / n
    };
}

/* This function returns the opposite vector */
vec2f_t vec2f_negative(
        vec2f_t v0)
{
    return (vec2f_t)
    {
        .x = -v0.x,
        .y = -v0.y
    };
}

/* This function returns the module of the vector */
vec2f_t vec2f_abs(
        vec2f_t v0)
{
    return (vec2f_t)
    {
        .x = fabsf(v0.x),
        .y = fabsf(v0.y)
    };
}

/* This function trunc the vector */
vec2f_t vec2f_trunc(
        vec2f_t v0)
{
    return (vec2f_t)
    {
        .x = truncf(v0.x),
        .y = truncf(v0.y)
    };
}

/* This function floor the vector */
vec2f_t vec2f_floor(
        vec2f_t v0)
{
    return (vec2f_t)
    {
        .x = floorf(v0.x),
        .y = floorf(v0.y)
    };
}

/* This function ceil the vector */
vec2f_t vec2f_ceil(
        vec2f_t v0)
{
    return (vec2f_t)
    {
        .x = ceilf(v0.x),
        .y = ceilf(v0.y)
    };
}

/* This function round the vector */
vec2f_t vec2f_round(
        vec2f_t v0)
{
    return (vec2f_t)
    {
        .x = roundf(v0.x),
        .y = roundf(v0.y)
    };
}

/* This function returns the maximum vector */
vec2f_t vec2f_max(
        vec2f_t v0,
        vec2f_t v1)
{
    return (vec2f_t) 
    { 
        .x = (v0.x > v1.x) ? v0.x : v1.x,
        .y = (v0.y > v1.y) ? v0.y : v1.y
    };
}

/* This function returns the minimum vector */
vec2f_t vec2f_min(
        vec2f_t v0,
        vec2f_t v1)
{
    return (vec2f_t) 
    { 
        .x = (v0.x < v1.x) ? v0.x : v1.x,
        .y = (v0.y < v1.y) ? v0.y : v1.y
    };
}

/* This function normalizes vector */
vec2f_t vec2f_normalize(
        vec2f_t v0)
{
    return vec2f_mul_n(v0, 1.0f / vec2f_len(v0));
}

/* This function of dot operation */
float vec2f_dot(
        vec2f_t v0,
        vec2f_t v1)
{
    return v0.x * v1.x + v0.y * v1.y;
}

/* This function projects vector onto vector */
vec2f_t vec2f_project(
        vec2f_t v0,
        vec2f_t v1)
{
    return vec2f_mul_n(v1, vec2f_dot(v0, v1) / vec2f_dot(v1, v1));
}

/* This function slides vector */
vec2f_t vec2f_slide(
        vec2f_t v0,
        vec2f_t normal)
{
    return vec2f_sub(v0, vec2f_mul_n(normal, vec2f_dot(v0, normal)));
}

/* This function reflects vector */
vec2f_t vec2f_reflect(
        vec2f_t v0,
        vec2f_t normal)
{
    return vec2f_sub(vec2f_mul_n(normal, 2.0f * vec2f_dot(v0, normal)), v0);
}

/* This function of lerp operation */
vec2f_t vec2f_lerp(
        vec2f_t v0,
        vec2f_t v1,
        float   n)
{
    return vec2f_add(v0, vec2f_mul_n(vec2f_sub(v1, v0), n));
}

/* This is lerp function for vector members */
float vec2f_lerp_v(
        vec2f_t v0,
        float   n)
{
    return v0.x + n * (v0.y - v0.x);
}

/* This is bezier function */
vec2f_t vec2f_bezier(
        vec2f_t v0)
{
    return (vec2f_t)
    {
        .x = v0.x * v0.x * v0.x * (v0.x * (v0.x * 6 - 15) + 10),
        .y = v0.y * v0.y * v0.y * (v0.y * (v0.y * 6 - 15) + 10)
    };
}

/* This function returns length of vector */
float vec2f_len(
        vec2f_t v0)
{
    return sqrtf(vec2f_dot(v0, v0));
}

/* This function returns length of vector squared */
float vec2f_len_squared(
        vec2f_t v0)
{
    return vec2f_dot(v0, v0);
}

/* This function returns distance between vectors */
float vec2f_dist(
        vec2f_t v0,
        vec2f_t v1)
{
    return vec2f_len(vec2f_sub(v0, v1));
}

/* This function returns distance between vectors squared */
float vec2f_dist_squared(
        vec2f_t v0,
        vec2f_t v1)
{
    return vec2f_len_squared(vec2f_sub(v0, v1));
}

/* This function compares two vectors with eps accuracy */
bool vec2f_is_equal(
        vec2f_t v0,
        vec2f_t v1,
        float   eps)
{
    return fabsf(vec2f_dist_squared(v0, v1)) < eps * eps;
}

/* This function creates vector */
vec2d_t vec2d_create(
        double x,
        double y)
{
    return (vec2d_t)
    {
        .x = x,
        .y = y
    };
}

/* This function converts double vector to float */
vec2f_t vec2d_f(
        vec2d_t v0)
{
    return (vec2f_t)
    {
        .x = (double)v0.x,
        .y = (double)v0.y
    };
}

/* This function set vector's values */
vec2d_t vec2d_set(
        double n)
{
    return (vec2d_t)
    {
        .x = n,
        .y = n
    };
}

/* This function adds vectors */
vec2d_t vec2d_add(
        vec2d_t v0,
        vec2d_t v1)
{
    return (vec2d_t)
    {
        .x = v0.x + v1.x,
        .y = v0.y + v1.y
    };
}

/* This function adds vector and number */
vec2d_t vec2d_add_n(
        vec2d_t  v0,
        double   n)
{
    return (vec2d_t)
    {
        .x = v0.x + n,
        .y = v0.y + n
    };
}

/* This function subtracts a vector from a vector */
vec2d_t vec2d_sub(
        vec2d_t v0,
        vec2d_t v1)
{
    return (vec2d_t)
    {
        .x = v0.x - v1.x,
        .y = v0.y - v1.y
    };
}

/* This function subtracts a number from a vector */
vec2d_t vec2d_sub_n(
        vec2d_t  v0,
        double   n)
{
    return (vec2d_t)
    {
        .x = v0.x - n,
        .y = v0.y - n
    };
}

/* This function multiplies two vectors */
vec2d_t vec2d_mul(
        vec2d_t v0,
        vec2d_t v1)
{
    return (vec2d_t)
    {
        .x = v0.x * v1.x,
        .y = v0.y * v1.y
    };
}

/* This function multiplies vector and number */
vec2d_t vec2d_mul_n(
        vec2d_t  v0,
        double   n)
{
    return (vec2d_t)
    {
        .x = v0.x * n,
        .y = v0.y * n
    };
}

/* This function divides vector by vector */
vec2d_t vec2d_div(
        vec2d_t v0,
        vec2d_t v1)
{
    return (vec2d_t)
    {
        .x = v0.x / v1.x,
        .y = v0.y / v1.y
    };
}

/* This function divides vector by number */
vec2d_t vec2d_div_n(
        vec2d_t  v0,
        double   n)
{
    return (vec2d_t)
    {
        .x = v0.x / n,
        .y = v0.y / n
    };
}

/* This function returns the opposite vector */
vec2d_t vec2d_negative(
        vec2d_t v0)
{
    return (vec2d_t)
    {
        .x = -v0.x,
        .y = -v0.y
    };
}

/* This function returns the module of the vector */
vec2d_t vec2d_abs(
        vec2d_t v0)
{
    return (vec2d_t)
    {
        .x = fabs(v0.x),
        .y = fabs(v0.y)
    };
}

/* This function trunc the vector */
vec2d_t vec2d_trunc(
        vec2d_t v0)
{
    return (vec2d_t)
    {
        .x = trunc(v0.x),
        .y = trunc(v0.y)
    };
}

/* This function floor the vector */
vec2d_t vec2d_floor(
        vec2d_t v0)
{
    return (vec2d_t)
    {
        .x = floor(v0.x),
        .y = floor(v0.y)
    };
}

/* This function ceil the vector */
vec2d_t vec2d_ceil(
        vec2d_t v0)
{
    return (vec2d_t)
    {
        .x = ceil(v0.x),
        .y = ceil(v0.y)
    };
}

/* This function round the vector */
vec2d_t vec2d_round(
        vec2d_t v0)
{
    return (vec2d_t)
    {
        .x = round(v0.x),
        .y = round(v0.y)
    };
}

/* This function returns the maximum vector */
vec2d_t vec2d_max(
        vec2d_t v0,
        vec2d_t v1)
{
    return (vec2d_t) 
    { 
        .x = (v0.x > v1.x) ? v0.x : v1.x,
        .y = (v0.y > v1.y) ? v0.y : v1.y
    };
}

/* This function returns the minimum vector */
vec2d_t vec2d_min(
        vec2d_t v0,
        vec2d_t v1)
{
    return (vec2d_t) 
    { 
        .x = (v0.x < v1.x) ? v0.x : v1.x,
        .y = (v0.y < v1.y) ? v0.y : v1.y
    };
}

/* This function normalizes vector */
vec2d_t vec2d_normalize(
        vec2d_t v0)
{
    return vec2d_mul_n(v0, 1.0f / vec2d_len(v0));
}

/* This function of dot operation */
double vec2d_dot(
        vec2d_t v0,
        vec2d_t v1)
{
    return v0.x * v1.x + v0.y * v1.y;
}

/* This function projects vector onto vector */
vec2d_t vec2d_project(
        vec2d_t v0,
        vec2d_t v1)
{
    return vec2d_mul_n(v1, vec2d_dot(v0, v1) / vec2d_dot(v1, v1));
}

/* This function slides vector */
vec2d_t vec2d_slide(
        vec2d_t v0,
        vec2d_t normal)
{
    return vec2d_sub(v0, vec2d_mul_n(normal, vec2d_dot(v0, normal)));
}

/* This function reflects vector */
vec2d_t vec2d_reflect(
        vec2d_t v0,
        vec2d_t normal)
{
    return vec2d_sub(vec2d_mul_n(normal, 2.0f * vec2d_dot(v0, normal)), v0);
}

/* This function of lerp operation */
vec2d_t vec2d_lerp(
        vec2d_t v0,
        vec2d_t v1,
        double   n)
{
    return vec2d_add(v0, vec2d_mul_n(vec2d_sub(v1, v0), n));
}

/* This is lerp function for vector members */
double vec2d_lerp_v(
        vec2d_t v0,
        double  n)
{
    return v0.x + n * (v0.y - v0.x);
}

/* This is bezier function */
vec2d_t vec2d_bezier(
        vec2d_t v0)
{
    return (vec2d_t)
    {
        .x = v0.x * v0.x * v0.x * (v0.x * (v0.x * 6 - 15) + 10),
        .y = v0.y * v0.y * v0.y * (v0.y * (v0.y * 6 - 15) + 10)
    };
}

/* This function returns length of vector */
double vec2d_len(
        vec2d_t v0)
{
    return sqrt(vec2d_dot(v0, v0));
}

/* This function returns length of vector squared */
double vec2d_len_squared(
        vec2d_t v0)
{
    return vec2d_dot(v0, v0);
}

/* This function returns distance between vectors */
double vec2d_dist(
        vec2d_t v0,
        vec2d_t v1)
{
    return vec2d_len(vec2d_sub(v0, v1));
}

/* This function returns distance between vectors squared */
double vec2d_dist_squared(
        vec2d_t v0,
        vec2d_t v1)
{
    return vec2d_len_squared(vec2d_sub(v0, v1));
}

/* This function compares two vectors with eps accuracy */
bool vec2d_is_equal(
        vec2d_t  v0,
        vec2d_t  v1,
        double   eps)
{
    return fabs(vec2d_dist_squared(v0, v1)) < eps * eps;
}

/* This function creates vector */
vec3f_t vec3f_create(
        float x,
        float y,
        float z)
{
    return (vec3f_t)
    {
        .x = x,
        .y = y,
        .z = z
    };
}

/* This function converts float vector to double */
vec3d_t vec3f_d(
        vec3f_t v0)
{
    return (vec3d_t) 
    { 
        .x = (double)v0.x,
        .y = (double)v0.y,
        .z = (double)v0.z
    };
}

/* This function set vector's values */
vec3f_t vec3f_set(
        float n)
{
    return (vec3f_t)
    {
        .x = n,
        .y = n,
        .z = n
    };
}

/* This returns xy vector */
vec2f_t vec3f_xy(
        vec3f_t v0)
{
    return (vec2f_t) 
    { 
        .x = v0.x,
        .y = v0.y
    };
}

/* This returns yz vector */
vec2f_t vec3f_yz(
        vec3f_t v0)
{
    return (vec2f_t) 
    { 
        .x = v0.y,
        .y = v0.z
    };
}

/* This returns xz vector */
vec2f_t vec3f_xz(
        vec3f_t v0)
{
    return (vec2f_t) 
    { 
        .x = v0.x,
        .y = v0.z
    };
}

/* This function adds vectors */
vec3f_t vec3f_add(
        vec3f_t v0,
        vec3f_t v1)
{
    return (vec3f_t) 
    { 
        .x = v0.x + v1.x,
        .y = v0.y + v1.y,
        .z = v0.z + v1.z
    };
}

/* This function adds vector and number */
vec3f_t vec3f_add_n(
        vec3f_t v0,
        float   n)
{
    return (vec3f_t) 
    { 
        .x = v0.x + n,
        .y = v0.y + n,
        .z = v0.z + n
    };
}

/* This function subtracts a vector from a vector */
vec3f_t vec3f_sub(
        vec3f_t v0,
        vec3f_t v1)
{
    return (vec3f_t) 
    { 
        .x = v0.x - v1.x,
        .y = v0.y - v1.y,
        .z = v0.z - v1.z
    };
}

/* This function subtracts a number from a vector */
vec3f_t vec3f_sub_n(
        vec3f_t v0,
        float   n)
{
    return (vec3f_t) 
    { 
        .x = v0.x - n,
        .y = v0.y - n,
        .z = v0.z - n
    };
}

/* This function multiplies two vectors */
vec3f_t vec3f_mul(
        vec3f_t v0,
        vec3f_t v1)
{
    return (vec3f_t) 
    { 
        .x = v0.x * v1.x,
        .y = v0.y * v1.y,
        .z = v0.z * v1.z
    };
}

/* This function multiplies vector and number */
vec3f_t vec3f_mul_n(
        vec3f_t v0,
        float   n)
{
    return (vec3f_t) 
    { 
        .x = v0.x * n,
        .y = v0.y * n,
        .z = v0.z * n
    };
}

/* This function divides vector by vector */
vec3f_t vec3f_div(
        vec3f_t v0,
        vec3f_t v1)
{
    return (vec3f_t) 
    { 
        .x = v0.x / v1.x,
        .y = v0.y / v1.y,
        .z = v0.z / v1.z
    };
}

/* This function divides vector by number */
vec3f_t vec3f_div_n(
        vec3f_t v0,
        float   n)
{
    return (vec3f_t) 
    { 
        .x = v0.x / n,
        .y = v0.y / n,
        .z = v0.z / n
    };
}

/* This function returns the opposite vector */
vec3f_t vec3f_negative(
        vec3f_t v0)
{
    return (vec3f_t) 
    { 
        .x = -v0.x,
        .y = -v0.y,
        .z = -v0.z
    };
}

/* This function returns the module of the vector */
vec3f_t vec3f_abs(
        vec3f_t v0)
{
    return (vec3f_t)
    { 
        .x = fabsf(v0.x),
        .y = fabsf(v0.y),
        .z = fabsf(v0.z)
    };
}

/* This function trunc the vector */
vec3f_t vec3f_trunc(
        vec3f_t v0)
{
    return (vec3f_t)
    { 
        .x = truncf(v0.x),
        .y = truncf(v0.y),
        .z = truncf(v0.z)
    };
}

/* This function floor the vector */
vec3f_t vec3f_floor(
        vec3f_t v0)
{
    return (vec3f_t)
    { 
        .x = floorf(v0.x),
        .y = floorf(v0.y),
        .z = floorf(v0.z)
    };
}

/* This function ceil the vector */
vec3f_t vec3f_ceil(
        vec3f_t v0)
{
    return (vec3f_t)
    { 
        .x = ceilf(v0.x),
        .y = ceilf(v0.y),
        .z = ceilf(v0.z)
    };
}

/* This function round the vector */
vec3f_t vec3f_round(
        vec3f_t v0)
{
    return (vec3f_t)
    { 
        .x = roundf(v0.x),
        .y = roundf(v0.y),
        .z = roundf(v0.z)
    };
}

/* This function returns the maximum vector */
vec3f_t vec3f_max(
        vec3f_t v0,
        vec3f_t v1)
{
    return (vec3f_t)
    {
        .x = (v0.x > v1.x) ? v0.x : v1.x,
        .y = (v0.y > v1.y) ? v0.y : v1.y,
        .z = (v0.z > v1.z) ? v0.z : v1.z
    };
}

/* This function returns the minimum vector */
vec3f_t vec3f_min(
        vec3f_t v0,
        vec3f_t v1)
{
    return (vec3f_t)
    {
        .x = (v0.x < v1.x) ? v0.x : v1.x,
        .y = (v0.y < v1.y) ? v0.y : v1.y,
        .z = (v0.z < v1.z) ? v0.z : v1.z
    };
}

/* This function of cross operation */
vec3f_t vec3f_cross(
        vec3f_t v0,
        vec3f_t v1)
{
    return (vec3f_t) 
    {
        .x = v0.y * v1.z - v0.z * v1.y,
        .y = v0.z * v1.x - v0.x * v1.z,
        .z = v0.x * v1.y - v0.y * v1.x
    };
}

/* This function normalizes vector */
vec3f_t vec3f_normalize(
        vec3f_t v0)
{
    return vec3f_mul_n(v0, 1.0f / vec3f_len(v0));
}

/* This function of dot operation */
float vec3f_dot(
        vec3f_t v0,
        vec3f_t v1)
{
    return v0.x * v1.x + v0.y * v1.y + v0.z * v1.z;
}

/* This function projects vector onto vector */
vec3f_t vec3f_project(
        vec3f_t v0,
        vec3f_t v1)
{
    return vec3f_mul_n(v1, vec3f_dot(v0, v1) / vec3f_dot(v1, v1));
}

/* This function slides vector */
vec3f_t vec3f_slide(
        vec3f_t v0,
        vec3f_t normal)
{
    return vec3f_sub(v0, vec3f_mul_n(normal, vec3f_dot(v0, normal)));
}

/* This function reflects vector */
vec3f_t vec3f_reflect(
        vec3f_t v0,
        vec3f_t normal)
{
    return vec3f_sub(vec3f_mul_n(normal, 2.0f * vec3f_dot(v0, normal)), v0);
}

/* This function of lerp operation */
vec3f_t vec3f_lerp(
        vec3f_t v0,
        vec3f_t v1,
        float   n)
{
    return vec3f_add(v0, vec3f_mul_n(vec3f_sub(v1, v0), n));
}

/* This is bezier function */
vec3f_t vec3f_bezier(
        vec3f_t v0)
{
    return (vec3f_t)
    {
        .x = v0.x * v0.x * v0.x * (v0.x * (v0.x * 6 - 15) + 10),
        .y = v0.y * v0.y * v0.y * (v0.y * (v0.y * 6 - 15) + 10),
        .z = v0.z * v0.z * v0.z * (v0.z * (v0.z * 6 - 15) + 10)
    };
}

/* This function returns length of vector */
float vec3f_len(
        vec3f_t v0)
{
    return sqrtf(vec3f_dot(v0, v0));
}

/* This function returns length of vector squared */
float vec3f_len_squared(
        vec3f_t v0)
{
    return vec3f_dot(v0, v0);
}

/* This function returns distance between vectors */
float vec3f_dist(
        vec3f_t v0,
        vec3f_t v1)
{
    return vec3f_len(vec3f_sub(v0, v1));
}

/* This function returns distance between vectors squared */
float vec3f_dist_squared(
        vec3f_t v0,
        vec3f_t v1)
{
    return vec3f_len_squared(vec3f_sub(v0, v1));
}

/* This function compares two vectors with eps accuracy */
bool vec3f_is_equal(
        vec3f_t v0,
        vec3f_t v1,
        float   eps)
{
    return fabsf(vec3f_dist_squared(v0, v1)) < eps * eps;
}

/* This function creates vector */
vec3d_t vec3d_create(
        double x,
        double y,
        double z)
{
    return (vec3d_t)
    {
        .x = x,
        .y = y,
        .z = z
    };
}

/* This function converts double vector to float */
vec3f_t vec3d_f(
        vec3d_t v0)
{
    return (vec3f_t)
    { 
        .x = (float)v0.x,
        .y = (float)v0.y,
        .z = (float)v0.z
    };
}

/* This function set vector's values */
vec3d_t vec3d_set(
        double n)
{
    return (vec3d_t)
    {
        .x = n,
        .y = n,
        .z = n
    };
}

/* This returns xy vector */
vec2d_t vec3d_xy(
        vec3d_t v0)
{
    return (vec2d_t) 
    { 
        .x = v0.x,
        .y = v0.y
    };
}

/* This returns yz vector */
vec2d_t vec3d_yz(
        vec3d_t v0)
{
    return (vec2d_t) 
    { 
        .x = v0.y,
        .y = v0.z
    };
}

/* This returns xz vector */
vec2d_t vec3d_xz(
        vec3d_t v0)
{
    return (vec2d_t) 
    { 
        .x = v0.x,
        .y = v0.z
    };
}

/* This function adds vectors */
vec3d_t vec3d_add(
        vec3d_t v0,
        vec3d_t v1)
{
    return (vec3d_t)
    { 
        .x = v0.x + v1.x,
        .y = v0.y + v1.y,
        .z = v0.z + v1.z
    };
}

/* This function adds vector and number */
vec3d_t vec3d_add_n(
        vec3d_t v0,
        double  n)
{
    return (vec3d_t)
    { 
        .x = v0.x + n,
        .y = v0.y + n,
        .z = v0.z + n
    };
}

/* This function subtracts a vector from a vector */
vec3d_t vec3d_sub(
        vec3d_t v0,
        vec3d_t v1)
{
    return (vec3d_t)
    { 
        .x = v0.x - v1.x,
        .y = v0.y - v1.y,
        .z = v0.z - v1.z
    };
}

/* This function subtracts a number from a vector */
vec3d_t vec3d_sub_n(
        vec3d_t v0,
        double  n)
{
    return (vec3d_t)
    { 
        .x = v0.x - n,
        .y = v0.y - n,
        .z = v0.z - n
    };
}

/* This function multiplies two vectors */
vec3d_t vec3d_mul(
        vec3d_t v0,
        vec3d_t v1)
{
    return (vec3d_t)
    { 
        .x = v0.x * v1.x,
        .y = v0.y * v1.y,
        .z = v0.z * v1.z
    };
}

/* This function multiplies vector and number */
vec3d_t vec3d_mul_n(
        vec3d_t v0,
        double  n)
{
    return (vec3d_t)
    { 
        .x = v0.x * n,
        .y = v0.y * n,
        .z = v0.z * n
    };
}

/* This function divides vector by vector */
vec3d_t vec3d_div(
        vec3d_t v0,
        vec3d_t v1)
{
    return (vec3d_t)
    { 
        .x = v0.x / v1.x,
        .y = v0.y / v1.y,
        .z = v0.z / v1.z
    };
}

/* This function divides vector by number */
vec3d_t vec3d_div_n(
        vec3d_t v0,
        double  n)
{
    return (vec3d_t)
    { 
        .x = v0.x / n,
        .y = v0.y / n,
        .z = v0.z / n
    };
}

/* This function returns the opposite vector */
vec3d_t vec3d_negative(
        vec3d_t v0)
{
    return (vec3d_t)
    { 
        .x = -v0.x,
        .y = -v0.y,
        .z = -v0.z
    };
}

/* This function returns the module of the vector */
vec3d_t vec3d_abs(
        vec3d_t v0)
{
    return (vec3d_t)
    { 
        .x = fabs(v0.x),
        .y = fabs(v0.y),
        .z = fabs(v0.z)
    };
}

/* This function trunc the vector */
vec3d_t vec3d_trunc(
        vec3d_t v0)
{
    return (vec3d_t)
    { 
        .x = trunc(v0.x),
        .y = trunc(v0.y),
        .z = trunc(v0.z)
    };
}

/* This function floor the vector */
vec3d_t vec3d_floor(
        vec3d_t v0)
{
    return (vec3d_t)
    { 
        .x = floor(v0.x),
        .y = floor(v0.y),
        .z = floor(v0.z)
    };
}

/* This function ceil the vector */
vec3d_t vec3d_ceil(
        vec3d_t v0)
{
    return (vec3d_t)
    { 
        .x = ceil(v0.x),
        .y = ceil(v0.y),
        .z = ceil(v0.z)
    };
}

/* This function round the vector */
vec3d_t vec3d_round(
        vec3d_t v0)
{
    return (vec3d_t)
    { 
        .x = round(v0.x),
        .y = round(v0.y),
        .z = round(v0.z)
    };
}

/* This function returns the maximum vector */
vec3d_t vec3d_max(
        vec3d_t v0,
        vec3d_t v1)
{
    return (vec3d_t)
    {
        .x = (v0.x > v1.x) ? v0.x : v1.x,
        .y = (v0.y > v1.y) ? v0.y : v1.y,
        .z = (v0.z > v1.z) ? v0.z : v1.z
    };
}

/* This function returns the minimum vector */
vec3d_t vec3d_min(
        vec3d_t v0,
        vec3d_t v1)
{
    return (vec3d_t)
    {
        .x = (v0.x < v1.x) ? v0.x : v1.x,
        .y = (v0.y < v1.y) ? v0.y : v1.y,
        .z = (v0.z < v1.z) ? v0.z : v1.z
    };
}

/* This function of cross operation */
vec3d_t vec3d_cross(
        vec3d_t v0,
        vec3d_t v1)
{
    return (vec3d_t)
    {
        .x = v0.y * v1.z - v0.z * v1.y,
        .y = v0.z * v1.x - v0.x * v1.z,
        .z = v0.x * v1.y - v0.y * v1.x
    };
}

/* This function normalizes vector */
vec3d_t vec3d_normalize(
        vec3d_t v0)
{
    return vec3d_mul_n(v0, 1.0f / vec3d_len(v0));
}

/* This function of dot operation */
double vec3d_dot(
        vec3d_t v0,
        vec3d_t v1)
{
    return v0.x * v1.x + v0.y * v1.y + v0.z * v1.z;
}

/* This function projects vector onto vector */
vec3d_t vec3d_project(
        vec3d_t v0,
        vec3d_t v1)
{
    return vec3d_mul_n(v1, vec3d_dot(v0, v1) / vec3d_dot(v1, v1));
}

/* This function slides vector */
vec3d_t vec3d_slide(
        vec3d_t v0,
        vec3d_t normal)
{
    return vec3d_sub(v0, vec3d_mul_n(normal, vec3d_dot(v0, normal)));
}

/* This function reflects vector */
vec3d_t vec3d_reflect(
        vec3d_t v0,
        vec3d_t normal)
{
    return vec3d_sub(vec3d_mul_n(normal, 2.0f * vec3d_dot(v0, normal)), v0);
}

/* This function of lerp operation */
vec3d_t vec3d_lerp(
        vec3d_t v0,
        vec3d_t v1,
        double  n)
{
    return vec3d_add(v0, vec3d_mul_n(vec3d_sub(v1, v0), n));
}

/* This is bezier function */
vec3d_t vec3d_bezier(
        vec3d_t v0)
{
    return (vec3d_t)
    {
        .x = v0.x * v0.x * v0.x * (v0.x * (v0.x * 6 - 15) + 10),
        .y = v0.y * v0.y * v0.y * (v0.y * (v0.y * 6 - 15) + 10),
        .z = v0.z * v0.z * v0.z * (v0.z * (v0.z * 6 - 15) + 10)
    };
}

/* This function returns length of vector */
double vec3d_len(
        vec3d_t v0)
{
    return sqrtf(vec3d_dot(v0, v0));
}

/* This function returns length of vector squared */
double vec3d_len_squared(
        vec3d_t v0)
{
    return vec3d_dot(v0, v0);
}

/* This function returns distance between vectors */
double vec3d_dist(
        vec3d_t v0,
        vec3d_t v1)
{
    return vec3d_len(vec3d_sub(v0, v1));
}

/* This function returns distance between vectors squared */
double vec3d_dist_squared(
        vec3d_t v0,
        vec3d_t v1)
{
    return vec3d_len_squared(vec3d_sub(v0, v1));
}

/* This function compares two vectors with eps accuracy */
bool vec3d_is_equal(
        vec3d_t v0,
        vec3d_t v1,
        double  eps)
{
    return fabs(vec3d_dist_squared(v0, v1)) < eps * eps;
}

/* This function creates vector */
vec4f_t vec4f_create(
        float x,
        float y,
        float z,
        float w)
{
    return (vec4f_t)
    {
        .x = x,
        .y = y,
        .z = z,
        .w = w 
    };
}

/* This function converts float vector to double */
vec4d_t vec4f_d(
        vec4f_t v0)
{
    return (vec4d_t) 
    { 
        .x = (double)v0.x,
        .y = (double)v0.y,
        .z = (double)v0.z,
        .w = (double)v0.w
    };
}

/* This function set vector's values */
vec4f_t vec4f_set(
        float n)
{
    return (vec4f_t)
    {
        .x = n,
        .y = n,
        .z = n,
        .w = n
    };
}

/* This returns xz vector */
vec2f_t vec4f_xz(
        vec4f_t v0)
{
    return (vec2f_t) 
    { 
        .x = v0.x,
        .y = v0.z
    };
}

/* This returns xyz vector */
vec3f_t vec4f_xyz(
        vec4f_t v0)
{
    return (vec3f_t) 
    {
        .x = v0.x,
        .y = v0.y,
        .z = v0.z 
    };
}

/* This returns yzw vector */
vec3f_t vec4f_yzw(
        vec4f_t v0)
{
    return (vec3f_t)
    {
        .x = v0.y, 
        .y = v0.z,
        .z = v0.w
    };
}

/* This function adds vectors */
vec4f_t vec4f_add(
        vec4f_t v0,
        vec4f_t v1)
{
    return (vec4f_t) 
    { 
        .x = v0.x + v1.x,
        .y = v0.y + v1.y,
        .z = v0.z + v1.z,
        .w = v0.w + v1.w
    };
}

/* This function adds vector and number */
vec4f_t vec4f_add_n(
        vec4f_t v0,
        float   n)
{
    return (vec4f_t) 
    { 
        .x = v0.x + n,
        .y = v0.y + n,
        .z = v0.z + n,
        .w = v0.w + n
    };
}

/* This function subtracts a vector from a vector */
vec4f_t vec4f_sub(
        vec4f_t v0,
        vec4f_t v1)
{
    return (vec4f_t) 
    { 
        .x = v0.x - v1.x,
        .y = v0.y - v1.y,
        .z = v0.z - v1.z,
        .w = v0.w - v1.w
    };
}

/* This function subtracts a number from a vector */
vec4f_t vec4f_sub_n(
        vec4f_t v0,
        float   n)
{
    return (vec4f_t) 
    { 
        .x = v0.x - n,
        .y = v0.y - n,
        .z = v0.z - n,
        .w = v0.w - n
    };
}

/* This function multiplies two vectors */
vec4f_t vec4f_mul(
        vec4f_t v0,
        vec4f_t v1)
{
    return (vec4f_t) 
    { 
        .x = v0.x * v1.x,
        .y = v0.y * v1.y,
        .z = v0.z * v1.z,
        .w = v0.w * v1.w
    };
}

/* This function multiplies vector and number */
vec4f_t vec4f_mul_n(
        vec4f_t v0,
        float   n)
{
    return (vec4f_t) 
    { 
        .x = v0.x * n,
        .y = v0.y * n,
        .z = v0.z * n,
        .w = v0.w * n
    };
}

/* This function divides vector by vector */
vec4f_t vec4f_div(
        vec4f_t v0,
        vec4f_t v1)
{
    return (vec4f_t) 
    { 
        .x = v0.x / v1.x,
        .y = v0.y / v1.y,
        .z = v0.z / v1.z,
        .w = v0.w / v1.w
    };
}

/* This function divides vector by number */
vec4f_t vec4f_div_n(
        vec4f_t v0,
        float   n)
{
    return (vec4f_t) 
    { 
        .x = v0.x / n,
        .y = v0.y / n,
        .z = v0.z / n,
        .w = v0.w / n
    };
}

/* This function returns the opposite vector */
vec4f_t vec4f_negative(
        vec4f_t v0)
{
    return (vec4f_t) 
    { 
        .x = -v0.x,
        .y = -v0.y,
        .z = -v0.z,
        .w = -v0.w
    };
}

/* This function returns the module of the vector */
vec4f_t vec4f_abs(
        vec4f_t v0)
{
    return (vec4f_t) 
    { 
        .x = fabsf(v0.x),
        .y = fabsf(v0.y),
        .z = fabsf(v0.z),
        .w = fabsf(v0.w)
    };
}

/* This function trunc the vector */
vec4f_t vec4f_trunc(
        vec4f_t v0)
{
    return (vec4f_t) 
    { 
        .x = truncf(v0.x),
        .y = truncf(v0.y),
        .z = truncf(v0.z),
        .w = truncf(v0.w)
    };
}

/* This function floor the vector */
vec4f_t vec4f_floor(
        vec4f_t v0)
{
    return (vec4f_t) 
    { 
        .x = floorf(v0.x),
        .y = floorf(v0.y),
        .z = floorf(v0.z),
        .w = floorf(v0.w)
    };
}

/* This function ceil the vector */
vec4f_t vec4f_ceil(
        vec4f_t v0)
{
    return (vec4f_t) 
    { 
        .x = ceilf(v0.x),
        .y = ceilf(v0.y),
        .z = ceilf(v0.z),
        .w = ceilf(v0.w)
    };
}

/* This function round the vector */
vec4f_t vec4f_round(
        vec4f_t v0)
{
    return (vec4f_t) 
    { 
        .x = roundf(v0.x),
        .y = roundf(v0.y),
        .z = roundf(v0.z),
        .w = roundf(v0.w)
    };
}

/* This function returns the maximum vector */
vec4f_t vec4f_max(
        vec4f_t v0,
        vec4f_t v1)
{
    return (vec4f_t)
    {
        .x = (v0.x > v1.x) ? v0.x : v1.x,
        .y = (v0.y > v1.y) ? v0.y : v1.y,
        .z = (v0.z > v1.z) ? v0.z : v1.z,
        .w = (v0.w > v1.w) ? v0.w : v1.w
    };
}

/* This function returns the minimum vector */
vec4f_t vec4f_min(
        vec4f_t v0,
        vec4f_t v1)
{
    return (vec4f_t)
    {
        .x = (v0.x < v1.x) ? v0.x : v1.x,
        .y = (v0.y < v1.y) ? v0.y : v1.y,
        .z = (v0.z < v1.z) ? v0.z : v1.z,
        .w = (v0.w < v1.w) ? v0.w : v1.w
    };
}

/* This function normalizes vector */
vec4f_t vec4f_normalize(
        vec4f_t v0)
{
    return vec4f_mul_n(v0, 1.0f / vec3f_len(vec4f_xyz(v0)));
}

/* This function returns length of vector */
float vec4f_len(
        vec4f_t v0)
{
    return sqrtf(v0.x * v0.x + v0.y * v0.y + v0.z * v0.z + v0.w * v0.w);
}

/* This function returns length of vector squared */
float vec4f_len_squared(
        vec4f_t v0)
{
    return v0.x * v0.x + v0.y * v0.y + v0.z * v0.z + v0.w * v0.w;
}

/* This function compares two vectors with eps accuracy */
bool vec4f_is_equal(
        vec4f_t v0,
        vec4f_t v1,
        float   eps)
{
    return fabsf(vec4f_len_squared(vec4f_sub(v0, v1))) < eps * eps;
}

/* This function creates vector */
vec4d_t vec4d_create(
        double x,
        double y,
        double z,
        double w)
{
    return (vec4d_t) 
    {
        .x = x,
        .y = y,
        .z = z,
        .w = w 
    };
}

/* This function converts double vector to float */
vec4f_t vec4d_f(
        vec4d_t v0)
{
    return (vec4f_t) 
    { 
        .x = (float)v0.x,
        .y = (float)v0.y,
        .z = (float)v0.z,
        .w = (float)v0.w
    };
}

/* This function set vector's values */
vec4d_t vec4d_set(
        double n)
{
    return (vec4d_t)
    {
        .x = n,
        .y = n,
        .z = n,
        .w = n
    };
}

/* This returns xz vector */
vec2d_t vec4d_xz(
        vec4d_t v0)
{
    return (vec2d_t) 
    { 
        .x = v0.x,
        .y = v0.z
    };
}

/* This returns xyz vector */
vec3d_t vec4d_xyz(
        vec4d_t v0)
{
    return (vec3d_t) 
    {
        .x = v0.x,
        .y = v0.y,
        .z = v0.z 
    };
}

/* This returns yzw vector */
vec3d_t vec4d_yzw(
        vec4d_t v0)
{
    return (vec3d_t) 
    {
        .x = v0.y,
        .y = v0.z,
        .z = v0.w 
    };
}

/* This function adds vectors */
vec4d_t vec4d_add(
        vec4d_t v0,
        vec4d_t v1)
{
    return (vec4d_t) 
    { 
        .x = v0.x + v1.x,
        .y = v0.y + v1.y,
        .z = v0.z + v1.z,
        .w = v0.w + v1.w
    };
}

/* This function adds vector and number */
vec4d_t vec4d_add_n(
        vec4d_t  v0,
        double   n)
{
    return (vec4d_t)
    { 
        .x = v0.x + n,
        .y = v0.y + n,
        .z = v0.z + n,
        .w = v0.w + n
    };
}

/* This function subtracts a vector from a vector */
vec4d_t vec4d_sub(
        vec4d_t v0,
        vec4d_t v1)
{
    return (vec4d_t)
    { 
        .x = v0.x - v1.x,
        .y = v0.y - v1.y,
        .z = v0.z - v1.z,
        .w = v0.w - v1.w
    };
}

/* This function subtracts a number from a vector */
vec4d_t vec4d_sub_n(
        vec4d_t  v0,
        double   n)
{
    return (vec4d_t)
    { 
        .x = v0.x - n,
        .y = v0.y - n,
        .z = v0.z - n,
        .w = v0.w - n
    };
}

/* This function multiplies two vectors */
vec4d_t vec4d_mul(
        vec4d_t v0,
        vec4d_t v1)
{
    return (vec4d_t)
    { 
        .x = v0.x * v1.x,
        .y = v0.y * v1.y,
        .z = v0.z * v1.z,
        .w = v0.w * v1.w
    };
}

/* This function multiplies vector and number */
vec4d_t vec4d_mul_n(
        vec4d_t  v0,
        double   n)
{
    return (vec4d_t)
    { 
        .x = v0.x * n,
        .y = v0.y * n,
        .z = v0.z * n,
        .w = v0.w * n
    };
}

/* This function divides vector by vector */
vec4d_t vec4d_div(
        vec4d_t v0,
        vec4d_t v1)
{
    return (vec4d_t)
    { 
        .x = v0.x / v1.x,
        .y = v0.y / v1.y,
        .z = v0.z / v1.z,
        .w = v0.w / v1.w
    };
}

/* This function divides vector by number */
vec4d_t vec4d_div_n(
        vec4d_t  v0,
        double   n)
{
    return (vec4d_t)
    { 
        .x = v0.x / n,
        .y = v0.y / n,
        .z = v0.z / n,
        .w = v0.w / n
    };
}

/* This function returns the opposite vector */
vec4d_t vec4d_negative(
        vec4d_t v0)
{
    return (vec4d_t)
    { 
        .x = -v0.x,
        .y = -v0.y,
        .z = -v0.z,
        .w = -v0.w
    };
}

/* This function returns the module of the vector */
vec4d_t vec4d_abs(
        vec4d_t v0)
{
    return (vec4d_t)
    { 
        .x = fabs(v0.x),
        .y = fabs(v0.y),
        .z = fabs(v0.z),
        .w = fabs(v0.w)
    };
}

/* This function trunc the vector */
vec4d_t vec4d_trunc(
        vec4d_t v0)
{
    return (vec4d_t)
    { 
        .x = trunc(v0.x),
        .y = trunc(v0.y),
        .z = trunc(v0.z),
        .w = trunc(v0.w)
    };
}

/* This function floor the vector */
vec4d_t vec4d_floor(
        vec4d_t v0)
{
    return (vec4d_t)
    { 
        .x = floor(v0.x),
        .y = floor(v0.y),
        .z = floor(v0.z),
        .w = floor(v0.w)
    };
}

/* This function ceil the vector */
vec4d_t vec4d_ceil(
        vec4d_t v0)
{
    return (vec4d_t)
    { 
        .x = ceil(v0.x),
        .y = ceil(v0.y),
        .z = ceil(v0.z),
        .w = ceil(v0.w)
    };
}

/* This function round the vector */
vec4d_t vec4d_round(
        vec4d_t v0)
{
    return (vec4d_t)
    { 
        .x = fabsf(v0.x),
        .y = fabsf(v0.y),
        .z = fabsf(v0.z),
        .w = fabsf(v0.w)
    };
}

/* This function returns the maximum vector */
vec4d_t vec4d_max(
        vec4d_t v0,
        vec4d_t v1)
{
    return (vec4d_t)
    {
        .x = (v0.x > v1.x) ? v0.x : v1.x,
        .y = (v0.y > v1.y) ? v0.y : v1.y,
        .z = (v0.z > v1.z) ? v0.z : v1.z,
        .w = (v0.w > v1.w) ? v0.w : v1.w
    };
}

/* This function returns the minimum vector */
vec4d_t vec4d_min(
        vec4d_t v0,
        vec4d_t v1)
{
    return (vec4d_t)
    {
        .x = (v0.x < v1.x) ? v0.x : v1.x,
        .y = (v0.y < v1.y) ? v0.y : v1.y,
        .z = (v0.z < v1.z) ? v0.z : v1.z,
        .w = (v0.w < v1.w) ? v0.w : v1.w
    };
}

/* This function normalizes vector */
vec4d_t vec4d_normalize(
        vec4d_t v0)
{
    return vec4d_mul_n(v0, 1.0f / vec3d_len(vec4d_xyz(v0)));
}

/* This function returns length of vector */
double vec4d_len(
        vec4d_t v0)
{
    return sqrtf(v0.x * v0.x + v0.y * v0.y + v0.z * v0.z + v0.w * v0.w);
}

/* This function returns length of vector squared */
double vec4d_len_squared(
        vec4d_t v0)
{
    return v0.x * v0.x + v0.y * v0.y + v0.z * v0.z + v0.w * v0.w;
}

/* This function compares two vectors with eps accuracy */
bool vec4d_is_equal(
        vec4d_t  v0,
        vec4d_t  v1,
        double   eps)
{
    return fabs(vec4d_len_squared(vec4d_sub(v0, v1))) < eps * eps;
}
