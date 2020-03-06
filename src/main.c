#include "../includes/wolf.h"

static void		put_px(t_img *img, int x, int y, int color)
{
	int		index;

	index = x + y * WIDTH;
	if (index < 0 || index >= HEIGHT * WIDTH)
		return ;
	img->data[index] = color;
}

void  color_base(t_img *img)
{
      int x;
      int y;

      y = -1;
      while (++y < HEIGHT)
      {
            x = -1;
            while (++x < WIDTH)
                  put_px(img, x, y, (y < HEIGHT / 2) ? 0x7F7979 : 0x3D3B3C);
      }
}

int		put_txture_to_img(t_img *src, t_txtur *texture, t_vec2 pos, int id);
int		put_sprt_to_img(t_img *src, t_sprt *sprite, t_vec2 pos);

#define TWOPI 2 * M_PI
int  run(t_env *e)
{
	t_vec2	dir;
	static int id = 106;
	static int change = 0;

      ft_bzero(e->img->data, WIDTH * HEIGHT * (e->img->bpp / 8));
	if (e->key_right == 1)
	{
		e->shead.frame = 2;
		e->txt_head->pos_x = 200;
	  	e->player->eyes_dir += 0.03;
		if (e->player->eyes_dir > TWOPI)
			e->player->eyes_dir -= TWOPI;
	}
	else if (e->key_left == 1)
	{
		e->shead.frame = 1;
		e->txt_head->pos_x = 0;
  	  	e->player->eyes_dir -= 0.03;
		if (e->player->eyes_dir < 0)
			e->player->eyes_dir += TWOPI;
	}
	else
		e->shead.frame = 0;
	if (e->key_right == 0 && e->key_left == 0)
		e->txt_head->pos_x = 100;
	dir = 0;
	if (e->key_w == 1)
		dir.y = -1;//move_player(e->player, (t_vec2){0, -1}, *(e->map), 0.05);
	if (e->key_s == 1)
		dir.y = 1;//move_player(e->player, (t_vec2){0, 1}, *(e->map), 0.05);
	if (e->key_a == 1)
		dir.x = -1;//move_player(e->player, (t_vec2){-1, 0}, *(e->map), 0.05);
	if (e->key_d == 1)
		dir.x = 1;//move_player(e->player, (t_vec2){1, 0}, *(e->map), 0.05);
	if (e->key_shoot && e->cut.frame == -1)
		e->cut.frame = 0;
		move_player(e->player, dir, *(e->map), 0.05);
      color_base(e->img);
      ray_cast(e, e->cam);
	  put_sprt_to_img(e->img, &(e->cut), (t_vec2){(WIDTH - 128) / 2, HEIGHT - 228});
      mlx_put_image_to_window(e->mlx_ptr, e->win_ptr, e->img->ptr, 0, 0);
	  legend(e);
      return (SUCCESS);
}

int   main(int argc, char **argv)
{
      t_env e;
      int   fd;
	int i;

      if (argc > 2)
        error(-1);
      fd = open(argv[1], O_RDONLY | O_NOFOLLOW);
      init_env(&e);
      if ((i = map_int(&e, fd)) == ERROR)
	{
		ft_putendl("Pb de map");
		clean(&e);
	}
      mlx_loop_hook(e.mlx_ptr, run, &e);
      mlx_hook(e.win_ptr, 2, (1L << 0), key_press, &e);
      mlx_hook(e.win_ptr, 3, (1L << 1), key_release, &e);
      mlx_loop(e.mlx_ptr);
      return (0);
}
