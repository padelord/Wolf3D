/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   text_box.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenaudi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 15:18:21 by crenaudi          #+#    #+#             */
/*   Updated: 2019/03/29 15:21:54 by crenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/gfx.h"

t_img *do_div(void *mlx_ptr, int x, int y, int c)
{
  t_img	*div_info;
  int   i;

  div_info = init_img(mlx_ptr, x, y);
  i = 0;
  while (i < (x * y))
    div_info->data[i++] = c;
  return (div_info);
}
