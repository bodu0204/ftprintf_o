#include <stdarg.h>
#include <unistd.h>

int	ft_printf(const char *	fmt, ...)
{
	va_list	ap;
	size_t	rtn;
	size_t	len;

	if (!fmt)
		return (0);
	va_start(ap, fmt);
	rtn = 0;
	len = 0;
	while ()
	{
		/* code */
	}
	
	return (rtn);
}
