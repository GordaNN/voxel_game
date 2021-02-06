/*
* Author: Naumenko Nikolay
* Email: v-v-vlasov1999@mail.ru
*
* Module description:
* This module contains application control functions.
*/

#ifndef GAME_APPLICATION_APPLICATION_H
#define GAME_APPLICATION_APPLICATION_H

#include <stdbool.h>
#include "core/graphics/camera.h"
#include "core/graphics/graphical_context.h"
#include "core/graphics/window.h"
#include "core/world/world.h"
#include "application/application_events.h"

/* This is application state structure */
typedef struct application_t
{
    window_t            window;
    graphical_context_t context;
    camera_t            camera;
    vec3f_t             camera_speed;
    double              last_calculation_position_time;
    world_t             world;
} application_t;

/* This function creates application */
bool application_create(
        application_t* application_p);

/* This function destroys application */
void application_destroy(
        application_t* application_p);

/* This function handles application's event */
void application_handle_event(
        application_t*      application_p,
        application_event_t event);

/* This function rotates camera */
void application_rotate_camera(
        application_t* application_p,
        vec2f_t        delta_cursore);

/* This function calculates physics */
void application_calculate_physics(
        application_t* application_p);

/* This function draws world */
void application_draw_world(
        application_t* application_p);

#endif // GAME_APPLICATION_APPLICATION_H
