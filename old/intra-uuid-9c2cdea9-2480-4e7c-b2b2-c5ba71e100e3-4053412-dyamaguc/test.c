#include <stdio.h>
#include "libftprintf.h"

int main (void)
{
	int i;
	char *s = "hello";
	(void)s;

	printf("your\n");

	printf("[start]"); fflush(stdout);
	i = ft_printf(NULL);/*  */fflush(stdout);
	printf("[end]"); fflush(stdout);

	printf("\nreturn = %d\n", i); fflush(stdout);
	printf("\n");
	printf("ori\n");fflush(stdout);

	printf("[start]"); fflush(stdout);
	i = printf(NULL);/*  */fflush(stdout);
	printf("[end]"); fflush(stdout);

	printf("\nreturn = %d\n", i);

	return (0);
}

