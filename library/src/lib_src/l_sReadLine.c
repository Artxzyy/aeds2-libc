/**
 * @file l_sReadLine.c
 * @author Arthur Rodrigues Soares de Quadros ( aquadros\@sga.pucminas.br )
 *
 * Created: 10/07/2022
 * Last updated: 29/07/2022
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "../lib.h"

/**
 * @brief Read a line until line terminator is found.
 * LF or CR and replace it with NUL.
 * It is supposed that S is already correctly allocated.
 * Uses the global MAXLEN as max string length.
 *
 * @param s char* to receive the value read.
 * @param fptr file stream.
 * @return string with teh line read.
 */
char *l_sReadLine(char *s, FILE *fptr)
{
    return l_rbreak(fgets(s, (int)maxlen, fptr));
}
