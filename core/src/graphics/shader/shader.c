/*
* Author: Naumenko Nikolay
* Email: v-v-vlasov1999@mail.ru
*
* Module description:
* This module has functions for shader creation and destroying
*/

#ifdef DEBUG
#include <stdio.h>
#include <memory.h>
#endif // DEBUG

#include <glad/glad.h>
#include "core/graphics/shader/shader.h"

/* This function creates shader */
unsigned int shader_create(
        const char*  shader_source_p,
        unsigned int type)
{
    GLuint shader = glCreateShader(type);
    glShaderSource(shader, 1, &shader_source_p, 0);
    glCompileShader(shader);

#ifdef DEBUG
    GLint success;
    GLchar log_p[256];
    memset(log_p, 0, 256 * sizeof(GLchar));
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(shader, 256, NULL, log_p);
        printf("\n\nshader compilation error\n%s\n", log_p);
    }
#endif // DEBUG

    return shader;
}

/* This function deletes shader */
void shader_destroy(
        unsigned int* shader_p)
{
    glDeleteShader(*shader_p);
    *shader_p = 0;
}
