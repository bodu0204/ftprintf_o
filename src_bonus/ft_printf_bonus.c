#include "ft_printf_bonus.h"

int	ft_printf(const char	*fmt, ...)
{
	va_list	ap;
	int		rtn;
	char	*str;

	if (!fmt)
		return (-1);
	if (!*fmt)
		return (0);
	rtn = -1;
	va_start(ap, fmt);
	str = block(fmt, 0, ap);
	va_end(ap);
	if (str)
	{
		rtn = write(1, str, ft_strlen(str));
		free(str);
	}
	return (rtn);
}

char*	block(const char	*fmt, size_t	len, va_list	ap)
{
	t_block	b;
	char	*s;

	if(!*fmt)
		return(malloc(len));
	ft_bzero(&b, sizeof(t_block));
	b.nums = b.buf;
	b.fmts = fmt;
	if(mkblc(&b, ap))
		return (NULL);
	s = block(b.fmts + b.fmtl, len + blclen(&b), ap);
	if (s)
		mkput(s + len, &b);
	return (s);
}

int	mkblc(t_block	*b, va_list	ap)
{
	if (each_len(b))/* .fmtsを進めとけ */ /* .fmtlを作れ */
		return (1);
	if (b->type == 'c')
		b->fmts[0] = va_arg(ap, int);
	else if (b->type == 's')
		b->fmts = va_arg(ap, char *);
	else if (b->type == 'p')
		itosx(b->fmts, (unsigned long int)va_arg(ap, void *));
	else if (b->type == 'x' || b->type == 'X')
		itosx(b->fmts, va_arg(ap, unsigned int));
	else if (b->type == 'd' || b->type == 'i')
		itosd(b->fmts, va_arg(ap, int), b->sing);
	else if (b->type == 'u')
		itosu(b->fmts, va_arg(ap, unsigned int));
	else if (b->type == '%')
		b->fmts[0] = '%';
	adjust(b);
	if (b->direct == ZERO_right)
	{
		b->zero += b->spase;
		b->spase = 0;
	}
	return (0);
}

void	adjust(t_block	*b)
{
	f_blc[CONTENTLEN] = ft_strlen(s_blc[CONTENTSTR]);
	if (f_blc[ZERO] < f_blc[CONTENTLEN])
	{
		if (f_blc[BLANK] + f_blc[ZERO] < f_blc[CONTENTLEN])
			f_blc[BLANK] = 0;
		else
			f_blc[BLANK] -= f_blc[CONTENTLEN] - f_blc[ZERO];
		f_blc[ZERO] = 0;
	}
	else
		f_blc[ZERO] -= f_blc[CONTENTLEN];
	if (f_blc[CONTENT] == Ep)
		f_blc[SING] = ZEROX_0x;
	if (f_blc[CONTENT] == EX)
		strupper(s_blc[CONTENTSTR]);
	if (f_blc[CONTENT] == EX && f_blc[SING] == ZEROX_0x)
		f_blc[SING] = _0X;
	if (f_blc[CONTENT] == Ex && !ft_memcmp(s_blc[CONTENTSTR], "0", 2))
		f_blc[SING] = DEFAULT_none;
	if (f_blc[CONTENT] == EX && !ft_memcmp(s_blc[CONTENTSTR], "0", 2))
		f_blc[SING] = DEFAULT_none;
	if (f_blc[CONTENT] == Eper)
		f_blc[SING] = DEFAULT_none;
	return ;
}

int	each_len(t_block	*b)/* .fmtsを進めとけ */ /* .fmtlを作れ */
{
	char	c;
	if (*(b->fmts) == '%')
	{
		b->fmts++;
		if (set_sing(b))
			return (1);
		if (set_len(b))
			return (1);
		if (set_type(b))
			return (1);
	}
	c = b->fmts[b->fmtl];
	while (c && c != '%')
	{
		b->fmtl++;
		c = b->fmts[b->fmtl];
	}
	return (0);
}
