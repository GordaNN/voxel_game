/*
* Author: Naumenko Nikolay
* Email: v-v-vlasov1999@mail.ru
*
* Module description:
* This module contains auxiliary functions for working with files.
*/

#include <stdio.h>
#include <stdlib.h>
#include "core/utils/file.h"

/* This function returns contents of the file */
char* file_text_read(
        const char* file_name_p)
{
    char* source_p = NULL;
    FILE* file_p = NULL;
    if ((file_p = fopen(file_name_p, "r")) != NULL)
    {
        fseek(file_p, 0, SEEK_END);

        size_t count = ftell(file_p);
        source_p = calloc(count, sizeof(char));

        fseek(file_p, 0, SEEK_SET);
        for (size_t i = 0, j = 0; j < count; ++i, j = ftell(file_p))
            if (fgets(source_p + j - i, count - j + 1, file_p) == NULL)
            {
                free(source_p);
                source_p = NULL;
                break;
            }
        fclose(file_p);
    }
    return source_p;
}
