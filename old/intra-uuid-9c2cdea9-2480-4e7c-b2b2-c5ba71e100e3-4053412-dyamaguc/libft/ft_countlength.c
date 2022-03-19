/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_length.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daisukeyamaguchi <daisukeyamaguchi@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 01:21:44 by daisukeyama       #+#    #+#             */
/*   Updated: 2022/02/17 01:29:32 by daisukeyama      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_countlength(long n)
{
	size_t	length;
	int		isneg;

	length = 0;
	isneg = 0;
	if (n < 0)
	{
		length++;
		isneg++;
		n = -n;
	}
	while (n >= 1)
	{
		length++;
		n /= 10;
	}
	return (length);
}
