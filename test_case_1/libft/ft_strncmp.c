/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blyu <blyu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 07:19:56 by blyu              #+#    #+#             */
/*   Updated: 2021/11/04 07:19:57 by blyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_strncmp(const char	*s1, const char	*s2, size_t	n)
{
	size_t	i;
	int		m;

	i = 0;
	m = 0;
	if (n > 0)
		m = (unsigned char)*s1 - (unsigned char)*s2;
	while (!m && *(s1 + i) && *(s2 + i))
	{
		i++;
		if (i >= n)
			break ;
		m = (unsigned char)*(s1 + i) - (unsigned char)*(s2 + i);
	}
	return (m);
}
