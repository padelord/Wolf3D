/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: padelord <padelord@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 21:40:33 by padelord          #+#    #+#             */
/*   Updated: 2020/02/01 18:23:28 by padelord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "libft.h"
#include "wolf3d.h"
#include <math.h>

int		init_player(t_plr *plr, t_ivec2 orig, float angle)
{
	printf("new player at %d:%d looking at %d° from right\n", orig.x, orig.y, (int)(angle * 360 / 2 * M_PI));
	if (!(plr = malloc(sizeof(t_plr))))
		return (R_PLR_MALC);
	plr->pos = (t_vec2){(float)orig.x + 0.5, (float)orig.y + 0.5};
	plr->a = angle;
	return (0);
}

int		init_env(t_env *env, const char *path)
{
	int	err;

	env->state = 0;
	if (!(err = get_map(path, &(env->map))))
		env->state |= ST_INIT_MAP;
	else
		return (err);
	if (!(err = init_player(env->plr, env->map.orig, 0.0)))
		env->state |= ST_INIT_PLR;
	return (err);
}

int		close_env(t_env *env)
{
	if (env->state & ST_INIT_MAP)
	{
		delete_map(&(env->map));
		env->state ^= ST_INIT_MAP;
	}
	printf("plr pos : %fx%f\n", env->plr->pos.x, env->plr->pos.y);
	if (env->state & ST_INIT_PLR)
	{
		free((void*)env->plr);
		env->state ^= ST_INIT_PLR;
	}
	return (1);
}
