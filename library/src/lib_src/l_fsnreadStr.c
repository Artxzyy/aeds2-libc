/**
 * @file l_fsnreadStr.c
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
 * @brief Read a sequence of characters from any file stream
 * until line feed, carriage return, white-space
 * is found or the maximum length is reached.
 * Uses the global MAXLEN as max string length.
 *
 * @param fptr file stream
 * @return char*
 */
char *l_fsnreadStr(FILE *fptr)
{
    return l_fnreadStr(fptr, maxlen);
}
