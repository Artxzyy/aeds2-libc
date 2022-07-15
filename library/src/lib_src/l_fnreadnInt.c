/**
 * @file l_fnreadnInt.c
 * @author Arthur Rodrigues Soares de Quadros ( aquadros\@sga.pucminas.br )
 *
 * Created: 11/07/2022
 * Last updated: 12/07/2022
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "../lib.h"

int *l_fnreadnInt(int n, FILE *fptr, size_t max_len)
{
    int *ni = (int *)malloc(n * sizeof(int));
    if (ni == NULL)
        fprintf(stderr, "ERROR: Not enough memory.\n");
    else
    {
        char *tmp = l_nnewStr(max_len);
        for (register int i = 0; i < n; i++)
            ni[i] = (strcpy(tmp, l_fnreadStr(fptr, max_len)), atoi(tmp));
        free(tmp);
    }
    return ni;
}
