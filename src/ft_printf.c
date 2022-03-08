#include <stdarg.h>
#include <unistd.h>

enum
{
	OUTPUT,
	PUTLEN,
};

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
		if (output(fmt, len, ap))
			return (-1);
		fmt += len;
		if (*fmt != '%' && rsp(fmt, ap, &len))
			return (-1);
	}
	return (output(NULL, 0, ap));
}

int	output(const char *	str, size_t len, va_list	ap)
{
	static size_t	putlen = 0;
	int flag;

	if (!str)
	{
		va_end(ap);
		return((int)putlen);
	}
	putlen += len;
	#ifdef REAL
		while (len)
		{
			flag = -1 * !putchar(*str);
			str++;
			len--;
		}
	#else
		flag = write(1, str, len);
	#endif
	if (flag == -1)
	{
		va_end(ap);
		return (1);
	}
	return (0);
}
