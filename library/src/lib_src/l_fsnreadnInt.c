/**
 * @file l_fsnreadnInt.c
 * @author Arthur Rodrigues Soares de Quadros ( aquadros\@sga.pucminas.br )
 *
 * Created: 11/07/2022
 * Last updated: 12/07/2022
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "../lib.h"

int *l_fsnreadnInt(int n, FILE *fptr)
{
    return l_fnreadnInt(n, fptr, maxlen);
}
