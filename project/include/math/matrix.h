/*
* Author: Naumenko Nikolay
* Email: v-v-vlasov1999@mail.ru
*
* Module description:
* This module contains functions for working with a 4x4 matrix,
* and function for multiplying 4-vector and 4x4 matrix.
*/

#ifndef MATH_MATRIX_4F_H
#define MATH_MATRIX_4F_H

#include "math/vector.h"

/*
* Struct of matrix 4x4
* Matrix 4x4 representation:
* 0|m11 4|m12  8|m13 12|m14
* 1|m21 5|m22  9|m23 13|m24
* 2|m31 6|m32 10|m33 14|m34
* 3|m41 7|m42 11|m43 15|m44
*/
typedef union mat4f_t
{
    struct
    {
        float m11;
        float m21;
        float m31;
        float m41;
        float m12;
        float m22;
        float m32;
        float m42;
        float m13;
        float m23;
        float m33;
        float m43;
        float m14;
        float m24;
        float m34;
        float m44;
    };
    float pointer[16];
} mat4f_t;

/* This function multiplies matrix by vector */
vec4f_t vec4f_mul_mat(
        vec4f_t v0,
        mat4f_t m0);

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
        float m44);

/* This function fills matrix with values */
mat4f_t mat4f_set(
        float n);

/* This function multiplies matrices */
mat4f_t mat4f_mul(
        mat4f_t m0,
        mat4f_t m1);

/* This function multiplies matrix by number */
mat4f_t mat4f_mul_n(
        mat4f_t m0,
        float   n);

/* This function translate matrix */
mat4f_t mat4f_translate(
        mat4f_t m0,
        vec3f_t v0);

/* This function rotates matrix by x */
mat4f_t mat4f_rotation_x(
        mat4f_t m0,
        float   n);

/* This function rotates matrix by y */
mat4f_t mat4f_rotation_y(
        mat4f_t m0,
        float   n);

/* This function rotates matrix by z */
mat4f_t mat4f_rotation_z(
        mat4f_t m0,
        float   n);

/* This function creates look-at matrix */
mat4f_t mat4f_look_at(
        vec3f_t position,
        vec3f_t target,
        vec3f_t up);

/* This function creates perspective matrix */
mat4f_t mat4f_perspective(
        float fov_y,
        float aspect,
        float near,
        float far);

#endif // MATH_MATRIX_4F_H
