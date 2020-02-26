#include "mlx.h"
#include "wolf3d.h"
#include "ft_keymap.h"
#include <math.h>

#define SPEED 0.1f

int				close_hook(void *param)
{
	close_env((t_env*)param, 1);
	return (1);
}

int				move_player(t_plr *plr, t_ivec2 dir, t_map map)
{
	t_vec2		newpos;
	float		angle;

	if (dir.x)
	{
		if (dir.x == 1)
			angle = 0;
		else
			angle = M_PI;
	}
	else
		angle = M_PI / 2.0 * (float)dir.y;
	newpos = (t_vec2){cos(plr->a + angle),
						-1 * sin(plr->a + angle)};
	plr->pos += newpos * SPEED;
}

int				key_hook(int keycode, void *param)
{
	t_env			*env;

	env = (t_env*)param;
	if (keycode == K_ALEFT)
		env->plr->a -= 0.03;
	if (keycode == K_ARIGHT)
		env->plr->a += 0.03;
	if (keycode == K_Z)
		move_player(env->plr, (t_ivec2){1,0}, *(env->map));
	if (keycode == K_S)
		move_player(env->plr, (t_ivec2){-1,0}, *(env->map));
	if (keycode == K_Q)
		move_player(env->plr, (t_ivec2){0,-1}, *(env->map));
	if (keycode == K_D)
		move_player(env->plr, (t_ivec2){0,1}, *(env->map));
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
	draw_scene(env);
	//close_env(env, 1);
	mlx_put_image_to_window(env->mlx, env->win, env->img->ptr, 0, 0);
	frame++;
	return (1);
}
