/**
 * @file lib.c
 * @author Arthur Rodrigues Soares de Quadros ( aquadros\@sga.pucminas.br )
 * @brief General functions in C. A better input library and other things.
 * @version 0.5
 *
 * Created: 10/08/2022
 * Last updated: 10/08/2022
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdarg.h>

#define READ_MODE_ONLY    "r"
#define WRITE_MODE_ONLY   "w"
#define APPEND_MODE_ONLY  "a"

/*  This is not a constant, but a global variable.
    You can re-define it as the max length for strings and other vectors
    in your file and call functions with 's' prefix without passing the
    max length every time.

    The internal first definition is 255.

    The best way to declare and define a global variable in
    a deeply nested C project is declaring the global variable
    in a header file (as declared in "extern int maxlen;") and
    defining it ONLY ONCE in one of the other files used
    (e.g "int maxlen = 255;" in ONE file that includes this one).
    And for possibly changing the value in other files, you simply
    change it (e.g "maxlen = 300;" or "maxlen += 50;").

    In this file, the global was declared and defined at the same time, but
    in the "library" folder it followed this structure. */
size_t maxlen = 255;

/**
 * @brief allocate memory for LEN characters and define variable with empty string if possible.
 *
 * @param len amount of chars to be allocated.
 * @return new char pointer with empty value if possible, NULL if not.
 */
char *l_newStr(size_t len) {
    char *tmp = NULL;

    /* size_t is unsigned long, which means it can't be negative,
       so it will have unpredicted actions and possibly never
       enter the "if" statement if not converted to a signed long. */
    if ((long) len <= 0)
        fprintf(stderr, "ERROR: Invalid length.\n");
    else {
        tmp = (char *) malloc((len + 1) * sizeof(char));
        if (tmp)
            strcpy(tmp, "");
        else
            fprintf(stderr, "ERROR: Not enough memory.\n");
    }
    return tmp;
}

/**
 * @brief allocate memory for MAXLEN characters and define variable with empty string if possible.
 * @return new char pointer with empty value if possible, NULL if not.
 * */
char *l_sNewStr(void) {
    return l_newStr(maxlen);
}

/**
 * Remove string terminator different than '\0' and change it to it.
 * Internal use function.
 */
char *l_rbreak(char *s) {
    for (; *s != 10 && *s != 13; s++);
    *s = 0;
    return s;
}

/**
 * @brief Read a line until line terminator, '\\n' or '\\r' is found and change it to '\0'.
 *
 * @param s char* to receive the value read.
 * @param len max length of string
 * @param fptr file stream.
 * @return string with the line read.
 */
char *l_readLine(char *s, size_t len, FILE *fptr) {
    return l_rbreak(fgets(s, (int) len, fptr));
}

/**
 * @brief Read a line until line terminator, '\\n' or '\\r' is found and change it to '\0'.
 * Uses the global MAXLEN as max string length.
 *
 * @param s char* to receive the value read.
 * @param fptr file stream.
 * @return string with the line read.
 */
char *l_sReadLine(char *s, FILE *fptr) {
    return l_rbreak(fgets(s, (int) maxlen, fptr));
}

/**
 * @brief Read a sequence of characters from any file stream
 * until '\\n', '\\r', white-space
 * is found or the maximum length is reached.
 *
 * @param fptr file stream
 * @param len max length for char pointer
 * @return string read
 */
char *l_readStr(FILE *fptr, size_t len) {
    char *buffer = l_newStr(len);
    if (!buffer)
        fprintf(stderr, "ERROR: Not enough memory.\n");
    else {
        int c;
        char *tmp = buffer;
        while ((c = getc(fptr)) != 10 && c != ' ' && c != 13 && len > 0)
            *tmp++ = (len--, (char) c);
        tmp = ((*tmp++ = 0), NULL);
        free(tmp);
    }
    return buffer;
}

/**
 * @brief Read a sequence of characters from any file stream
 * until '\\n', '\\r', white-space
 * is found or the maximum length is reached.
 * Uses the global MAXLEN as max string length.
 *
 * @param fptr file stream
 * @return string read
 */
char *l_sReadStr(FILE *fptr) {
    return l_readStr(fptr, maxlen);
}

/**
 * @brief Read a string from any file stream and, if possible, casts it
 * into a double variable.
 *
 * @param fptr file stream
 * @param len max length for string
 * @return string parsed as a double variable if possible, .0F if not
 */
double l_readDouble(FILE *fptr, size_t len) {
    double d = .0F;
    char *tmp = l_readStr(fptr, len);
    if (!tmp)
        fprintf(stderr, "ERROR: Not enough memory.\n");
    else {
        for (register int i = 0; i < (int) strlen(tmp); i++)
            if (tmp[i] == ',') tmp[i] = '.';
        d = atof(tmp);
        free(tmp);
    }
    return d;
}

/**
 * @brief Read a string from any file stream and, if possible, casts it
 * into a double variable.
 * Uses the global MAXLEN as max string length.
 *
 * @param fptr file stream
 * @return string parsed as a double variable if possible, 0.0 if not
 */
double l_sReadDouble(FILE *fptr) {
    return l_readDouble(fptr, maxlen);
}

/**
 * @brief Read a string from any file stream and, if possible, casts it
 * into a float variable.
 *
 * @param fptr file stream
 * @param len max string size
 * @return string parsed as a float variable if possible, 0.0 if not
 */
float l_readFloat(FILE *fptr, size_t len) {
    return (float) l_readDouble(fptr, len);
}

/**
 * @brief Read a string from any file stream and, if possible, casts it
 * into a float variable.
 * Uses the global MAXLEN as max string length.
 *
 * @param fptr file stream
 * @return string parsed as a float variable if possible, 0.0 if not
 */
float l_sReadFloat(FILE *fptr) {
    return (float) l_readDouble(fptr, maxlen);
}

/**
 * @brief Read a string from any file stream and, if possible, casts it
 * into an int variable.
 *
 * @param fptr file stream
 * @param len max length of string
 * @return string parsed as an int if possible, 0 if not
 */
int l_readInt(FILE *fptr, size_t len) {
    int i = 0;
    char *tmp = l_readStr(fptr, len);
    if (!tmp)
        fprintf(stderr, "ERROR: Not enough memory.\n");
    else {
        i = atoi(tmp);
        free(tmp);
    }
    return i;
}

/**
 * @brief Read a string from any file stream and, if possible, casts it
 * into an int variable.
 * Uses the global MAXLEN as max string length.
 *
 * @param fptr file stream
 * @return string parsed as an integer variable if possible, 0 if not
 */
int l_sReadInt(FILE *fptr) {
    return l_readInt(fptr, maxlen);
}

/**
 * @brief Read a string from any file stream and return it parsed as a boolean, defining if it is true or false.
 * True values (case is not ignored):
 * "verdadeiro", "VERDADEIRO", "true", "TRUE", "V", "t", "1".
 * Anything different is considered false.
 *
 * @param fptr file stream
 * @param len max length of string
 * @return parsed string value as true or false
 */
bool l_readBool(FILE *fptr, size_t len) {
    bool b = false;
    char *tmp = l_readStr(fptr, len);
    if (!tmp)
        fprintf(stderr, "ERROR: Not enough memory.\n");
    else {
        if ((!strcmp(tmp, "verdadeiro")) ||
            (!strcmp(tmp, "VERDADEIRO")) ||
            (!strcmp(tmp, "true")) ||
            (!strcmp(tmp, "TRUE")) ||
            (!strcmp(tmp, "V")) ||
            (!strcmp(tmp, "t")) ||
            (!strcmp(tmp, "1")))
            b = true;
        free(tmp);
    }
    return b;
}

/**
 * @brief Read a string from any file stream and return it parsed as a boolean, defining if it is true or false.
 * True values (case is not ignored):
 * "verdadeiro", "VERDADEIRO", "true", "TRUE", "V", "t", "1".
 * Anything different is considered false.
 * Uses the global MAXLEN as max string length.
 *
 * @param fptr file stream
 * @return parsed string value as true or false
 */
bool l_sReadBool(FILE *fptr) {
    return l_readBool(fptr, maxlen);
}

/**
 * @brief Read a sequence of 'n' strings separated by white-space or '\\n'
 * with any file stream, having max length of 'max_len' and returns an array of char pointers.
 *
 * @param n amount of strings to read
 * @param fptr file stream
 * @param max_len max length of each string
 *
 * @return array of char pointers
 */
char **l_readNStr(int n, FILE *fptr, size_t max_len) {
    char **m = (char **) malloc(n * sizeof(char *));
    if (!m)
        fprintf(stderr, "ERROR: Not enough memory.\n");
    else {
        char *tmp = l_newStr(max_len);
        if (tmp) {
            for (register int i = 0; i < n; i++) {
                strcpy(tmp, l_readStr(fptr, max_len));
                m[i] = l_newStr(strlen(tmp));
                strcpy(m[i], tmp);
            }
            free(tmp);
        }
    }
    return m;
}

/**
 * @brief Read a sequence of 'n' strings separated by white-space or '\\n'
 * with any file stream, having max length of 'max_len' and returns an array of char pointers.
 *
 * @param n amount of string to read
 * @param fptr file stream to be read
 *
 * @return array of char pointers
 */
char **l_sReadNStr(int n, FILE *fptr) {
    return l_readNStr(n, fptr, maxlen);
}

/**
 * @brief Read a sequence of 'n' int numbers separated by white-space or '\\n'
 * with any stream, having max length of 'max_len' and sets an array with the values.
 *
 * @param n amount of integers to read
 * @param fptr file stream to be read
 * @param max_len max string length to be parsed
 *
 * @return new int pointer with N values read
 * */
int *l_readNInt(int n, FILE *fptr, size_t max_len) {
    int *ni = (int *) malloc(n * sizeof(int));
    if (!ni)
        fprintf(stderr, "ERROR: Not enough memory.\n");
    else {
        char *tmp = l_newStr(max_len);
        for (register int i = 0; i < n; i++)
            ni[i] = (strcpy(tmp, l_readStr(fptr, max_len)), atoi(tmp));
        free(tmp);
    }
    return ni;
}

/**
 * @brief Read a sequence of 'n' int numbers separated by white-space or '\\n'
 * with any stream, having max length of 'max_len' and sets an array with the values.
 *
 * @param n amount of integers to read
 * @param fptr file stream to be read
 *
 * @return new int pointer with 'n' values read
 * */
int *l_sReadNInt(int n, FILE *fptr) {
    return l_readNInt(n, fptr, maxlen);
}

/**
 * @brief General pause in the terminal.
 */
void l_pause(void) {
    getchar();
}

/**
 * @brief Method for printing 2d vectors or pointers to char pointers
 * with a specific format and separator of each value.
 * Any character that isn't a format will be printed normally as a CHAR.
 * Vector formats accepted: %s, %i, %d, %g.
 * Format Application:
 *
 * l_formatPrintVector("{%s} - {%g}", strVector, strVectorSize, strSeparator,
 * floatVector, floatVectorSize, floatSeparator);
 *
 * Go to "tests.c" to see example applications.
 *
 * @param format string with format of parameters to be printed
 **/
void l_formatPrintVector(char *format, ...) {
    va_list ap;
    va_start(ap, format);
    while (*format) {
        if (*format == '%') {
            size_t n;
            char *sep;

            if (*(format + 1) == 'i' || *(format + 1) == 'd') {
                int *ni;

                ni = va_arg(ap, int *);
                n = va_arg(ap, int);
                sep = va_arg(ap, char *);
                if (n == 1)
                    printf("%i", ni[0]);
                else if (n == 2)
                    printf("%i%s%i", ni[0], sep, ni[1]);
                else if (n > 2) {
                    printf("%i%s", ni[0], sep);
                    for (register int i = 1; i < (int) n - 1; ++i)
                        printf("%i%s", ni[i], sep);
                    printf("%i", ni[n - 1]);
                }
            } else if (*(format + 1) == 'g') {
                double *nd;

                nd = va_arg(ap, double *);
                n = va_arg(ap, int);
                sep = va_arg(ap, char *);
                if (n == 1)
                    printf("%g", nd[0]);
                else if (n == 2)
                    printf("%g%s%g", nd[0], sep, nd[1]);
                else if (n > 2) {
                    printf("%g%s", nd[0], sep);
                    for (register int i = 1; i < (int) n - 1; ++i)
                        printf("%g%s", nd[i], sep);
                    printf("%g", nd[n - 1]);
                }
            } else if (*(format + 1) == 's') {
                char **m;

                m = va_arg(ap, char **);
                n = va_arg(ap, int);
                sep = va_arg(ap, char *);
                if (n == 1)
                    printf("%s", m[0]);
                else if (n == 2)
                    printf("%s%s%s", m[0], sep, m[1]);
                else if (n > 2) {
                    printf("%s%s", m[0], sep);
                    for (register int i = 1; i < (int) n - 1; ++i)
                        printf("%s%s", m[i], sep);
                    printf("%s", m[n - 1]);
                }
            } else if (*(format + 1) == '%') {
                printf("%%");
            }
            format++;
        } else
            printf("%c", *format);
        format++;
    }
    va_end(ap);
}

/**
 * @brief Method for building strings with 2d vectors or pointers to char pointers
 * with a specific format and separator for each value.
 * Any character that isn't a format will be printed normally as a CHAR.
 * Vector formats accepted: %s, %i, %d, %g.
 * Format Application:
 *
 * l_formatStrVector(maxlen, "{%s} - {%g}", strVector, strVectorSize, strSeparator,
 * floatVector, floatVectorSize, floatSeparator);
 *
 * Go to "tests.c" to see example applications.
 * It works just the same as l_formatPrintVector, with the only difference being that
 * this one returns a string for you to use after.
 *
 * @param maxSize max string size to be returned
 * @param format string with format of parameters to be printed
 *
 * @return formatted string
 **/
char *l_formatStrVector(size_t maxSize, char *format, ...) {
    char *result = l_newStr(maxSize);
    if (result) {
        va_list ap;
        va_start(ap, format);
        char *tmp = l_newStr(maxSize);
        while (*format) {
            if (*format == '%') {
                size_t n;
                char *sep;

                if (*(format + 1) == 'i' || *(format + 1) == 'd') {
                    int *ni;

                    ni = va_arg(ap, int *);
                    n = va_arg(ap, int);
                    sep = va_arg(ap, char *);
                    if (n == 1) {
                        sprintf(tmp, "%i", ni[0]);
                        strcat(result, tmp);
                    } else if (n == 2) {
                        sprintf(tmp, "%i%s%i", ni[0], sep, ni[1]);
                        strcat(result, tmp);
                    } else if (n > 2) {
                        sprintf(tmp, "%i%s", ni[0], sep);
                        strcat(result, tmp);
                        for (register int i = 1; i < (int) n - 1; ++i) {
                            sprintf(tmp, "%i%s", ni[i], sep);
                            strcat(result, tmp);
                        }
                        sprintf(tmp, "%i", ni[n - 1]);
                        strcat(result, tmp);
                    }
                } else if (*(format + 1) == 'g') {
                    double *nd;

                    nd = va_arg(ap, double *);
                    n = va_arg(ap, int);
                    sep = va_arg(ap, char *);
                    if (n == 1) {
                        sprintf(tmp, "%g", nd[0]);
                        strcat(result, tmp);
                    } else if (n == 2) {
                        sprintf(tmp, "%g%s%g", nd[0], sep, nd[1]);
                        strcat(result, tmp);
                    } else if (n > 2) {
                        sprintf(tmp, "%g%s", nd[0], sep);
                        strcat(result, tmp);
                        for (register int i = 1; i < (int) n - 1; ++i) {
                            sprintf(tmp, "%g%s", nd[i], sep);
                            strcat(result, tmp);
                        }
                        sprintf(tmp, "%g", nd[n - 1]);
                        strcat(result, tmp);
                    }
                } else if (*(format + 1) == 's') {
                    char **m;

                    m = va_arg(ap, char **);
                    n = va_arg(ap, int);
                    sep = va_arg(ap, char *);
                    if (n == 1) {
                        sprintf(tmp, "%s", m[0]);
                        strcat(result, tmp);
                    } else if (n == 2) {
                        sprintf(tmp, "%s%s%s", m[0], sep, m[1]);
                        strcat(result, tmp);
                    } else if (n > 2) {
                        sprintf(tmp, "%s%s", m[0], sep);
                        strcat(result, tmp);
                        for (register int i = 1; i < (int) n - 1; ++i) {
                            sprintf(tmp, "%s%s", m[i], sep);
                            strcat(result, tmp);
                        }
                        sprintf(tmp, "%s", m[n - 1]);
                        strcat(result, tmp);
                    }
                } else if (*(format + 1) == '%') {
                    strcat(result, "%");
                }
                format++;
            } else {
                sprintf(tmp, "%c", *format);
                strcat(result, tmp);
            }
            format++;
        }
        free(tmp);
        va_end(ap);
    }
    return result;
}
