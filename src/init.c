#include "../includes/wolf.h"

t_camera  init_cam()
{
      t_camera c;

      c.fov = M_PI / 3;
      c.half_fov = c.fov / 2.0f;
      c.speed_move = 100.;
      c.speed_angle = 100.;
      return (c);
}

t_map  init_map()
{
      t_map        mp;

      mp.size_x = 0;
      mp.size_y = 0;
      mp.width_screen = 0;
      mp.height_screen = 0;
      mp.data = NULL;
      return (mp);
}

t_sprite    add_sprite(void *mlx_ptr, char *str, int width, int height)
{
      t_sprite    s;

      if ((s.ptr = mlx_xpm_file_to_image(mlx_ptr, str, &width, &height)) != NULL)
            ft_putendl("ptr null");
      if ((s.data = mlx_get_data_addr(s.ptr, &s.bpp, &s.sl, &s.endian)) == NULL)
            ft_putendl("data null");
      s.width = width;
      s.height = height;
      s.sp_size[0] = 100;
      s.sp_size[1] = 100;
      s.pos_x = 100;
      s.pos_y = 0;
      return (s);
}

t_player    init_player()
{
      t_player    p;

      p.pos_y = 2;
      p.pos_x = 1;
      p.coord_x = (float)(p.pos_x) + 0.5;
      p.coord_y = (float)(p.pos_y) + 0.5;
      p.h_view = 32;
      p.eyes_dir = M_PI_4;
      p.level = 1;
      p.score = 0;
      p.pv = 100;
      p.arms = 1;
      return (p);
}

void init_global(t_glob *global, void *mlx_ptr)
{
    t_camera    c;
    t_player    p;
 	t_map       mp;
    t_sprite    s;

	c = init_cam();
	p = init_player();
    mp = init_map();
    s = add_sprite(mlx_ptr, "src/sprite/head.xpm", 300, 100);
    global->map = mp;
    global->cam = c;
	global->player = p;
    global->txt_head = s;
}

t_img    *init_image(t_env *e, int w, int h)
{
    t_img *img;

    if (!(img = (t_img *)malloc(sizeof(t_img))))
		return (NULL);
	ft_bzero(img, sizeof(t_img));
    img->ptr = mlx_new_image(e->mlx_ptr, w, h);
	img->data = (int *)(mlx_get_data_addr(img->ptr, &img->bpp, &img->sl,
				&img->endian));
	img->size = (t_vec2){w, h};
    return (img);
}

int		ft_gettextures(void *mlx, t_txtur *data, t_vec2 size, char *path);
int	get_sprite(t_sprt *src, t_txtur txt, t_sprtinfo infos);

void init_env(t_env *e)
{
    ft_bzero(e, sizeof(t_env));
    e->mlx_ptr = mlx_init();
	e->win_ptr = mlx_new_window(e->mlx_ptr, WIDTH, HEIGHT, "Wolf3D");
    if ((e->img = init_image(e, WIDTH, HEIGHT)) == NULL)
    	ft_putstr("IMG NULL !!!!!!!!");
    e->map = &(e->global.map);
	e->cam = &(e->global.cam);
	e->player = &(e->global.player);
    e->txt_head = &(e->global.txt_head);
    init_global(&e->global, e->mlx_ptr);
	e->texture = &(e->global.texture);
	ft_gettextures(e->mlx_ptr, e->texture, (t_vec2){128, 128}, "Base.xpm");
	get_sprite(&(e->cut), *(e->texture), (t_sprtinfo){1, 106, 4, 4, 10, 2});
	ft_gettextures(e->mlx_ptr, &(e->thead),(t_vec2){100, 100}, "fhead.xpm");
	get_sprite(&(e->shead), e->thead, (t_sprtinfo){0, 0, 3, 1, 0, 0});
    e->key_right = 0;
    e->key_left = 0;
    e->key_w = 0;
    e->key_s = 0;
    e->key_a = 0;
    e->key_d = 0;
	e->key_shoot = 0;
}
