/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blyu <blyu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 10:54:41 by blyu              #+#    #+#             */
/*   Updated: 2021/11/09 17:16:32 by blyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
char	*nothing(void);

char	*ft_substr(char const	*s, unsigned int	start, size_t	len)
{
	char	*c;
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (*(s + i))
		i++;
	if (start >= i)
		return (nothing());
	if (i - start < len)
		len = i - start;
	c = malloc(len + 1);
	if (c == NULL)
		return (NULL);
	i = 0;
	while (i < len && *(s + start + i))
	{
		*(c + i) = *(s + start + i);
		i++;
	}
	*(c + i) = 0;
	return (c);
}

char	*nothing(void)
{
	char	*c;

	c = malloc (1);
	if (c == NULL)
		return (NULL);
	*c = 0;
	return (c);
}
