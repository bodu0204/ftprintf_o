/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blyu <blyu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 17:48:55 by blyu              #+#    #+#             */
/*   Updated: 2022/03/19 15:59:20 by blyu             ###   ########.fr       */
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
//	if (!(b->type == 'c' && !*(b->nums)))
		len += b->numl;
	len += b->fmtl;
	return (len);
}

size_t	mkput(char	*buf, t_block	*b)
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
//	if (!(b->type == 'c' && !*(b->nums)))
//	{
		ft_memcpy(buf, b->nums, b->numl);
		buf += b->numl;
//	}
	if (b->direct == _left)
	{
		ft_memset(buf, ' ', b->spase);
		buf += b->spase;
	}
	ft_memcpy(buf, b->fmts, b->fmtl);
//	if (b->type == 'c' && !*(b->nums))
//		return (1);
	return (0);
}
