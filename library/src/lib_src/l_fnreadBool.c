/**
 * @file l_fnreadBool.c
 * @author Arthur Rodrigues Soares de Quadros ( aquadros\@sga.pucminas.br )
 *
 * Created: 11/07/2022
 * Last updated: 12/07/2022
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "../lib.h"

bool l_fnreadBool(FILE *fptr, size_t len)
{
    bool b = false;
    char *tmp = l_fnreadStr(fptr, len);
    if (tmp == NULL)
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
