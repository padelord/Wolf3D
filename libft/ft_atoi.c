/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: padelord <padelord@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 00:57:22 by padelord          #+#    #+#             */
/*   Updated: 2018/12/03 00:03:35 by padelord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	size_t			i;
	int				sign;
	unsigned int	nb;

	i = 0;
	while (str[i] && ft_isspace(str[i]))
		i++;
	sign = 1;
	if (str[i] == '-' || str[i] == '+')
		sign = 44 - str[i++];
	nb = 0;
	while (str[i] && ft_isdigit(str[i]))
	{
		nb *= 10;
		nb += str[i] - '0';
		i++;
	}
	return ((int)(nb * sign));
}
