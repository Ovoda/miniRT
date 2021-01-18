/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <calide-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 17:13:32 by calide-n          #+#    #+#             */
/*   Updated: 2020/11/18 12:43:42 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_strdup_to_char(char const *str, char c)
{
	int		i;
	char	*dest;

	i = 0;
	while (str[i] != c && str[i])
		i++;
	if (!(dest = (char *)malloc(sizeof(char) * (i + 1))))
		return (0);
	i = 0;
	while (str[i] && str[i] != c)
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

static int		ft_get_word_nb(char const *s, char c)
{
	size_t i;
	size_t nb;

	i = 0;
	nb = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
		{
			nb++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (nb);
}

char			**ft_split(char const *s, char c)
{
	size_t	nb_of_words;
	char	**tab;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!s)
		return (0);
	nb_of_words = ft_get_word_nb(s, c);
	if (!(tab = (char **)malloc(sizeof(char *) * (nb_of_words + 1))))
		return (0);
	while (j < nb_of_words)
	{
		while (s[i] && s[i] == c)
			i++;
		tab[j++] = ft_strdup_to_char(s + i, c);
		while (s[i] && s[i] != c)
			i++;
	}
	tab[j] = 0;
	return (tab);
}
