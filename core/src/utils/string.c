/*
* Author: Naumenko Nikolay
* Email: v-v-vlasov1999@mail.ru
*
* Module description:
* This module contains functions witch helps to work with strings.
*/

#include <string.h>
#include "core/utils/string.h"

/*
* This function returns address of next line (before \n or \0) from text.
* If end_pp == NULL, it returns first line.
*/
bool string_get_line(
        const char** begin_pp,
        const char** end_pp)
{
    if (*end_pp != NULL)
    {
        if (**end_pp == '\0')
            return false;

        *begin_pp = *end_pp + 1;
    }

    const char* new_line = strchr(*begin_pp, '\n');
    const char* string_end = strchr(*begin_pp, '\0');
    *end_pp = (new_line < string_end&& new_line != NULL) ? new_line : string_end;

    return true;
}

/* This function copies string without ignored symbols */
char* string_copy_without(
        char*       to_p,
        const char* from_p,
        size_t      number,
        const char* ignore_p)
{
    size_t j = 0;
    for (size_t i = 0; i < number; ++i)
    {
        bool copy = true;
        for (size_t k = 0; k < strlen(ignore_p); ++k)
            if (from_p[i] == ignore_p[k])
            {
                copy = false;
                break;
            }

        if (copy)
        {
            to_p[j] = from_p[i];
            ++j;
        }
    }
    to_p[j] = '\0';

    return to_p;
}
