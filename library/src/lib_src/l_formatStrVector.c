/**
 * @file l_formatStrVector.c
 * @author Arthur Rodrigues Soares de Quadros ( aquadros\@sga.pucminas.br )
 *
 * Created: 27/07/2022
 * Last updated: 28/07/2022
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "lib.h"

/**
 *  TODO document l_formatStrVector
 * */
char *l_formatStrVector(size_t maxSize, char *format, ...) {
    char *result = l_nnewStr(maxSize);
    if(result != NULL) {
        va_list ap;
        va_start(ap, format);
        char *tmp = l_nnewStr(maxSize);
        while(*format)
        {
            if(*format == '%') {
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
                    }
                    else if (n == 2) {
                        sprintf(tmp, "%i%s%i", ni[0], sep, ni[1]);
                        strcat(result, tmp);
                    }
                    else if (n > 2) {
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
                    }
                    else if (n == 2) {
                        sprintf(tmp, "%g%s%g", nd[0], sep, nd[1]);
                        strcat(result, tmp);
                    }
                    else if (n > 2) {
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
                    }
                    else if (n == 2) {
                        sprintf(tmp, "%s%s%s", m[0], sep, m[1]);
                        strcat(result, tmp);
                    }
                    else if (n > 2) {
                        sprintf(tmp, "%s%s", m[0], sep);
                        strcat(result, tmp);
                        for (register int i = 1; i < (int) n - 1; ++i) {
                            sprintf(tmp, "%s%s", m[i], sep);
                            strcat(result, tmp);
                        }
                        sprintf(tmp, "%s", m[n - 1]);
                        strcat(result, tmp);
                    }
                } else if(*(format + 1) == '%') {
                    strcat(result, "%");
                }
                format++;
            }
            else {
                sprintf(tmp, "%c", *format);
                strcat(result, tmp);
            }
            format++;
        }
        va_end(ap);
        free(tmp);
    }
    return result;
}
