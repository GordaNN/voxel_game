/*
* Author: Naumenko Nikolay
* Email: v-v-vlasov1999@mail.ru
*
* Module description:
* This module contains application control functions.
*/

#include "core/math/matrix.h"
#include "core/physics/movement.h"
#include "core/system.h"
#include "application/binder.h"
#include "application/application.h"

/* This function creates application */
bool application_create(
        application_t* application_p)
{
    /* Initializing the system (glfw) */
    if (!system_initialize())
        return false;

    /* Creating window */
    if (!window_create(&application_p->window, "Game", 800, 600))
    {
        system_finalize();
        return false;
    }

    /* Creating and configuring the openGL context */
    if (!system_opengl_load())
    {
        system_finalize();
        return false;
    }

    if (!graphical_context_create(&application_p->context))
    {
        system_finalize();
        return false;
    }
    graphical_context_set_viewport(0, 0, 800, 600);

    /* Creating and configuring a camera */
    application_p->camera.projection         = mat4f_set(0.0f);
    application_p->camera.position           = vec3d_create(0.0, 8.0, 0.0);
    application_p->camera.rotation           = vec3f_create(0.0f, 0.0f, 0.0f);
    application_p->camera.fov                = 1.309f;
    application_p->camera.screen_proportions = 4.0f / 3.0f;
    application_p->camera.view_distance      = 1000.0f;
    camera_calculate_projection(&application_p->camera);

    /* Linking the camera to graphical context */
    application_p->context.camera_p = &application_p->camera;

    /* Camera speed vector and last position calculation time */
    application_p->camera_speed = vec3f_create(0.0f, 0.0f, 0.0f);
    application_p->last_calculation_position_time = system_get_time();

    /* Creating and generating world */
    world_create(&application_p->world, 0);
    if (world_generate(&application_p->world) == false)
    {
        system_finalize();
        return false;
    }

    /* Binder setup */
    binder_create();

    binder_bind_keydown_event(CORE_KEY_ESCAPE, CLOSE_APPLICATION);
    binder_bind_keydown_event(CORE_KEY_W, MOVE_FORWARD);
    binder_bind_keydown_event(CORE_KEY_S, MOVE_BACKWARD);
    binder_bind_keydown_event(CORE_KEY_A, MOVE_LEFT);
    binder_bind_keydown_event(CORE_KEY_D, MOVE_RIGHT);
    binder_bind_keydown_event(CORE_KEY_SPACE, MOVE_UP);
    binder_bind_keydown_event(CORE_KEY_LEFT_CONTROL, MOVE_DOWN);
    binder_bind_keydown_event(CORE_KEY_LEFT_SHIFT, MOVE_FAST);

    binder_bind_keyup_event(CORE_KEY_W, STOP_FORWARD);
    binder_bind_keyup_event(CORE_KEY_S, STOP_BACKWARD);
    binder_bind_keyup_event(CORE_KEY_A, STOP_LEFT);
    binder_bind_keyup_event(CORE_KEY_D, STOP_RIGHT);
    binder_bind_keyup_event(CORE_KEY_SPACE, STOP_UP);
    binder_bind_keyup_event(CORE_KEY_LEFT_CONTROL, STOP_DOWN);
    binder_bind_keyup_event(CORE_KEY_LEFT_SHIFT, MOVE_SLOW);

    return true;
}

/* This function destroys application */
void application_destroy(
        application_t* application_p)
{
    /* Releasing resources */
    world_destroy(&application_p->world);
    graphical_context_destroy(&application_p->context);
    system_finalize();
}

/* This function handles application's event */
void application_handle_event(
        application_t*      application_p,
        application_event_t event)
{
    switch (event)
    {
    case CLOSE_APPLICATION:
        window_close(application_p->window);
        break;
    case MOVE_FORWARD:
        application_p->camera_speed.z = 3.0f;
        break;
    case MOVE_BACKWARD:
        application_p->camera_speed.z = -3.0f;
        break;
    case MOVE_LEFT:
        application_p->camera_speed.x = 3.0f;
        break;
    case MOVE_RIGHT:
        application_p->camera_speed.x = -3.0f;
        break;
    case MOVE_UP:
        application_p->camera_speed.y = 3.0f;
        break;
    case MOVE_DOWN:
        application_p->camera_speed.y = -3.0f;
        break;
    case MOVE_FAST:
        application_p->camera_speed = vec3f_mul_n(application_p->camera_speed, 3.0f);
        break;
    case MOVE_SLOW:
        application_p->camera_speed = vec3f_div_n(application_p->camera_speed, 3.0f);
        break;
    case STOP_FORWARD:
    case STOP_BACKWARD:
        application_p->camera_speed.z = 0.0f;
        break;
    case STOP_LEFT:
    case STOP_RIGHT:
        application_p->camera_speed.x = 0.0f;
        break;
    case STOP_UP:
    case STOP_DOWN:
        application_p->camera_speed.y = 0.0f;
    }
}

/* This function rotates camera */
void application_rotate_camera(
        application_t* application_p,
        vec2f_t        delta_cursore)
{
    const float sensitivity = 0.01f;
    const float two_pi  = 6.283185307f;
    const float half_pi = 1.570796327f;

    application_p->camera.rotation.yaw   -= sensitivity * delta_cursore.x;
    application_p->camera.rotation.pitch += sensitivity * delta_cursore.y;

    if (application_p->camera.rotation.yaw <= 0.0f)
        application_p->camera.rotation.yaw += two_pi;
    else if (application_p->camera.rotation.yaw >= two_pi)
        application_p->camera.rotation.yaw -= two_pi;

    if (application_p->camera.rotation.pitch < -half_pi + 0.001f)
        application_p->camera.rotation.pitch = -half_pi + 0.001f;
    else if (application_p->camera.rotation.pitch > half_pi - 0.001f)
        application_p->camera.rotation.pitch = half_pi - 0.001f;
}

/* This function calculates physics */
void application_calculate_physics(
        application_t* application_p)
{
    /* Calculating the camera position */
    application_p->camera.position = physics_move_point(
            application_p->camera.position,
            application_p->camera.rotation,
            application_p->camera_speed,
            system_get_time() - application_p->last_calculation_position_time);
    application_p->last_calculation_position_time = system_get_time();
}

/* This function draws world */
void application_draw_world(
        application_t* application_p)
{
    const vec4f_t clear_color = vec4f_create(0.0f, 0.525f, 1.0f, 0.0f);

    /* Start drawing */
    graphical_context_clear_buffer(&clear_color);
    graphical_context_begin_drawing_voxels(&application_p->context);

    /*
    * Processing the world
    * draw chunks, allocate or release video memory (depends on the state of the chunk)
    */
    world_draw(&application_p->world, &application_p->context);
}
