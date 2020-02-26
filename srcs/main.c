#include <unistd.h>
#include <math.h>
#include "libft.h"
#include "mlx.h"
#include "wolf3d.h"

void printerror(int code, char *msg[])
{
	int	i;

	i = 0;
	while (++i < R_MAX)
	{
		if (code == i)
			ft_putendl(msg[i - 1]);
	}
}

void handle_error(int code)
{
	printerror(code,(char*[]){"Unable to open file", "Unable to read file", "Map error: Bad character", "Map error: Bad player", "Map error: Can't malloc", "Player error: Can't malloc", "Mlx error: mlx_init() failed", "Window error: Can't create"});
}

int   main(int ac, char **av)
{
	t_env	env;
	int		err;

	if (ac == 2)
	{
		if (!ft_strcmp(av[1], "test"))
			test();
		else if (!(err = init_env(&env, av[1])))
		{
			printmap(env.map);
			mlx_loop(env.mlx);
			close_env(&env, 1);
		}
		else
		{
			handle_error(err);
			close_env(&env, 0);
		}
	}
	else
		ft_putendl(USAGE);
    return 0;
}
