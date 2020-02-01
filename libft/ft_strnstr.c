/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: padelord <padelord@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 23:30:39 by padelord          #+#    #+#             */
/*   Updated: 2018/12/03 03:34:40 by padelord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	n_len;

	n_len = ft_strlen(needle);
	if (n_len == 0)
		return ((char *)haystack);
	if (n_len > ft_strlen(haystack) || n_len > len)
		return (0);
	while (*(haystack + n_len - 1) && len >= n_len)
	{
		if (ft_strncmp(haystack, needle, n_len) == 0)
			return ((char *)haystack);
		haystack++;
		len--;
	}
	return (0);
}
