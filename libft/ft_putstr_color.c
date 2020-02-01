/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_color.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: padelord <padelord@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 23:58:46 by padelord          #+#    #+#             */
/*   Updated: 2019/03/22 21:54:25 by padelord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

void	ft_putchar_color(const char c, const char *attr, const char *fg,
						const char *bg)
{
	char	buff[49];

	ft_memcpy(buff, "\e[0;38;2;000;000;000;48;2;000;000;000mc\e[0;39;49m", 50);
	ft_memcpy(buff + 2, attr, 1);
	ft_memcpy(buff + 9, fg, 11);
	ft_memcpy(buff + 26, bg, 11);
	buff[38] = c;
	ft_memcpy(buff + 39, "\e[0;39;49m", 10);
	write(1, buff, 49);
}

void	ft_putstr_color(const char *str, const char *attr, const char *fg,
						const char *bg)
{
	char	buffer[39];

	buffer[0] = '\0';
	ft_strcat(buffer, "\e[");
	ft_strcat(buffer, attr);
	ft_strcat(buffer, ";38;2;");
	ft_strcat(buffer, fg);
	ft_strcat(buffer, ";48;2;");
	ft_strcat(buffer, bg);
	ft_strcat(buffer, "m");
	ft_putstr(buffer);
	ft_putstr(str);
	ft_putstr("\e[0;39;49m");
}
