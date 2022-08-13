/**
 * @file l_formatPrintVector.c
 * @author Arthur Rodrigues Soares de Quadros ( aquadros\@sga.pucminas.br )
 *
 * Created: 11/07/2022
 * Last updated: 13/08/2022
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "../lib.h"

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
 * Go to "lib1file/tests.c" to see example applications.
 *
 * @param format string with format of parameters to be printed
 **/
void l_formatPrintVector(char *format, ...)
{
    va_list ap;
    va_start(ap, format);
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
            } else if(*(format + 1) == '%') {
                printf("%%");
            }
            format++;
        }
        else
            printf("%c", *format);
        format++;
    }
    va_end(ap);
}
