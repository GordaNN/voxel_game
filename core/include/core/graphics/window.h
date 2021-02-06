/*
* Author: Naumenko Nikolay
* Email: v-v-vlasov1999@mail.ru
*
* Module description:
* This module contains functions for working with the window and the glfw library.
*/

#ifndef CORE_GRAPHICS_WINDOW_H
#define CORE_GRAPHICS_WINDOW_H

#include <stdbool.h>
#include "core/utils/containers/queue_static.h"

#define CORE_KEY_RELEASE    0
#define CORE_KEY_PRESS      1
#define CORE_KEY_REPEAT     2

#define CORE_KEY_UNKNOWN        -1
#define CORE_KEY_SPACE          32
#define CORE_KEY_APOSTROPHE     39 /* ' */
#define CORE_KEY_COMMA          44 /* , */
#define CORE_KEY_MINUS          45 /* - */
#define CORE_KEY_PERIOD         46 /* . */
#define CORE_KEY_SLASH          47 /* / */
#define CORE_KEY_0              48
#define CORE_KEY_1              49
#define CORE_KEY_2              50
#define CORE_KEY_3              51
#define CORE_KEY_4              52
#define CORE_KEY_5              53
#define CORE_KEY_6              54
#define CORE_KEY_7              55
#define CORE_KEY_8              56
#define CORE_KEY_9              57
#define CORE_KEY_SEMICOLON      59 /* ; */
#define CORE_KEY_EQUAL          61 /* = */
#define CORE_KEY_A              65
#define CORE_KEY_B              66
#define CORE_KEY_C              67
#define CORE_KEY_D              68
#define CORE_KEY_E              69
#define CORE_KEY_F              70
#define CORE_KEY_G              71
#define CORE_KEY_H              72
#define CORE_KEY_I              73
#define CORE_KEY_J              74
#define CORE_KEY_K              75
#define CORE_KEY_L              76
#define CORE_KEY_M              77
#define CORE_KEY_N              78
#define CORE_KEY_O              79
#define CORE_KEY_P              80
#define CORE_KEY_Q              81
#define CORE_KEY_R              82
#define CORE_KEY_S              83
#define CORE_KEY_T              84
#define CORE_KEY_U              85
#define CORE_KEY_V              86
#define CORE_KEY_W              87
#define CORE_KEY_X              88
#define CORE_KEY_Y              89
#define CORE_KEY_Z              90
#define CORE_KEY_LEFT_BRACKET   91 /* [ */
#define CORE_KEY_BACKSLASH      92 /* \ */
#define CORE_KEY_RIGHT_BRACKET  93 /* ] */
#define CORE_KEY_GRAVE_ACCENT   96 /* ` */
#define CORE_KEY_WORLD_1        161 /* non-US #1 */
#define CORE_KEY_WORLD_2        162 /* non-US #2 */
#define CORE_KEY_ESCAPE         256
#define CORE_KEY_ENTER          257
#define CORE_KEY_TAB            258
#define CORE_KEY_BACKSPACE      259
#define CORE_KEY_INSERT         260
#define CORE_KEY_DELETE         261
#define CORE_KEY_RIGHT          262
#define CORE_KEY_LEFT           263
#define CORE_KEY_DOWN           264
#define CORE_KEY_UP             265
#define CORE_KEY_PAGE_UP        266
#define CORE_KEY_PAGE_DOWN      267
#define CORE_KEY_HOME           268
#define CORE_KEY_END            269
#define CORE_KEY_CAPS_LOCK      280
#define CORE_KEY_SCROLL_LOCK    281
#define CORE_KEY_NUM_LOCK       282
#define CORE_KEY_PRINT_SCREEN   283
#define CORE_KEY_PAUSE          284
#define CORE_KEY_F1             290
#define CORE_KEY_F2             291
#define CORE_KEY_F3             292
#define CORE_KEY_F4             293
#define CORE_KEY_F5             294
#define CORE_KEY_F6             295
#define CORE_KEY_F7             296
#define CORE_KEY_F8             297
#define CORE_KEY_F9             298
#define CORE_KEY_F10            299
#define CORE_KEY_F11            300
#define CORE_KEY_F12            301
#define CORE_KEY_F13            302
#define CORE_KEY_F14            303
#define CORE_KEY_F15            304
#define CORE_KEY_F16            305
#define CORE_KEY_F17            306
#define CORE_KEY_F18            307
#define CORE_KEY_F19            308
#define CORE_KEY_F20            309
#define CORE_KEY_F21            310
#define CORE_KEY_F22            311
#define CORE_KEY_F23            312
#define CORE_KEY_F24            313
#define CORE_KEY_F25            314
#define CORE_KEY_KP_0           320
#define CORE_KEY_KP_1           321
#define CORE_KEY_KP_2           322
#define CORE_KEY_KP_3           323
#define CORE_KEY_KP_4           324
#define CORE_KEY_KP_5           325
#define CORE_KEY_KP_6           326
#define CORE_KEY_KP_7           327
#define CORE_KEY_KP_8           328
#define CORE_KEY_KP_9           329
#define CORE_KEY_KP_DECIMAL     330
#define CORE_KEY_KP_DIVIDE      331
#define CORE_KEY_KP_MULTIPLY    332
#define CORE_KEY_KP_SUBTRACT    333
#define CORE_KEY_KP_ADD         334
#define CORE_KEY_KP_ENTER       335
#define CORE_KEY_KP_EQUAL       336
#define CORE_KEY_LEFT_SHIFT     340
#define CORE_KEY_LEFT_CONTROL   341
#define CORE_KEY_LEFT_ALT       342
#define CORE_KEY_LEFT_SUPER     343
#define CORE_KEY_RIGHT_SHIFT    344
#define CORE_KEY_RIGHT_CONTROL  345
#define CORE_KEY_RIGHT_ALT      346
#define CORE_KEY_RIGHT_SUPER    347
#define CORE_KEY_MENU           348
#define CORE_KEY_LAST           GLFW_KEY_MENU

/* This is structure of window */
typedef struct window_t
{
    void*           window_p;
    void*           monitor_p;
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

#endif // CORE_GRAPHICS_WINDOW_H
