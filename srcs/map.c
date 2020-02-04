#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include "wolf3d.h"
#include "libft.h"

int		get_validmap(t_map *map, char *buffer)
{
	unsigned int	*p;
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
				*p++ = IWALL;
			else if (*buffer == PLR)
			{
				map->orig = (t_ivec2){x, y};
				*p++ = 0;
				buffer++;
			}
			else
				*p++ = (*buffer++ == FLOOR ? 0 : IWALL);
		}
		buffer++;
	}
	return (0);
}

int		check_player(t_map *map, char *buffer, t_ivec2 size)
{
	int	count;
	int	i;
	t_ivec2	pos;

	map->height = size.y;
	map->width = size.x;
	count = 0;
	pos.y = 0;
	i = -1;
	while (buffer[++i])
	{
		pos.x = 0;
		if (buffer[i] == PLR)
		{
			if (count++)
				return (0);
			pos.x++;
		}
		pos.y++;
	}
	printf("orig: %d:%d\n", map->orig.x, map->orig.y);
	return (1);
}

int		valid_map(t_map *map, char *buffer)
{
	int	tline;
	char	*t;
	t_ivec2	i;

	tline = 0;
	i = (t_ivec2){0, 0};
	t = buffer;
	while (*t)
	{
		if (*t == '\n')
		{
			if (tline > i.x)
				i.x = --tline;
			tline = 0;
			i.y++;
		}
		tline++;
		t++;
	}
	if (!(map->data = malloc(sizeof(int) * i.x * i.y)))
		return (R_MAP_MALC);//TODO: malloc foireux
	ft_bzero((void*)(map->data), sizeof(int) * i.x * i.y);
	if (!(check_player(map, buffer, i)))
		return (R_MAP_PLYR);
	return (get_validmap(map, buffer));
}

int		get_map(const char *name, t_map *map)
{
	char	buffer[BUFF_SIZE];
	int		fd;
	int		i;

	if ((fd = open(name, O_RDONLY)) == -1)
		return (R_MAP_OPEN);
	if ((i = read(fd, buffer, BUFF_SIZE)) == BUFF_SIZE)
		return (R_MAP_READ);
	buffer[i] = '\0';
	while (i--)
	{
		if (!(buffer[i] == FLOOR || buffer[i] == WALL || buffer[i] == PLR
			|| buffer[i] == '\n'))
			return (R_MAP_CHAR);
	}
	return (valid_map(map, buffer));
}

void	delete_map(t_map *data)
{
	ft_bzero(data->data, sizeof(int) * data->height * data->width);
	free(data->data);
	ft_bzero(data, sizeof(t_map) + data->height * data->width);
}
