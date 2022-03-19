/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blyu <blyu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 06:41:57 by blyu              #+#    #+#             */
/*   Updated: 2021/11/09 15:43:32 by blyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stddef.h>

char	*ft_strmapi(char const	*s, char	(*f)(unsigned int, char))
{
	size_t	i;
	char	*c;

	if (!s || !f)
		return (0);
	i = 0;
	while (*(s + i))
		i++;
	c = malloc(i + 1);
	if (!c)
		return (0);
	i = 0;
	while (*(s + i))
	{
		*(c + i) = f(i, *(s + i));
		i++;
	}
	*(c + i) = 0;
	return (c);
}
