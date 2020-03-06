/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenaudi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 22:13:18 by crenaudi          #+#    #+#             */
/*   Updated: 2019/01/13 17:47:09 by crenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int		ft_sqrt(int nb)
{
	int		i;

	if (nb <= 0)
		return (0);
	if (nb == 1)
		return (1);
	i = 1;
	while (i < 46342)
	{
		if ((i * i) == nb)
			return (i);
		else if ((i * i) > nb)
			return (i - 1);
		i++;
	}
	return (i);
}
