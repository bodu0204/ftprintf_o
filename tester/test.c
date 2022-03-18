#include <stdio.h>
#include "libftprintf.h"

int main (void)
{
	int i;
	char *s = "hello";

	printf("ori\n");

	printf("[start]");
	i = printf("apple, %%+010d = %+010d, %%-10.80s = %-10.80s, %%#X = %#X, %%#X = %#X, %%#5%% = %#5%, %%p = %p\n", 63, s, 1024, 0, s);/*  */
	printf("[end]");

	printf("\nreturn = %d\n", i);
	printf("\n");
	printf("your\n");

	printf("[start]");
	i = ft_printf("apple, %%+010d = %+010d, %%-10.80s = %-10.80s, %%#X = %#X, %%#X = %#X, %%#5%% = %#5%, %%p = %p\n", 63, s, 1024, 0, s);/*  */
	printf("[end]");

	printf("\nreturn = %d\n", i);
	return (0);
}

