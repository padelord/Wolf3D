/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wtabdel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: padelord <padelord@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 15:05:32 by padelord          #+#    #+#             */
/*   Updated: 2018/12/06 15:18:22 by padelord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_wtabdel(char **tab)
{
	size_t	i;

	if (tab)
	{
		i = 0;
		while (tab[i])
		{
			free(tab[i]);
			tab[i] = 0;
			i++;
		}
		free(tab);
		tab = 0;
	}
}
