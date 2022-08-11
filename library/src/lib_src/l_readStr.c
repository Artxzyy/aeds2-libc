/**
 * @file l_readStr.c
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
 * @brief Read a sequence of characters from any file stream
 * until '\\n', '\\r', white-space
 * is found or the maximum length is reached.
 *
 * @param fptr file stream
 * @param len max length for char pointer
 * @return string read
 */
char *l_readStr(FILE *fptr, size_t len)
{
    char *buffer = l_newStr(len);
    if (buffer == NULL)
        fprintf(stderr, "ERROR: Not enough memory.\n");
    else
    {
        int c;
        char *tmp = buffer;
        while ((c = getc(fptr)) != LF && c != ' ' && c != CR && len > 0)
            *tmp++ = (len--, (char)c);
        tmp = ((*tmp++ = NUL), NULL);
        free(tmp);
    }
    return buffer;
}
