#ifndef     WOLF_H
#define     WOLF_H

#define SUCCESS   0
#define ERROR     -1
#define WIDTH     1000
#define HEIGHT    768
#define Y_SCREEN  668
#define X_SCREEN  1000
#define H_LEGEND  650

#define EPSILON   0.06f
#define ALPHA_0   0xE6007E
#define BLOCKS    64

#define S_TXT 16384

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "mlx.h"
#include "libft.h"
#include "gfx.h"
#include "ft_keymap.h"

typedef unsigned long	t_uint64;
typedef unsigned int	t_uint;

typedef struct s_env    t_env;
typedef struct s_camera t_camera;
typedef struct s_player t_player;
typedef struct s_map    t_map;
typedef struct s_sprite t_sprite;
typedef struct s_ray    t_ray;
typedef struct s_cube   t_cube;
typedef	struct s_txtur	t_txtur;
typedef	struct s_sprt	t_sprt;
typedef	struct s_sprtinfo	t_sprtinfo;

struct		s_sprtinfo
{
	int		isanim;
	int		id;
	int		size;
	int		refresh;
	int		waitingtime;
	int		cooldown;
};

struct		s_sprt
{
	t_uint	*p;
	t_vec2	size;
	int		n;
	int		isanim;
	int		frame;
	int		wait;
	int		waitingtime;
	t_uint	gap;
	int		refresh;
	int		init;
};

struct		s_txtur
{
	t_img	imgsrc;
	void	*ptr;
	t_uint	*src;
	t_vec2	size;
	t_uint	nelem;
	int		bpp;
	int		sl;
	int		endian;
	t_uint	gap;
};

struct      s_camera
{
      float             fov;
      float             half_fov;
      float             speed_move;
      float             speed_angle;
};

struct      s_ray
{
      float               map_x;
      float               map_y;
      float             hit_x;
      float             hit_y;
      t_vecf2           ray;
	//float             ray_dist;
    t_vecf2             ray_dist;
      float             ray_angle;
	int               hit;
      float         point_hit_wall;
};

struct      s_map
{
      int		size_x;
      int		size_y;
      int		width_screen;
      int		height_screen;
      int		**data;
};

struct      s_sprite
{
    int			width;
    int			height;
    int			pos_x;
    int			pos_y;
    int			sp_size[2];
    void		*ptr;
	char		*data;
	int			bpp;
	int			sl;
	int			endian;
};

struct      s_player
{
      int         pos_x;
      int         pos_y;
      float       coord_x;
      float       coord_y;
      float       eyes_dir;
      int         h_view;
      float       dist2screen;
      int         level;
      int         score;
      int         arms;
      int         pv;
      int         dir_wall;
};

typedef struct	s_glob	t_glob;

struct		s_glob
{
	t_map		map;
      t_camera	cam;
	t_player	player;
      t_sprite    txt_head;
	  t_txtur		texture;
};

struct            s_env
{
      void        *mlx_ptr;
      void        *win_ptr;
      t_img       *img;
	t_player    *player;
      t_camera	*cam;
	t_map	      *map;
      t_sprite    *txt_head;
	  t_txtur	*texture;
	  t_txtur	thead;
	  t_sprt	shead;
	t_glob      global;
	t_sprt		cut;
      int         key_right;
      int         key_left;
      int         key_w;
      int         key_s;
      int         key_a;
      int         key_d;
	  int		key_shoot;
};

struct s_cube
{
      float		size_cube;
      float		hight;
};

int			run(t_env *e);
void		legend(t_env *e);
int			key_press(int key, t_env *e);
int			key_release(int key, t_env *e);
void		init_env(t_env *e);
t_img		*init_image(t_env *e, int w, int h);
void		init_global(t_glob *global, void *mlx_ptr);
t_camera	init_cam();
t_player	init_player();
t_map		init_map();
t_sprite	add_sprite(void *mlx_ptr, char *str, int width, int height);
int			map_int(t_env *e, int fd);

void		free_secure(void *ptr);
void		error(int err);

void		dda_dir(t_ray *r, t_player *player);
int			dda_ray(t_env *e, t_ray *r, t_player *p, t_map *map);
int			ray_cast(t_env *e, t_camera *c);
void		draw_wall(t_env *e, int x, float draw[2]);

int			move_player(t_player *plr, t_vec2 dir, t_map map, float speed);

void		clean(t_env *e);
void		clean_tab(int **map, int y);
void		clean_image(t_img *img);
void		kill_image(t_env *env);

#endif
/*
#ifndef     WOLF_H
#define     WOLF_H

#define SUCCESS   0
#define ERROR     -1
#define WIDTH     1000
#define HEIGHT    768
#define Y_SCREEN  668
#define X_SCREEN  1000
#define H_LEGEND  650

#define EPSILON   0.06f
#define ALPHA_0   0xE6007E
#define BLOCKS    64

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "mlx.h"
#include "libft.h"
#include "gfx.h"
#include "ft_keymap.h"

typedef struct s_env    t_env;
typedef struct s_camera t_camera;
typedef struct s_player t_player;
typedef struct s_map    t_map;
typedef struct s_sprite t_sprite;
typedef struct s_ray    t_ray;
typedef struct s_cube   t_cube;

struct      s_camera
{
      float             fov;
      float             half_fov;
      float             speed_move;
      float             speed_angle;
};

struct      s_ray
{
      float               map_x;
      float               map_y;
      float             hit_x;
      float             hit_y;
      t_vecf2           ray;
	float             ray_dist;
      float             ray_angle;
	int               hit;
};

struct      s_map
{
      int         size_x;
      int         size_y;
      int         width_screen;
      int         height_screen;
      int         **data;
};

struct      s_sprite
{
      int         width;
      int         height;
      int         pos_x;
      int         pos_y;
      int         sp_size[2];
      void        *ptr;
	char		*data;
	int		bpp;
	int		sl;
	int		endian;
};

struct      s_player
{
      int         pos_x;
      int         pos_y;
      float       coord_x;
      float       coord_y;
      float       eyes_dir;
      int         h_view;
      float       dist2screen;
      int         level;
      int         score;
      int         arms;
      int         pv;
      int         dir_wall;
};

typedef struct	s_glob	t_glob;

struct		s_glob
{
	t_map		map;
      t_camera	cam;
	t_player	player;
      t_sprite    txt_head;
};

struct            s_env
{
      void        *mlx_ptr;
      void        *win_ptr;
      t_img       *img;
	t_player    *player;
      t_camera	*cam;
	t_map	      *map;
      t_sprite    *txt_head;
	t_glob      global;
      int         key_right;
      int         key_left;
      int         key_w;
      int         key_s;
      int         key_a;
      int         key_d;
};

struct s_cube
{
      float       size_cube;
      float       hight;
};

int         run(t_env *e);
void        legend(t_env *e);
int         key_press(int key, t_env *e);
int         key_release(int key, t_env *e);
void        init_env(t_env *e);
t_img       *init_image(t_env *e, int w, int h);
void        init_global(t_glob *global, void *mlx_ptr);
t_camera    init_cam();
t_player    init_player();
t_map       init_map();
t_sprite    add_sprite(void *mlx_ptr, char *str, int width, int height);
int         map_int(t_env *e, int fd);

void        free_secure(void *ptr);
void        error(int err);

void 	      dda_dir(t_ray *r, t_player *player);
int 	      dda_ray(t_ray *r, t_player *p, t_map *map);
int         ray_cast(t_env *e, t_camera *c);
void        draw_wall(t_env *e, int x, float draw[2]);

int		move_player(t_player *plr, t_vec2 dir, t_map map, float speed);

void        clean(t_env *e);
void		clean_tab(int **map, int y);
void        clean_image(t_img *img);
void        kill_image(t_env *env);

#endif
*/
