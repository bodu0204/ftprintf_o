/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daisukeyamaguchi <daisukeyamaguchi@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 17:54:09 by daisukeyama       #+#    #+#             */
/*   Updated: 2021/12/12 16:39:10 by daisukeyama      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*str;
	char	cc;
	size_t	i;

	str = (char *)s;
	cc = (char)c;
	i = 0;
	while (s[i])
		i++;
	while (i > 0)
	{
		if (str[i] == cc)
			return (str + i);
		i--;
	}
	if (str[i] == cc)
		return (str);
	return (NULL);
}
