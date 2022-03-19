/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daisukeyamaguchi <daisukeyamaguchi@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 22:24:49 by daisukeyama       #+#    #+#             */
/*   Updated: 2021/12/10 16:38:55 by daisukeyama      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void	*buf, int	ch, size_t	n)
{
	size_t			i;

	if (!buf)
		return (NULL);
	i = 0;
	while (i < n)
	{
		*(unsigned char *)(buf + i) = (unsigned char)ch;
		i++;
	}
	return (buf);
}
