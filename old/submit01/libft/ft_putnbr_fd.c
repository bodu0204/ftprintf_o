/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blyu <blyu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 08:44:30 by blyu              #+#    #+#             */
/*   Updated: 2021/11/09 17:45:49 by blyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr_fd(int	n, int	fd)
{
	int		s;
	int		i;
	char	m[13];

	i = 1;
	m[0] = '-';
	if (n >= 0)
	{
		n *= -1;
		(i)--;
	}
	s = 1;
	while (((n) / s) <= -10)
		s *= 10;
	while (s > 0)
	{
		m[i] = '0' - (n / s);
		n += (m[i] - '0') * s;
		s /= 10;
		(i)++;
	}
	m[i] = 0;
	write(fd, m, i * sizeof(char));
}
/*
void	ft_putnbr_fd(int	n, int	fd)
{
	long int	ln;
	int			i;
	char		c;

	ln = n;
	if (ln < 0)
	{
		ln *= -1;
		write(fd, "-", 1);
	}
	i = 1;
	while (ln / i >= 10)
		i *= 10;
	while (i)
	{
		c = ln / i + '0';
		ln -= (c - '0') * i;
		write(fd, &c, 1);
		i /= 10;
	}
	write(fd, "\n", 1);
}
 */
