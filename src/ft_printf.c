/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoakira <ryoakira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 17:48:41 by blyu              #+#    #+#             */
/*   Updated: 2022/03/21 16:24:47 by ryoakira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mk_ft_printf.h"

int	ft_printf(const char	*fmt, ...)
{
	va_list	ap;
	int		rtn;
	t_rtn	r;

	if (!fmt)
		return (-1);
	if (!*fmt)
		return (0);
	rtn = -1;
	va_start(ap, fmt);
	r = block(fmt, 0, ap);
	va_end(ap);
	if (r.prt)
	{
		rtn = write(1, r.prt, r.prtl);
		free(r.prt);
		if (rtn >= 0)
			rtn = r.prtl;
	}
	return (rtn);
}

t_rtn	block(const char	*fmt, size_t	len, va_list	ap)
{
	t_block	b;
	t_rtn	r;

	ft_bzero(&r, sizeof(t_rtn));
	if (!*fmt)
	{
		r.prt = ft_calloc(1, len + 1);
		if (r.prt)
			r.prt[len] = '\0';
		r.prtl = len;
		return (r);
	}
	ft_bzero(&b, sizeof(t_block));
	b.nums = b.buf;
	b.fmts = (char *)fmt;
	if (mkblc(&b, ap))
		return (r);
	r = block(b.fmts + b.fmtl, len + blclen(&b), ap);
	if (r.prt)
		mkput(r.prt + len, &b);
	return (r);
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
		itosx(b->nums, (unsigned long int)va_arg(ap, void *));
	else if (b->type == 'x' || b->type == 'X')
		itosx(b->nums, va_arg(ap, unsigned int));
	else if (b->type == 'd' || b->type == 'i')
		itosd(b->nums, va_arg(ap, int), b->sing);
	else if (b->type == 'u')
		itosu(b->nums, va_arg(ap, unsigned int));
	else if (b->type == '%')
		b->nums[0] = '%';
	adjust(b);
	return (0);
}

int	each_len(t_block	*b)
{
	char	c;

	if (*(b->fmts) == '%')
	{
		b->fmts++;
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
