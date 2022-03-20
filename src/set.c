/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blyu <blyu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 17:48:52 by blyu              #+#    #+#             */
/*   Updated: 2022/03/20 17:42:09 by blyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mk_ft_printf.h"
void	read_sing(t_block	*b, int	*i);

int	set_sing(t_block	*b)
{
	int	i[5];

	ft_bzero(i, sizeof(i));
	read_sing(b, i);
	if (i[0] * i[1])
		return (1);
	if (i[2] * i[3] || i[3] * i[4] || i[4] * i[2])
		return (1);
	if (i[0])
		b->direct = _left;
	else if (i[1])
		b->direct = ZERO_right;
	else
		b->direct = DEFAULT_right;
	if (i[2])
		ft_strlcpy(b->sing, "0x", 3);
	else if (i[3])
		ft_strlcpy(b->sing, "+", 3);
	else if (i[4])
		ft_strlcpy(b->sing, " ", 3);
	else
		ft_bzero(b->sing, 3);
	return (0);
}

int	set_len(t_block	*b)
{
	b->spase = ft_atoi(b->fmts);
	while (ft_isdigit(*(b->fmts)))
		b->fmts++;
	b->dot = DEFAULT_no_dot;
	if (*(b->fmts) == '.')
	{
		b->dot = _yes_dot;
		b->fmts++;
	}
	b->zero = ft_atoi(b->fmts);
	while (ft_isdigit(*(b->fmts)))
		b->fmts++;
	if (b->dot == _yes_dot && *(b->fmts) == 'c')
		return (1);
	if (*(b->fmts) != '%')
	{
		if (b->spase < b->zero)
			b->spase = 0;
		else
			b->spase -= b->zero;
	}
	else
		b->zero = 0;
	return (0);
}

int	set_type(t_block	*b)
{
	b->type = *(b->fmts);
	if ((b->type == 'c' && !*(b->sing) && b->direct != ZERO_right) \
	|| (b->type == 's' && !*(b->sing) && b->direct != ZERO_right) \
	|| (b->type == 'p' && !*(b->sing)) \
	|| (b->type == 'd' && ft_strncmp("0x", b->sing, 3)) \
	|| (b->type == 'i' && ft_strncmp("0x", b->sing, 3)) \
	|| (b->type == 'u' && !*(b->sing)) \
	|| (b->type == 'x' && (!*(b->sing) || !ft_strncmp("0x", b->sing, 3))) \
	|| (b->type == 'X' && (!*(b->sing) || !ft_strncmp("0x", b->sing, 3))) \
	|| (b->type == '%'))
		b->fmts++;
	else
		return (1);
	return (0);
}

void	read_sing(t_block	*b, int	*i)
{
	while (1)
	{
		if (*(b->fmts) == '-')
			i[0] = 1;
		else if (*(b->fmts) == '0')
			i[1] = 1;
		else if (*(b->fmts) == '#')
			i[2] = 1;
		else if (*(b->fmts) == '+')
			i[3] = 1;
		else if (*(b->fmts) == ' ')
			i[4] = 1;
		else
			break ;
		b->fmts++;
	}
	return ;
}
