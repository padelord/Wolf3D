#include "../includes/wolf.h"

static void		put_px(t_img *img, int x, int y, int color)
{
	int		index;

	index = x + y * WIDTH;
	if (index < 0 || index >= HEIGHT * WIDTH)
		return ;
	img->data[index] = color;
}

static void  color_box(int height, int x_start, int width, t_img *img)
{
      int x;
	int y;
      int y_border;

      y_border = 2;
	y = -1;
      while (++y < height)
      {
            x = x_start - 1;
            while (++x < width)
			put_px(img, x, y, (y < y_border || x < x_start + 3) ?
                  0xAF1FAEE : 0x232ED1);
      }
}

static void  lgd_txt(void *mlx_ptr, void * win_ptr, t_player *player, int posY)
{
	mlx_string_put(mlx_ptr, win_ptr, 30, posY + 25, 0xFFFFFF, "LEVEL");
      mlx_string_put(mlx_ptr, win_ptr, 30, posY + 50, 0xFFFFFF,
            ft_itoa(player->level));
	mlx_string_put(mlx_ptr, win_ptr, 180, posY + 25, 0xFFFFFF, "SCORE");
      mlx_string_put(mlx_ptr, win_ptr, 180, posY + 50, 0xFFFFFF,
            ft_itoa(player->score));
      mlx_string_put(mlx_ptr, win_ptr, 330, posY + 25, 0xFFFFFF, "HEALTH");
      mlx_string_put(mlx_ptr, win_ptr, 330, posY + 50, 0xFFFFFF,
            ft_itoa(player->pv));
	mlx_string_put(mlx_ptr, win_ptr, 580, posY + 25, 0xFFFFFF, "ARMS");
      mlx_string_put(mlx_ptr, win_ptr, 580, posY + 50, 0xFFFFFF,
            ft_itoa(player->arms));
	mlx_string_put(mlx_ptr, win_ptr, 680, posY + 15, 0xFFFFFF, "FORWARD..W");
	mlx_string_put(mlx_ptr, win_ptr, 680, posY + 40, 0xFFFFFF, "BACK.....S");
	mlx_string_put(mlx_ptr, win_ptr, 680, posY + 65, 0xFFFFFF, "RIGHT....D");
	mlx_string_put(mlx_ptr, win_ptr, 805, posY + 65, 0xFFFFFF, "LEFT...A");
	mlx_string_put(mlx_ptr, win_ptr, 805, posY + 15, 0xFFFFFF,
            "SHOOT..(enter)");
	mlx_string_put(mlx_ptr, win_ptr, 805, posY + 40, 0xFFFFFF,
            "TAKE...(space)");
}

static void  put_sprite(t_img *dest, t_sprite *sp,  int pos_x, int pos_y)
{
	int x;
	int y;
	int *color;
	int i;

	color = (int *)sp->data;
	if (dest == NULL && sp == NULL)
		printf("PB : src ou dest null!!\n");
	y = -1;
	while (++y < sp->sp_size[1])
	{
		x = -1;
		while (++x < sp->sp_size[0])
		{
			i = (x + sp->pos_x) + (y + sp->pos_y) * sp->width;
			if (color[i] != ALPHA_0)
				put_px(dest, x + pos_x, y + pos_y, color[i]);
			else
				put_px(dest, x + pos_x, y + pos_y, 0x0D0D3E);
		}
	}
}
int		put_sprt_to_img(t_img *src, t_sprt *sprite, t_vec2 pos);

void  legend(t_env *e)
{
	int 	x;
      int 	posY;
	t_img lgd;

      x = 100;
      posY = HEIGHT - x;
	lgd.ptr = mlx_new_image(e->mlx_ptr, WIDTH, x);
	lgd.data = (int *)(mlx_get_data_addr(lgd.ptr, &lgd.bpp, &lgd.sl,
				&lgd.endian));
	lgd.size = (t_vec2){WIDTH, 100};
      color_box(x, 0, 150, &lgd);
	color_box(x, 150, 300, &lgd);
      color_box(x, 300, 450, &lgd);
	color_box(x, 550, 650, &lgd);
	color_box(x, 650, WIDTH, &lgd);
	color_box(x, 450, 550, &lgd);
//	put_sprite(&lgd, e->txt_head, 450, 0);
	put_sprt_to_img(&lgd, &(e->shead), (t_vec2){(WIDTH - 100) / 2 ,0});
      mlx_put_image_to_window(e->mlx_ptr, e->win_ptr, lgd.ptr, 0, posY);
	lgd_txt(e->mlx_ptr, e->win_ptr, e->player, posY);
      mlx_destroy_image(e->mlx_ptr, lgd.ptr);
}
