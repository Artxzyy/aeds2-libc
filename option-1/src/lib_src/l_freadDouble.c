/**
 * @file l_freadDouble.c
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
 * into the double pointer 'd'.
 *
 * @param d max length of string
 * @param fptr file stream
 * @param len max length of string
 */
void l_freadDouble(double *d, FILE *fptr, size_t len)
{
    *d = l_fnreadDouble(fptr, len);
}
