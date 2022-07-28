/**
 * @file l_fnreadFloat.c
 * @author Arthur Rodrigues Soares de Quadros ( aquadros\@sga.pucminas.br )
 *
 * Created: 11/07/2022
 * Last updated: 28/07/2022
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "../lib.h"

/**
 * @brief Read a string from stdin and, if possible, casts it
 * into a float variable.
 * Uses the global MAXLEN as max string length.
 *
 * @param fptr file stream
 * @return string parsed as a float variable if possible, 0.0 if not
 */
float l_fnreadFloat(FILE *fptr, size_t len)
{
    return (float)l_fnreadDouble(fptr, len);
}
