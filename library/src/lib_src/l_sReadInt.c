/**
 * @file l_sReadInt.c
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
 * @brief Read a string from any file stream and, if possible, casts it
 * into an int variable.
 * Uses the global MAXLEN as max string length.
 *
 * @param fptr file stream
 * @return string parsed as an integer variable if possible, 0.0 if not
 */
int l_sReadInt(FILE *fptr)
{
    return l_readInt(fptr, maxlen);
}
