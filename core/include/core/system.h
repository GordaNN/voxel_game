/*
* Author: Naumenko Nikolay
* Email: v-v-vlasov1999@mail.ru
*
* Module description:
* This module contains system functions.
*/

#ifndef CORE_SYSTEM_H
#define CORE_SYSTEM_H

#include <stdbool.h>

/* This function initializes the glfw library */
bool system_initialize(void);

/* This function load glad */
bool system_opengl_load(void);

/* This function terminates the glfw library and event's queue */
void system_finalize(void);

/* This function returns the value of the GLFW timer */
double system_get_time(void);

#endif // CORE_SYSTEM_H
