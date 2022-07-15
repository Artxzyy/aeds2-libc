/**
 * @file l_freadnInt.c
 * @author Arthur Rodrigues Soares de Quadros ( aquadros\@sga.pucminas.br )
 *
 * Created: 11/07/2022
 * Last updated: 12/07/2022
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "../lib.h"

void l_freadnInt(int **ni, int n, FILE *fptr, size_t max_len)
{
    *ni = l_fnreadnInt(n, fptr, max_len);
}
