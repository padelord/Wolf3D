/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstgetsize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: padelord <padelord@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 21:57:14 by padelord          #+#    #+#             */
/*   Updated: 2019/02/08 21:57:17 by padelord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_lstgetsize(t_list *lst)
{
	size_t	size;

	size = 0;
	while (lst)
	{
		size += lst->content_size;
		lst = lst->next;
	}
	return (size);
}
