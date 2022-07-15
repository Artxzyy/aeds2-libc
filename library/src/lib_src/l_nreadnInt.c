/**
 * @file l_nreadnInt.c
 * @author Arthur Rodrigues Soares de Quadros ( aquadros\@sga.pucminas.br )
 *
 * Created: 11/07/2022
 * Last updated: 12/07/2022
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "../lib.h"

int *l_nreadnInt(int n, size_t max_len)
{
    return l_fnreadnInt(n, stdin, max_len);
}
