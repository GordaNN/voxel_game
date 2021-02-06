/*
* Author: Naumenko Nikolay
* Email: v-v-vlasov1999@mail.ru
*
* Module description:
* This module contains functions witch helps to work with strings.
*/

#ifndef CORE_UTILS_STRING_H
#define CORE_UTILS_STRING_H

#include <stdbool.h>

/*
* This function returns address of next line (before \n or \0) from text.
* If end_pp == NULL, it returns first line.
*/
bool string_get_line(
        const char** begin_pp,
        const char** end_pp);

/* This function copies string without ignored symbols */
char* string_copy_without(
        char*       to_p,
        const char* from_p,
        size_t      number,
        const char* ignore_p);

#endif // CORE_UTILS_STRING_H
