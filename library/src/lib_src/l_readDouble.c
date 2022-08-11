/**
 * @file l_readDouble.c
 * @author Arthur Rodrigues Soares de Quadros ( aquadros\@sga.pucminas.br )
 *
 * Created: 11/07/2022
 * Last updated: 29/07/2022
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "../lib.h"

/**
 * @brief Read a string from any file stream and, if possible, casts it
 * into a double variable.
 *
 * @param fptr file stream
 * @param len max length for string
 * @return string parsed as a double variable if possible, .0F if not
 */
double l_readDouble(FILE *fptr, size_t len)
{
    double d = .0F;
    char *tmp = l_readStr(fptr, len);
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
