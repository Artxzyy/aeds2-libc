/**
 * @file l_readBool.c
 * @author Arthur Rodrigues Soares de Quadros ( aquadros\@sga.pucminas.br )
 *
 * Created: 11/07/2022
 * Last updated: 10/08/2022
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "../lib.h"

/**
 * @brief Read a string from any file stream and return it parsed as a boolean, defining if it is true or false.
 * True values (case is not ignored):
 * "verdadeiro", "VERDADEIRO", "true", "TRUE", "V", "t", "1".
 * Anything different is considered false.
 *
 * @param fptr file stream
 * @param len max length of string
 * @return parsed string value as true or false
 */
bool l_readBool(FILE *fptr, size_t len)
{
    bool b = false;
    char *tmp = l_readStr(fptr, len);
    if (!tmp)
        fprintf(stderr, "ERROR: Not enough memory.\n");
    else
    {
        if ((!strcmp(tmp, "verdadeiro")) ||
            (!strcmp(tmp, "VERDADEIRO")) ||
            (!strcmp(tmp, "true")) ||
            (!strcmp(tmp, "TRUE")) ||
            (!strcmp(tmp, "V")) ||
            (!strcmp(tmp, "t")) ||
            (!strcmp(tmp, "1")))
            b = true;
        free(tmp);
    }
    return b;
}
