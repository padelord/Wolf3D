/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_color.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: padelord <padelord@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 23:52:13 by padelord          #+#    #+#             */
/*   Updated: 2018/11/19 00:06:36 by padelord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_color(const char *str, const char *attr, const char *fg,
						const char *bg)
{
	ft_putstr_color(str, attr, fg, bg);
	ft_putchar('\n');
}
