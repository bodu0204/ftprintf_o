/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blyu <blyu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 07:18:08 by blyu              #+#    #+#             */
/*   Updated: 2021/11/04 07:18:15 by blyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
int			set(const char	*str, int	*j);
long int	ten_times(long	n);

int	ft_atoi(const char	*str)
{
	int			i;
	long int	n;
	int			j;

	i = set(str, &j);
	n = 0;
	while (*(str + i) >= '0' && *(str + i) <= '9')
	{
		n = ten_times(n);
		n += *(str + i) - '0';
		i++;
		if (n < 0 && j == 1)
			return (-1);
		if (n < 0 && j == -1)
		{
			return (0);
		}
	}
	return (n * j);
}

int	set(const char	*str, int	*j)
{
	int	i;

	i = 0;
	*j = 1;
	while ((*(str + i) >= 9 && *(str + i) <= 13) || *(str + i) == 32)
		i++;
	if (*(str + i) == '-' || *(str + i) == '+' )
	{
		if (*(str + i) == '-')
			*j = -1;
		i++;
	}
	return (i);
}

long int	ten_times(long n)
{
	int		i;
	long	m;

	i = 0;
	m = 0;
	while (i < 10)
	{
		m += n;
		if (m < 0)
			return (-10);
		i++;
	}
	return (m);
}
