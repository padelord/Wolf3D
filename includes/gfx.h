/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gfx.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenaudi <crenaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 15:18:21 by crenaudi          #+#    #+#             */
/*   Updated: 2020/03/03 22:28:34 by padelord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GFX_H
# define GFX_H
# include "mlx.h"
# include <stdio.h>
# include <stdbool.h>
# include <math.h>
# include "libft.h"

typedef int		t_vec2 __attribute__((ext_vector_type(2)));
typedef float	t_vecf2 __attribute__((ext_vector_type(2)));
typedef float	t_vecf3 __attribute__((ext_vector_type(3)));
typedef float	t_vecf4 __attribute__((ext_vector_type(4)));
typedef t_vecf3			t_point;
typedef struct t_vecf4		t_q;
typedef struct s_img		t_img;
typedef struct s_color		t_color;
typedef struct s_hsl		t_hsl;
typedef union u_rgb		t_rgb;
typedef struct s_cam		t_cam;
typedef struct s_listpoint	t_listpoint;

struct					s_img
{
	void			*ptr;
	int				*data;
	int				bpp;
	int				sl;
	int				endian;
	t_vec2			size;
};

struct					s_color
{
	int		r;
	int		g;
	int		b;
	int		color;
};

struct					s_hsl
{
	int					h;
	int					s;
	int					l;
};

union s_rgb
{
  unsigned char        rgba[4];
  unsigned int         full;
};

struct					s_cam
{
	t_vecf3		right;
	t_vecf3		up;
	t_vecf3		forward;
	t_vecf3		from;
	float			fov;
};

struct				s_listpoint
{
	float				x;
	float				y;
	float				z;
	struct s_listpoint	*next;
};

float 	float_max(float *n);
float 	float_max(float *n);
t_vecf3 	rgbtoHSL(float r, float g, float b);
int 		HSLtorgb(float hue, float sat, float lum);
t_img 	*init_img(void *mlx_ptr, int x, int y);
t_img 	*do_div(void *mlx_ptr, int x, int y, int c);
float		vec2_dist(t_vec2 v2);
t_color	init_c(int color);
int		lerp_c(t_color s, t_color e, float t);
int		lerp_non_init_color(int a, int b, float t);
float		deg2rad(float d);
float		rad2deg(float r);
void		scale(t_point *p, float e);
float		dot_product(t_vecf3 a, t_vecf3 b);
t_point	cross_product(t_vecf3 a, t_vecf3 b);
void		rotate_x(t_point *p, float a);
void		rotate_y(t_point *p, float a);
void		rotate_z(t_point *p, float a);
t_point	normalize(t_point v);
float		spherical_theta(t_point v);
float		spherical_phi(t_point v);
t_point	to_vec_spherical(t_point v);
void		spherical_perspective(t_point v, t_point *p);
t_cam      	*init_camera();
void 		clean_camera(t_cam *c);
void       	matrice_camera(t_cam *c, t_vecf3 from, t_vecf3 to, t_vecf3 tmp);
bool 		quaternion_equal(t_q *q1, t_q *q2);

#endif
