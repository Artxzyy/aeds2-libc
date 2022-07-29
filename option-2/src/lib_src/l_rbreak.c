/**
 * @file l_rbreak.c
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
 * @brief Remove new-line string terminators and replace with NUL.
 * It is supposed that the parameter is terminated by LF or CR.
 * It changes the original string AND returns the new value.
 *
 * @param s char pointer to be changed.
 * @return string with NUL terminator.
 */
char *l_rbreak(char *s)
{
    for (; *s != LF && *s != CR; s++)
        ;
    *s = NUL;
    return s;
}
