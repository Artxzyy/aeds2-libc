/**
 * @file l_fsnreadFloat.c
 * @author Arthur Rodrigues Soares de Quadros ( aquadros\@sga.pucminas.br )
 *
 * Created: 11/07/2022
 * Last updated: 11/07/2022
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "../lib.h"

float l_fsnreadFloat(FILE *fptr)
{
    return (float)l_fnreadDouble(fptr, maxlen);
}
