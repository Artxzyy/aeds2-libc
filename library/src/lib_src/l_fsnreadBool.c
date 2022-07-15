/**
 * @file l_fsnreadBool.c
 * @author Arthur Rodrigues Soares de Quadros ( aquadros\@sga.pucminas.br )
 *
 * Created: 11/07/2022
 * Last updated: 12/07/2022
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "../lib.h"

bool l_fsnreadBool(FILE *fptr)
{
    return l_fnreadBool(fptr, maxlen);
}
