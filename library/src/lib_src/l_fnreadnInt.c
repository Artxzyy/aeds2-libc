/**
 * @file l_fnreadnInt.c
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
 * @brief Read a sequence of 'n' int numbers separated by white-space or line feed
 * with any stream, having max length of 'max_len' and sets the "ni" array with the values.
 *
 * @param n amount of integers to read
 * @param fptr file stream to be read
 * @param max_len max string length to be parsed
 *
 * @return new int pointer with N values read
 * */
int *l_fnreadnInt(int n, FILE *fptr, size_t max_len)
{
    int *ni = (int *)malloc(n * sizeof(int));
    if (ni == NULL)
        fprintf(stderr, "ERROR: Not enough memory.\n");
    else
    {
        char *tmp = l_nnewStr(max_len);
        for (register int i = 0; i < n; i++)
            ni[i] = (strcpy(tmp, l_fnreadStr(fptr, max_len)), atoi(tmp));
        free(tmp);
    }
    return ni;
}
