/**
 * @file l_nreadStr.c
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
 * @brief Read a sequence of characters from stdin
 * until line feed, carriage return or white-space
 * is found, or the maximum length is reached.
 *
 * @param len max length for char pointer
 * @return char*
 */
char *l_nreadStr(size_t len)
{
    return l_fnreadStr(stdin, len);
}
