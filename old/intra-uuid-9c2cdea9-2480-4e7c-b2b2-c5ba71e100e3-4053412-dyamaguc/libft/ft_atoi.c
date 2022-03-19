/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daisukeyamaguchi <daisukeyamaguchi@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 14:09:41 by daisukeyama       #+#    #+#             */
/*   Updated: 2022/02/17 01:11:08 by daisukeyama      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	size_t	i;
	int		pn;
	int		r;

	if (!str)
		return (0);
	i = 0;
	pn = 0;
	while (str[i] != '\0' && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
			|| str[i] == '\r' || str[i] == '\v' || str[i] == '\f'))
		i++;
	if (str[i] != '\0' && str[i] == '-')
	{
		pn = 1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	r = 0;
	while (str[i] != '\0' && ft_isdigit(str[i]))
		r = (r * 10) + (str[i++] - '0');
	if (pn == 1)
		return (-r);
	return (r);
}
