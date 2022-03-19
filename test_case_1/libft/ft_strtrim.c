/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blyu <blyu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 11:26:02 by blyu              #+#    #+#             */
/*   Updated: 2021/11/07 19:32:40 by blyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
int		check(char c, char const	*set);
void	trimcpy(char *s, char const *t, size_t start, size_t end);

char	*ft_strtrim(char const	*s1, char const	*set)
{
	size_t	i;
	size_t	start;
	char	*s;

	if (!s1)
		return (0);
	i = 0;
	while (*(s1 + i) && check (*(s1 + i), set))
		i++;
	start = i;
	while (*(s1 + i))
		i++;
	if (i)
		i--;
	while (i && check (*(s1 + i), set))
		i--;
	if (i < start)
		s = (char *)malloc(1);
	else
		s = (char *)malloc(i + 2 - start);
	if (s)
		trimcpy(s, s1, start, i);
	return (s);
}

int	check(char c, char const	*set)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (set && *(set + i))
	{
		j *= c != *(set + i);
		i++;
	}
	return (!j);
}

void	trimcpy(char *s, char const *t, size_t start, size_t end)
{
	size_t	i;

	i = 0;
	while (start + i <= end)
	{
		*(s + i) = *(t + start + i);
		i++;
	}
	*(s + i) = 0;
	return ;
}
