/*
* Author: Naumenko Nikolay
* Email: v-v-vlasov1999@mail.ru
*
* Module description:
* This module manages bindings of application events.
*/

#include <memory.h>
#include "application/binder.h"

/*
* Local binder settings.
* They are global variables in this module because
* they are supposed to be used in the same exemplar and thread.
* This is done to simplify the code, since you do not need to remember
* about these variables outside of this code.
* To be honest, I'm too lazy to drag the state of binder everywhere,
* especially since it is always in a single instance.
*/
bool is_showed_cursor;
application_event_t keydown_binds_p[349];
application_event_t keyup_binds_p[349];
bool event_states_p[APPLICATION_EVENT_NUMBER];

/* This function initializes binder */
void binder_create(void)
{
    is_showed_cursor = false;
    memset(keydown_binds_p, 0, 349);
    memset(keyup_binds_p, 0, 349);
    memset(event_states_p, false, APPLICATION_EVENT_NUMBER);
}

/* This function returns showed cursor flag */
bool binder_is_showed_cursor(void)
{
    return is_showed_cursor;
}

/* This function binds event with key down */
void binder_bind_keydown_event(
        int                 key,
        application_event_t event)
{
    if (key >= 349 || key < 0)
        return;
    keydown_binds_p[key] = event;
}

/* This function binds event with key up */
void binder_bind_keyup_event(
        int                 key,
        application_event_t event)
{
    if (key >= 349 || key < 0)
        return;
    keyup_binds_p[key] = event;
}

/* This function returns event by key down */
application_event_t binder_get_keydown_event(
        int key)
{
    if (key >= 349 || key < 0)
        return VOID;
    application_event_t event = keydown_binds_p[key];

    /* Event collision */
    switch (event)
    {
    case MOVE_FORWARD:
        if (event_states_p[MOVE_BACKWARD] == true)
            event = VOID;
        else
            event_states_p[MOVE_FORWARD] = true;
        break;
    case MOVE_BACKWARD:
        if (event_states_p[MOVE_FORWARD] == true)
            event = VOID;
        else
            event_states_p[MOVE_BACKWARD] = true;
        break;
    case MOVE_LEFT:
        if (event_states_p[MOVE_RIGHT] == true)
            event = VOID;
        else
            event_states_p[MOVE_LEFT] = true;
        break;
    case MOVE_RIGHT:
        if (event_states_p[MOVE_LEFT] == true)
            event = VOID;
        else
            event_states_p[MOVE_RIGHT] = true;
        break;
    case MOVE_UP:
        if (event_states_p[MOVE_DOWN] == true)
            event = VOID;
        else
            event_states_p[MOVE_UP] = true;
        break;
    case MOVE_DOWN:
        if (event_states_p[MOVE_UP] == true)
            event = VOID;
        else
            event_states_p[MOVE_DOWN] = true;
        break;
    }

    return event;
}

/* This function returns event by key up */
application_event_t binder_get_keyup_event(
        int key)
{
    if (key >= 349 || key < 0)
        return VOID;
    application_event_t event = keyup_binds_p[key];

    /* Event collision */
    switch (event)
    {
    case STOP_FORWARD:
        if (event_states_p[MOVE_BACKWARD] == true)
            event = VOID;
        else
            event_states_p[MOVE_FORWARD] = false;
        break;
    case STOP_BACKWARD:
        if (event_states_p[MOVE_FORWARD] == true)
            event = VOID;
        else
            event_states_p[MOVE_BACKWARD] = false;
        break;
    case STOP_LEFT:
        if (event_states_p[MOVE_RIGHT] == true)
            event = VOID;
        else
            event_states_p[MOVE_LEFT] = false;
        break;
    case STOP_RIGHT:
        if (event_states_p[MOVE_LEFT] == true)
            event = VOID;
        else
            event_states_p[MOVE_RIGHT] = false;
        break;
    case STOP_UP:
        if (event_states_p[MOVE_DOWN] == true)
            event = VOID;
        else
            event_states_p[MOVE_UP] = false;
        break;
    case STOP_DOWN:
        if (event_states_p[MOVE_UP] == true)
            event = VOID;
        else
            event_states_p[MOVE_DOWN] = false;
        break;
    }

    return event;
}
