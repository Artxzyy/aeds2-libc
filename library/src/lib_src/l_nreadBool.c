/**
 * @file l_nreadBool.c
 * @author Arthur Rodrigues Soares de Quadros ( aquadros\@sga.pucminas.br )
 *
 * Created: 11/07/2022
 * Last updated: 12/07/2022
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "../lib.h"

bool l_nreadBool(size_t len)
{
    return l_fnreadBool(stdin, len);
}

