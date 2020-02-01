/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: padelord <padelord@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 21:09:21 by padelord          #+#    #+#             */
/*   Updated: 2019/11/05 15:12:25 by padelord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "mlx.h"

static inline int	gray_hsl(int lum)
{
	return (lum << 16 | lum << 8 | lum);
}

static float		color_adjust(float val)
{
	if (val < 0.0)
		return (val + 1.0);
	else if (val > 1.0)
		return (val - 1.0);
	else
		return (val);
}

static int			hsl_gp(float hue, float t1, float t2, float tmod)
{
	float			tmp;

	tmp = color_adjust(hue + tmod);
	if (6.0 * tmp < 1.0)
		return ((int)((t2 + (t1 - t2) * 6.0 * tmp) * 255.0));
	else if (2.0 * tmp < 1.0)
		return ((int)(t1 * 255.0));
	else if (3.0 * tmp < 2.0)
		return ((int)((t2 + (t1 - t2) * (0.666 - tmp) * 6.0) * 255.0));
	else
		return ((int)(t2 * 255.0));
}

unsigned int		fx_gethslcolor(int hue, float sat, float lum)
{
	float			t1;
	float			t2;
	float			hrad;

	if (sat == 0.0)
		return (gray_hsl((char)(lum * 255)));
	if (lum < 0.5)
		t1 = lum * (1.0 + sat);
	else
		t1 = lum + sat - lum * sat;
	t2 = 2 * lum - t1;
	hrad = (float)(hue / 360.0);
	return ((hsl_gp(hrad, t1, t2, 0.333) << 16) |
	(hsl_gp(hrad, t1, t2, 0.0) << 8) |
	(hsl_gp(hrad, t1, t2, -0.333)));
}

void				fx_getpal(unsigned int *pal, int size)
{
	int				i;

	i = -1;
	while (++i < size)
		pal[i] = fx_gethslcolor(i, 0.9, 0.4);
}
