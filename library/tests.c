#include "src/lib.h"

int main()
{
    maxlen = 4096;

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
    int *ni = (int *) malloc(20 * sizeof(int));
    for(register int i = 1; i < 21; ++i)
        ni[i-1] = ((i + (125/i))*i*i)/(i+2);
    l_formatPrintVector("[%s], { %i }\n", vec, 22, ", ", ni, 20, " ");
    strcpy(s1, l_formatStrVector(maxlen, "[%i] - [%s]", ni, 20, ", ", vec, 22, " - "));
    printf("l_formatStrVector: %s\n", s1);
    return EXIT_SUCCESS;
}
