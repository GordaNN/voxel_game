/*
* Author: Naumenko Nikolay
* Email: v-v-vlasov1999@mail.ru
*
* Module description:
* This module has functions for shader program creation and destroying.
*/

#ifdef DEBUG
#include <stdio.h>
#include <memory.h>
#endif // DEBUG

#include "graphics/shader/shader_program.h"

/* This function creates shader program */
GLuint shader_program_create(
        GLuint vertex_shader,
        GLuint geometry_shader,
        GLuint fragment_shader)
{
    GLuint program = glCreateProgram();

    if (vertex_shader != 0)
        glAttachShader(program, vertex_shader);
    if (geometry_shader != 0)
        glAttachShader(program, geometry_shader);
    if (fragment_shader != 0)
        glAttachShader(program, fragment_shader);

    glLinkProgram(program);

    if (vertex_shader != 0)
        glDetachShader(program, vertex_shader);
    if (geometry_shader != 0)
        glDetachShader(program, geometry_shader);
    if (fragment_shader != 0)
        glDetachShader(program, fragment_shader);

#ifdef DEBUG
    GLint success;
    GLchar log_p[256];
    memset(log_p, 0, 256 * sizeof(GLchar));
    glGetProgramiv(program, GL_LINK_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(program, 256, NULL, log_p);
        printf("\n\nshader linking error\n%s\n", log_p);
    }
#endif // DEBUG

    return program;
}

/* This function deletes shader program */
void shader_program_destroy(
        GLuint* program_p)
{
    glDeleteProgram(*program_p);
    *program_p = 0;
}

/* This function sets shader matrix uniform */
void shader_program_uniform_matrix_4fv(
        GLuint        program,
        const GLchar* name_p,
        void*         value_p)
{
    glUniformMatrix4fv(glGetUniformLocation(program, name_p), 1, GL_FALSE, value_p);
}

/* This function sets shader uniform */
void shader_program_uniform3fv(
        GLuint        program,
        const GLchar* name_p,
        void*         value_p)
{
    glUniform3fv(glGetUniformLocation(program, name_p), 1, value_p);
}
