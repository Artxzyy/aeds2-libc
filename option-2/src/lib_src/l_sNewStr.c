/**
 * @file l_sNewStr.c
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
 * @brief allocate memory for MAXLEN characters and define variable with empty string if possible.
 * @return new char pointer with empty value if possible, NULL if not.
 * */
char *l_sNewStr(void)
{
    return l_newStr(maxlen);
}
