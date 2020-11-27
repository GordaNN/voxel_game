/*
* Author: Naumenko Nikolay
* Email: v-v-vlasov1999@mail.ru
*
* Module description:
* This module has functions for shader program creation and destroying.
*/

#ifndef GRAPHICS_SHADER_PROGRAM_H
#define GRAPHICS_SHADER_PROGRAM_H

#include <glad/glad.h>

/* This function creates shader program */
GLuint shader_program_create(
        GLuint vertex_shader,
        GLuint geometry_shader,
        GLuint fragment_shader);

/* This function deletes shader program */
void shader_program_destroy(
        GLuint* program_p);

/* This function sets shader matrix 4f uniform */
void shader_program_uniform_matrix_4fv(
        GLuint        program,
        const GLchar* name_p,
        void*         value_p);

/* This function sets shader vector 3f uniform */
void shader_program_uniform3fv(
        GLuint        program,
        const GLchar* name_p,
        void*         value_p);

#endif // GRAPHICS_SHADER_PROGRAM_H
