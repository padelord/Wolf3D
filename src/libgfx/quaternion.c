/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quaternion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenaudi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 15:15:48 by crenaudi          #+#    #+#             */
/*   Updated: 2019/03/29 15:16:42 by crenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/gfx.h"

float   norm_quaternion_norm(t_q *q)
{
      if (q == NULL)
            return(0.0);
      return (ft_sqrt(q.a * q.a + q.b * q.b + q.c * q.c + q.d * q.d));
}

void quaternion_neg(t_q *r, t_q *q)
{
  if (q == NULL || r == NULL)
      return;
  r.a = -q.a;
  r.b = -q.b;
  r.c = -q.c;
  r.d = -q.d;
}

t_q   *add_real_num(float r, t_q *q)
{
  q.a = q.a + r;
  return (q);
}

t_q   *quaternion_mult_real_num(t_q *q)
{
      float r;

      r = 0.0;
      q.a = q.a * r;
      q.b = q.b * r;
      q.c = q.c * r;
      q.d = q.d * r;
      return (q);
}

t_q   *quaternion_add(t_q *q1, t_q *q2)
{
  t_q *q;

  q.a = q1.a + q2.a;
  q.b = q1.b + q2.b;
  q.c = q1.c + q2.c;
  q.d = q1.d + q2.d;
  return (q);
}

t_q   *quaternion_mult(t_q *q1, t_q *q2)
{
  t_q *q;

  if (q1 == NULL || q2 == NULL)
      return;
  q.a = (q1.a * q2.a) - (q1.b * q2.b) - (q1.c * q2.c) - (q1.d * q2.d);
  q.b = (q1.a * q2.b) + (q1.b * q2.a) + (q1.c * q2.d) - (q1.d * q2.c);
  q.c = (q1.a * q2.c) - (q1.b * q2.d) + (q1.c * q2.a) + (q1.d * q2.b);
  q.d = (q1.a * q2.d) + (q1.b * q2.c) - (q1.c * q2.b) + (q1.d * q2.a);
  return (q);
}

bool quaternion_equal(t_q *q1, t_q *q2)
{
  if (q1.a != q2.a || q1.b != q2.b || q1.c != q2.c || q1.d != q2.d)
      return false;
  return true;
}
