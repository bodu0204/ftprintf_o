#include <stdarg.h>
#include <unistd.h>

enum

int	ft_printf(const char *	fmt, ...)
{
	va_list	ap;
	size_t	rtn;
	size_t	len;

	if (!fmt)
		return (0);
	va_start(ap, fmt);
	rtn = 0;
	while (!fmt)
	{
		len = 0;
		while (fmt[len] && fmt[len] != '%')
			len++;
		if (output(fmt, len, ap, PUT))
			return (-1);
		fmt += len;
		if (*fmt != '%' && rsp(fmt, ap, &len))
			return (-1);
	}
	return (rtn);
}
