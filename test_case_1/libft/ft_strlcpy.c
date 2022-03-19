/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoakira <ryoakira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 07:19:48 by blyu              #+#    #+#             */
/*   Updated: 2021/11/15 09:35:03 by ryoakira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	ft_strlcpy(char	*dst, const char	*src, size_t	dstsize)
{
	size_t	i;

	i = 0;
	while (i + 1 < dstsize && *(src + i))
	{
		*(dst + i) = *(src + i);
		i++;
	}
	if (i < dstsize)
		*(dst + i) = 0;
	while (*(src + i))
		i++;
	return (i);
}
