/**
 * @file l_sReadNStr.c
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
 * @brief Read a sequence of 'n' strings separated by white-space or '\\n'
 * with any file stream, having max length of 'max_len' and returns an array of char pointers.
 *
 * @param n amount of string to read
 * @param fptr file stream to be read
 *
 * @return array of char pointers
 */
char **l_sReadNStr(int n, FILE *fptr)
{
    return l_readNStr(n, fptr, maxlen);
}
