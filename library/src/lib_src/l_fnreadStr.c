/**
 * @file l_fnreadStr.c
 * @author Arthur Rodrigues Soares de Quadros ( aquadros\@sga.pucminas.br )
 *
 * Created: 10/07/2022
 * Last updated: 12/07/2022
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "../lib.h"

char *l_fnreadStr(FILE *fptr, size_t len)
{
    char *buffer = l_nnewStr(len);
    if (buffer == NULL)
        fprintf(stderr, "ERROR: Not enough memory.\n");
    else
    {
        char *tmp = buffer;
        int c;
        while ((c = getc(fptr)) != LF && c != ' ' && c != CR && len > 0)
            *tmp++ = (len--, (char)c);
        tmp = (*tmp++ = NUL, NULL);
        free(tmp);
    }
    return buffer;
}
