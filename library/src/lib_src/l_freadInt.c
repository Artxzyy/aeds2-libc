/**
 * @file l_freadInt.c
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
 * into an int.
 *
 * @param i integer pointer to receive the value
 * @param fptr file stream
 * @param len max length of string
 * @return string parsed as an int if possible, 0 if not
 */
void l_freadInt(int *i, FILE *fptr, size_t len)
{
    *i = l_fnreadInt(fptr, len);
}
