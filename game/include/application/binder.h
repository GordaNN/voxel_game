/*
* Author: Naumenko Nikolay
* Email: v-v-vlasov1999@mail.ru
*
* Module description:
* This module manages bindings of application events.
*/

#ifndef GAME_APPLICATION_BINDER_H
#define GAME_APPLICATION_BINDER_H

#include <stdbool.h>
#include "application/application_events.h"

/* This function initializes binder */
void binder_create(void);

/* This function returns showed cursor flag */
bool binder_is_showed_cursor(void);

/* This function binds event with key down */
void binder_bind_keydown_event(
        int                 key,
        application_event_t event);

/* This function binds event with key up */
void binder_bind_keyup_event(
        int                 key,
        application_event_t event);

/* This function returns event by key down */
application_event_t binder_get_keydown_event(
        int key);

/* This function returns event by key up */
application_event_t binder_get_keyup_event(
        int key);

#endif // GAME_APPLICATION_BINDER_H
