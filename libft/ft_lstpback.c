/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpback.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: padelord <padelord@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 23:59:21 by padelord          #+#    #+#             */
/*   Updated: 2019/09/24 16:09:39 by padelord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstpback(t_list **alst, t_list *new)
{
	t_list	*l;

	if (*alst == 0)
	{
		*alst = new;
		return ;
	}
	l = *alst;
	while (l->next)
		l = l->next;
	l->next = new;
}
