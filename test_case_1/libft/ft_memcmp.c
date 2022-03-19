/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blyu <blyu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 10:00:14 by blyu              #+#    #+#             */
/*   Updated: 2021/11/11 10:34:40 by blyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && *((char *)s1 + i) == *((char *)s2 + i))
		i++;
	if (i == n)
		return (0);
	return (*((unsigned char *)s1 + i) - *((unsigned char *)s2 + i));
}
