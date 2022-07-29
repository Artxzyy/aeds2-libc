/**
 * @file l_readStr.c
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
 * @brief Read a sequence of characters from any file stream
 * until line feed, carriage return, white-space
 * is found or the maximum length is reached.
 *
 * @param fptr file stream
 * @param len max length for char pointer
 * @return char*
 */
char *l_readStr(FILE *fptr, size_t len)
{
    char *buffer = l_newStr(len);
    if (buffer == NULL)
        fprintf(stderr, "ERROR: Not enough memory.\n");
    else
    {
        char *tmp = buffer;
        int c;
        while ((c = getc(fptr)) != LF && c != ' ' && c != CR && len > 0)
            *tmp++ = (len--, (char)c);
        tmp = ((*tmp++ = NUL), NULL);
        free(tmp);
    }
    return buffer;
}
