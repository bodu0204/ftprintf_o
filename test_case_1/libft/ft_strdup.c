/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blyu <blyu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 07:19:38 by blyu              #+#    #+#             */
/*   Updated: 2021/11/11 10:35:25 by blyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>

char	*ft_strdup(const char	*s1)
{
	size_t	i;
	char	*s2;

	i = 0;
	while (*(s1 + i))
		i++;
	s2 = malloc(i + 1);
	if (s2 == NULL)
		return (NULL);
	i = 0;
	while (*(s1 + i))
	{
		*(s2 + i) = *(s1 + i);
		i++;
	}
	*(s2 + i) = 0;
	return (s2);
}
