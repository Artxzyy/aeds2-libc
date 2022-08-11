/**
 * @file lib.h
 * @author Arthur Rodrigues Soares de Quadros ( aquadros\@sga.pucminas.br )
 * @brief General functions in C. A better input library and other things.
 * @version 0.4
 *
 * Created: 22/07/2022
 * Last updated: 08/08/2022
 *
 * @copyright Copyright (c) 2022
 *
 */

/*
    The main idea for this library is not just for you to use it. It is also for you
    to use as source of studies for more specific keywords and possibilities of the C language.
    If you see something new that isn't documented in this file, these links may help:

    Specifications about SETLOCALE for Windows:

    https://docs.microsoft.com/pt-br/cpp/c-runtime-library/reference/setlocale-wsetlocale?view=msvc-170
    https://docs.microsoft.com/pt-br/cpp/c-runtime-library/locale-names-languages-and-country-region-strings?view=msvc-170
    https://docs.microsoft.com/pt-br/openspecs/windows_protocols/ms-lcid/a9eac961-e77d-41a6-90a5-ce1a8b0cdb9c

    Attributes and extern keyword in C:

    https://gcc.gnu.org/onlinedocs/gcc/
    https://gcc.gnu.org/onlinedocs/gcc/Common-Variable-Attributes.html
    https://www.geeksforgeeks.org/understanding-extern-keyword-in-c/

    How to use stdarg.h:

    https://linux.die.net/man/3/stdarg
    https://petbcc.ufscar.br/stdarg/
*/

#ifndef _LIB_H
#define _LIB_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdarg.h>

#define READ_MODE_ONLY    "r"
#define WRITE_MODE_ONLY   "w"
#define APPEND_MODE_ONLY  "a"

extern const char NUL;
extern const char LF;
extern const char CR;

extern size_t maxlen;

extern char *l_sNewStr(void);

extern char *l_newStr(size_t);

extern char *l_rbreak(char *);

extern char *l_readLine(char *, size_t);

extern char *l_sReadLine(char *, FILE *);

extern char *l_readStr(FILE *, size_t);

extern char *l_sReadStr(FILE *);

extern double l_sReadDouble(FILE *);

extern double l_readDouble(FILE *, size_t);

extern float l_sReadFloat(FILE *);

extern float l_readFloat(FILE *, size_t);

extern int l_sReadInt(FILE *);

extern int l_readInt(FILE *, size_t);

extern bool l_sReadBool(FILE *);

extern bool l_readBool(FILE *, size_t);

extern char **l_readNStr(int, FILE *, size_t);

extern char **l_sReadNStr(int, FILE *);

extern int *l_readNInt(int, FILE *, size_t);

extern int *l_sReadNInt(int, FILE *);

extern void l_pause(void);

extern void l_formatPrintVector(char *, ...);

extern char *l_formatStrVector(size_t, char *, ...);

#endif // _LIB_H
