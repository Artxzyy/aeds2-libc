/**
 * @file l_freadnStr.c
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
 * @brief Read a sequence of 'n' strings separated by white-space or line feed
 * with any file stream, having max length of 'max_len' and returns an array of char pointers.
 *
 * @param m 2d vector to receive the values
 * @param n amount of string to read
 * @param fptr file stream to be read
 * @param max_len max length of each string
 *
 * @return array of char pointers
 */
void l_freadnStr(char **m, int n, FILE *fptr, size_t max_len)
{
    for(register int i = 0; i < n; i++)
    {
        strcpy(m[i], l_fnreadStr(fptr, max_len));
    }
}
