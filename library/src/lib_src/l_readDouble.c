/**
 * @file l_readDouble.c
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
 * into the double pointer 'd'.
 *
 * @param d max length of string
 * @param len max length of string
 */
void l_readDouble(double *d, size_t len)
{
    *d = l_fnreadDouble(stdin, len);
}