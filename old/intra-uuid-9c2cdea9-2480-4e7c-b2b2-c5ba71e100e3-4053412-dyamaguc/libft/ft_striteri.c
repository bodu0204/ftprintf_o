/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daisukeyamaguchi <daisukeyamaguchi@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 00:49:28 by daisukeyama       #+#    #+#             */
/*   Updated: 2021/12/10 16:51:27 by daisukeyama      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (s && f)
	{
		i = ft_strlen(s);
		while (j < i)
		{
			(*f)(j, &s[j]);
			j++;
		}
	}
}
