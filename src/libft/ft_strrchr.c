/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenaudi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 17:14:19 by crenaudi          #+#    #+#             */
/*   Updated: 2018/11/22 13:33:11 by crenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	if (!(ft_strchr(s, c)))
		return (NULL);
	while (*s)
		s++;
	while (*s != (char)c)
		s--;
	return ((char *)s);
}
