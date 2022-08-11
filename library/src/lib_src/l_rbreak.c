/**
 * @file l_rbreak.c
 * @author Arthur Rodrigues Soares de Quadros ( aquadros\@sga.pucminas.br )
 *
 * Created: 10/07/2022
 * Last updated: 10/08/2022
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "../lib.h"

/**
 * Remove string terminator different than '\0' and change it to it.
 * Internal use function.
 */
char *l_rbreak(char *s)
{
    for (; *s != LF && *s != CR; s++)
        ;
    *s = NUL;
    return s;
}
