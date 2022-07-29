/**
 * @file l_fnreadnStr.c
 * @author Arthur Rodrigues Soares de Quadros ( aquadros\@sga.pucminas.br )
 *
 * Created: 11/07/2022
 * Last updated: 28/07/2022
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "../lib.h"

/**
 * @brief Read a sequence of 'n' strings separated by white-space or line feed
 * with any file stream, having max length of 'max_len' and returns an array of char pointers.
 *
 * @param n amount of string to read
 * @param max_len max length of each string
 *
 * @return array of char pointers
 */
char **l_fnreadnStr(int n, FILE *fptr, size_t max_len)
{
    char **m = (char **)malloc(n * sizeof(char *));
    if (m == NULL)
        fprintf(stderr, "ERROR: Not enough memory.\n");
    else
    {
        char *tmp = l_nnewStr(max_len);
        if(tmp != NULL)
        {
            for (register int i = 0; i < n; i++)
            {
                strcpy(tmp, l_fnreadStr(fptr, max_len));
                m[i] = l_nnewStr(strlen(tmp));
                strcpy(m[i], tmp);
            }
            free(tmp);
        }
    }
    return m;
}
