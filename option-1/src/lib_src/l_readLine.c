/**
 * @file l_readLine.c
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
 * @brief Read a line with stdin as file stream.
 * LF or CR and replace it with NUL.
 * It is supposed that S is already correctly allocated.
 *
 * @param s char pointer to receive the value read.
 * @param len max char pointer length.
 * @return string with the line read.
 */
char *l_readLine(char *s, size_t len)
{
    return l_rbreak(fgets(s, (int)len, stdin));
}
