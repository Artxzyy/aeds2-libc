/**
 * @file l_freadLine.c
 * @author Arthur Rodrigues Soares de Quadros ( aquadros\@sga.pucminas.br )
 *
 * Created: 10/07/2022
 * Last updated: 12/07/2022
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "../lib.h"

char *l_freadLine(char *s, FILE *fptr, size_t len)
{
    return l_rbreak(fgets(s, (int)len, fptr));
}
