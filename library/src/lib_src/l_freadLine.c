/**
 * @file l_freadLine.c
 * @author Arthur Rodrigues Soares de Quadros ( aquadros\@sga.pucminas.br )
 *
 * Created: 10/07/2022
 * Last updated: 28/07/2022
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "../lib.h"

/**
 * @brief Read a line until line terminator is found, remove
 * LF or CR and replace it with NUL.
 * It is supposed that S is already correctly allocated.
 *
 * @param s char pointer to receive the value read.
 * @param fptr file stream.
 * @param len max char pointer length.
 * @return string with teh line read.
 */
char *l_freadLine(char *s, FILE *fptr, size_t len)
{
    return l_rbreak(fgets(s, (int)len, fptr));
}
