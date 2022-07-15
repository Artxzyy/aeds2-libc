/**
 * @file l_nreadDouble.c
 * @author Arthur Rodrigues Soares de Quadros ( aquadros\@sga.pucminas.br )
 *
 * Created: 11/07/2022
 * Last updated: 12/07/2022
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "../lib.h"

double l_nreadDouble(size_t len)
{
    return l_fnreadDouble(stdin, len);
}
