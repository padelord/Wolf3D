#include "../includes/wolf.h"
#define DIST 0.2f

t_vecf2		get_newpos(t_vecf2 dir, t_vecf2 coord, t_map map)
{
	t_vecf2	new;

	if (dir.x > 0.0 && map.data[(int)coord.y][(int)(coord.x + DIST)])
		dir.x = 0;
	else if (dir.x < 0.0 && map.data[(int)coord.y][(int)(coord.x - DIST)])
		dir.x = 0;
	if (dir.y > 0.0 && map.data[(int)(coord.y + DIST)][(int)coord.x])
		dir.y = 0;
	else if (dir.y < 0.0 && map.data[(int)(coord.y - DIST)][(int)coord.x])
		dir.y = 0;
	new = coord + dir;
	if (map.data[(int)new.y][(int)new.x] == 0)
		return (new);
	return (coord);
}

static float	get_angle(t_vec2 dir)
{
	if (dir.x && dir.y)
		return (((dir.x == 1) ? 1 : 3) * (M_PI / 4) * (float)(dir.y));
	else if (dir.x)
		return (dir.x == 1 ? 0 : M_PI);
	else
		return (M_PI / 2.0 * (float)dir.y);
}

int		move_player(t_player *plr, t_vec2 dir, t_map map, float speed)
{
	t_vecf2		newpos;
	float		angle;

	if (!dir.x && !dir.y)
		return (ERROR);
	angle = get_angle(dir);
	newpos = (t_vecf2){cos(plr->eyes_dir + angle) * speed,
            -1 * sin(plr->eyes_dir + angle) * speed};
	newpos = get_newpos(newpos, (t_vecf2){plr->coord_x, plr->coord_y}, map);
	plr->coord_x = newpos.x;
	plr->coord_y = newpos.y;
	return (SUCCESS);
}

int key_press(int key, t_env *e)
{
	int moveSpeed;

	moveSpeed = 1;
	if (key == K_ARIGHT)
		e->key_right = 1;
	if (key == K_ALEFT)
		e->key_left = 1;
	if (key == K_Z)
		e->key_w = 1;
	if (key == K_S)
		e->key_s = 1;
	if (key == K_Q)
		e->key_a = 1;
	if (key == K_D)
		e->key_d = 1;
	if (key == K_SPC)
		e->key_shoot = 1;
	if (key == K_ESC)
	{
		clean(e);
		exit(0);
	}
	return (SUCCESS);
}

int  key_release(int key, t_env *e)
{
    int moveSpeed;

    moveSpeed = 1;
	if (key == K_ARIGHT)
		e->key_right = 0;
	if (key == K_ALEFT)
  		e->key_left = 0;
	if (key == K_Z)
		e->key_w = 0;
	if (key == K_S)
		e->key_s = 0;
	if (key == K_Q)
		e->key_a = 0;
	if (key == K_D)
		e->key_d = 0;
	if (key == K_SPC)
		e->key_shoot = 0;
    if (key == K_ESC)
    {
        clean(e);
        exit(0);
    }
    return (SUCCESS);
}
