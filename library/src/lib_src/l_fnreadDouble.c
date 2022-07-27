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
    double d = .0F;
    char *tmp = l_fnreadStr(fptr, len);
    if (tmp == NULL)
        fprintf(stderr, "ERROR: Not enough memory.\n");
    else
    {
        for(register int i = 0; i < (int)strlen(tmp); i++)
            if(tmp[i] == ',') tmp[i] = '.';
        d = atof(tmp);
        free(tmp);
    }
    return d;
}
