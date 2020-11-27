/*
* Author: Naumenko Nikolay
* Email: v-v-vlasov1999@mail.ru
*
* Module description:
* This module contains functions for working with a 4x4 matrix,
* and function for multiplying 4-vector and 4x4 matrix.
*/

#include <math.h>
#include "math/matrix.h"

/* This function multiplies matrix by vector */
vec4f_t vec4f_mul_mat(
        vec4f_t v0,
        mat4f_t m0)
{
    return (vec4f_t)
    {
        .x = m0.m11 * v0.x + m0.m21 * v0.y + m0.m31 * v0.z + m0.m41 * v0.w,
        .y = m0.m12 * v0.x + m0.m22 * v0.y + m0.m32 * v0.z + m0.m42 * v0.w,
        .z = m0.m13 * v0.x + m0.m23 * v0.y + m0.m33 * v0.z + m0.m43 * v0.w,
        .w = m0.m14 * v0.x + m0.m24 * v0.y + m0.m34 * v0.z + m0.m44 * v0.w
    };
}

/* This function creates matrix */
mat4f_t mat4f_create(
        float m11,
        float m21,
        float m31,
        float m41,
        float m12,
        float m22,
        float m32,
        float m42,
        float m13,
        float m23,
        float m33,
        float m43,
        float m14,
        float m24,
        float m34,
        float m44)
{
    return (mat4f_t)
    {
        .m11 = m11,
        .m21 = m21,
        .m31 = m31,
        .m41 = m41,
        .m12 = m12,
        .m22 = m22,
        .m32 = m32,
        .m42 = m42,
        .m13 = m13,
        .m23 = m23,
        .m33 = m33,
        .m43 = m43,
        .m14 = m14,
        .m24 = m24,
        .m34 = m34,
        .m44 = m44
    };
}

/* This function fills matrix with values */
mat4f_t mat4f_set(
        float n)
{
    return (mat4f_t)
    {
        .m11 = n,
        .m21 = 0.0f,
        .m31 = 0.0f,
        .m41 = 0.0f,
        .m12 = 0.0f,
        .m22 = n,
        .m32 = 0.0f,
        .m42 = 0.0f,
        .m13 = 0.0f,
        .m23 = 0.0f,
        .m33 = n,
        .m43 = 0.0f,
        .m14 = 0.0f,
        .m24 = 0.0f,
        .m34 = 0.0f,
        .m44 = n
    };
}

/* This function multiplies matrices */
mat4f_t mat4f_mul(
        mat4f_t m0,
        mat4f_t m1)
{
    return (mat4f_t) 
    {
        .m11 = m0.m11 * m1.m11 + m0.m12 * m1.m21 + m0.m13 * m1.m31 + m0.m14 * m1.m41,
        .m21 = m0.m21 * m1.m11 + m0.m22 * m1.m21 + m0.m23 * m1.m31 + m0.m24 * m1.m41,
        .m31 = m0.m31 * m1.m11 + m0.m32 * m1.m21 + m0.m33 * m1.m31 + m0.m34 * m1.m41,
        .m41 = m0.m41 * m1.m11 + m0.m42 * m1.m21 + m0.m43 * m1.m31 + m0.m44 * m1.m41,
        .m12 = m0.m11 * m1.m12 + m0.m12 * m1.m22 + m0.m13 * m1.m32 + m0.m14 * m1.m42,
        .m22 = m0.m21 * m1.m12 + m0.m22 * m1.m22 + m0.m23 * m1.m32 + m0.m24 * m1.m42,
        .m32 = m0.m31 * m1.m12 + m0.m32 * m1.m22 + m0.m33 * m1.m32 + m0.m34 * m1.m42,
        .m42 = m0.m41 * m1.m12 + m0.m42 * m1.m22 + m0.m43 * m1.m32 + m0.m44 * m1.m42,
        .m13 = m0.m11 * m1.m13 + m0.m12 * m1.m23 + m0.m13 * m1.m33 + m0.m14 * m1.m43,
        .m23 = m0.m21 * m1.m13 + m0.m22 * m1.m23 + m0.m23 * m1.m33 + m0.m24 * m1.m43,
        .m33 = m0.m31 * m1.m13 + m0.m32 * m1.m23 + m0.m33 * m1.m33 + m0.m34 * m1.m43,
        .m43 = m0.m41 * m1.m13 + m0.m42 * m1.m23 + m0.m43 * m1.m33 + m0.m44 * m1.m43,
        .m14 = m0.m11 * m1.m14 + m0.m12 * m1.m24 + m0.m13 * m1.m34 + m0.m14 * m1.m44,
        .m24 = m0.m21 * m1.m14 + m0.m22 * m1.m24 + m0.m23 * m1.m34 + m0.m24 * m1.m44,
        .m34 = m0.m31 * m1.m14 + m0.m32 * m1.m24 + m0.m33 * m1.m34 + m0.m34 * m1.m44,
        .m44 = m0.m41 * m1.m14 + m0.m42 * m1.m24 + m0.m43 * m1.m34 + m0.m44 * m1.m44
    };
}

/* This function multiplies matrix by number */
mat4f_t mat4f_mul_n(
        mat4f_t m0,
        float   n)
{
    return (mat4f_t)
    {
        .m11 = m0.m11 * n,
        .m21 = m0.m21 * n,
        .m31 = m0.m31 * n,
        .m41 = m0.m41 * n,
        .m12 = m0.m12 * n,
        .m22 = m0.m22 * n,
        .m32 = m0.m32 * n,
        .m42 = m0.m42 * n,
        .m13 = m0.m13 * n,
        .m23 = m0.m23 * n,
        .m33 = m0.m33 * n,
        .m43 = m0.m43 * n,
        .m14 = m0.m14 * n,
        .m24 = m0.m24 * n,
        .m34 = m0.m34 * n,
        .m44 = m0.m44 * n
    };
}

/* This function translate matrix */
mat4f_t mat4f_translate(
        mat4f_t m0,
        vec3f_t v0)
{
    return (mat4f_t) 
    {
        .m11 = m0.m11,
        .m21 = m0.m21,
        .m31 = m0.m31,
        .m41 = m0.m41,
        .m12 = m0.m12,
        .m22 = m0.m22,
        .m32 = m0.m32,
        .m42 = m0.m42,
        .m13 = m0.m13,
        .m23 = m0.m23,
        .m33 = m0.m33,
        .m43 = m0.m43,
        .m14 = m0.m14 + v0.x,
        .m24 = m0.m24 + v0.y,
        .m34 = m0.m34 + v0.z,
        .m44 = m0.m44
    };
}

/* This function rotates matrix by x */
mat4f_t mat4f_rotation_x(
        mat4f_t m0,
        float   n)
{
    const float sine = sinf(n);
    const float cosine = cosf(n);
    return (mat4f_t)
    {
        .m11 = m0.m11,
        .m21 = m0.m21,
        .m31 = m0.m31,
        .m41 = m0.m41,
        .m12 = m0.m12,
        .m22 = cosine,
        .m32 = sine,
        .m42 = m0.m42,
        .m13 = m0.m13,
        .m23 = -sine,
        .m33 = cosine,
        .m43 = m0.m43,
        .m14 = m0.m14,
        .m24 = m0.m24,
        .m34 = m0.m34,
        .m44 = m0.m44
    };
}

/* This function rotates matrix by y */
mat4f_t mat4f_rotation_y(
        mat4f_t m0,
        float   n)
{
    const float sine = sinf(n);
    const float cosine = cosf(n);
    return (mat4f_t)
    {
        .m11 = cosine,
        .m21 = m0.m21,
        .m31 = -sine,
        .m41 = m0.m41,
        .m12 = m0.m12,
        .m22 = m0.m22,
        .m32 = m0.m32,
        .m42 = m0.m42,
        .m13 = sine,
        .m23 = m0.m23,
        .m33 = cosine,
        .m43 = m0.m43,
        .m14 = m0.m14,
        .m24 = m0.m24,
        .m34 = m0.m34,
        .m44 = m0.m44
    };
}

/* This function rotates matrix by z */
mat4f_t mat4f_rotation_z(
        mat4f_t m0,
        float   n)
{
    const float sine = sinf(n);
    const float cosine = cosf(n);
    return (mat4f_t)
    {
        .m11 = cosine,
        .m21 = sine,
        .m31 = m0.m31,
        .m41 = m0.m41,
        .m12 = -sine,
        .m22 = cosine,
        .m32 = m0.m32,
        .m42 = m0.m42,
        .m13 = m0.m13,
        .m23 = m0.m23,
        .m33 = m0.m33,
        .m43 = m0.m43,
        .m14 = m0.m14,
        .m24 = m0.m24,
        .m34 = m0.m34,
        .m44 = m0.m44
    };
}

/* This function creates look-at matrix */
mat4f_t mat4f_look_at(
        vec3f_t position,
        vec3f_t target,
        vec3f_t up)
{
    const vec3f_t temp_forward = vec3f_normalize(vec3f_sub(target, position));
    const vec3f_t temp_side = vec3f_normalize(vec3f_cross(temp_forward, up));
    const vec3f_t temp_up = vec3f_cross(temp_side, temp_forward);
    return (mat4f_t)
    {
        .m11 = temp_side.x,
        .m21 = temp_up.x,
        .m31 = -temp_forward.x,
        .m41 = 0.0f,
        .m12 = temp_side.y,
        .m22 = temp_up.y,
        .m32 = -temp_forward.y,
        .m42 = 0.0f,
        .m13 = temp_side.z,
        .m23 = temp_up.z,
        .m33 = -temp_forward.z,
        .m43 = 0.0f,
        .m14 = -vec3f_dot(temp_side, position),
        .m24 = -vec3f_dot(temp_up, position),
        .m34 = vec3f_dot(temp_forward, position),
        .m44 = 1.0f
    };
}

/* This function creates perspective matrix */
mat4f_t mat4f_perspective(
        float fov_y,
        float aspect,
        float near,
        float far)
{
    const float tan_half_fov_y = tanf(0.5f * fov_y);
    return (mat4f_t)
    {
        .m11 = 1.0f / (aspect * tan_half_fov_y),
        .m21 = 0.0f,
        .m31 = 0.0f,
        .m41 = 0.0f,
        .m12 = 0.0f,
        .m22 = 1.0f / tan_half_fov_y,
        .m32 = 0.0f,
        .m42 = 0.0f,
        .m13 = 0.0f,
        .m23 = 0.0f,
        .m33 = (far + near) / (near - far),
        .m43 = -1.0f,
        .m14 = 0.0f,
        .m24 = 0.0f,
        .m34 = (2.0f * far * near) / (near - far),
        .m44 = 0.0f
    };
}
