/*
* Author: Naumenko Nikolay
* Email: v-v-vlasov1999@mail.ru
*
* Module description:
* This module has functions for shader creation and destroying.
*/

#ifndef CORE_GRAPHICS_SHADER_H
#define CORE_GRAPHICS_SHADER_H

/* This function creates shader */
unsigned int shader_create(
        const char*  shader_source_p,
        unsigned int type);

/* This function deletes shader */
void shader_destroy(
        unsigned int* shader_p);

#endif // CORE_GRAPHICS_SHADER_H
