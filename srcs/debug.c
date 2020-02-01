#include <unistd.h>
#include "libft.h"
#include "wolf3d.h"

void printmap(t_map *map)
{
	int		i;

	i = -1;
	while (++i<map->height)
	{
		write(1, (map->data) + i * map->width, map->width);
		write(1, "\n", 1);
	}
}
