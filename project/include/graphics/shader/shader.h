/*
* Author: Naumenko Nikolay
* Email: v-v-vlasov1999@mail.ru
*
* Module description:
* This module has functions for shader creation and destroying.
*/

#ifndef GRAPHICS_SHADER_H
#define GRAPHICS_SHADER_H

#include <glad/glad.h>

/* This function creates shader */
GLuint shader_create(
        const GLchar* shader_source_p,
        GLenum        type);

/* This function deletes shader */
void shader_destroy(
        GLuint* shader_p);

#endif // GRAPHICS_SHADER_H
