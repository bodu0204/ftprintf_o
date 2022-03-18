#include <stdio.h>
#include "libftprintf.h"

int main (void)
{
	int i;

	printf("ori\n");
	i = printf("apple, %%+10d = %+10d, %%-10.80s = %-10.80s, %%#x = %#x, %%#x = %#x, %#5%\n", 63, NULL, 1024, 0);/*  */
	printf("\nreturn = %d\n", i);
	printf("\n");
	printf("your\n");
	i = ft_printf("apple, %%+10d = %+10d, %%-10.80s = %-10.80s, %%#x = %#x, %%#x = %#x, %#5%\n", 63, NULL, 1024, 0);/*  */
	printf("\nreturn = %d\n", i);
	return (0);
}

