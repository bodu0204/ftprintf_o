/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoakira <ryoakira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 07:18:29 by blyu              #+#    #+#             */
/*   Updated: 2021/11/08 13:48:53 by ryoakira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>

void	*ft_calloc(size_t count, size_t size)
{
	void	*s;
	size_t	i;
	size_t	max;

	max = count * size;
	if (count <= 0 || size <= 0)
		max = 1;
	s = malloc(max);
	if (s == NULL)
		return (NULL);
	i = 0;
	while (i < max)
	{
		*(unsigned char *)(s + i) = 0;
		i++;
	}
	return (s);
}
