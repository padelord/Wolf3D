/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenaudi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 18:42:59 by crenaudi          #+#    #+#             */
/*   Updated: 2018/11/27 18:23:35 by crenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static int	ft_index_nb(long nb)
{
	int		i;

	i = 1;
	while (nb >= 10)
	{
		nb = nb / 10;
		i = i * 10;
	}
	return (i);
}

char		*ft_itoa(int n)
{
	long	nb;
	char	*ret;
	int		size;
	int		i;
	int		modulo;

	nb = (long)n;
	size = ft_nblen(nb);
	if (!(ret = ft_strnew(size)))
		return (0);
	size = 0;
	if (n < 0)
	{
		ret[size++] = '-';
		nb = nb * -1;
	}
	i = ft_index_nb(nb);
	while (i > 0)
	{
		modulo = nb % i;
		ret[size++] = (nb / i) + 48;
		i = i / 10;
		nb = modulo;
	}
	return (ret);
}
