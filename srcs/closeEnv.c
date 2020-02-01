#include <stdlib.h>
#include "mlx.h"
#include "libft.h"
#include "wolf3d.h"

int		close_env(t_env *env, int ex)
{
	if (env->state & ST_INIT_MAP)
	{
		delete_map(env->map);
		env->state ^= ST_INIT_MAP;
	}
	if (env->state & ST_INIT_PLR)
	{
		free((void*)(env->plr));
		env->state ^= ST_INIT_PLR;
	}

	if (env->state & ST_INIT_WIN)
	{
		mlx_destroy_window(env->mlx, env->win);
	}
	if (ex)
		exit(0);
	return (1);
}
