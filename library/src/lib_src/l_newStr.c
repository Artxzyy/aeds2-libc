/**
 * @file l_newStr.c
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
 * @brief allocate memory for 'len' characters and define S with empty string if possible.
 * It is supposed that S is already correctly allocated.
 *
 * @param p pointer to char pointer to be allocated.
 * @param len amount of chars to be allocated.
 */
void l_newStr(char **p, size_t len)
{
    *p = l_nnewStr(len);
}
