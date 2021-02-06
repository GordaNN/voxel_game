/*
* Author: Naumenko Nikolay
* Email: v-v-vlasov1999@mail.ru
*
* Module description:
* This module contains auxiliary functions for working with files.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "core/utils/string.h"
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

/* This function parse text of ini file */
bool file_parse_ini(
        const char* text_p)
{
    const char* begin_p = text_p;
    const char* end_p = NULL;

    while (string_get_line(&begin_p, &end_p))
    {
        if (begin_p == end_p)
            continue;

        /* Find token */
        const char* min_p = end_p;

        const char* pos_comment_p = strchr(begin_p, ';');
        min_p = ((pos_comment_p < min_p) && (pos_comment_p != NULL)) ? pos_comment_p : min_p;

        const char* pos_section_p = strchr(begin_p, '[');
        min_p = ((pos_section_p < min_p) && (pos_section_p != NULL)) ? pos_section_p : min_p;

        const char* pos_equal_p = strchr(begin_p, '=');
        min_p = ((pos_equal_p < min_p) && (pos_equal_p != NULL)) ? pos_equal_p : min_p;

        /* Token processing */
        switch (*min_p)
        {
        case '[': /* section */
        {
            const char* pos_section_end_p = strchr(min_p, ']');
            if (pos_section_end_p > end_p)
                return false;

            ++min_p;
            char* section_name_p = malloc(pos_section_end_p - min_p + 1);
            if (section_name_p == NULL)
                return false;
            string_copy_without(section_name_p, min_p, pos_section_end_p - min_p, " \t");

            /* debug */ printf("%s\n", section_name_p);
            /* debug */ free(section_name_p);
        }
        break;
        case '=': /* var */
        {
            /* Var name */
            char* var_name_p = malloc(min_p - begin_p + 1);
            if (var_name_p == NULL)
                return false;
            string_copy_without(var_name_p, begin_p, min_p - begin_p, " \t");

            /* debug */ printf("%s = ", var_name_p);
            /* debug */ free(var_name_p);

            /* Var value */
            begin_p = min_p + 1;
            min_p = end_p;

            const char* pos_bool_p = strstr(begin_p, "true");
            min_p = ((pos_bool_p < min_p) && (pos_bool_p != NULL)) ? pos_bool_p : min_p;

            pos_bool_p = strstr(begin_p, "false");
            min_p = ((pos_bool_p < min_p) && (pos_bool_p != NULL)) ? pos_bool_p : min_p;

            const char* pos_string_p = strchr(begin_p, '"');
            min_p = ((pos_string_p < min_p) && (pos_string_p != NULL)) ? pos_string_p : min_p;

            const char* pos_float_p = strchr(begin_p, '.');
            min_p = ((pos_float_p < min_p) && (pos_float_p != NULL)) ? pos_float_p : min_p;

            switch (*min_p)
            {
            case 't': /* bool */
            {
                /* debug */ printf("true\n");
            }
            break;
            case 'f': /* bool */
            {
                /* debug */ printf("false\n");
            }
            break;
            case '"': /* string */
            {
                begin_p = min_p + 1;
                min_p = strchr(begin_p, '"');
                if (min_p == NULL)
                    return false;

                char* var_value_p = malloc(min_p - begin_p + 1);
                if (var_value_p == NULL)
                    return false;
                var_value_p[min_p - begin_p] = '\0';

                strncpy(var_value_p, begin_p, min_p - begin_p);

                /* debug */ printf("'%s'\n", var_value_p);
                /* debug */ free(var_value_p);
            }
            break;
            case '.': /* float */
            {
                float value = 0.0f;
                sscanf_s(begin_p, "%f", &value);
                /* debug */ printf("%f\n", value);
            }
            break;
            default: /* int */
            {
                int value = 0;
                sscanf_s(begin_p, "%i", &value);
                /* debug */ printf("%i\n", value);
            }
            }
        }
        }
    }
    return true;
}
