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
	i = printf(" %.1s %.2s %.3s %.4s ", " - ", "", "4", "");/*  */
	printf("[end]");

	printf("\nreturn = %d\n", i);
	printf("\n");
	printf("your\n");

	printf("[start]"); fflush(stdout);
	i = ft_printf(" %.1s %.2s %.3s %.4s ", " - ", "", "4", "");/*  */
	printf("[end]");

	printf("\nreturn = %d\n", i);
	return (0);
}

