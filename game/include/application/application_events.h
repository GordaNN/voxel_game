/*
* Author: Naumenko Nikolay
* Email: v-v-vlasov1999@mail.ru
*
* Module description:
* This module contains application events.
*/

#ifndef GAME_APPLICATION_APPLICATION_EVENTS_H
#define GAME_APPLICATION_APPLICATION_EVENTS_H

/* Application events */
typedef enum application_event_t
{
    VOID,
    CLOSE_APPLICATION,
    SHOW_CURSOR,
    HIDE_CURSOR,
    MOVE_FORWARD,
    MOVE_BACKWARD,
    MOVE_LEFT,
    MOVE_RIGHT,
    MOVE_UP,
    MOVE_DOWN,
    MOVE_FAST,
    MOVE_SLOW,
    STOP_FORWARD,
    STOP_BACKWARD,
    STOP_LEFT,
    STOP_RIGHT,
    STOP_UP,
    STOP_DOWN,
    APPLICATION_EVENT_NUMBER
} application_event_t;

#endif // GAME_APPLICATION_APPLICATION_EVENTS_H
