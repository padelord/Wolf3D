/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenaudi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 17:01:33 by crenaudi          #+#    #+#             */
/*   Updated: 2018/11/23 13:49:17 by crenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../../includes/libft.h"

static size_t	forbidden_strlen(char const *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void			ft_putstr_fd(char const *s, int fd)
{
	if (!s)
		return ;
	write(fd, s, forbidden_strlen(s));
}
