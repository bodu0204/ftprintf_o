/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoakira <ryoakira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 08:49:32 by blyu              #+#    #+#             */
/*   Updated: 2021/11/09 11:44:33 by ryoakira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include"libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*i;

	i = malloc(sizeof(t_list));
	if (i == 0)
		return (0);
	i->content = content;
	i->next = 0;
	return (i);
}
