/*
* Author: Naumenko Nikolay
* Email: v-v-vlasov1999@mail.ru
*
* Module description:
* This module contains auxiliary functions for working with files.
*/

#ifndef CORE_UTILS_FILE_H
#define CORE_UTILS_FILE_H

#include <stdbool.h>

/* This function returns contents of the file */
char* file_text_read(
        const char* file_name_p);

/* This function parse text of ini file */
bool file_parse_ini(
        const char* text_p);

#endif // CORE_UTILS_FILE_H
