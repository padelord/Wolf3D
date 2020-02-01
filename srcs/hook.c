#include "mlx.h"
#include "wolf3d.h"
#include "ft_keymap.h"

int				close_hook(void *param)
{
	close_env((t_env*)param, 1);
	return (1);
}

int				key_hook(int keycode, void *param)
{
	t_env			*env;

	env = (t_env*)param;
	if (keycode == K_ESC)
		close_env(env, 1);
	return (1);
}

int				loop_hook(void *param)
{
	t_env			*env;

	env = (t_env*)param;
	return (1);
}
