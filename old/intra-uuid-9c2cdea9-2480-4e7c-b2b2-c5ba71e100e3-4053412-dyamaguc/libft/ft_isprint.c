/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daisukeyamaguchi <daisukeyamaguchi@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 15:46:52 by daisukeyama       #+#    #+#             */
/*   Updated: 2021/12/09 21:10:51 by daisukeyama      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int	c)
{	
	return ((32 <= c) && (c <= 126));
}