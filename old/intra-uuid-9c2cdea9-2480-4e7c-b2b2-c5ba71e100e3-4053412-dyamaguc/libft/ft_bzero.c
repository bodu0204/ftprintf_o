/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daisukeyamaguchi <daisukeyamaguchi@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 19:42:44 by daisukeyama       #+#    #+#             */
/*   Updated: 2021/11/03 00:50:11 by daisukeyama      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void	*s, size_t	n)
{
	size_t				i;
	unsigned char		*z;

	i = 0;
	z = (unsigned char *)s;
	while (i < n)
	{
		z[i] = 0;
		i++;
	}
	s = z;
}
