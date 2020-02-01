/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: padelord <padelord@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 23:31:07 by padelord          #+#    #+#             */
/*   Updated: 2018/12/03 03:34:50 by padelord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strstr(const char *haystack, const char *needle)
{
	size_t	i;
	size_t	len;

	len = ft_strlen(needle);
	if (len > ft_strlen(haystack))
		return (0);
	if (len == 0)
		return ((char *)haystack);
	i = 0;
	while (haystack[i])
	{
		if (ft_strncmp(haystack + i, needle, len) == 0)
			return ((char *)(haystack + i));
		i++;
	}
	return (0);
}
