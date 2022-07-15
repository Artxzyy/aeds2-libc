/**
 * @file l_fnreadnStr.c
 * @author Arthur Rodrigues Soares de Quadros ( aquadros\@sga.pucminas.br )
 *
 * Created: 11/07/2022
 * Last updated: 12/07/2022
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "../lib.h"

char **l_fnreadnStr(int n, FILE *fptr, size_t max_len)
{
    char **m = (char **)malloc(n * sizeof(char *));
    if (m == NULL)
        fprintf(stderr, "ERROR: Not enough memory.\n");
    else
    {
        char *tmp = l_nnewStr(max_len);
        if(tmp != NULL)
        {
            for (register int i = 0; i < n; i++)
            {
                strcpy(tmp, l_fnreadStr(fptr, max_len));
                m[i] = l_nnewStr(strlen(tmp));
                strcpy(m[i], tmp);
            }
        }
    }
    return m;
}
