/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenaudi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 18:08:47 by crenaudi          #+#    #+#             */
/*   Updated: 2018/11/16 17:05:25 by crenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	*ft_memalloc(size_t size)
{
	char	*pointeur;

	if (!(pointeur = (char *)malloc(sizeof(char) * (size))))
		return (NULL);
	ft_bzero(pointeur, size);
	return (pointeur);
}
