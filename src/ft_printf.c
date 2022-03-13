#include <stdarg.h>
#include <unistd.h>
#include "libft.h"


int	ft_printf(const char	*fmt, ...)
{
	va_list	ap;
	size_t	i;
	size_t	len;

	if (!fmt)
		return (0);
	va_start(ap, fmt);
	while (!fmt)
	{
		len = 0;
		while (fmt[len] && fmt[len] != '%')
			len++;
		if (output(fmt, len, ap))
			return (-1);
		fmt += len;
		len = 0;
		if (*fmt == '%')
			if (rsp(fmt, ap, &len))
				return (-1);
			else
				fmt += len;
	}
	return (output(NULL, 0, ap));
}

int	output(const char	*str, size_t	len, va_list	ap)
{
	static size_t	putlen = 0;
	int				flag;

	if (!str)
	{
		va_enmod(ap);
		flag = (int)putlen;
		putlen = 0;
		return (flag);
	}
	putlen += len;
	flag = write(1, str, len);
	if (flag == -1)
	{
		va_end(ap);
		putlen = 0;
		return (1);
	}
	return (0);
}

int	rsp(const char	*str, va_list	ap, size_t	*len)
{
	int	rtn;

	rtn = 0;
	*len = 1;
}
