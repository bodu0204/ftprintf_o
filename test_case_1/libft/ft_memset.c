/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoakira <ryoakira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 07:19:28 by blyu              #+#    #+#             */
/*   Updated: 2021/11/10 19:00:10 by ryoakira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memset(void	*buf, int	ch, size_t	n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		*(unsigned char *)(buf + i) = (unsigned char)ch;
		i++;
	}
	return (buf);
}
