/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenaudi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 20:19:18 by crenaudi          #+#    #+#             */
/*   Updated: 2018/12/17 17:45:30 by crenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*copy;
	int		len;

	if (!s1 || !s2)
		return (0);
	len = ft_strlen(s1) + ft_strlen(s2);
	if (!(copy = (char *)ft_memalloc(sizeof(char) * (len + 1))))
		return (NULL);
	ft_strcpy(copy, s1);
	ft_strcat(copy, s2);
	copy[len] = '\0';
	return (copy);
}
