/**
 * @file l_nreadInt.c
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
 * @brief Read a string from stdin and, if possible, casts it
 * into an int.
 *
 * @param len max length of string
 * @return string parsed as an int if possible, 0 if not
 */
int l_nreadInt(size_t len)
{
    return l_fnreadInt(stdin, len);
}
