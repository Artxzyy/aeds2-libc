/**
 * @file l_freadBool.c
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
 * @brief Read a string from stdin and parse it as a boolean to 'b', defining if it is
 * true or false.
 * True values (case is not ignored):
 * "verdadeiro", "VERDADEIRO", "true", "TRUE", "V", "t", "1".
 * Anything different is considered false.
 *
 * @param b address of variable to receive parsed boolean
 * @param fptr file stream
 * @param len max length of string
 */
void l_freadBool(bool *b, FILE *fptr, size_t len)
{
    *b = l_fnreadBool(fptr, len);
}
