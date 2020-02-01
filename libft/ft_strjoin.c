/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: padelord <padelord@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 21:32:12 by padelord          #+#    #+#             */
/*   Updated: 2018/12/06 19:24:55 by padelord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dest;
	size_t	len;

	if (!s1 && s2)
		return (ft_strdup(s2));
	else if (s1 && !s2)
		return (ft_strdup(s1));
	else if (!s1 && !s2)
		return (0);
	len = ft_strlen(s1);
	if (!(dest = ft_strnew(len + ft_strlen(s2))))
		return (0);
	ft_strcpy(dest, s1);
	ft_strcpy(dest + len, s2);
	return (dest);
}
