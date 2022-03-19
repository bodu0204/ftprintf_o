/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blyu <blyu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 07:11:32 by blyu              #+#    #+#             */
/*   Updated: 2021/11/11 11:14:05 by blyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stddef.h>

void	ft_putendl_fd(char	*s, int	fd)
{
	size_t	i;

	if (!s)
		return ;
	i = 0;
	while (*(s + i))
		i++;
	write(fd, s, i * sizeof(char));
	write(fd, "\n", sizeof(char));
}
