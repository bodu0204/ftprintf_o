#include <stdio.h>
#include "libftprintf.h"

int main (void)
{
	int i;
	char *s = "hello";
	(void)s;

	printf("ori\n");

	printf("[start]");
	i = printf(" %-3s %-3s %-4s %-5s %-3s ", " - ", "", "4", "", "2 ");/*  */
	printf("[end]");

	printf("\nreturn = %d\n", i);
	printf("\n");
	printf("your\n");

	printf("[start]"); fflush(stdout);
	i = ft_printf(" %-3s %-3s %-4s %-5s %-3s ", " - ", "", "4", "", "2 ");/*  */
	printf("[end]");

	printf("\nreturn = %d\n", i);
	return (0);
}

