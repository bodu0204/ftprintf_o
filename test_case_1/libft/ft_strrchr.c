/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blyu <blyu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 07:20:05 by blyu              #+#    #+#             */
/*   Updated: 2021/11/11 10:29:20 by blyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strrchr(const char	*s, int	c)
{
	size_t	i;

	i = 0;
	while (*(s + i) != 0)
		i++;
	while (*(unsigned char *)(s + i) != (unsigned char)c && i > 0)
		i--;
	if (*(unsigned char *)(s + i) == (unsigned char)c)
		return ((char *)s + i);
	return (NULL);
}
