/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: padelord <padelord@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 23:56:43 by padelord          #+#    #+#             */
/*   Updated: 2018/12/03 03:33:43 by padelord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	len_dst;

	if (size == 0)
		return (ft_strlen(src) + size);
	len_dst = ft_strlen(dst);
	i = 0;
	while (src[i] && i + len_dst < size - 1)
	{
		dst[len_dst + i] = src[i];
		i++;
	}
	dst[len_dst + i] = '\0';
	if (size < len_dst)
		return (ft_strlen(src) + size);
	return (len_dst + ft_strlen(src));
}
