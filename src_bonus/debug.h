#ifndef DEBUG_H
#define DEBUG_H
#include <stdio.h>
#define TEST printf("[%s/%d]\n", __FILE__, __LINE__); fflush(stdin);
void show(char* s)
{
    size_t i;
    size_t ii;
    size_t m;
    size_t line;

    line = 32;
    m = 0;
    ii = 0;
    printf("\nstart:%p\n", s);
    while (m < 3)
    {
        printf("|");
        i = 0;
        while (i < line)
        {
            printf("%7zu|", ii + i + 1);
            i++;
        }
        printf("\n|");
        i = 0;
        while (i < line)
        {
            if (*(s + ii + i) == 0 && !m)
                m++;
            printf("%4d(%c)|", (int)*(s + ii + i), (*(s + ii + i) > 32 && *(s + ii + i) < 127) ? *(s + ii + i) : 32);
            i++;
        }
        printf("\n");
        if (m > 0)
            m++;
        ii += line;
    }

}
#endif
