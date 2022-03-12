#include <stdarg.h>
#include <unistd.h>
#include "libft.h"

enum
{
	DIRECTION,
	BLANK,
	SING,
	ZERO,
	CONTENTLEN,
	CONTENT,
	ORDERLEN,
	BLOCKLEN,
	B_FMT,
};

enum
{
	Ec,
	Es,
	Ep,
	Ed,
	Ei,
	Eu,
	Ex,
	EX,
	Eper,
	ERROR,
};

enum
{
	Defalt,
	Es,
	Ep,
	Ed,
	Ei,
	Eu,
	Ex,
	EX,
	Eper,
	ERROR,
};

enum
{
	FMTSTR,
	CONTENTSTR,
	B_STR,
};

#define BUFFER 32

int	ft_printf(const char	*fmt, ...)
{
	va_list	ap;
	int i;

	if (!fmt)
		return (-1);
	if (!*fmt)
		return (0);
	va_start(ap, fmt);
	i = put_block(fmt, fmt + ft_strlen(fmt) - 1, ap);
	va_end(ap);
	return (i);
}

int	put_block(const char	*s, const char	*e, va_list	ap)
{
	size_t	f_blc[B_FMT];
	char	*s_blc[B_STR];
	char	con[BUFFER];
	int		putlen;
	int		i;

	ft_bzero(f_blc, sizeof(f_blc));
	putlen = 0;
	s_blc[CONTENTSTR] = con;
	while (e > s && *e != '%')
	{
		e--;
		f_blc[BLOCKLEN]++;
	}
	f_blc[BLOCKLEN]++;
	if (set_block(e, s_blc, f_blc, ap))
		return (-1);
	if (e > s)
		putlen = put_block(s, e - 1, ap);
	if (putlen == -1)
		return (-1);
	i = output(s_blc, f_blc);
	if (i == -1)
		return (-1);
	return (putlen + i);
}

int	set_block(const char	*block, char	*s_blc[], size_t	*f_blc, va_list	ap)
{
	if (each_len(block, f_blc))
		return (1);
	s_blc[FMTSTR] = block + f_blc[ORDERLEN];
	if (f_blc[ORDERLEN] == Ec)
		*s_blc[CONTENTSTR] = va_arg(ap, char);
}
