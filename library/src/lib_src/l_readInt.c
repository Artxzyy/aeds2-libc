/**
 * @file l_readInt.c
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
 * @brief Read a string and parse it's value to 'i' if possible.
 *
 * @param i address of variable to receive parsed value
 * @param len max string length
 */
void l_readInt(int *i, size_t len)
{
    *i = l_fnreadInt(stdin, len);
}
