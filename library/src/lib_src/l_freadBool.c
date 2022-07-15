/**
 * @file l_freadBool.c
 * @author Arthur Rodrigues Soares de Quadros ( aquadros\@sga.pucminas.br )
 *
 * Created: 11/07/2022
 * Last updated: 12/07/2022
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "../lib.h"

void l_freadBool(bool *b, FILE *fptr, size_t len)
{
    *b = l_fnreadBool(fptr, len);
}
