/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: padelord <padelord@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 23:29:54 by padelord          #+#    #+#             */
/*   Updated: 2018/12/03 00:41:31 by padelord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*dest;
	size_t	i;

	if (!f || !(dest = ft_strnew(ft_strlen(s))))
		return (0);
	i = 0;
	while (s[i])
	{
		dest[i] = f(s[i]);
		i++;
	}
	return (dest);
}
