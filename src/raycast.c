#include "../includes/wolf.h"

void 	dda_dir(t_ray *r, t_player *player)
{
	float mx;
	float my;
	float angle;

	//j'ai les coordonnées du mur
	mx = r->map_x + 0.5f;
	my = r->map_y + 0.5f;
	r->hit_x = player->pos_x + r->ray.x * r->ray_dist.x;
	r->hit_y = player->pos_y + r->ray.y * r->ray_dist.y;
	//angle = atan2f((r->hit_y - my), (r->hit_x - mx));
	/*if (player->dir_wall == 0)
	{
		//HORIZONTAL  x;
		 r->point_hit_wall = r->hit_x % 64.f;
	}
	else
	{
		//VERTICAL y;
		 r->point_hit_wall = r->hit_y % 64.f;
	}*/
	//SPRITE = Taille = taille_reel * de / dm (ray.x / ray.y);
}

float		get_prec(float n)
{
	float	t;

	return ((t = n - (float)(int)n) > 0.5 ? 1 - t : t);
}

int		get_dir_wall(float x, float y, float px, float py)
{
	if (get_prec(x) > get_prec(y))
		printf("x");
	else
		printf ("y");
	printf (" ~\n");
	return (1);
}

int 	dda_ray(t_env *e, t_ray *r, t_player *p, t_map *map)
{
	(void)e;
	r->ray_dist += EPSILON;
	while (r->hit != 1)
	{
		r->map_x = (p->coord_x + r->ray.x * r->ray_dist.x);
		r->map_y = (p->coord_y + r->ray.y * r->ray_dist.y);
		if (r->ray_dist.x <= r->ray_dist.y)
		{
			p->dir_wall = 0;
			r->ray_dist.x += EPSILON;
		}
		else
		{
			p->dir_wall = 1;
			r->ray_dist.y += EPSILON;
		}
		if (map->data[(int)(r->map_y)][(int)(r->map_x)] != 0)
		{
			r->hit = map->data[(int)(r->map_y)][(int)(r->map_x)];
			dda_dir(r, p);
		}
	}
	// if (is_int(r->map_x, 0.3) || is_int(r->map_x, 0.3))
	// 	printf("isint\n");
	//get_dir_wall(r->map_x, r->map_y, p->coord_x, p->coord_y);
	//printf("ray : %.2f:%.2f\n", r->map_x, r->map_y);
	return (SUCCESS);
}

int ray_cast(t_env *e, t_camera *c)
{
	float  err;
	float		drawing[2];
	int 		x;
	t_ray 	r;

	x = -1;
	ft_bzero(&r, sizeof(t_ray));
	while (++x < X_SCREEN)
	{
		r.ray_angle = (e->player->eyes_dir - c->half_fov)
			+ x / (float)X_SCREEN * c->fov;
		r.ray.x = sin(r.ray_angle);
		r.ray.y = cos(r.ray_angle);
	//	r.ray_dist = 0;
		r.ray_dist.x = 0;
		r.ray_dist.y = 0;
		r.hit = 0;
		dda_ray(e, &r, e->player, e->map);
		err = ((float)x * c->fov) / ((float)WIDTH);
		err -= c->half_fov;
		r.ray_dist *= cosf(err);
		drawing[0] = (float)(HEIGHT / 2) - (float)(HEIGHT / r.ray_dist.x) / 2;
		drawing[1] = (float)(HEIGHT) - drawing[0];
		draw_wall(e, x, drawing);
		//clean(e);
	}
	return (SUCCESS);
}

/*
void 	dda_dir(t_ray *r, t_player *player)
{
	float mx;
	float my;
	float angle;

//j'ai les coordonnées du mur
	mx = r->map_x + 0.5f;
	my = r->map_y + 0.5f;
	r->hit_x = player->pos_x + r->ray.x * r->ray_dist;
	r->hit_y = player->pos_y + r->ray.y * r->ray_dist;
	angle = atan2f((r->hit_y - my), (r->hit_x - mx));
	if (angle >= M_PI && angle < 0)
	{
		//NORD_OUEST;
		 player->dir_wall = 0;
	}
	else
	{
		//NORD-EST;
		 player->dir_wall = 1;
	}

}

int 	dda_ray(t_ray *r, t_player *p, t_map *map)
{
	while (r->hit != 1)
	{
		r->ray_dist += EPSILON;
		r->map_x = (p->coord_x + r->ray.x * r->ray_dist);
		r->map_y = (p->coord_y + r->ray.y * r->ray_dist);
		if (map->data[(int)(r->map_y)][(int)(r->map_x)] != 0)
		{
			r->hit = map->data[(int)(r->map_y)][(int)(r->map_x)];
			dda_dir(r, p);
		}
	}
	return (SUCCESS);
}

int ray_cast(t_env *e, t_camera *c)
{
	float		rectify;
	float		drawing[2];
	int 		x;
	t_ray 	r;

	x = -1;
	ft_bzero(&r, sizeof(t_ray));
	while (++x < X_SCREEN)
	{
		r.ray_angle = (e->player->eyes_dir - c->half_fov)
			+ x / (float)X_SCREEN * c->fov;
		r.ray.x = sin(r.ray_angle);
		r.ray.y = cos(r.ray_angle);
		r.ray_dist = 0;
		r.hit = 0;
		dda_ray(&r, e->player, e->map);
		rectify = ((float)x * c->fov / (float)WIDTH) - c->half_fov;
		r.ray_dist *= cosf(rectify) + 0.6f;
		drawing[0] = (float)(HEIGHT / 2) - (float)(HEIGHT / r.ray_dist);
		drawing[1] = (float)(HEIGHT) - drawing[0];
		draw_wall(e, x, drawing);
		//clean(e);
	}
	return (SUCCESS);
}
*/
