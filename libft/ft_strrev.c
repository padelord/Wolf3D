/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: padelord <padelord@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 20:28:34 by padelord          #+#    #+#             */
/*   Updated: 2018/12/06 14:55:45 by padelord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *str)
{
	size_t	len;
	size_t	i;

	if (!str)
		return (0);
	len = ft_strlen(str) - 1;
	i = 0;
	while (i < len)
	{
		ft_cswap(str + i, str + len);
		i++;
		len--;
	}
	return (str);
}
