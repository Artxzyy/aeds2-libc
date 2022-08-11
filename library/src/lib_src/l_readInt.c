/**
 * @file l_readInt.c
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
 * @brief Read a string from any file stream and, if possible, casts it
 * into an int variable.
 *
 * @param fptr file stream
 * @param len max length of string
 * @return string parsed as an int if possible, 0 if not
 */
int l_readInt(FILE *fptr, size_t len)
{
    int i = 0;
    char *tmp = l_readStr(fptr, len);
    if (!tmp)
        fprintf(stderr, "ERROR: Not enough memory.\n");
    else
    {
        i = atoi(tmp);
        free(tmp);
    }
    return i;
}
