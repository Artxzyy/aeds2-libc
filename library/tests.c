#include "src/lib.h"

int main()
{
    /* declaring variables */
    char *s1, *s2, **vec;
    int integer;
    double d = .0F;
    FILE *fptr;

    d = l_fnreadDouble(stdin, 10);
    printf("%lf\n", d);
    fptr = fopen("simple_test.txt", READ_MODE_ONLY);
    s1 = NULL;


    printf("\nFile for simple implementations of most functions and methods of the library \"lib\"\n\n");

    s2 = l_snnewStr();
    l_fsreadLine(s2, fptr);
    printf("First line: %s\n", s2);
    printf("5 next words: ");
    for (register int i = 0; i < 5; ++i) {
        printf("%s ", l_fsnreadStr(fptr));
    }
    printf("\n");

    integer = l_fnreadInt(fptr, 5);
    printf("Next str parsed as an int, plus 25 | %i + 25 = %i\n", integer, (integer + 25));

    printf("\nNext 22 words in a \"char **\" using \"l_fsnreadnStr()\"\n\n");
    vec = l_fnreadnStr(22, fptr, maxlen);
    for(register int i = 0; i < 22; ++i)
        printf("%s ", vec[i]);
    printf("\n");

    printf("Initial value for global \"maxlen\": %li\n", maxlen);
    maxlen += 245;
    printf("New value for global \"maxlen\": %li\n", maxlen);
    l_newStr(&s1, maxlen);

    l_fsreadLine(s1, fptr);
    printf("Remaining of line: %s\n", s1);

    printf("\nl_formatPrint tests:\n\n");
    double *ni = (double *) malloc(20 * sizeof(double));
    for(register int i = 1; i < 21; ++i)
        ni[i-1] = ((i + (125.0/i))*i*i)/(i+2.0);
    l_formatPrint("{%i - %c _ %f (%lf) ** %s [${s}] => %p - %p | ${g}}\n", 10, '&', 10.5, 843.197287122379, "ABC",
                  vec, 22, ", ", vec, &vec, ni, 20, " ");
    return EXIT_SUCCESS;
}
