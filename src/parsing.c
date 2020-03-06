
#include "../includes/wolf.h"

t_listpoint		*add_point(int x, int y, int z)
{
	t_listpoint		*p;

	p = (t_listpoint *)malloc(sizeof(t_listpoint));
	p->x = (float)x;
	p->y = (float)y;
	p->z = (float)z;
	p->next = NULL;
	return (p);
}

static void		coordonees(char **line, t_env *env, int x, int y)
{
	t_listpoint		*p;
	int		z;

	z = ft_atoi(*line);
	p = add_point(x, y, z);
	if (env->p == NULL)
		env->p = p;
	else
	{
		p->next = env->p;
		env->p = p;
	}
	while (**line != ' ' && **line != '\0')
		(*line)++;
}

static t_point	**make_tab(int y, t_env *env)
{
	t_point		**tab;
	t_point		*point;
	t_listpoint		*p;
	int			x;

	y = env->y_max;
	p = env->p;
	if (!(tab = (t_point **)malloc(sizeof(t_point *) * env->y_max)))
		return (NULL);
	while (y--)
	{
		x = env->x_max;
		if (!(point = (t_point *)malloc(sizeof(t_point) * env->x_max)))
			return (NULL);
		tab[y] = point;
		while (x--)
		{
			point[x].x = p->x;
			point[x].y = p->y;
			point[x].z = p->z;
			p = p->next;
		}
	}
	return (tab);
}

static void		complete_env(t_env *env, int x, int y)
{
	env->x_max = x;
	env->y_max = y;
	env->map = make_tab(-1, env);
	//env->tab_m = make_tab(-1, env);
}

int			parsing(int fd, t_env *env)
{
	char	*line2;
	t_listpoint		*p;
	t_vec2	index;

	index.y = 0;
	p = NULL;
	env->p = p;
	while (get_next_line(fd, &env->line) == 1)
	{
		line2 = env->line;
		index.x = 0;
		while (*env->line != '\0')
		{
			while (*env->line == ' ')
				env->line++;
			if (*env->line == '\0')
				break ;
			coordonees(&env->line, env, index.x, index.y);
			index.x++;
		}
		free(line2);
		index.y++;
	}
	complete_env(env, index.x, index.y);
	return (SUCCESS);
}
