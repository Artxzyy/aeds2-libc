/**
 * @file l_nreadDouble.c
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
 * into a double variable.
 *
 * @param len max length of string
 * @return string parsed as a double variable if possible, 0.0 if not
 */
double l_nreadDouble(size_t len)
{
    return l_fnreadDouble(stdin, len);
}
