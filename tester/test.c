#include <stdio.h>
#include "libftprintf.h"

int main (void)
{
	int i;

	printf("ori\n");
	i = printf("apple, %%d = %d, %%s = %s\n", 63, "test");/*  */
	printf("\nreturn = %d\n", i);
	printf("\n");
	printf("your\n");
	i = ft_printf("apple, %%d = %d, %%s = %s\n", 63, "test");/*  */
	printf("\nreturn = %d\n", i);
	return (0);
}

