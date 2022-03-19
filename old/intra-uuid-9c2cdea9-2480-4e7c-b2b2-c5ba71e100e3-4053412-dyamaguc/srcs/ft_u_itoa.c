/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u_itoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daisukeyamaguchi <daisukeyamaguchi@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 17:01:01 by daisukeyama       #+#    #+#             */
/*   Updated: 2022/03/16 23:28:30 by daisukeyama      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ft_length(unsigned int n)
{
	size_t	length;

	length = 0;
	while (n >= 1)
	{
		length++;
		n /= 10;
	}
	return (length);
}

static char	*ft_gen(unsigned int nbr, int len)
{
	char	*rtn;

	if (nbr != 0)
		rtn = malloc(sizeof(char) * (len + 1));
	else
		return (rtn = ft_strdup("0"));
	if (!rtn)
		return (0);
	rtn[len] = '\0';
	while (--len)
	{
		rtn[len] = (nbr % 10) + '0';
		nbr /= 10;
	}
	rtn[0] = (nbr % 10) + '0';
	return (rtn);
}

char	*ft_u_itoa(unsigned int n)
{
	int		len;
	char	*rtn;
	long	nbr;

	nbr = n;
	len = ft_length(nbr);
	rtn = ft_gen(nbr, len);
	if (!rtn)
		return (0);
	return (rtn);
}
