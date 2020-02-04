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
		ft_bzero((void*)(env->plr), sizeof(t_plr));
		env->state ^= ST_INIT_PLR;
	}
	if (env->state & ST_INIT_WIN)
	{
		ft_putendl("Destroying window");
		mlx_destroy_window(env->mlx, env->win);
	}
	mlx_do_sync(env->mlx);
	if (ex)
	{
		//read(0, &ex, 1);
		exit(0);
	}
	return (1);
}
