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
	static int	frame = 0;
	static int	moment = 0;
	int			t;
	t_env		*env;

	env = (t_env*)param;
	t = time(0);
	if (moment != t)
	{
		printf("%dfps\n", frame);
		moment = t;
		frame = 0;
	}
	draw_bg(env->img->buffer);
	mlx_put_image_to_window(env->mlx, env->win, env->img->ptr, 0, 0);
	frame++;
	return (1);
}
