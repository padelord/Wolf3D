/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: padelord <padelord@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 21:40:33 by padelord          #+#    #+#             */
/*   Updated: 2020/02/03 13:24:32 by padelord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "mlx.h"
#include "libft.h"
#include "wolf3d.h"
#include <math.h>

int		init_player(t_plr *plr, t_ivec2 orig, float angle)
{
	plr->pos = (t_vec2){((float)orig.x) + 0.5, ((float)orig.y) + 0.5};
	plr->a = angle;
	plr->fov = 70.0 * M_PI / 360;
	printf("new player at %.2f:%.2f looking at %.2f with Fov of %.2f\n", plr->pos.x, plr->pos.y, plr->a, plr->fov);
	return (0);
}

int			new_image(t_img *t, void *mlx, int w, int h)
{
	ft_bzero(t, sizeof(t_img));
	if (!(t->ptr = mlx_new_image(mlx, w, h)))
		return (R_IMG_INIT);
	t->w = w;
	t->h = h;
	if (!(t->buffer = (unsigned int *)mlx_get_data_addr(t->ptr, &(t->bpp),
													&(t->sl), &(t->endian))))
		return (R_IMG_BUFF);
	ft_bzero(t->buffer, w * h * sizeof(int));
	draw_bg(t->buffer);
	return (0);
}

int		init_env(t_env *env, const char *path)
{
	int	err;

	err = 0;
	env->state = 0;
	env->map = &(env->global.map);
	env->img = &(env->global.img);
	env->plr = &(env->global.plr);
	if (!(env->mlx = mlx_init()))
		return (R_MLX_INIT);
	else
		env->state |= ST_INIT_MLX;
	if ((env->win = mlx_new_window(env->mlx, WIDTH, HEIGHT, "Wolf3D")))
		env->state |= ST_INIT_WIN;
	else
		return (R_WIN_INIT);
	if ((err = new_image(env->img, env->mlx, WIDTH, HEIGHT)))
		return (err);
	if (!(err = get_map(path, env->map)))
		env->state |= ST_INIT_MAP;
	else
		return (err);
	if (!(err = init_player(env->plr, env->map->orig, 0.0)))
		env->state |= ST_INIT_PLR;
	else
		return (err);
	mlx_hook(env->win, 2, 1, key_hook, env);
	mlx_loop_hook(env->mlx, loop_hook, env);
	printf("init worked\n");
	return (err);
}
