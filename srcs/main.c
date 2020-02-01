#include "libft.h"
#include "mlx.h"
#include "wolf3d.h"
#include <unistd.h>
#include <math.h>
#include <pthread.h>


#define NT 32
#define DH HEIGHT / 2
#define DW WIDTH / 2
#define ST (HEIGHT * WIDTH / NT)
#define HT HEIGHT / NT


# define FC_SKY 0xFF3F3F3FFF3F3F3F
# define FC_FLOOR 0XFF980088FF980088
# define FC_FLOOR 0xFF727272FF727272

void	draw_bg(unsigned long int *buffer)
{
	int	i;
	int	limit;

	limit = WIDTH * HEIGHT / 4;
	i = -1;
	while (++i < limit)
		buffer[i] = FC_SKY;
	limit = WIDTH * HEIGHT / 2;
	i--;
	while (++i < limit)
		buffer[i] = FC_FLOOR;
}

#define TEXW 128
#define TEXH 128

void	draw_wcol(unsigned int *buffer, int size, unsigned int *tex)
{
	int	i;

	if (size > HEIGHT)
		size = HEIGHT;
	else
	{
		buffer += (HEIGHT - size) / 2 * WIDTH;
	}
	i = -1;
	while (++i < size)
	{
		*buffer = *(tex + (TEXW * i / size) * TEXW);
		buffer += WIDTH;
	}
}

void	draw_wall(unsigned int *buffer, unsigned int *tex)
{
	int	i;

	i = -1;
	while (++i < WIDTH)
	{
		draw_wcol(buffer++, i/3 + 100, tex + (i/TEXW + i % TEXW));
	}
}

void print_bchar(unsigned char c)
{
	int		i;
	char	buff[9];

	i = -1;
	while (++i < 8)
		buff[7 - i] = (((1U << i) & c) ? '1' : '0');
	write(1, buff, 8);
}

void test()
{
	unsigned char	a, curs;

	printf("0^0=%c\n", (0^0 ? '1':'0'));
	printf("1^0=%c\n", (1^0 ? '1':'0'));
	printf("0^1=%c\n", (0^1 ? '1':'0'));
	printf("1^1=%c\n", (1^1 ? '1':'0'));
	printf("\n");
	printf("0|0=%c\n", (0|0 ? '1':'0'));
	printf("1|0=%c\n", (1|0 ? '1':'0'));
	printf("0|1=%c\n", (0|1 ? '1':'0'));
	printf("1|1=%c\n", (1|1 ? '1':'0'));
	printf("\n");
	printf("0&0=%c\n", (0&0 ? '1':'0'));
	printf("1&0=%c\n", (1&0 ? '1':'0'));
	printf("0&1=%c\n", (0&1 ? '1':'0'));
	printf("1&1=%c\n", (1&1 ? '1':'0'));
	printf("\n");
	printf("~0=%c\n", (~0 ? '1':'0'));
	printf("~1=%c\n", (~1 ? '1':'0'));
	printf("\n");
	printf("!0=%c\n", (!0 ? '1':'0'));
	printf("!1=%c\n", (!1 ? '1':'0'));
	print_bchar(35);
	printf("\n");
}

void printerror(int code, char **msg)
{
	int	i;

	while (++i < R_MAX)
	{
		printf("pe code = %d\ti=%d\n", code, i);
		if (code == i)
		{
			printf("mabite\n");
			ft_putendl(msg[i - 1]);
		}
	}
}

void handle_error(int code)
{
	code = code * -1 - 1;
	printerror(code,(char*[]){"Unable to open file", "Unable to read file", "Map error: Bad character", "Map error: to much players", "Map error: Can't malloc"});
}
int	get_tex(unsigned int *tex, unsigned int *rend, t_ivec2 size, t_ivec2 data)
{
	t_ivec2	i;

	i.y = -1;
	while (++i.y < size.y)
	{
		i.x = -1;
		while (++i.x < size.x)
		{
			*rend++ = *tex++;
		}
		tex += data.x - size.x;
	}
	return (1);
}

typedef struct	s_texture
{
	unsigned int	*pixels;
	int				w;
	int				h;
}				t_texture;

void apply_text(t_texture src, t_texture dst, t_ivec2 pos, t_vec2 scale)
{
	t_ivec2	i;
	t_ivec2	j;
	int		cas;

	if (src.w + pos.x > dst.w || src.h + pos.y > dst.h)
		return ;
	i.y = -1;
	j.y = pos.y;
	while (++i.y < src.h)
	{
		i.x = -1;
		j.x = pos.x;
		while (++i.x < src.w)
		{
			cas = i.x + i.y * src.w;
			if (src.pixels[cas] != C_TRANSP)
				dst.pixels[j.x + j.y * dst.w] = src.pixels[cas];
			j.x++;
		}
		j.y++;
	}
}

int   main(int ac, char **av)
{
	t_env	env;
	int		bpp, sl, endian;
	int		tbpp, tsl, tendian;

	void	*mlx;
	void 	*win;
	void	*img1;
	void	*img2;
	void	*img3;
	char	*buffer;
	char	*btex;
	char	*btmp;
	int		err;
	int		frame = 37;
	int		x = 0, y = 0;
	test();
	if (ac == 2)
	{
		if (!(err = init_env(&env, av[1])))
		{
			printf("It worked!!!\n");
			printf("close code: %d\n", close_env(&env));
		}
		else
		{
			printf("Error : %d\n", err);
			handle_error(err);
		}
		close_env(&env);
	}
	else
	{
	mlx = mlx_init();
	win = mlx_new_window(mlx, WIDTH, HEIGHT, "Wolf3D");
	img1 = mlx_new_image(mlx, WIDTH, HEIGHT);
	buffer = mlx_get_data_addr(img1, &bpp, &sl, &endian);
	printf("bpp : %d\nsl  : %d\nend : %d\n", bpp, sl, endian);
	draw_bg((unsigned long int*)buffer);

	ft_putendl("on va prendre l'image");
	if (!(img2 = mlx_xpm_file_to_image(mlx, "Resources.xpm", &x, &y)))
		ft_putendl("ya pa dimaj");
	else
		ft_putendl("ya une imaj");
	printf("Resources.xpm : %dx%d\n", x, y);
	btex = mlx_get_data_addr(img2, &tbpp, &tsl, &tendian);

	draw_wall((unsigned int*)buffer, btex);

//	img3 = mlx_new_image(mlx, 128, 128);
//	btmp = mlx_get_data_addr(img3, &bpp, &sl, &endian);
#define EPSI 128 * 128 * 4
	int	i;
	t_texture	t1, t2;
	t2 = (t_texture){buffer, WIDTH, HEIGHT};
	i = -1;
	while (++i < frame)
	{
//		get_tex((unsigned int *)btex, btmp, (t_ivec2){128,128}, (t_ivec2){x, y});
		t1 = (t_texture){btex, 128, 128};
		apply_text(t1, t2, (t_ivec2){i * 100, i * 18}, 0);
		btex += EPSI;
//		mlx_put_image_to_window(mlx, win, img3, 0, 0);
		mlx_put_image_to_window(mlx, win, img1, 0, 0);
		usleep(500000);
	}
	usleep(5000000);

	mlx_destroy_image(mlx, img1);
	mlx_destroy_image(mlx, img2);
//	mlx_destroy_image(mlx, img3);
	mlx_destroy_window(mlx, win);
	}
    return 0;
}
