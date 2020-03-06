#include "../includes/wolf.h"

void        free_secure(void *ptr)
{
      if (ptr != NULL)
      {
            free(ptr);
            ptr = NULL;
      }
      else
            ft_putendl("Free sur ptr NULL");
}
/*
void        print_map(int **map, t_vec2 i)
{
      int   x;
      int   y;

      ft_putendl("Map :");
      y = -1;
      while (++y < i.y)
      {
            x = -1;
            while (++x < i.x)
            {
                  if (map[y][x] == 0)
                        ft_putchar('.');
                  else
                        ft_putchar('o');
            }
            ft_putchar('\n');
       }
       ft_putchar('\n');
}

static void put_square(t_img *img, int width, int height, int color)
{
      int   x;
      int   y;
      int	index;

      y = -1;
      while (++y < WALL_MAP)
      {
            x = -1;
            while (++x < WALL_MAP)
            {
                  index = (width + x) + ((height + y) * WIDTH);
                  if (index < 0 || index >= WIDTH * HEIGHT)
            		return ;
                  img->data[index] = color;
            }
      }
}

void        mapONscreen(t_env *e)
{
      t_vec2 mp;
      t_vec2 px;


      mp = -1;
      px.y = (HEIGHT / 2) - ((e->size_map.y * WALL_MAP) / 2);
      while (++mp.y < e->size_map.y)
      {
            mp.x = -1;
            px.x = (WIDTH / 2) - ((e->size_map.x * WALL_MAP) / 2);
            while (++mp.x < e->size_map.x)
            {

                  if (e->map[mp.y][mp.x] == 0)
                        put_square(e->img, px.x, px.y, 0x112233);
                  else
                        put_square(e->img, px.x, px.y, 0x663322);
                  px.x += WALL_MAP;
            }
            px.y += WALL_MAP;
       }
}*/
