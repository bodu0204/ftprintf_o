#include <stdio.h>
#include "libftprintf.h"

int main (void)
{
	int i;
	char *s = "hello";
	(void)s;

	printf("ori\n");

	printf("[start]");
	i = printf(" %-1c %-2c %-3c ", '0', 0, '1');/*  */
	printf("[end]");

	printf("\nreturn = %d\n", i);
	printf("\n");
	printf("your\n");

	printf("[start]");
	i = ft_printf(" %-1c %-2c %-3c ", '0', 0, '1');/*  */
	printf("[end]");

	printf("\nreturn = %d\n", i);
	return (0);
}

