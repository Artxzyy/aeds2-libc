/**
 * @file l_nreadnStr.c
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
 * with stdin, having max length of 'max_len' and returns an array of char pointers.
 *
 * @param n amount of string to read
 * @param max_len max length of each string
 *
 * @return array of char pointers
 */
char **l_nreadnStr(int n, size_t max_len)
{
    return l_fnreadnStr(n, stdin, max_len);
}
