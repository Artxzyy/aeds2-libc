/**
 * @file tests.c
 * @author Arthur Rodrigues Soares de Quadros ( aquadros\@sga.pucminas.br )
 * @brief Test file for the library functions.
 *
 * Created: 13/08/2022
 * Last updated: 13/08/2022
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "lib.c"

FILE *tests_fptr;

int main(void) {
    tests_fptr = fopen("tests.txt", READ_MODE_ONLY);

    printf("\n\nTests using most of the library functions.\n"
           "In case of any problems, feel free to contact me.\n\n");

    // variables definition

    int a, b, *c;
    double d;
    char *s1, *s2, **m1, **m2;
    bool bo1, bo2, bo3;

    // initializing s1
    s1 = l_sNewStr(); // malloc(256)
    s2 = l_sNewStr(); // malloc(256)

    // redefining global length
    maxlen = 5;

    // detail of readStr
    printf("!!! When the l_readStr is stopped because of the length limit, "
           "you may lose the immediate character after the last one read. !!!\n\n");

    // reading two integers
    a = l_sReadInt(tests_fptr);
    b = l_sReadInt(tests_fptr); // should not read the last digit

    printf("a + b = %i\n", (a+b));

    // printf("remaining: %s", l_sReadStr(tests_fptr));
    printf("Remaining: %s\n\n", l_sReadStr(tests_fptr)); // reading the remaining of the line

    maxlen = 10;
    d = l_sReadDouble(tests_fptr);

    printf("First double: %lf\n", d);
    printf("Second double: %lf\n", l_sReadDouble(tests_fptr));

    printf("Remaining of the second double: %s\n\n", l_sReadStr(tests_fptr));

    bo1 = l_readBool(tests_fptr, 12);
    bo2 = l_readBool(tests_fptr, 12);
    bo3 = l_readBool(tests_fptr, 12);

    printf("bo1, bo2, bo3: %i %i %i\n\n", bo1, bo2, bo3);

    maxlen = 64;
    m1 = l_sReadNStr(15, tests_fptr);
    m2 = l_sReadNStr(17, tests_fptr);

    l_formatPrintVector("{ %s }\n", m1, 15, " ");
    strcpy(s1, l_formatStrVector(255, "[ %s ]", m2, 17, " "));
    free(m2);

    printf("(%s)\n\n", s1);

    free(s1);

    s2 = l_readStr(tests_fptr, 64);
    printf("s2: %s\n", s2);

    l_readLine(s2, (64-1), tests_fptr);
    printf("s2: %s\n\n", s2);

    c = l_readNInt(5, tests_fptr, 3);
    m1 = l_readNStr(4, tests_fptr, 3);

    l_formatPrintVector("Integer vector: {%i};\nString vector: [%s].\n\n",
                        c, 5, ", ",
                        m1, 4, "");

    free(c);
    free(m1);

    return EXIT_SUCCESS;
}
