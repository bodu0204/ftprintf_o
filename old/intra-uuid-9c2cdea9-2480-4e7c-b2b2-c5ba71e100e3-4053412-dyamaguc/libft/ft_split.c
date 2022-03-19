/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daisukeyamaguchi <daisukeyamaguchi@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 14:07:07 by daisukeyama       #+#    #+#             */
/*   Updated: 2021/12/10 00:23:46 by daisukeyama      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_counter(const char *s, char c)
{
	size_t	i;
	size_t	nbr;
	int		flag;

	i = 0;
	nbr = 0;
	flag = 0;
	while (s[i])
	{
		if (s[i] != c && flag == 0)
		{
			nbr++;
			flag = 1;
		}
		else if (s[i] == c)
			flag = 0;
		i++;
	}
	return (nbr);
}

static size_t	ft_next_word_count(char const *str, char sep, int i)
{
	size_t	count;

	count = 0;
	while (str[i] == sep && str[i] != '\0')
	{
		i++;
	}
	while (str[i] != '\0' && str[i] != sep)
	{
		count++;
		i++;
	}
	return (count);
}

static char	**ft_free(char **str_tab, size_t i)
{
	size_t	j;

	j = 0;
	while (j < i && str_tab[j] != 0)
	{
		free(str_tab[j]);
		j++;
	}
	free(str_tab);
	return (0);
}

char	**ft_spliter(char const *s, char c)
{
	size_t		n;
	size_t		i;
	size_t		j;
	char		**tab_str;

	n = 0;
	i = -1;
	tab_str = malloc(sizeof(*tab_str) * (ft_counter(s, c) + 1));
	if (tab_str == 0)
		return (0);
	while (++i < ft_counter(s, c))
	{
		j = 0;
		tab_str[i] = malloc(ft_next_word_count(s, c, n) + 1);
		if (!tab_str[i])
			return (ft_free(tab_str, i));
		while (s[n] != '\0' && s[n] == c)
			n++;
		while (s[n] != '\0' && s[n] != c)
			tab_str[i][j++] = s[n++];
		tab_str[i][j] = '\0';
	}
	tab_str[i] = 0;
	return (tab_str);
}

char	**ft_split(char const *s, char c)
{
	if (s == 0)
		return (0);
	return (ft_spliter(s, c));
}
