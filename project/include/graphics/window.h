/*
* Author: Naumenko Nikolay
* Email: v-v-vlasov1999@mail.ru
*
* Module description:
* This module contains functions for working with the window and the glfw library.
*/

#ifndef GRAPHICS_WINDOW_H
#define GRAPHICS_WINDOW_H

#include <stdbool.h>
#include <GLFW/glfw3.h>
#include "utils/containers/queue_static.h"

/* This is structure of window */
typedef struct window_t
{
    GLFWwindow*     window_p;
    GLFWmonitor*    monitor_p;
    queue_static_t* events_queue_p;
} window_t;

/* This is enum of window event type */
typedef enum window_event_type_t
{
    WINDOW_KEY_EVENT,
    WINDOW_CURSOR_POS_EVENT
} window_event_type_t;

/* This is enum of window event */
typedef struct window_event_t
{
    window_event_type_t type;
    union
    {
        struct
        {
            int key;
            int scancode;
            int action;
            int mode;
        };
        struct
        {
            double x;
            double y;
        };
    };
} window_event_t;

/* This function initializes the glfw library and event's queue */
bool system_initialize(void);

/* This function terminates the glfw library and event's queue */
void system_finalize(void);

/* This function returns pointer to function which returns process address */
GLFWglproc system_load_proc_function(void);

/* This function returns the value of the GLFW timer */
double system_get_time(void);

/* This function creates window */
bool window_create(
        window_t*   window_p,
        const char* name_p,
        int         width,
        int         height);

/* This function returns event. If there is no events it returns false */
bool window_get_event(
        window_event_t* event_p);

/* This function returns cursor's event. If there is no events it returns false */
bool window_get_cursor_event(
        window_event_t* event_p);

/* This function sets the window size */
void window_set_size(
        window_t window,
        int      width,
        int      height);

/* This function checks whether the window is closed */
bool window_is_closed(
        window_t window);

/* This function closes window */
void window_close(
        window_t window);

/* This function collects window events */
void window_poll_events(void);

/* This function changes the window buffer */
void window_swap_buffers(
        window_t window);

#endif // GRAPHICS_WINDOW_H
