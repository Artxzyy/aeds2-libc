/**
 * @file l_consts.c
 * @author Arthur Rodrigues Soares de Quadros ( aquadros\@sga.pucminas.br )
 *
 * Created: 10/07/2022
 * Last updated: 28/07/2022
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "../lib.h"

const char NUL = '\0'; /* null terminator - NUL */
const char LF  = '\n'; /* line feed - LF */
const char CR  = '\r'; /* carriage return - CR */

/*  This is not a constant, but a global variable.
    You can re-define it as the max length for strings in your file
    and call functions with 's' prefix without passing the max length
    every time.

    The internal first definition is 255.

    The best way to declare and define a global variable in
    a deeply nested C project is declaring the global variable
    in a header file (as declared in "extern int maxlen;") and
    defining it ONLY ONCE in one of the other files used
    (e.g "int maxlen = 255;" in ONE file that includes this one).
    And for possibly changing the value in other files, you simply
    change it (e.g "maxlen = 300;" or "maxlen += 50;"). */
size_t maxlen = 255;
