#include "ft_printf.h"

int	my_putchar(int	c)
{
	static char		stream[STMSIZE + BUFFER];
	static size_t	i = 0;
	size_t			ii;
	size_t			iii;

	if (!c)
		return (0);
	i++;
	ii = i % STMSIZE;
	if (c == FLUSH || c == CLEAN)
	{
		iii = i - 1;
		i = 0;
		if (c == FLUSH)
			if (write(1, stream, ii) < 0)
				return (-1);
		return (iii);
	}
	stream[ii] = c;
	stream[ii + 1] = '\0';
	if (!ii)
		if (write(1, stream, STMSIZE) < 0)
			return (-1);
	return (1);
}

size_t	my_putchars(int	c, size_t	i)
{
	int		j;
	size_t	ii;

	j = 1;
	ii = 0;
	while (ii < i && j > 0)
	{
		j = my_putchar(c);
		ii++;
	}
	if (j < 0)
	{
		my_putchar(CLEAN);
		return (-1);
	}
	return (ii);
}

size_t	my_putstr(const char	*str, size_t	i)
{
	int		j;
	size_t	ii;

	j = 1;
	ii = 0;
	while (ii < i && j > 0 && str[ii])
	{
		j = my_putchar(str[ii]);
		ii++;
	}
	if (j < 0)
		my_putchar(CLEAN);
	return (ii);
}

size_t	my_puts(const char	*str)
{
	return (my_putstr(str, ft_strlen(str)));
}
