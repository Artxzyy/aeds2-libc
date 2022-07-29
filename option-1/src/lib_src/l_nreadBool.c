/**
 * @file l_nreadBool.c
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
 * @brief Read a string from stdin and return it parsed as a boolean, defining if it is true or false.
 * True values (case is not ignored):
 * "verdadeiro", "VERDADEIRO", "true", "TRUE", "V", "t", "1".
 * Anything different is considered false.
 *
 * @param len max length of string
 * @return parsed value as true or false
 */
bool l_nreadBool(size_t len)
{
    return l_fnreadBool(stdin, len);
}

