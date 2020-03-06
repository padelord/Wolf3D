#include "../includes/wolf.h"

void		clean_image(t_img *img)
{
	ft_bzero(img->data, WIDTH * HEIGHT * (img->bpp / 8));
}

int		cleartexture(void *mlx, t_txtur *txt)
{
	mlx_destroy_image(mlx, txt->imgsrc.ptr);
	ft_bzero((void*)txt, sizeof(*txt));
}

void		kill_image(t_env *e)
{
	mlx_destroy_image(e->mlx_ptr, e->img->ptr);
	free(e->img);
	//mlx_destroy_image(e->mlx_ptr, e->player->head->src);
}

void        clean(t_env *e)
{
      clean_image(e->img);
	  cleartexture(e->mlx_ptr, e->texture);
	  cleartexture(e->mlx_ptr, &e->thead);
      kill_image(e);
      mlx_destroy_window(e->mlx_ptr, e->win_ptr);
      ft_bzero(e, sizeof(t_env));
      ft_putendl("A bientot !");
      exit(0);
}
