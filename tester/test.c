#include <stdio.h>
#include <limits.h>
#include "libftprintf.h"

int main (void)
{
	int i;
	char *s = "hello";
	(void)s;

	printf("ori\n");

	printf("[start]");
	i = printf(" %+d %+d %+d %+d %+d %+d %+d", INT_MAX, INT_MIN, (int)LONG_MAX, (int)LONG_MIN, (int)ULONG_MAX, 0, -42);/*  */
	printf("[end]");

	printf("\nreturn = %d\n", i);
	printf("\n");
	printf("your\n");

	printf("[start]"); fflush(stdout);
	i = ft_printf(" %+d %+d %+d %+d %+d %+d %+d", INT_MAX, INT_MIN, (int)LONG_MAX, (int)LONG_MIN, (int)ULONG_MAX, 0, -42);/*  */
	printf("[end]");

	printf("\nreturn = %d\n", i);
	return (0);
}

