/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenaudi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 15:18:21 by crenaudi          #+#    #+#             */
/*   Updated: 2019/03/29 15:21:54 by crenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/gfx.h"

t_cam       *init_camera()
{
      t_cam *c;

      if (!(c = (t_cam *)malloc(sizeof(t_cam))))
        return (NULL);
      ft_bzero(c, sizeof(t_cam));
      return (c);
}

void       clean_camera(t_cam *c)
{
      ft_bzero(c, sizeof(t_cam));
}

void       matrice_camera(t_cam *c, t_vecf3 from, t_vecf3 to, t_vecf3 tmp)
{
      t_vecf3 forward;
      t_vecf3 right;
      t_vecf3 up;

      tmp.x = 0.0;
      tmp.y = 1.0;
      tmp.z = 0.0;
      forward = normalize(from - to);
      right = cross_product(normalize(tmp), forward);
      if (right.x == 0.0)
            right.x = 1.0;
      up = cross_product(forward, right);

      c->right = right;
      c->up = up;
      c->forward = forward;
      c->from = from;
      c->fov = 60;
}
