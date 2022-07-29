/**
 * @file lib.h
 * @author Arthur Rodrigues Soares de Quadros ( aquadros\@sga.pucminas.br )
 * @brief General functions in C. A better input library and other things.
 * @version 0.4
 *
 * Created: 22/07/2022
 * Last updated: 10/07/2022
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

    General conventions used in implementations:

    All functions with the prefix 'n' return a value generated inside itself.
    For example: the function "nreadDouble()" is different from "readDouble()"
    because it returns a value for you to define a variable outside the function,
    meanwhile the latter usually receives an extra parameter (a pointer to a double variable in this case)
    which will be defined inside the function itself.

    f  conventions  (...)
    s conventions  (...)

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

extern char * l_nnewStr(size_t len);

extern char *l_snnewStr(void);

extern void l_newStr(char **, size_t);

extern char *l_rbreak(char *);

extern char *l_freadLine(char *, FILE *, size_t);

extern char *l_readLine(char *, size_t);

extern char *l_fsreadLine(char *, FILE *);

extern char *l_fnreadStr(FILE *, size_t);

extern char *l_fsnreadStr(FILE *);

extern char *l_nreadStr(size_t);

extern double l_fnreadDouble(FILE *, size_t);

extern double l_fsnreadDouble(FILE *);

extern double l_nreadDouble(size_t);

extern void l_freadDouble(double *, FILE *, size_t);

extern void l_readDouble(double *, size_t);

extern float l_fnreadFloat(FILE *, size_t);

extern float l_fsnreadFloat(FILE *);

extern float l_nreadFloat(size_t);

extern void l_freadFloat(float *, FILE *, size_t);

extern void l_readFloat(float *, size_t);

extern int l_fnreadInt(FILE *, size_t);

extern int l_fsnreadInt(FILE *);

extern int l_nreadInt(size_t);

extern void l_freadInt(int *, FILE *, size_t);

extern void l_readInt(int *, size_t);

extern bool l_fnreadBool(FILE *, size_t);

extern bool l_nreadBool(size_t);

extern bool l_fsnreadBool(FILE *);

extern void l_readBool(bool *, size_t);

extern void l_freadBool(bool *, FILE *, size_t);

extern char **l_fnreadnStr(int, FILE *, size_t);

extern char **l_fsnreadnStr(int, FILE *);

extern char **l_nreadnStr(int, size_t);

extern void l_freadnStr(char **, int, FILE *, size_t);

extern int *l_fnreadnInt(int, FILE *, size_t);

extern int *l_fsnreadnInt(int, FILE *);

extern void l_freadnInt(int **, int, FILE *, size_t);

extern int *l_nreadnInt(int, size_t);

extern void l_pause(void);

extern void l_formatPrintVector(char *, ...);

extern char *l_formatStrVector(size_t, char *, ...);

#endif // _LIB_H
