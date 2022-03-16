#include "ft_printf_bonus.h"

void	strupper(char	*s)
{
	while(*s)
	{
		*s = ft_toupper(*s);
		s++;
	}
	return ;
}

size_t	blclen(t_block	*b)
{
	size_t	len;

	len = b->spase;
	len += ft_strlen(b->sing);
	len += b->zero;
	len += b->numl;
	len += b->fmtl;
	return (len);
}

size_t	charset(char	*buf, char	c, size_t	l)
{
	size_t	i;

	i = 0;
	while (i < l)
	{
		buf[i] = c;
		i++;
	}
	return (i);
}

void	mkput(char	*buf, t_block	*b)
{
	size_t	i;

	i = 0;
	if (b->direct != _left)
		buf += charset(buf, ' ', b->spase);
	buf += ft_strlcpy(buf, b->sing, 3);
	buf += charset(buf, '0', b->zero);
	buf += ft_strlcpy(buf, b->nums, b->numl);
	if (b->direct == _left)
		buf += charset(buf, ' ', b->spase);
	ft_memcpy(buf, b->fmts, b->fmtl);
	return ;
}
