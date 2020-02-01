/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: padelord <padelord@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 17:14:57 by padelord          #+#    #+#             */
/*   Updated: 2019/11/05 18:31:14 by padelord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# define P_NAME "fract_ol"
# include "ft_keymap.h"
# include "libft.h"
# include <time.h>
# include <sys/time.h>
# include <pthread.h>
# define ST_MASK 1
# define ST_FRCT 2
# define ST_DSPL 4
# define MAXZOOM 15372286728091294000ul
# define NTHF 64
# define NTHM 8
# define EPSI (WINX * WINY / NTHM)
# define WINX 512
# define WINY 512
# define HWINX WINX / 2
# define HWINY WINY / 2
# define PTFSIZE WINX * WINY / NTHF
# define SPAL 360

typedef	long double		t_complx __attribute__((ext_vector_type(2)));
typedef int				t_vec3 __attribute__((ext_vector_type(3)));

typedef	struct s_fract	t_fract;

typedef struct			s_fractinfo
{
	int					*mask;
	int					size;
	t_vec3				curs;
	t_fract				*fract;
}						t_fractinfo;

struct					s_fract
{
	int					(*cp)(t_vec3, t_fract*);
	unsigned char		type;
	unsigned char		state;
	t_complx			mouse;
	t_complx			mod;
	int					maxit;
	unsigned long int	zoom;
	t_fractinfo			infos[NTHF];
	unsigned int		hue;
	float				lrt;
};

typedef struct			s_ptmask
{
	int					size;
	int					*mask;
	unsigned int		*buff;
	int					mod;
	unsigned int		*pal;
}						t_ptmask;

typedef struct			s_frate
{
	long int			prev;
	int					frame;
	int					fps;
}						t_frate;

typedef	struct			s_fps
{
	struct timeval		start;
	struct timeval		end;
	int					frame;
	float				dif;
	int					stime;
}						t_fps;

typedef union			u_color
{
	unsigned int		full;
	unsigned char		bgra[4];
}						t_color;

typedef struct			s_img
{
	void				*ptr;
	t_vec3				size;
	int					bpp;
	int					sl;
	int					endian;
	t_color				*buffer;
	unsigned char		state;
	int					*mask;
	unsigned int		pal[360];
}						t_img;

typedef	struct			s_win
{
	void				*ptr;
	int					x;
	int					y;
	char				*title;
}						t_win;

typedef struct			s_env
{
	void				*mlx;
	t_win				win;
	t_img				img;
	t_fract				fract;
	t_fps				fps;
}						t_env;

/*
** main.c
*/

float					timedifference_msec(struct timeval t0,
											struct timeval t1);
int						checktype(char *param);

/*
** init.c
*/

void					init_fract(t_env *env, t_fract *fract, int type);
int						fx_new_image(t_img *t, void *mlx, int x, int y);
int						fx_new_window(t_win *t, void *mlx, int x, int y);
int						fx_init_env(t_env *env, int x, int y, int type);
int						fx_close_env(t_env *env, int stop);

/*
**	color.c
*/

unsigned int			fx_gethslcolor(int hue, float sat, float lum);
void					fx_getpal(unsigned int *pal, int size);

/*
** hooks.c :
*/

int						fx_close_hook(void *param);
void					fx_update_fract(int keycode, t_env *env);
int						fx_key_hook(int keycode, void *param);
int						fx_mouse_hook(int button, int x, int y, void *param);
int						fx_loop_hook(void *param);

/*
** draw.c
*/

int						pixel_julia(t_vec3 curs, t_fract *dt);
int						pixel_brotcube(t_vec3 curs, t_fract *dt);
int						pixel_brot(t_vec3 curs, t_fract *dt);
void					*fx_threadmask(void *src);
void					fx_applymask(t_env *env, int mod);

/*
**	fract.c
*/

int						juliamouse(int x, int y, void *data);
t_complx				complex_mult(t_complx v1, t_complx v2);
void					*calc_fractpart(void *src);
void					fract_reset(t_fract *fract);
void					fract_prepare(t_env *env);

/*
**	display.c
*/

void					fract_putkeycodes(void);
void					fx_putname(t_env *env);
void					fx_putvalue(t_env *env, int fps);
int						fx_fps(int isframe);
void					fx_display(t_env *env);

#endif
