#include "../includes/wolf.h"


int		ft_gettexturesrc(void *mlx, t_img *img, char *path)
{
	int	x;
	int	y;

	img->ptr = mlx_xpm_file_to_image(mlx, path, &x, &y);
	img->data = (int*)mlx_get_data_addr(img->ptr, &(img->bpp), &(img->sl), &(img->endian));
	img->size = (t_vec2){x, y};
	return (SUCCESS);
}

int		ft_gettextures(void *mlx, t_txtur *data, t_vec2 size, char *path)
{
	ft_gettexturesrc(mlx, &(data->imgsrc), path);
	data->ptr = data->imgsrc.ptr;
	data->src = (t_uint*)data->imgsrc.data;
	data->size = size;
	data->nelem = data->imgsrc.size.y / size.y;
	data->gap = size.x * size.y;
	return (SUCCESS);
}

int		get_sprite(t_sprt *src, t_txtur txt, t_sprtinfo infos)
{
	if (infos.id + infos.size > txt.nelem)
		return (ERROR);
	src->p = txt.src + infos.id * txt.gap;
	src->size = txt.size;
	src->n = infos.size;
	src->frame = -1;
	src->wait = 0;
	src->refresh = infos.refresh;
	src->waitingtime = infos.waitingtime;
	src->init = infos.cooldown * -1;
	src->isanim = infos.isanim;
	src->gap = txt.gap;
	return (SUCCESS);
}

int		apply(t_img *src, t_uint *txt, t_vec2 size, t_vec2 pos)
{
	t_uint	*data;
	int		orig;

	if (src->size.x < pos.x + size.x || src->size.y < pos.y + size.y)
		return (ERROR);
	data = (t_uint*)src->data + (pos.x + pos.y * src->size.x);
	orig = size.x;
	while (size.y--)
	{
		while (size.x--)
		{
			if (*txt != 0x980088)
				*data = *txt;
			data++;
			txt++;
		}
		size.x = orig;
		data += src->size.x - size.x;
	}
	return (SUCCESS);
}

int		put_sprt_to_img(t_img *src, t_sprt *sprite, t_vec2 pos)
{
	int		dest;

	if (sprite->frame == -1)
	{
		if (sprite->wait < sprite->waitingtime)
			sprite->wait++;
		return (apply(src, sprite->p, sprite->size, pos));
	}
	if (!(sprite->isanim))
		return (apply(src, sprite->p + sprite->frame * sprite->gap, sprite->size, pos));
	if (++sprite->wait >= sprite->waitingtime)
	{
		if (++sprite->frame >= sprite->refresh)
			sprite->frame = sprite->init;
		sprite->wait = 0;
	}
	if (sprite->frame >= 0)
		dest = apply(src, sprite->p + sprite->frame * sprite->gap, sprite->size, pos);
	else
		dest = apply(src, sprite->p, sprite->size, pos);
	return (dest);
}

int		put_txture_to_img(t_img *src, t_txtur *texture, t_vec2 pos, int id)
{
	t_vec2	end;
	t_vec2	i;
	t_uint	*data;
	t_uint	*txt;

	end = texture->size + pos;
	if (end.x > src->size.x || end.y > src->size.y)
		return (0);
	data = (t_uint*)(src->data) + src->size.x * pos.y + pos.x;
	txt = texture->src + texture->gap * id;
	apply(src, txt, texture->size, pos);
	return (1);
}
