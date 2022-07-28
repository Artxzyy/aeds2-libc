/**
 * @file l_freadnInt.c
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
 * It is supposed that 'ni' is already correctly allocated.
 *
 * @param ni pointer integer pointer (int **) to receive the values
 * @param n amount of integers to read
 * @param fptr file stream to be read
 * @param max_len max length of each string to parse as a integer
 * */
void l_freadnInt(int **ni, int n, FILE *fptr, size_t max_len)
{
    *ni = l_fnreadnInt(n, fptr, max_len);
}
