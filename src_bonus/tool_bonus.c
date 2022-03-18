/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoakira <ryoakira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 17:48:55 by blyu              #+#    #+#             */
/*   Updated: 2022/03/18 09:33:03 by ryoakira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mk_ft_printf_bonus.h"

void	strupper(int	i, ...)
{
	va_list	ap;
	char	*s;

	va_start(ap, i);
	while (i)
	{
		s = va_arg(ap, char	*);
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
	if (b->direct != _left)
	{
		ft_memset(buf, ' ', b->spase);
		buf += b->spase;
	}
	ft_memcpy(buf, b->sing, b->singl);
	buf += b->singl;
	ft_memset(buf, '0', b->zero);
	buf += b->zero;
	ft_memcpy(buf, b->nums, b->numl);
	buf += b->numl;
	if (b->direct == _left)
	{
		ft_memset(buf, ' ', b->spase);
		buf += b->spase;
	}
	ft_memcpy(buf, b->fmts, b->fmtl);
	return ;
}
