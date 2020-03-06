#include "../includes/wolf.h"

static void        print_map(int **map, t_vec2 i)
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

static int  **compil_map(t_vec2 index, char *comp)
{
      int **ord;
      int *abc;
      int x;
      int y;

      if (!(ord = (int **)malloc(sizeof(int *) * index.y)))
            return NULL;
      y = -1;
      while (++y < index.y)
      {
            if (!(abc = (int *)malloc(sizeof(int) * index.x)))
                  return NULL;
            x = -1;
            while (++x < index.x)
            {
                  abc[x] = (*comp == '0') ? 0 : 1;
                  comp++;
            }
            ord[y] = abc;
      }
      return (ord);
}

static int info_map(t_env *e, t_vec2 i, char *comp)
{
      printf("i = %d, %d\n", i.x, i.y);
      e->map->size_x = i.x;
      e->map->size_y = i.y;
      e->map->width_screen = i.y * BLOCKS;
      e->map->height_screen = i.x * BLOCKS;
      if ((e->map->data = compil_map(i, comp)) == NULL)
            return (ERROR);
      print_map(e->map->data, i);
      return (SUCCESS);
}

int map_int(t_env *e, int fd)
{
      char *line;
      char *lfree;
      char *comp;
      t_vec2  i;

      i = 0;
      line = NULL;
      lfree = NULL;
      comp = NULL;
      while (get_next_line(fd, &line) == 1)
      {
            if (i.x == 0)
                  i.x = ft_strlen(line);
            if ((int)(ft_strlen(line)) != i.x)
                  error(-1);
            comp = (comp == NULL) ? ft_strdup(line) : ft_strjoin(comp, line);
            lfree = line;
            free(lfree);
            i.y += 1;
      }
      if (info_map(e, i, comp) == ERROR)
            return (ERROR);
      free(comp);
      return (SUCCESS);
}
