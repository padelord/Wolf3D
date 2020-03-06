/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenaudi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 14:41:13 by crenaudi          #+#    #+#             */
/*   Updated: 2018/11/23 20:44:58 by crenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static int	ft_len(char const *s, int i, int len)
{
	while (s[i] != '\0')
	{
		i++;
		len++;
	}
	i--;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
	{
		i--;
		len--;
	}
	return (len);
}

char		*ft_strtrim(char const *s)
{
	char	*copy;
	int		start;
	int		len;
	int		i;

	i = 0;
	start = 0;
	len = 0;
	if (!s)
		return (0);
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
	{
		i++;
		if (s[i] == '\0')
			return (ft_strdup(""));
		start++;
	}
	copy = ft_strsub(s, start, ft_len(s, i, len));
	return (copy);
}
