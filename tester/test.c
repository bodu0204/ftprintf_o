#include <stdio.h>
#include "libftprintf.h"

int main (void)
{
	int i;
	char *s = "hello";
	(void)s;

	printf("ori\n");

	printf("[start]");
	i = printf(" %c %c %c ", '0', 0, '1');/*  */
	printf("[end]");

	printf("\nreturn = %d\n", i);
	printf("\n");
	printf("your\n");

	printf("[start]"); fflush(stdout);
	i = ft_printf(" %c %c %c ", '0', 0, '1');/*  */
	printf("[end]");

	printf("\nreturn = %d\n", i);
	return (0);
}

