/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strocontent.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: padelord <padelord@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 18:56:00 by padelord          #+#    #+#             */
/*   Updated: 2019/10/09 17:33:02 by padelord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strocontent(char *src, char *content)
{
	int i;

	if (!src || !content)
		return (0);
	while (*src)
	{
		i = -1;
		while (*src != content[++i])
			;
		if (!content[i])
			return (0);
		src++;
	}
	return (1);
}
