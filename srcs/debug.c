#include <unistd.h>
#include "libft.h"
#include "wolf3d.h"

void printmap(t_map *map)
{
	t_ivec2	i;
	int		curs;
	unsigned int t;
	char	buff[BUFF_SIZE];

	printf("map: %d:%d\n", map->width, map->height);
	i.y = -1;
	while (++i.y < map->height)
	{
		i.x = -1;
		while (++i.x < map->width)
		{
			curs = i.x + i.y * (map->width);
			if ((t = map->data[curs]))
			{
				if (t >> 24 > 36)
					buff[curs + i.y] = 'E';
				else
					buff[curs + i.y] = 'W';
			}
			else
				buff[curs + i.y] = '.';
		}
		buff[curs + i.y + 1] = '\n';
	}
	buff[curs + i.y] = '\0';
	ft_putendl(buff);
}
