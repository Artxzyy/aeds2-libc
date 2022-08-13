/**
 * @file tests.c
 * @brief Tests with encoding using "wide chars" and "setlocale".
 * @author Arthur Rodrigues Soares de Quadros ( aquadros\@sga.pucminas.br )
 *
 * Created: 16/07/2022
 * Last updated: 13/08/2022
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>
#include <locale.h>

#define MAX 255

int main(void) {
    // for Linux Ubuntu:
    setlocale(LC_ALL, "pt_BR.UTF-8"); // does not work on Windows

    // for Windows:
    // setlocale(LC_ALL, "pt-BR"); // does not work on Linux

    /*  include "wchar.h" for using the wide input/output functions
        they work just the same as the "string.h", with the difference
        that instead of representing a string as an array of one byte chars,
        it's represented as an array of integers (four byte chars).

        example of changes from string.h to wchar.h:
        'char' and any variation is replaced with 'wchar_t'
        'strstr()' is replaced with 'wcsstr()'
        'strcmp()' is replaced with 'wcscmp()'
        'printf("")' is replaced with 'wprintf(L"")' */

    wchar_t *ws = (wchar_t *)malloc((MAX + 1) * sizeof(wchar_t));
    fgetws(ws, MAX, stdin);
    wprintf(L"%ls\n", ws);

    return EXIT_SUCCESS;
}
