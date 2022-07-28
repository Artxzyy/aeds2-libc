/**
 * @file l_freadFloat.c
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
 * into the float pointer 'f'.
 *
 * @param f float pointer to receive parsed value
 * @param fptr file stream
 * @param len max length of string
 */
void l_freadFloat(float *f, FILE *fptr, size_t len)
{
    *f = (float)l_fnreadDouble(fptr, len);
}
