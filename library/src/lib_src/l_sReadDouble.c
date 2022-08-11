/**
 * @file l_sReadDouble.c
 * @author Arthur Rodrigues Soares de Quadros ( aquadros\@sga.pucminas.br )
 *
 * Created: 11/07/2022
 * Last updated: 10/08/2022
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "../lib.h"

/**
 * @brief Read a string from any file stream and, if possible, casts it
 * into a double variable.
 * Uses the global MAXLEN as max string length.
 *
 * @param fptr file stream
 * @return string parsed as a double variable if possible, 0.0 if not
 */
double l_sReadDouble(FILE *fptr)
{
    return l_readDouble(fptr, maxlen);
}
