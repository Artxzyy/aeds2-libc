/**
 * @file l_fsnreadnInt.c
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
 *
 * @return new int pointer with N values read
 * */
int *l_fsnreadnInt(int n, FILE *fptr)
{
    return l_fnreadnInt(n, fptr, maxlen);
}
