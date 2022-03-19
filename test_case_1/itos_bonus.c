/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itos_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blyu <blyu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 17:48:44 by blyu              #+#    #+#             */
/*   Updated: 2022/03/18 12:53:50 by blyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mk_ft_printf_bonus.h"

void	itosx(char	*str, unsigned long int	n)
{
	char				*num;
	unsigned long int	nn;
	int					i;

	if (n == 0)
	{
		*str = '0';
		return ;
	}
	num = "0123456789abcdef";
	nn = 1;
	while (n / nn >= 16)
		nn *= 16;
	while (nn > 0)
	{
		i = n / nn;
		*str = num[i];
		str++;
		n -= i * nn;
		nn /= 16;
	}
	return ;
}

void	itosu(char	*str, unsigned int	n)
{
	char			*num;
	unsigned int	nn;
	int				i;

	if (n == 0)
	{
		*str = '0';
		return ;
	}
	num = "0123456789";
	nn = 1;
	while (n / nn >= 10)
		nn *= 10;
	while (nn > 0)
	{
		i = n / nn;
		*str = *(num + i);
		str++;
		n -= i * nn;
		nn /= 10;
	}
	return ;
}

void	itosd(char	*str, int	n, char	*sig)
{
	int	nn;

	if (n == 0)
	{
		*str = '0';
		return ;
	}
	if (n < 0)
		ft_strlcpy(sig, "-", 2);
	else
		n *= -1;
	nn = 1;
	while (n / nn <= -10)
		nn *= 10;
	while (nn > 0)
	{
		*str = '0' - (n / nn);
		n += (*str - '0') * nn;
		str++;
		nn /= 10;
	}
	return ;
}
