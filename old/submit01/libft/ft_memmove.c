/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blyu <blyu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 07:19:22 by blyu              #+#    #+#             */
/*   Updated: 2021/11/06 09:29:05 by blyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memmove(void	*dest, const void	*src, size_t	n)
{
	size_t	i;
	int		j;

	if (!dest && !src)
		return (0);
	j = 0;
	i = 0;
	while (i < n)
	{
		j += (char *)dest == (char *)(src + i);
		i++;
	}
	if (!j)
		i = 0;
	while ((i < n && !j) || (i > 0 && j))
	{
		*(char *)(dest + i - j) = *(char *)(src + i - j);
		if (j)
			i--;
		else
			i++;
	}
	if (j)
		*(char *)(dest + i) = *(char *)(src + i);
	return (dest);
}
