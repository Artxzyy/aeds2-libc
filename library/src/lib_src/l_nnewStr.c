/**
 * @file l_nnewStr.c
 * @author Arthur Rodrigues Soares de Quadros ( aquadros\@sga.pucminas.br )
 *
 * Created: 10/07/2022
 * Last updated: 12/07/2022
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "../lib.h"

char *l_nnewStr(size_t len)
{
    char *tmp = NULL;

    /* size_t is unsigned int, which means it can't be negative,
       so it will have unpredicted actions and possibly never
       enter the "if" statement if not converted to a signed int. */
    if ((int)len <= 0)
        fprintf(stderr, "ERROR: Invalid length.\n");
    else
    {
        tmp = (char *)malloc((len + 1) * sizeof(char));
        if(tmp != NULL)
            strcpy(tmp, "");
        else
            fprintf(stderr, "ERROR: Not enough memory.\n");
    }
    return tmp;
}