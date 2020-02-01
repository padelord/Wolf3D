#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include "wolf3d.h"
#include "libft.h"

int		get_validmap(t_map *map, char *buffer)
{
	char	*p;
	int		x;
	int		y;

	p = map->data;
	y  = -1;
	while (++y < map->height)
	{
		x = -1;
		while (++x < map->width)
		{
			if (*buffer == '\n')
				*p++ = WALL;
			else
				*p++ = *buffer++;
		}
		buffer++;
	}
	return (0);
}

int		check_player(t_map *map, char *buffer)
{
	int	count;
	int	i;

	count = 0;
	i = -1;
	while (buffer[++i])
	{
		if (buffer[i] == PLR)
		{
			if (count++)
				return (0);
			buffer[i] = PLR;
			map->orig = (t_ivec2){i % WIDTH, i / WIDTH};
		}
	}
	return (1);
}

int		valid_map(t_map *map, char *buffer)
{
	int	tline;
	char	*t;

	t = buffer;
	tline = 0;
	while (*t)
	{
		if (*t == '\n')
		{
			if (tline > map->width)
				map->width = --tline;
			tline = 0;
			map->height++;
		}
		tline++;
		if (!(*t == FLOOR || *t == WALL || *t == PLR || *t == '\n'))
			return (-3);
		t++;
	}
	if (!(check_player(map, buffer)))
		return (-4);
	if (!(map->data = malloc(map->width * map->height)))
		return (-5);//TODO: malloc foireux
	return (get_validmap(map, buffer));
}

int		get_map(const char *name, t_map *map)
{
	char	buffer[BUFF_SIZE];
	int		fd;
	int		i;

	ft_bzero((void*)map, sizeof(t_map));
	if ((fd = open(name, O_RDONLY)) == -1)
	{
		return (-1);//TODO: Open foireux
	}
	if ((i = read(fd, buffer, BUFF_SIZE)) == BUFF_SIZE)
		return (-2);//TODO: Read foireux
	buffer[i] = '\0';
	return (valid_map(map, buffer));
}

void	delete_map(t_map *data)
{
	ft_bzero(data->data, data->height * data->width);
	free(data->data);
	ft_bzero(data, sizeof(t_map));
}
