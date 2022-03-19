/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blyu <blyu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 13:21:36 by ryoakira          #+#    #+#             */
/*   Updated: 2021/11/09 15:42:45 by blyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
void	next_comand(char const *s, char c, char ***p, size_t *info);
void	split_turn(char const *s, char c, char **p, size_t *info);
void	contents_turn(char const *s, char c, char **p, size_t *info);
void	allfree(char **p, size_t exit);
enum
{
	COMAND,
	STR_No,
	UNIT_No,
	LIST_No,
	EXIT,
};
enum
{
	MAKE_BASE,
	MAKE_LINE,
	CPY_CONTENT,
};

char	**ft_split(char const *s, char c)
{
	size_t	info[8];
	char	**p;

	if (!s)
		return (0);
	info[COMAND] = 0;
	info[EXIT] = 0;
	while (!info[EXIT] && info[COMAND] < 3)
	{
		info[STR_No] = 0;
		while (*(s + info[STR_No]) &&*(s + info[STR_No]) == c)
			info[STR_No]++;
		info[LIST_No] = 0;
		while (!info[EXIT] && *(s + info[STR_No]))
		{
			contents_turn(s, c, p, info);
			split_turn(s, c, p, info);
		}
		next_comand(s, c, &p, info);
	}
	allfree(p, info[EXIT]);
	return (p);
}

void	next_comand(char const *s, char c, char ***p, size_t *info)
{
	size_t	i;

	(void)c;
	(void)s;
	if (info[COMAND] == MAKE_BASE)
	{
		*p = malloc((info[LIST_No] + 1) * sizeof(char *));
		if (*p)
		{
			i = 0;
			while (i < info[LIST_No] + 1)
			{
				*(*p + i) = 0;
				i++;
			}
		}
		else
			info[EXIT] = 1;
	}
	info[COMAND]++;
}

void	split_turn(char const *s, char c, char **p, size_t *info)
{
	if (info[COMAND] == MAKE_LINE)
	{
		*(p + info[LIST_No]) = malloc(info[UNIT_No] + 1);
		if (!*(p + info[LIST_No]))
			info[EXIT] = 1;
	}
	info[LIST_No]++;
	info[UNIT_No] = 0;
	while (!info[EXIT] && *(s + info[STR_No]) && *(s + info[STR_No]) == c)
		info[STR_No]++;
	return ;
}

void	contents_turn(char const *s, char c, char **p, size_t *info)
{
	while (*(s + info[STR_No]) && *(s + info[STR_No]) != c)
	{
		if (info[COMAND] == CPY_CONTENT)
			*(*(p + info[LIST_No]) + info[UNIT_No]) = *(s + info[STR_No]);
		info[STR_No]++;
		info[UNIT_No]++;
	}
	if (info[COMAND] == CPY_CONTENT)
		*(*(p + info[LIST_No]) + info[UNIT_No]) = 0;
	return ;
}

void	allfree(char **p, size_t exit)
{
	size_t	i;

	i = 0;
	if (exit)
	{
		if (!p)
			return ;
		while (*(p + i))
		{
			free(*(p + i));
			i++;
		}
		free(p);
	}
	return ;
}
