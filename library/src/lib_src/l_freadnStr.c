/**
 * @file l_freadnStr.c
 * @author Arthur Rodrigues Soares de Quadros ( aquadros\@sga.pucminas.br )
 *
 * Created: 11/07/2022
 * Last updated: 12/07/2022
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "../lib.h"

void l_freadnStr(char **m, int n, FILE *fptr, size_t max_len)
{
    for(register int i = 0; i < n; i++)
    {
        strcpy(m[i], l_fnreadStr(fptr, max_len));
    }
}
