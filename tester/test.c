#include <stdio.h>
#include "libftprintf.h"

int main (void)
{
	int i;

	printf("ori\n");
	i = printf("i\n");
	printf("\nreturn = %d\n", i);
	printf("\n");
	printf("your\n");
	i = ft_printf("i\n");
	printf("\nreturn = %d\n", i);
	return (0);
}

