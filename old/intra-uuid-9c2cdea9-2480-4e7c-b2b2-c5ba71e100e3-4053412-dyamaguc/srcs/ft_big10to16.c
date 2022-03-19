/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_big10to16.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daisukeyamaguchi <daisukeyamaguchi@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 18:39:50 by daisukeyama       #+#    #+#             */
/*   Updated: 2022/03/16 23:28:04 by daisukeyama      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_big10to16(unsigned int n)
{
	int		i;
	int		j;
	char	*change;
	char	result[10];

	i = 0;
	j = 0;
	change = "0123456789ABCDEF";
	if (n == 0)
		return (write(1, "0", 1));
	while (n > 0)
	{
		j = n % 16;
		n = n / 16;
		result[i] = change[j];
		i++;
	}
	j = i - 1;
	while (j >= 0)
		write(1, &result[j--], 1);
	return (i);
}
