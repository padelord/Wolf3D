#include <unistd.h>
#include "libft.h"
#include "mlx.h"
#include "wolf3d.h"

#define NT 32
#define DH HEIGHT / 2
#define DW WIDTH / 2
#define ST (HEIGHT * WIDTH / NT)
#define HT HEIGHT / NT



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
		draw_wcol(buffer++, i/3 + 100, tex + (i % TEXW));
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



void apply_text(t_texture src, t_texture dst, t_ivec2 pos)
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

void draw_hbg(unsigned int *buffer, int al)
{
	unsigned int	color;
	int				i;
	int				size;

	color = (al ? 0x00FFFFFF : 0xFFFFFFFF);
	size = WIDTH * (HEIGHT / 2);
	i = -1;
	while (++i < size)
		buffer[i] = color;
}

void test()
{
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
	int		bpp, sl, endian;
	int		tbpp, tsl, tendian;

	void	*mlx;
	void 	*win;
	void	*img1;
	void	*img2;
	void	*img3;
	char	*buffer;
	unsigned int	*buffer2;
	unsigned int	*buffer3;
	char	*btex;
	int		frame = 105;
	int		x = 0, y = 0;
	mlx = mlx_init();
	win = mlx_new_window(mlx, WIDTH, HEIGHT, "Wolf3D");
	img1 = mlx_new_image(mlx, WIDTH, HEIGHT);
	buffer = mlx_get_data_addr(img1, &bpp, &sl, &endian);
	printf("bpp : %d\nsl  : %d\nend : %d\n", bpp, sl, endian);
	img2 = mlx_new_image(mlx, WIDTH / 2, HEIGHT);
	buffer2 = mlx_get_data_addr(img2, &bpp, &sl, &endian);
	img3 = mlx_new_image(mlx, WIDTH / 2, HEIGHT);
	buffer3 = mlx_get_data_addr(img3, &bpp, &sl, &endian);
	draw_bg((unsigned long int*)buffer);
	draw_hbg(buffer2, 0);
	draw_hbg(buffer3, 1);
	mlx_put_image_to_window(mlx, win, img1, 0, 0);
	mlx_put_image_to_window(mlx, win, img2, WIDTH / 2, 0);
	mlx_put_image_to_window(mlx, win, img3, 0, 0);
	mlx_do_sync(mlx);
	usleep(3000000);

	mlx_destroy_image(mlx, img1);
	mlx_destroy_image(mlx, img2);
	mlx_destroy_image(mlx, img3);
	mlx_destroy_window(mlx, win);
	return ;
	ft_putendl("on va prendre l'image");

/*
	if (!(img2 = mlx_xpm_file_to_image(mlx, "Resources.xpm", &x, &y)))
		ft_putendl("ya pa dimaj");
	else
		ft_putendl("ya une imaj");
*/
	printf("Resources.xpm : %dx%d\n", x, y);
//	btex = mlx_get_data_addr(img2, &tbpp, &tsl, &tendian);

//	draw_wall((unsigned int*)buffer, (unsigned int*)btex);

	#define EPSI 128 * 128 * 4
	int	i;
	t_texture	t1, t2;
	t2 = (t_texture){(unsigned int*)buffer, WIDTH, HEIGHT};
	i = -1;
	while (++i < frame)
	{
		t1 = (t_texture){(unsigned int*)btex, 128, 128};
		apply_text(t1, t2, (t_ivec2){i % 16 * 128, i / 16 * 128});
		btex += EPSI;
		usleep(50000);
		mlx_put_image_to_window(mlx, win, img1, 0, 0);
	}
	usleep(50000);

	mlx_destroy_image(mlx, img1);
	mlx_destroy_image(mlx, img2);
	mlx_destroy_window(mlx, win);
}
