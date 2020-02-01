/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: padelord <padelord@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 23:31:11 by padelord          #+#    #+#             */
/*   Updated: 2018/12/03 00:43:59 by padelord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*dest;
	size_t	size;
	size_t	i;

	if (!s)
		return (0);
	size = ft_strlen(s);
	if (start >= size || size < len)
		return (0);
	if (!(dest = ft_strnew(ft_min(size - start, len))))
		return (0);
	i = 0;
	while (s[start + i] && i < len)
	{
		dest[i] = s[start + i];
		i++;
	}
	return (dest);
}
