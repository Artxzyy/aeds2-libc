/**
 * @file l_nreadnStr.c
 * @author Arthur Rodrigues Soares de Quadros ( aquadros\@sga.pucminas.br )
 *
 * Created: 11/07/2022
 * Last updated: 12/07/2022
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "../lib.h"

char **l_nreadnStr(int n, size_t max_len)
{
    return l_fnreadnStr(n, stdin, max_len);
}
