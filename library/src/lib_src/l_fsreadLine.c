/**
 * @file l_fsreadLine.c
 * @author Arthur Rodrigues Soares de Quadros ( aquadros\@sga.pucminas.br )
 *
 * Created: 10/07/2022
 * Last updated: 12/07/2022
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "../lib.h"

char *l_fsreadLine(char *s, FILE *fptr)
{
    return l_rbreak(fgets(s, (int)maxlen, fptr));
}
