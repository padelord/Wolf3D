/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenaudi <crenaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 15:18:21 by crenaudi          #+#    #+#             */
/*   Updated: 2020/03/06 16:17:57 by padelord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/gfx.h"

t_img *init_img(void *mlx_ptr, int x, int y)
{
  t_img	*img;

  if (!(img = (t_img *)malloc(sizeof(t_img))))
    return (NULL);
  ft_bzero(img, sizeof(t_img));
  img->size = (t_vec2){x, y};
  img->ptr = mlx_new_image(mlx_ptr, y, x);
	img->data = (int *)(mlx_get_data_addr(img->ptr, &img->bpp, &img->sl,
				&img->endian));
  return (img);
}
