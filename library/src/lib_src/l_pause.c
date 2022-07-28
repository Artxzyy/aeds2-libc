/**
 * @file l_pause.c
 * @author Arthur Rodrigues Soares de Quadros ( aquadros\@sga.pucminas.br )
 *
 * Created: 11/07/2022
 * Last updated: 27/07/2022
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "../lib.h"

/**
 * @brief General pause in the terminal.
 */
void l_pause(void)
{
    printf("Press ENTER to continue.");
    getchar();
}