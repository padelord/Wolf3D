#include "wolf3d.h"

void	draw_bg(unsigned long int *buffer)
{
	int	i;
	int	limit;

	limit = WIDTH * HEIGHT / 4;
	i = -1;
	while (++i < limit)
		buffer[i] = FC_SKY;
	limit = WIDTH * HEIGHT / 2;
	i--;
	while (++i < limit)
		buffer[i] = FC_FLOOR;
}
