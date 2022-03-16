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
	{
		s = malloc(len + 1);
		s[len] = '\0';
		return (s);
	}
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
	if (each_len(b))
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
	b->numl = ft_strlen(b->nums);
	if (b->zero < b->numl)
	{
		if (b->spase + b->zero < b->numl)
			b->spase = 0;
		else
			b->spase -= b->numl - b->zero;
		b->zero = 0;
	}
	else
		b->zero -= b->numl;
	if (b->type == 'p')
		ft_strlcpy(b->sing, "0x", 3);
	if (b->type == 'X')
		strupper(b->nums);
	if (b->type == 'X' && !ft_memcmp(b->sing, "0x", 3))
		ft_strlcpy(b->sing, "0X", 3);
	if (b->type == 'x' && !ft_memcmp(b->nums, "0", 2))
		ft_bzero(b->sing, 3);
	if (b->type == 'X' && !ft_memcmp(b->nums, "0", 2))
		ft_bzero(b->sing, 3);
	if (b->type == '%')
		ft_bzero(b->sing, 3);
	return ;
}

int	each_len(t_block	*b)
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
