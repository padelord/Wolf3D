/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenaudi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 14:40:47 by crenaudi          #+#    #+#             */
/*   Updated: 2018/11/26 16:43:02 by crenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_strrev(char const *str)
{
	int		i;
	int		j;
	char	*s;
	char	*tmp;

	i = 0;
	j = 0;
	s = (char const *)s;
	while (str[i + 1] != '\0')
		i++;
	while (i > j)
	{
		tmp = s[i];
		s[i] = s[j];
		s[j] = tmp;
		i--;
		j++;
	}
	return (str);
}
