/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blyu <blyu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 17:48:35 by blyu              #+#    #+#             */
/*   Updated: 2022/03/16 17:48:36 by blyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mk_ft_printf.h"

void	strupper(char	*s)
{
	while (*s)
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
	ft_memcpy(buf, b->sing, ft_strlen(b->sing));
	buf += ft_strlen(b->sing);
	buf += charset(buf, '0', b->zero);
	ft_memcpy(buf, b->nums, b->numl);
	buf += b->numl;
	if (b->direct == _left)
		buf += charset(buf, ' ', b->spase);
	ft_memcpy(buf, b->fmts, b->fmtl);
	return ;
}
