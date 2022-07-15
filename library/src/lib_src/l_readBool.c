/**
 * @file l_readBool.c
 * @author Arthur Rodrigues Soares de Quadros ( aquadros\@sga.pucminas.br )
 *
 * Created: 11/07/2022
 * Last updated: 12/07/2022
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "../lib.h"

void l_readBool(bool *b, size_t len)
{
    *b = l_nreadBool(len);
}
