#include "wolf3d.h"

void	draw_bg(unsigned long int *buffer)
{
	int	i;
	int	limit;

	limit = WIDTH * HEIGHT / 4;
	i = -1;
	while (++i < limit)
	{
		buffer[i] = FC_SKY;
	}
	limit = WIDTH * HEIGHT / 2;
	i--;
	while (++i < limit)
	{
		buffer[i] = FC_FLOOR;
	}
}

void fx_drawcol(unsigned int *buffer, float dist)
{
	int	i;
	int	size;
	int	limit;

	size = (int)((16.0 - dist) * 50.0);
	//printf("dist : %.2f\nsize : %d\n", dist, size);
	limit = (HEIGHT - size) / 2;
	i = -1;
	while (++i < limit && i < HEIGHT)
	{
		*buffer = C_SKY;
		buffer += WIDTH;
	}
	limit += size;
	i--;
	while (++i < limit && i < HEIGHT)
	{
		*buffer = C_WALL;
		buffer += WIDTH;
	}
	i--;
	while (++i < HEIGHT)
	{
		*buffer = C_FLOOR;
		buffer += WIDTH;
	}
}

void draw_scene(t_env *env)
{
	int		i;
	float	a;
	t_vec2	angle;
	float	hfov;
	float	epsa;
	t_vec2	epsi;
	float	dist;
	int		wall;
	t_vec2	fping;
	t_ivec2 ping;

//	printf("player at %.2f:%.2f\n", env->plr->pos.x, env->plr->pos.y);
	hfov = env->plr->fov / 2;
	a = env->plr->a - hfov;
	epsa = env->plr->fov / WIDTH;
	i = -1;
	while (++i < WIDTH)
	{
		angle = (t_vec2){cos(a), sin(a) * -1};
		epsi = angle * 0.001;
//		printf("angle : %.2f:%.2f\n", angle.x, angle.y);
		fping = env->plr->pos;
		dist = 0.0;
		wall = 0;
		while (!wall)
		{
			fping += epsi;
			dist += 0.001;
			ping = (t_ivec2){(int)(fping.x), (int)(fping.y)};
//			printf("ping : %d:%d\n", ping.x, ping.y);
			if (ping.x < 0 || ping.x >= env->map->width ||
				ping.y < 0 || ping.y >= env->map->height ||
				env->map->data[ping.x + ping.y * env->map->width])
				wall = 1;
		}
//		printf("pixel %d dist: %.2f\n", i, dist);
		fx_drawcol(env->img->buffer + i, dist);
		a += epsa;
	}
}
