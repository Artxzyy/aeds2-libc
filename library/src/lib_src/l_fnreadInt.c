/**
 * @file l_fnreadInt.c
 * @author Arthur Rodrigues Soares de Quadros ( aquadros\@sga.pucminas.br )
 *
 * Created: 11/07/2022
 * Last updated: 12/07/2022
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "../lib.h"

int l_fnreadInt(FILE *fptr, size_t len)
{
    int i = 0;
    char *tmp = l_fnreadStr(fptr, len);
    if (tmp == NULL)
        fprintf(stderr, "ERROR: Not enough memory.\n");
    else
    {
        i = (int)atoi(tmp);
        free(tmp);
    }
    return i;
}
