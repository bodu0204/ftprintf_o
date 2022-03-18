/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blyu <blyu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 17:48:41 by blyu              #+#    #+#             */
/*   Updated: 2022/03/18 12:26:41 by blyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mk_ft_printf_bonus.h"
#include "debug.h"/* test */

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

char	*block(const char	*fmt, size_t	len, va_list	ap)
{
	t_block	b;
	char	*s;

	if (!*fmt)
	{
		s = malloc(len + 1);
		s[len] = '\0';
		return (s);
	}
	ft_bzero(&b, sizeof(t_block));
	b.nums = b.buf;
	b.fmts = (char *)fmt;
	if (mkblc(&b, ap))
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
		b->nums[0] = va_arg(ap, int);
	else if (b->type == 's')
		b->nums = va_arg(ap, char *);
	else if (b->type == 'p')
		{/* test */
TEST
			itosx(b->nums, (unsigned long int)va_arg(ap, void *));
printf("type:%c, num:%s", b->type, b->nums); TEST
		}/* test */
	else if (b->type == 'x' || b->type == 'X')
		itosx(b->nums, va_arg(ap, unsigned int));
	else if (b->type == 'd' || b->type == 'i')
		itosd(b->nums, va_arg(ap, int), b->sing);
	else if (b->type == 'u')
		itosu(b->nums, va_arg(ap, unsigned int));
	else if (b->type == '%')
		b->nums[0] = '%';
printf("type:%c, num:%s", b->type, b->nums); TEST
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
	if (b->type == 's' && !(b->nums))
	{
		b->nums = b->buf;
		ft_strlcpy(b->nums, "(null)", BUFFER);
	}
	if (b->type == 'p')
		ft_strlcpy(b->sing, "0x", 3);
	if (b->type == 'X')
		strupper(2, b->nums, b->sing);
	if ((b->type == '%') \
	|| ((b->type == 'X' || b->type == 'x' ) && !ft_memcmp(b->nums, "0", 2)))
		ft_bzero(b->sing, 3);
	b->numl = ft_strlen(b->nums);
	b->singl = ft_strlen(b->sing);
	if (b->zero < b->numl + b->singl)
	{
		if (b->spase + b->zero < b->numl + b->singl)
			b->spase = 0;
		else
			b->spase -= b->numl + b->singl - b->zero;
		b->zero = 0;
	}
	else
		b->zero -= b->numl + b->singl;
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
