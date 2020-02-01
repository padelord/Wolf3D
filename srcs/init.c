/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: padelord <padelord@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 21:40:33 by padelord          #+#    #+#             */
/*   Updated: 2020/02/01 21:48:13 by padelord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "mlx.h"
#include "libft.h"
#include "wolf3d.h"
#include <math.h>

int		init_player(t_plr **plr, t_ivec2 orig, float angle)
{
	if (!(*plr = malloc(sizeof(t_plr))))
		return (R_PLR_MALC);
	(*plr)->pos = (t_vec2){((float)orig.x) + 0.5, ((float)orig.y) + 0.5};
	(*plr)->a = angle;
	printf("new player at %.2f:%.2f\n", (*plr)->pos.x, (*plr)->pos.y);
	return (0);
}

int		init_env(t_env *env, const char *path)
{
	int	err;

	err = 0;
	env->state = 0;
	if (!(env->mlx = mlx_init()))
		return (R_MLX_INIT);
	else
		env->state |= ST_INIT_MLX;
	if ((env->win = mlx_new_window(env->mlx, WIDTH, HEIGHT, "Wolf3D")))
		env->state |= ST_INIT_WIN;
	else
		return (R_WIN_INIT);
	if (!(err = get_map(path, &env->map)))
		env->state |= ST_INIT_MAP;
	else
		return (err);
	if (!(err = init_player(&env->plr, env->map->orig, 0.0)))
		env->state |= ST_INIT_PLR;
	else
		return (err);
	mlx_hook(env->win, 2, 1, key_hook, env);
	mlx_loop_hook(env->mlx, loop_hook, env);
	printf("init worked\n");
	return (err);
}
