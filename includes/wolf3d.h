#ifndef WOLF3D_H
# define WOLF3D_H
# define PNAME "Wolfenstein 3D"
# define HEIGHT 1080
# define WIDTH 1920
# define WALL 'W'
# define FLOOR '.'
# define PLR 'P'
# define C_TRANSP 9961608U
#include <stdio.h>

typedef float	t_vec4 __attribute__((ext_vector_type(4)));
typedef float	t_vec2 __attribute__((ext_vector_type(2)));
typedef int		t_ivec4 __attribute__((ext_vector_type(4)));
typedef int		t_ivec2 __attribute__((ext_vector_type(2)));

typedef struct	s_plr	t_plr;
typedef struct	s_map	t_map;
typedef struct	s_img	t_img;
typedef struct	s_env	t_env;

typedef enum	e_state	t_state;

enum	e_state
{
	ST_INIT_MAP = 1U << 0,
	ST_INIT_MLX = 1U << 1,
	ST_INIT_WIN = 1U << 2,
	ST_INIT_IMG = 1U << 3,
	ST_INIT_PLR = 1U << 4
};

enum	e_err
{
	R_MAP_OPEN = 1,
	R_MAP_READ,
	R_MAP_CHAR,
	R_MAP_PLYR,
	R_MAP_MALC,
	R_PLR_MALC,
	R_MAX
};

struct					s_plr
{
	t_vec2				pos;
	float				a;
};

struct					s_map
{
	int			height;
	int			width;
	t_ivec2		orig;
	char		*data;
};

struct	s_img
{
	void	*ptr;
	int		w;
	int		h;
	int		bpp;
	int		sl;
	int		endian;
	char	*buffer;
};

struct	s_env
{
	int		state;
	void	*mlx;
	t_img	*img;
	void	*win;
	t_plr	*plr;
	t_map	map;
};

/*
**	debug.c
*/

void	printmap(t_map *map);

/*
**	map.c :
*/

int		get_map(const char *name, t_map *map);
void	delete_map(t_map *data);

/*
**	color.c :
*/

unsigned int		fx_gethslcolor(int hue, float sat, float lum);
void				fx_getpal(unsigned int *pal, int size);

/*
**	init.c :
*/

int		init_env(t_env *env, const char *path);
#endif
