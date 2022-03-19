/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blyu <blyu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 07:20:02 by blyu              #+#    #+#             */
/*   Updated: 2021/11/04 07:20:03 by blyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strnstr(const char	*haystack, const char *needle, size_t	len)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (*(haystack + i) && i < len)
	{
		j = 0;
		while (*(haystack + i + j) == *(needle + j) \
		 && *(needle + j) && i + j < len)
			j++;
		if (!*(needle + j))
			return ((char *)haystack + i);
		i++;
	}
	if (!*needle)
		return ((char *)haystack);
	return (NULL);
}
