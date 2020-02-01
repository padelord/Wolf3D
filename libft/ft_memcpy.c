/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: padelord <padelord@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 22:43:25 by padelord          #+#    #+#             */
/*   Updated: 2019/03/22 21:52:32 by padelord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*ft_longmemcpy(long long *dst, const long long *src, size_t n)
{
	while (n--)
		*dst++ = *src++;
	return ((void*)dst);
}

void		*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*cdst;
	unsigned char	*csrc;
	size_t			i;

	cdst = (unsigned char *)dst;
	csrc = (unsigned char *)src;
	if (n > sizeof(long long))
	{
		i = n / sizeof(long long);
		ft_longmemcpy((long long*)dst, (long long*)src, i);
		i *= sizeof(long long);
		cdst += i;
		csrc += i;
		n -= i;
	}
	while (n--)
		*cdst++ = *csrc++;
	return (dst);
}
