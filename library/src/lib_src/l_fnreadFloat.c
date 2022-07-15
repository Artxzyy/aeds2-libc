/**
 * @file l_fnreadFloat.c
 * @author Arthur Rodrigues Soares de Quadros ( aquadros\@sga.pucminas.br )
 *
 * Created: 11/07/2022
 * Last updated: 12/07/2022
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "../lib.h"

float l_fnreadFloat(FILE *fptr, size_t len)
{
    return (float)l_fnreadDouble(fptr, len);
}
