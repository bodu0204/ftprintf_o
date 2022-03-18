/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoakira <ryoakira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 17:48:55 by blyu              #+#    #+#             */
/*   Updated: 2022/03/18 22:50:34 by ryoakira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mk_ft_printf_bonus.h"
#include "debug.h"/* test */

void	strupper(int	i, ...)
{
	va_list	ap;
	char	*s;

	va_start(ap, i);
	while (i)
	{
		s = va_arg(ap, char *);
		while (*s)
		{
			*s = ft_toupper(*s);
			s++;
		}
		i--;
	}
	va_end(ap);
	return ;
}

size_t	blclen(t_block	*b)
{
	size_t	len;

	len = b->spase;
	len += b->singl;
	len += b->zero;
	len += b->numl;
	len += b->fmtl;
	return (len);
}

void	mkput(char	*buf, t_block	*b)
{
write(1, "[", 1);/* test */
	if (b->direct != _left)
	{
for (size_t i = 0; i < b->spase; i++) write(1, " ", 1);/* test */
		ft_memset(buf, ' ', b->spase);
		buf += b->spase;
	}
write(1, b->sing, b->singl);/* test */
	ft_memcpy(buf, b->sing, b->singl);
	buf += b->singl;
for (size_t i = 0; i < b->zero; i++) write(1, "0", 1);/* test */
	ft_memset(buf, '0', b->zero);
	buf += b->zero;
write(1, b->nums, b->numl);/* test */
	ft_memcpy(buf, b->nums, b->numl);
	buf += b->numl;
	if (b->direct == _left)
	{
for (size_t i = 0; i < b->spase; i++) write(1, " ", 1);/* test */
		ft_memset(buf, ' ', b->spase);
		buf += b->spase;
	}
write(1, b->fmts, b->fmtl);/* test */
	ft_memcpy(buf, b->fmts, b->fmtl);
write(1, "]", 1);/* test */
	return ;
}
