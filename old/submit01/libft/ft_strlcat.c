/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blyu <blyu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 07:19:42 by blyu              #+#    #+#             */
/*   Updated: 2021/11/04 07:19:43 by blyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	ft_strlcat(char	*dst, const char	*src, size_t	dstsize)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (*(dst + i) && i < dstsize)
		i++;
	while (*(src + j) && i + j + 1 < dstsize)
	{
		*(dst + i + j) = *(src + j);
		j++;
	}
	if (i < dstsize)
		*(dst + i + j) = 0;
	while (*(src + j))
		j++;
	return (i + j);
}
