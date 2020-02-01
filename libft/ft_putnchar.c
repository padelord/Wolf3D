/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: padelord <padelord@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 23:28:28 by padelord          #+#    #+#             */
/*   Updated: 2018/11/18 23:39:06 by padelord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

void	ft_putnchar(char c, size_t len)
{
	char	buff[BUFF_SIZE];

	ft_memset(buff, c, BUFF_SIZE);
	while (len > 0)
		len -= write(1, buff, ((len > BUFF_SIZE) ? BUFF_SIZE : len));
}
