/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lsttostr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: padelord <padelord@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 21:57:43 by padelord          #+#    #+#             */
/*   Updated: 2019/02/08 21:57:45 by padelord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_lsttostr(t_list *lst)
{
	char	*line;
	size_t	size;

	if (!lst)
		return (NULL);
	size = ft_lstgetsize(lst);
	if (!(line = ft_strnew(size)))
		return (NULL);
	line[size] = '\0';
	while (lst)
	{
		size -= lst->content_size;
		ft_memcpy(line + size, lst->content, lst->content_size);
		lst = lst->next;
	}
	return (line);
}
