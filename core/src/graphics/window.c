/*
* Author: Naumenko Nikolay
* Email: v-v-vlasov1999@mail.ru
*
* Module description:
* This module contains functions for working with the window and the glfw library.
*/

#include <GLFW/glfw3.h>
#include "core/graphics/window.h"

#define PROJECT_OPENGL_VERSION_MAJOR 4
#define PROJECT_OPENGL_VERSION_MINOR 5

queue_static_t window_event_queue;
queue_static_t window_cursor_event_queue;

/* This is key callback function */
void window_key_callback(
        GLFWwindow* window_p,
        int         key,
        int         scancode,
        int         action,
        int         mode);

/* This is cursor position callback function */
void window_cursor_pos_callback(
        GLFWwindow* window_p,
        double      x,
        double      y);

// This function creates window
bool window_create(
        window_t*   window_p,
        const char* name_p,
        int         width,
        int         height)
{
    if (!queue_static_create(&window_event_queue, 7, sizeof(window_event_t)))
        return false;
    if (!queue_static_create(&window_cursor_event_queue, 7, sizeof(window_event_t)))
        return false;

    window_p->window_p = NULL;
    window_p->monitor_p = NULL;
    window_p->events_queue_p = &window_event_queue;

    queue_static_clear(&window_event_queue);

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, PROJECT_OPENGL_VERSION_MAJOR);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, PROJECT_OPENGL_VERSION_MINOR);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

    window_p->monitor_p = glfwGetPrimaryMonitor();
    if (window_p->monitor_p == NULL)
        return false;

    window_p->window_p = glfwCreateWindow(width, height, name_p, NULL, NULL);
    if (window_p->window_p == NULL)
        return false;

    window_set_size(*window_p, width, height);

    glfwSetInputMode((GLFWwindow*)window_p->window_p, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
    glfwSetCursorPos((GLFWwindow*)window_p->window_p, 0, 0);
    if (glfwRawMouseMotionSupported())
        glfwSetInputMode((GLFWwindow*)window_p->window_p, GLFW_RAW_MOUSE_MOTION, GLFW_TRUE);

    glfwSetKeyCallback((GLFWwindow*)window_p->window_p, window_key_callback);
    glfwSetCursorPosCallback((GLFWwindow*)window_p->window_p, window_cursor_pos_callback);

    glfwMakeContextCurrent((GLFWwindow*)window_p->window_p);
    return true;
}

/* This function returns event. If there is no events it returns false */
bool window_get_event(
        window_event_t* event_p)
{
    if (queue_static_is_empty(&window_event_queue))
        return false;
    *event_p = *(window_event_t*)queue_static_get(&window_event_queue);
    queue_static_pop(&window_event_queue);
    return true;
}

/* This function returns cursor's event. If there is no events it returns false */
bool window_get_cursor_event(
        window_event_t* event_p)
{
    if (queue_static_is_empty(&window_cursor_event_queue))
        return false;
    *event_p = *(window_event_t*)queue_static_get(&window_cursor_event_queue);
    queue_static_pop(&window_cursor_event_queue);
    return true;
}

// This function sets the window size
void window_set_size(
        window_t window,
        int      width,
        int      height)
{
    glfwSetWindowSize((GLFWwindow*)window.window_p, width, height);
    const GLFWvidmode* mode_p = glfwGetVideoMode((GLFWmonitor*)window.monitor_p);
    glfwSetWindowPos(
            (GLFWwindow*)window.window_p,
            (mode_p->width - width) >> 1,
            (mode_p->height - height) >> 1);
}

/* This function checks whether the window is closed */
bool window_is_closed(
        window_t window)
{
    return glfwWindowShouldClose((GLFWwindow*)window.window_p);
}

/* This function closes window */
void window_close(
        window_t window)
{
    glfwSetWindowShouldClose((GLFWwindow*)window.window_p, GL_TRUE);

    queue_static_destroy(&window_cursor_event_queue);
    queue_static_destroy(&window_event_queue);
}

/* This function collects window events */
void window_poll_events(void)
{
    glfwPollEvents();
}

/* This function changes the window buffer */
void window_swap_buffers(
        window_t window)
{
    glfwSwapBuffers((GLFWwindow*)window.window_p);
}

/* This is key callback function */
void window_key_callback(
        GLFWwindow* window_p,
        int         key,
        int         scancode,
        int         action,
        int         mode)
{
    window_event_t event =
    {
         .type     = WINDOW_KEY_EVENT,
         .key      = key,
         .scancode = scancode,
         .action   = action,
         .mode     = mode
    };
    if (action != GLFW_REPEAT)
        queue_static_push(&window_event_queue, &event);
}

/* This is cursor position callback function */
void window_cursor_pos_callback(
        GLFWwindow* window_p,
        double      x,
        double      y)
{
    window_event_t event =
    {
        .type = WINDOW_CURSOR_POS_EVENT,
        .x = x,
        .y = y
    };
    queue_static_push(&window_cursor_event_queue, &event);
}
