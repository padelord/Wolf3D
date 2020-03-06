#include "../includes/wolf.h"

static void		put_px(t_img *img, int x, int y, int color)
{
	int		index;

	index = x + y * X_SCREEN;
	if (index < 0 || index >= Y_SCREEN * X_SCREEN)
		return ;
	img->data[index] = color;
}
/*
void draw_wall(t_env *e, int x, float draw[2])
{
      int y;
	int color;


	if (e->player->dir_wall == 0)
		color = 0x999933;
	else if (e->player->dir_wall == 1)
		color = 0x666633;
	else if (e->player->dir_wall == 2)
		color = 0x333333;
	else
		color = 0x999999;
	y = -1;
      while (++y < Y_SCREEN)
	{
		if (y >= (int)(draw[0]) && y <= (int)(draw[1]))
			put_px(e->img, x, y, color);
	}
}
*/
void draw_wall(t_env *e, int x, float draw[2])
{
		int y;
		int color;

		if (e->player->dir_wall == 0)
			color = 0x999933;
		if (e->player->dir_wall != 0)
			color = 0x887722;
		y = -1;
    	while (++y < Y_SCREEN)
		{
			if (y >= (int)(draw[0]) && y <= (int)(draw[1]))
				put_px(e->img, x, y, color);
		}
}
