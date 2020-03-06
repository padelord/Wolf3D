/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenaudi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 15:43:46 by crenaudi          #+#    #+#             */
/*   Updated: 2018/11/16 17:08:02 by crenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	*ft_memrchr(const void *s, int c, size_t n)
{
	unsigned int	i;
	unsigned char	*s2;
	unsigned char	c2;

	i = ft_strlen(s);
	s2 = (unsigned char *)s;
	c2 = (unsigned char)c;
	while (n--)
	{
		if (s2[i] == c2)
			return (s2 + i);
		i--;
	}
	return (NULL);
}
