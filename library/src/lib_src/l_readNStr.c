/**
 * @file l_readNStr.c
 * @author Arthur Rodrigues Soares de Quadros ( aquadros\@sga.pucminas.br )
 *
 * Created: 11/07/2022
 * Last updated: 29/07/2022
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "../lib.h"

/**
 * @brief Read a sequence of 'n' strings separated by white-space or '\\n'
 * with any file stream, having max length of 'max_len' and returns an array of char pointers.
 *
 * @param n amount of strings to read
 * @param fptr file stream
 * @param max_len max length of each string
 *
 * @return array of char pointers
 */
char **l_readNStr(int n, FILE *fptr, size_t max_len)
{
    char **m = (char **)malloc(n * sizeof(char *));
    if (!m)
        fprintf(stderr, "ERROR: Not enough memory.\n");
    else
    {
        char *tmp = l_newStr(max_len);
        if(tmp)
        {
            for (register int i = 0; i < n; i++)
            {
                strcpy(tmp, l_readStr(fptr, max_len));
                m[i] = l_newStr(strlen(tmp));
                strcpy(m[i], tmp);
            }
            free(tmp);
        }
    }
    return m;
}
