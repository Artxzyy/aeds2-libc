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
    Last accessed: 22/07/2022

    https://docs.microsoft.com/pt-br/cpp/c-runtime-library/reference/setlocale-wsetlocale?view=msvc-170
    https://docs.microsoft.com/pt-br/cpp/c-runtime-library/locale-names-languages-and-country-region-strings?view=msvc-170
    https://docs.microsoft.com/pt-br/openspecs/windows_protocols/ms-lcid/a9eac961-e77d-41a6-90a5-ce1a8b0cdb9c

    Attributes as extern keyword in C:

    https://gcc.gnu.org/onlinedocs/gcc/
    https://gcc.gnu.org/onlinedocs/gcc/Common-Variable-Attributes.html
    https://www.geeksforgeeks.org/understanding-extern-keyword-in-c/

    General conventions used in implementations:

    All functions with the prefix 'n' return a value generated inside itself.
    For example: the function "nreaddouble()" is different from "readdouble()"
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

extern const char NUL; /* null terminator - NUL */
extern const char LF;  /* line feed - LF */
extern const char CR;  /* carriage return - CR */

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
extern size_t maxlen;

/**
 * @brief allocate memory for LEN characters and define variable with empty string if possible.
 *
 * @param len amount of chars to be allocated.
 * @return new char pointer with empty value if possible, NULL if not.
 */
extern char * l_nnewStr(size_t len);

/**
 * @brief allocate memory for MAXLEN characters and define variable with empty string if possible.
 * @return new char pointer with empty value if possible, NULL if not.
 * */
extern char *l_snnewStr(void);

/**
 * @brief allocate memory for 'len' characters and define S with empty string if possible.
 * It is supposed that S is already correctly allocated.
 *
 * @param p pointer to char pointer to be allocated.
 * @param len amount of chars to be allocated.
 */
extern void l_newStr(char **, size_t);

/**
 * @brief Create a copy of the char pointer passed,
 * replace C1 with C2 and return
 *
 * @param s char pointer with replaced chars if possible
 *
 * */
extern char *l_nreplaceChar(const char *, char, char);

/**
 * @brief Remove new-line string terminators and replace with NUL.
 * It is supposed that the parameter is terminated by LF or CR.
 * It changes the original string AND returns the new value.
 *
 * @param s char pointer to be changed.
 * @return string with NUL terminator.
 */
extern char *l_rbreak(char *);

/**
 * @brief Read a line until line terminator is found, remove
 * LF or CR and replace it with NUL.
 * It is supposed that S is already correctly allocated.
 *
 * @param s char pointer to receive the value read.
 * @param fptr file stream.
 * @param len max char pointer length.
 * @return string with teh line read.
 */
extern char *l_freadLine(char *, FILE *, size_t);

/**
 * @brief Read a line with stdin as file stream.
 * LF or CR and replace it with NUL.
 * It is supposed that S is already correctly allocated.
 *
 * @param s char pointer to receive the value read.
 * @param len max char pointer length.
 * @return string with the line read.
 */
extern char *l_readLine(char *, size_t);

/**
 * @brief Read a line until line terminator is found.
 * LF or CR and replace it with NUL.
 * It is supposed that S is already correctly allocated.
 * Uses the global MAXLEN as max string length.
 *
 * @param s char* to receive the value read.
 * @param fptr file stream.
 * @return string with teh line read.
 */
extern char *l_fsreadLine(char *, FILE *);

/**
 * @brief Read a sequence of characters from any file stream
 * until line feed, carriage return, white-space
 * is found or the maximum length is reached.
 *
 * @param fptr file stream
 * @param len max length for char pointer
 * @return char*
 */
extern char *l_fnreadStr(FILE *, size_t);

/**
 * @brief Read a sequence of characters from any file stream
 * until line feed, carriage return, white-space
 * is found or the maximum length is reached.
 * Uses the global MAXLEN as max string length.
 *
 * @param fptr file stream
 * @return char*
 */
extern char *l_fsnreadStr(FILE *);

/**
 * @brief Read a sequence of characters from stdin
 * until line feed, carriage return or white-space
 * is found, or the maximum length is reached.
 *
 * @param len max length for char pointer
 * @return char*
 */
extern char *l_nreadStr(size_t);

/**
 * @brief Read a string from stdin and, if possible, casts it
 * into a double variable.
 *
 * @param fptr file stream
 * @param len max length of string
 * @return string parsed as a double variable if possible, 0.0 if not
 */
extern double l_fnreadDouble(FILE *, size_t);

/**
 * @brief Read a string from stdin and, if possible, casts it
 * into a double variable.
 * Uses the global MAXLEN as max string length.
 *
 * @param fptr file stream
 * @return string parsed as a double variable if possible, 0.0 if not
 */
extern double l_fsnreadDouble(FILE *);

/**
 * @brief Read a string from stdin and, if possible, casts it
 * into a double variable.
 *
 * @param len max length of string
 * @return string parsed as a double variable if possible, 0.0 if not
 */
extern double l_nreadDouble(size_t);

/**
 * @brief Read a string from any file stream and, if possible, casts it
 * into the double pointer 'd'.
 *
 * @param d max length of string
 * @param fptr file stream
 * @param len max length of string
 */
extern void l_freadDouble(double *, FILE *, size_t);

/**
 * @brief Read a string from stdin and, if possible, casts it
 * into the double pointer 'd'.
 *
 * @param d max length of string
 * @param len max length of string
 */
extern void l_readDouble(double *, size_t);

/**
 * @brief Read a string from stdin and, if possible, casts it
 * into a float variable.
 * Uses the global MAXLEN as max string length.
 *
 * @param fptr file stream
 * @return string parsed as a float variable if possible, 0.0 if not
 */
extern float l_fnreadFloat(FILE *, size_t);

/**
 * @brief Read a string from any file stream and, if possible, casts it
 * into a float variable.
 * Uses the global MAXLEN as max string length.
 *
 * @param fptr file stream
 * @return string parsed as a float variable if possible, 0.0 if not
 */
extern float l_fsnreadFloat(FILE *);

/**
 * @brief Read a string from stdin and, if possible, casts it
 * into the float pointer 'f'.
 *
 * @param len max length of string
 * @return string parsed as a float if possible, 0.0 if not
 */
extern float l_nreadFloat(size_t);

/**
 * @brief Read a string from any file stream and, if possible, casts it
 * into the float pointer 'f'.
 *
 * @param f float pointer to receive parsed value
 * @param fptr file stream
 * @param len max length of string
 */
extern void l_freadFloat(float *, FILE *, size_t);

/**
 * @brief Read a string from stdin and, if possible, casts it
 * into the float pointer 'f'.
 *
 * @param f float pointer to receive parsed value
 * @param len max length of string
 */
extern void l_readFloat(float *, size_t);

/**
 * @brief Read a string from any file stream and, if possible, casts it
 * into the int.
 *
 * @param fptr file stream
 * @param len max length of string
 * @return string parsed as an int if possible, 0 if not
 */
extern int l_fnreadInt(FILE *, size_t);

/**
 * @brief Read a string from any file stream and, if possible, casts it
 * into an int variable.
 * Uses the global MAXLEN as max string length.
 *
 * @param fptr file stream
 * @return string parsed as an integer variable if possible, 0.0 if not
 */
extern int l_fsnreadInt(FILE *);

/**
 * @brief Read a string from stdin and, if possible, casts it
 * into an int.
 *
 * @param len max length of string
 * @return string parsed as an int if possible, 0 if not
 */
extern int l_nreadInt(size_t);

/**
 * @brief Read a string from any file stream and, if possible, casts it
 * into an int.
 *
 * @param i integer pointer to receive the value
 * @param fptr file stream
 * @param len max length of string
 * @return string parsed as an int if possible, 0 if not
 */
extern void l_freadInt(int *, FILE *, size_t);

/**
 * @brief Read a string and parse it's value to 'i' if possible.
 *
 * @param i address of variable to receive parsed value
 * @param len max string length
 */
extern void l_readInt(int *, size_t);

/**
 * @brief Read a string from any file stream and return it parsed as a boolean, defining if it is true or false.
 * True values (case is not ignored):
 * "verdadeiro", "VERDADEIRO", "true", "TRUE", "V", "t", "1".
 * Anything different is considered false.
 *
 * @param fptr file stream
 * @param len max length of string
 * @return parsed value as true or false
 */
extern bool l_fnreadBool(FILE *, size_t);

/**
 * @brief Read a string from stdin and return it parsed as a boolean, defining if it is true or false.
 * True values (case is not ignored):
 * "verdadeiro", "VERDADEIRO", "true", "TRUE", "V", "t", "1".
 * Anything different is considered false.
 *
 * @param len max length of string
 * @return parsed value as true or false
 */
extern bool l_nreadBool(size_t);

/**
 * @brief Read a string from any file stream and return it parsed as a boolean, defining if it is true or false.
 * True values (case is not ignored):
 * "verdadeiro", "VERDADEIRO", "true", "TRUE", "V", "t", "1".
 * Anything different is considered false.
 * Uses the global MAXLEN as max string length.
 *
 * @param fptr file stream
 * @return parsed value as true or false
 */
extern bool l_fsnreadBool(FILE *);

/**
 * @brief Read a string from stdin and parse it as a boolean to 'b', defining if it is
 * true or false.
 * True values (case is not ignored):
 * "verdadeiro", "VERDADEIRO", "true", "TRUE", "V", "t", "1".
 * Anything different is considered false.
 *
 * @param b address of variable to receive parsed boolean
 * @param len max length of string
 */
extern void l_readBool(bool *, size_t);

/**
 * @brief Read a string from stdin and parse it as a boolean to 'b', defining if it is
 * true or false.
 * True values (case is not ignored):
 * "verdadeiro", "VERDADEIRO", "true", "TRUE", "V", "t", "1".
 * Anything different is considered false.
 *
 * @param b address of variable to receive parsed boolean
 * @param fptr file stream
 * @param len max length of string
 */
extern void l_freadBool(bool *, FILE *, size_t);

/**
 * @brief Read a sequence of 'n' strings separated by white-space or line feed
 * with any file stream, having max length of 'max_len' and returns an array of char pointers.
 *
 * @param n amount of string to read
 * @param max_len max length of each string
 *
 * @return array of char pointers
 */
extern char **l_fnreadnStr(int, FILE *, size_t);

/**
 * @brief Read a sequence of 'n' strings separated by white-space or line feed
 * with any file stream, having max length of 'max_len' and returns an array of char pointers.
 *
 * @param n amount of string to read
 * @param fptr file stream to be read
 *
 * @return array of char pointers
 */
extern char **l_fsnreadnStr(int, FILE *);

/**
 * @brief Read a sequence of 'n' strings separated by white-space or line feed
 * with stdin, having max length of 'max_len' and returns an array of char pointers.
 *
 * @param n amount of string to read
 * @param max_len max length of each string
 *
 * @return array of char pointers
 */
extern char **l_nreadnStr(int, size_t);

/**
 * @brief Read a sequence of 'n' strings separated by white-space or line feed
 * with stdin, having max length of 'max_len' and returns an array of char pointers.
 *
 * @param n amount of string to read
 * @param max_len max length of each string
 *
 * @return array of char pointers
 */
extern char **l_nreadnStr(int, size_t);

/**
 * @brief Read a sequence of 'n' strings separated by white-space or line feed
 * with any file stream, having max length of 'max_len' and returns an array of char pointers.
 *
 * @param m 2d vector to receive the values
 * @param n amount of string to read
 * @param fptr file stream to be read
 * @param max_len max length of each string
 *
 * @return array of char pointers
 */
extern void l_freadnStr(char **, int, FILE *, size_t);

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
extern int *l_fnreadnInt(int, FILE *, size_t);

/**
 * @brief Read a sequence of 'n' int numbers separated by white-space or line feed
 * with any stream, having max length of 'max_len' and sets the "ni" array with the values.
 *
 * @param n amount of integers to read
 * @param fptr file stream to be read
 *
 * @return new int pointer with N values read
 * */
extern int *l_fsnreadnInt(int, FILE *);

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
extern void l_freadnInt(int **, int, FILE *, size_t);

/**
 * @brief Read a sequence of 'n' int numbers separated by white-space or line feed
 * with any stream, having max length of 'max_len' and sets the "ni" array with the values.
 * It is supposed that 'ni' is already correctly allocated.
 *
 * @param n amount of integers to read
 * @param max_len max length of each string to parse as a integer
 *
 * @return int pointer with N values read
 * */
extern int *l_nreadnInt(int, size_t);

/**
 * @brief General pause in the terminal.
 */
extern void l_pause(void);

/**
 * @brief Method for printing 2d vectors or pointers to char pointers
 * with a specific format and separator of each value.
 * It is also accepted some simple variables, but with no limit specified
 * Example: '%2.3f' is not accepted, but '%f' is.\n
 * Any character that isn't a format will be printed normally as a CHAR.
 * For each simple format passed you need to pass a parameter with the
 * respective format, in order.\n\n
 * Simple formats (%) accepted: i, d, c, f, lf, Lf, g, e, E, s, p.\n
 * Example of application with only simple formats:\n\n
 *
 * int x = 5;\n
 * double f = 50.123456789;\n
 * l_formatPrint("%i - %c - %s - %f | %lf", x, '+', "SAMPLE TEXT", (float)f, f);\n\n
 *
 * Expected output: "5 - + - SAMPLE TEXT - 50.123455 | 50.123457"\n\n
 *
 * The syntax for vector formats is "${format}", being "${s}", the "char **"
 * equivalent, for example.
 * For each vector format, you need to pass 3 parameters in this order: the pointer,
 * the size and the separator for each value.
 *
 * Example using vector formats:\n\n
 *
 * int *testInt = (int *) malloc(5 * sizeof(int));\n
 * char **testStr = (char **) malloc(2 * sizeof(char *));\n
 * testStr[0] = l_nnewstr(5);\n
 * testStr[1] = l_nnewstr(6);\n
 * for(int i = 0; i < 5; i++) testInt[i] = i+1;\n
 * strcpy(testStr[0], "First");\n
 * strcpy(testStr[1], "Second");\n
 * l_formatPrint("[${i}] {${s}}", testInt, 5, " - ", testStr, 2, ", ");\n\n
 *
 * Expected output: "[1 - 2 - 3 - 4 - 5] {First, Second}"\n\n
 *
 * Vector formats accepted: i, d, s, g.
 *
 * @param format format for every parameter (ellipsis) and complementary text
 *
 * */
extern void l_formatPrint(char *, ...);

#endif // _LIB_H