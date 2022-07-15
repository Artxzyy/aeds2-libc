/**
 * @file l_fnreadDouble.c
 * @author Arthur Rodrigues Soares de Quadros ( aquadros\@sga.pucminas.br )
 *
 * Created: 11/07/2022
 * Last updated: 15/07/2022
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "../lib.h"

double l_fnreadDouble(FILE *fptr, size_t len)
{
    double d = 0.0;
    char *tmp = l_fnreadStr(fptr, len);
    if (tmp == NULL)
        fprintf(stderr, "ERROR: Not enough memory.\n");
    else
    {
        d = atof(l_nreplaceChar(tmp, ',', '.'));
        free(tmp);
    }
    return d;
}
