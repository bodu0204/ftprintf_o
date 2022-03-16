#include <stdio.h>
#include "libftprintf.h"

int main (void)
{
	int i;

	printf("ori\n");
	i = printf("apple, %%d = %-10d, %%-10.80s = %-10.80s, %%x = %x\n", 63, "test", 1024);/*  */
	printf("\nreturn = %d\n", i);
	printf("\n");
	printf("your\n");
	i = ft_printf("apple, %%d = %-10d, %%-10.80s = %-10.80s, %%x = %x\n", 63, "test", 1024);/*  */
	printf("\nreturn = %d\n", i);
	return (0);
}

