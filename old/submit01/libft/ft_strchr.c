/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blyu <blyu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 07:19:33 by blyu              #+#    #+#             */
/*   Updated: 2021/11/11 10:35:39 by blyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strchr(const char	*s, int	c)
{
	size_t	i;

	i = 0;
	while (*(unsigned char *)(s + i) != (unsigned char)c && *(s + i) != 0)
		i++;
	if (*(unsigned char *)(s + i) == (unsigned char)c)
		return ((char *)s + i);
	return (NULL);
}
