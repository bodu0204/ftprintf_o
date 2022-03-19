/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blyu <blyu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 12:11:57 by blyu              #+#    #+#             */
/*   Updated: 2021/11/09 17:15:38 by blyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
void	mk_number(char	*m, int	*n, int	*i);

char	*ft_itoa(int	n)
{
	char	m[12];
	int		i;
	char	*a;

	mk_number(m, &n, &i);
	a = malloc(i + 1);
	if (a == NULL)
		return (NULL);
	i = 0;
	while (m[i])
	{
		*(a + i) = m[i];
		i++;
	}
	*(a + i) = 0;
	return (a);
}

void	mk_number(char	*m, int	*n, int	*i)
{
	int	s;

	*i = 1;
	m[0] = '-';
	if (*n >= 0)
	{
		*n *= -1;
		(*i)--;
	}
	s = 1;
	while (((*n) / s) <= -10)
		s *= 10;
	while (s > 0)
	{
		m[*i] = '0' - (*n / s);
		*n += (m[*i] - '0') * s;
		s /= 10;
		(*i)++;
	}
	m[*i] = 0;
}
