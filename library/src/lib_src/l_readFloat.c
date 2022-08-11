/**
 * @file l_readFloat.c
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
 * into a float variable.
 *
 * @param fptr file stream
 * @param len max string size
 * @return string parsed as a float variable if possible, 0.0 if not
 */
float l_readFloat(FILE *fptr, size_t len)
{
    return (float)l_readDouble(fptr, len);
}
