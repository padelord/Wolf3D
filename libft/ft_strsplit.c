/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: padelord <padelord@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 23:30:52 by padelord          #+#    #+#             */
/*   Updated: 2018/11/18 23:51:38 by padelord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_countword(const char *s, char c)
{
	size_t	n;

	if (!s || !*s)
		return (0);
	n = 0;
	while (*s)
	{
		s++;
		if (*s == c && *(s - 1) != c)
			n++;
	}
	n += ((*(s - 1) != c) ? 1 : 0);
	return (n);
}

static char		*ft_worddup(const char *s, char end)
{
	size_t	i;
	char	*dest;

	i = 0;
	while (s[i] && s[i] != end)
		i++;
	if (!(dest = ft_strnew(i)))
		return (0);
	i = 0;
	while (s[i] && s[i] != end)
	{
		dest[i] = s[i];
		i++;
	}
	return (dest);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**tab;
	size_t	i;
	size_t	n_word;

	n_word = ft_countword(s, c);
	if (!(tab = (char **)ft_memalloc(sizeof(char *) * (n_word + 1))))
		return (0);
	tab[n_word] = 0;
	i = 0;
	while (i < n_word)
	{
		while (*s && *s == c)
			s++;
		if (!(tab[i] = ft_worddup(s, c)))
			return (tab);
		while (*s && *s != c)
			s++;
		i++;
	}
	return (tab);
}
