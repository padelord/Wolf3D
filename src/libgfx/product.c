/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   product.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenaudi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 15:14:14 by crenaudi          #+#    #+#             */
/*   Updated: 2019/03/29 15:15:39 by crenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/gfx.h"

float	vec2_dist(t_vec2 v2)
{
	return (sqrt(v2.x * v2.x + v2.y * v2.y));
}

float	dot_product(t_point a, t_point b)
{
	float	angle;

	angle = (a.x * b.x) + (a.y * b.y) + (a.z * b.z);
	return (angle);
}

t_point	cross_product(t_point a, t_point b)
{
	t_point		c;

	c.x = (a.y * b.z) - (a.z * b.y);
	c.y = (a.z * b.x) - (a.x * b.z);
	c.z = (a.x * b.y) - (a.y * b.x);
	return (c);
}
