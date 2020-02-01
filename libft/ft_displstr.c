/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_displstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: padelord <padelord@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 21:56:30 by padelord          #+#    #+#             */
/*   Updated: 2019/02/08 21:56:55 by padelord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

void	ft_displstr(t_list *lst)
{
	if (!lst)
		return ;
	ft_displstr(lst->next);
	write(1, lst->content, lst->content_size);
}
