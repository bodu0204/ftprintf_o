#include "ft_printf.h"

int	ft_printf(const char	*fmt, ...)
{
	va_list	ap;
	t_mum	n;
	size_t	len;

	if (!fmt)
		return (0);
	va_start(ap, fmt);
	while (!fmt)
	{
		len = 0;
		while (fmt[len] && fmt[len] != '%')
			len++;
		if (my_putstr(fmt, len) < 0)
			return (-1);
		fmt += len;
		ft_bzero(&n, sizeof(t_mum));
		fmt += numblock(fmt, &n, ap);
		if (n.type == Eerror)
		{
			my_putchar(CLEAN);
			return (-1);
		}
	}
	return (my_putchar(FLUSH));
}

size_t	numblock(const char	fmt, t_mum	*n, va_list	ap)
{}
