/**
 * @file l_nreplaceChar.c
 * @author Arthur Rodrigues Soares de Quadros ( aquadros\@sga.pucminas.br )
 *
 * Created: 10/07/2022
 * Last updated: 12/07/2022
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "../lib.h"

char *l_nreplaceChar(const char *s, char c1, char c2)
{
    char *result;
    int len = (int)strlen(s);
    result = l_nnewStr(len);
    if(result == NULL)
    {
        fprintf(stderr, "ERROR: Not enough memory.\n");
        result = (char *)s;
    }
    else
    {
        strcpy(result, s);
        for(register int i = 0; i < len; i++)
            if(result[i] == c1)
                result[i] = c2;
    }
    return result;
}
