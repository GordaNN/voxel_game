/*
* Author: Naumenko Nikolay
* Email: v-v-vlasov1999@mail.ru
*
* Module description:
* This module contains the structure of the graphical context and functions for working with it.
*/

#include <stdlib.h>
#include "graphics/shader/shader.h"
#include "graphics/shader/shader_program.h"
#include "utils/file.h"
#include "graphics/graphical_context.h"

#define VOXEL_VERTEX_SHADER_FILE_NAME   "shaders/voxel_vertex.glsl"
#define VOXEL_GEOMETRY_SHADER_FILE_NAME "shaders/voxel_geometry.glsl"
#define VOXEL_FRAGMENT_SHADER_FILE_NAME "shaders/voxel_fragment.glsl"

/* This function creates graphical context */
bool graphical_context_create(
        graphical_context_t* context_p,
        GLADloadproc         loadproc)
{
    /* glad initialization */
    if (!gladLoadGLLoader(loadproc))
        return false;

    /* Loading voxel shaders */
    GLchar* voxel_vertex_shader_source_p   = file_text_read(VOXEL_VERTEX_SHADER_FILE_NAME);
    GLchar* voxel_geometry_shader_source_p = file_text_read(VOXEL_GEOMETRY_SHADER_FILE_NAME);
    GLchar* voxel_fragment_shader_source_p = file_text_read(VOXEL_FRAGMENT_SHADER_FILE_NAME);

    if (voxel_vertex_shader_source_p   == NULL ||
        voxel_geometry_shader_source_p == NULL ||
        voxel_fragment_shader_source_p == NULL)
    {
        free(voxel_vertex_shader_source_p);
        free(voxel_geometry_shader_source_p);
        free(voxel_fragment_shader_source_p);
        return false;
    }

    GLuint voxel_vertex_shader = shader_create(
            voxel_vertex_shader_source_p,
            GL_VERTEX_SHADER);
    free(voxel_vertex_shader_source_p);

    GLuint voxel_geometry_shader = shader_create(
            voxel_geometry_shader_source_p,
            GL_GEOMETRY_SHADER);
    free(voxel_geometry_shader_source_p);

    GLuint voxel_fragment_shader = shader_create(
            voxel_fragment_shader_source_p,
            GL_FRAGMENT_SHADER);
    free(voxel_fragment_shader_source_p);

    context_p->voxel_shader_program = shader_program_create(
            voxel_vertex_shader,
            voxel_geometry_shader,
            voxel_fragment_shader);

    shader_destroy(&voxel_vertex_shader);
    shader_destroy(&voxel_geometry_shader);
    shader_destroy(&voxel_fragment_shader);

    if (context_p->voxel_shader_program == 0)
        return false;

    /* Setting pointer to current camepa */
    context_p->camera_p = NULL;

    /* OpenGL Settings */
    glEnable(GL_DEPTH_TEST);

    return true;
}

/* This function destroys graphical context */
void graphical_context_destroy(
        graphical_context_t* context_p)
{
    shader_program_destroy(&context_p->voxel_shader_program);
}

/* This function changes settings of viewport */
void graphical_context_set_viewport(
        GLint x,
        GLint y,
        GLsizei width,
        GLsizei height)
{
    glViewport(x, y, width, height);
}

/* This function sets state for rendering */
void graphical_context_begin_drawing(void)
{
    glClearColor(0.0f, 0.525f, 1.0f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

/* This function sets state for voxel rendering */
void graphical_context_begin_drawing_voxels(
        const graphical_context_t* context_p)
{
    glUseProgram(context_p->voxel_shader_program);
}
