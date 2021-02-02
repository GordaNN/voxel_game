/*
* Author: Naumenko Nikolay
* Email: v-v-vlasov1999@mail.ru
*
* Module description:
* This module has functions for shader program creation and destroying.
*/

#ifndef CORE_GRAPHICS_SHADER_PROGRAM_H
#define CORE_GRAPHICS_SHADER_PROGRAM_H

/* This function creates shader program */
unsigned int shader_program_create(
        unsigned int vertex_shader,
        unsigned int geometry_shader,
        unsigned int fragment_shader);

/* This function deletes shader program */
void shader_program_destroy(
        unsigned int* program_p);

/* This function sets shader matrix 4f uniform */
void shader_program_uniform_matrix_4fv(
        unsigned int program,
        const char*  name_p,
        void*        value_p);

/* This function sets shader vector 3f uniform */
void shader_program_uniform3fv(
        unsigned int program,
        const char*  name_p,
        void*        value_p);

#endif // CORE_GRAPHICS_SHADER_PROGRAM_H
