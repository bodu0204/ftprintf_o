#include <stdarg.h>
#include <unistd.h>
#include "libft.h"

enum
{
	DIRECTION,
	BLANK,
	SING,
	ZERO,
	CONTENT,
	CONTENTLEN,
	ORDERLEN,
	BLOCKLEN,
	B_FMT,
};

enum
{
	DEFAULT_none,
	SPASE_spase,
	PLUS_plus,
	_minus,
	ZEROX_0x,
	_0X,
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
	Enone,
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
	if (f_blc[CONTENT] == Ec)
		s_blc[CONTENTSTR][0] = va_arg(ap, char);
	else if (f_blc[CONTENT] == Es)
		s_blc[CONTENTSTR] = va_arg(ap, char *);
	else if (f_blc[CONTENT] == Ep)
		itosx(s_blc[CONTENTSTR], va_arg(ap, void *));
	else if (f_blc[CONTENT] == Ex || f_blc[CONTENT] == EX)
		itosx(s_blc[CONTENTSTR], va_arg(ap, unsigned int));
	else if (f_blc[CONTENT] == Ed || f_blc[CONTENT] == Ei)
		itosd(s_blc[CONTENTSTR], va_arg(ap, int), f_blc);
	else if (f_blc[CONTENT] == Eu)
		itosu(s_blc[CONTENTSTR], va_arg(ap, unsigned int));
	else if (f_blc[CONTENT] == Eper)
		s_blc[CONTENTSTR][0] = '%';
	adjust(s_blc, f_blc);
	return (0);
}

void	adjust(char	*s_blc[], size_t	*f_blc)
{
	f_blc[CONTENTLEN] = ft_strlen(s_blc[CONTENTSTR]);
	f_blc[ZERO] -= f_blc[CONTENTLEN];
	if (f_blc[ZERO] < 0)
	{
		f_blc[BLANK] += f_blc[ZERO];
		f_blc[ZERO] = 0;
		if (f_blc[BLANK] < 0)
			f_blc[BLANK] = 0;
	}
	if (f_blc[CONTENT] == Ep)
		f_blc[SING] = ZEROX_0x;
	if (f_blc[CONTENT] == EX)
		ft_toupper(s_blc[CONTENTSTR]);
	if (f_blc[CONTENT] == EX && f_blc[SING] == ZEROX_0x)
		f_blc[SING] = _0X;
	if (f_blc[CONTENT] == Ex && !ft_memcmp(s_blc[CONTENTSTR], "0", 2))
		f_blc[SING] = DEFAULT_none;
	if (f_blc[CONTENT] == EX && !ft_memcmp(s_blc[CONTENTSTR], "0", 2))
		f_blc[SING] = DEFAULT_none;
	return ;
}

int	each_len(const char	*block, size_t	*f_blc)
{
	if (*block != '%')
		return (0);
	block++;
	if (set_sing(block ,f_blc))
		return (1);
	if (set_len(block ,f_blc))
		return(1);
	if (set_esc(block ,f_blc))
		return(1);
	return (0);
}