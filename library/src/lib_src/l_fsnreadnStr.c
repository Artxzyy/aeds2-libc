/**
 * @file l_fsnreadnStr.c
 * @author Arthur Rodrigues Soares de Quadros ( aquadros\@sga.pucminas.br )
 *
 * Created: 11/07/2022
 * Last updated: 12/07/2022
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "../lib.h"

char **l_fsnreadnStr(int n, FILE *fptr)
{
    return l_fnreadnStr(n, fptr, maxlen);
}
