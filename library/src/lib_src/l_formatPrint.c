/**
 * @file l_formatPrint.c
 * @author Arthur Rodrigues Soares de Quadros ( aquadros\@sga.pucminas.br )
 *
 * Created: 11/07/2022
 * Last updated: 12/07/2022
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "../lib.h"

void l_formatPrint(char *format, ...)
{
    va_list ap;
    va_start(ap, format);
    while(*format)
    {
        if(*format == '%')
        {
            if(*(format+1) == 'i' || *(format+1) == 'd')
            {
                int x = va_arg(ap, int);
                printf("%i", x);
                format++;
            }
            else if(*(format+1) == 'c') {
                int c = va_arg(ap,
                int);
                printf("%c", (char) c);
                format++;
            }
            else if(*(format+1) == 'f')
            {
                double f = va_arg(ap, double);
                printf("%f", (float)f);
                format++;
            }
            else if(*(format+1) == 'l' && *(format+2) == 'f')
            {
                double d = va_arg(ap, double);
                printf("%lf", d);
                format+=2;
            }
            else if(*(format+1) == 'L' && *(format+2) == 'f')
            {
                long double d = va_arg(ap, long double);
                printf("%Lf", d);
                format+=2;
            }
            else if(*(format+1) == 'g')
            {
                double d = va_arg(ap, double);
                printf("%g", d);
                format++;
            }
            else if(*(format+1) == 'e')
            {
                double d = va_arg(ap, double);
                printf("%e", d);
                format++;
            }
            else if(*(format+1) == 'E')
            {
                double d = va_arg(ap, double);
                printf("%E", d);
                format++;
            }
            else if(*(format+1) == 's')
            {
                char *s = va_arg(ap, char *);
                printf("%s", s);
                format++;
            }
            else if(*(format+1) == 'p')
            {
                void *p = va_arg(ap, void *);
                printf("%p", p);
                format++;
            }
        }
        else if(*format == '$' && *(format+1) == '{' && *(format+3) == '}')
        {
            if(*(format+2) == 's')
            {
                char **m, *sep;
                size_t n;

                m = va_arg(ap, char **);
                n = va_arg(ap, int);
                sep = va_arg(ap, char *);
                if(n == 1)
                    printf("%s", m[0]);
                else if(n == 2)
                    printf("%s%s%s", m[0], sep, m[1]);
                else if(n > 2)
                {
                    printf("%s%s", m[0], sep);
                    for (register int i = 1; i < (int)n - 1; ++i)
                        printf("%s%s", m[i], sep);
                    printf("%s", m[n-1]);
                }
            }
            else if(*(format+2) == 'i' || *(format+2) == 'd')
            {
                int *ni;
                char *sep;
                size_t n;

                ni = va_arg(ap, int *);
                n = va_arg(ap, int);
                sep = va_arg(ap, char *);
                if(n == 1)
                    printf("%i", ni[0]);
                else if(n == 2)
                    printf("%i%s%i", ni[0], sep, ni[1]);
                else if(n > 2)
                {
                    printf("%i%s", ni[0], sep);
                    for (register int i = 1; i < (int)n - 1; ++i)
                        printf("%i%s", ni[i], sep);
                    printf("%i", ni[n-1]);
                }
            }
            else if(*(format+2) == 'g')
            {
                double *nd;
                char *sep;
                size_t n;

                nd = va_arg(ap, double *);
                n = va_arg(ap, int);
                sep = va_arg(ap, char *);
                if(n == 1)
                    printf("%g", nd[0]);
                else if(n == 2)
                    printf("%g%s%g", nd[0], sep, nd[1]);
                else if(n > 2)
                {
                    printf("%g%s", nd[0], sep);
                    for (register int i = 1; i < (int)n - 1; ++i)
                        printf("%g%s", nd[i], sep);
                    printf("%g", nd[n-1]);
                }
            }
            format += 3;
        }
        else
            printf("%c", *format);
        format++;
    }
    va_end(ap);
}
