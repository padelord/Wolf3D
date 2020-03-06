/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenaudi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 18:35:50 by crenaudi          #+#    #+#             */
/*   Updated: 2018/11/26 17:44:44 by crenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static int	ft_counter(long nbl)
{
	int i;

	i = 1;
	while (nbl >= 10)
	{
		nbl = nbl / 10;
		i = i * 10;
	}
	return (i);
}

void		ft_putnbr(int n)
{
	long	nbl;
	int		i;
	int		modulo;

	nbl = n;
	if (nbl < 0)
	{
		ft_putchar('-');
		nbl = nbl * -1;
	}
	i = ft_counter(nbl);
	while (i > 0)
	{
		modulo = nbl % i;
		nbl = nbl / i;
		ft_putchar(nbl + 48);
		i = i / 10;
		nbl = modulo;
	}
}
