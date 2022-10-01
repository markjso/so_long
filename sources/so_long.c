/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarks <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 15:53:39 by jmarks            #+#    #+#             */
/*   Updated: 2022/09/28 16:16:30 by jmarks           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	init_components(t_map *map)
{
	map->pcount = 0;
	map->ccount = 0;
	map->ecount = 0;
	map->end = 0;
	map->counter = 0;
	map->steps = 1;
}

int	check_map_file(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	if (str[i - 1] != 'r' && str[i - 2] != 'e'
			&& str[i - 3] != 'b' && str[i - 4] != '.')
	{
		closeprogram("Map must be a .ber file\n");
		return (1);
	}
	return (0);
}

t_map	*read_map(char *argv )
{
	t_map 	*new;
	int		y;

	new->fd = open(argv, O_RDONLY);
	new->h = 0;
	new->w = 0;
	y = 0;
	if (new->fd < 0)
		return (1);
	new = (t_map *) ft_calloc(1, sizeof(t_map));
	while (get_next_line(new->fd))
		new->h += 1;
	close (new->fd);
	new->map = (char **) ft_calloc(new->h + 1, sizeof(char *));
	new->fd = open(argv, O_RDONLY);
	while (y < new->h)
	{
		new->map[y] = get_next_line(new->fd);
		y++;
	}
	while (new->map[0][new->w++ + 2]) ;
	close(new->fd);
	return (new);
}

int	main(int argc, char **argv)
{
	t_map	*map;

	if (argc != 2)
	{
		closeprogram("Invalid number of arguments to run function. Must be 2\n");
	}
	if (check_map_file(argv[1]))
		return (1);
	map = read_map(argv[1]);
	init_components(map);
	check_walls(map);
	valid_map(map);
	map->mlx = mlx_init();
	map->win = mlx_new_window(map->mlx, map->w * 32, map->h * 32, "so_long");
	render_map(map);
	parse_map(map);
	mlx_hook(map->win, 17, 0, exitprogram, NULL);
	mlx_hook(map->win, 2, 1L<<0, keypress_hook, map);
	mlx_loop(map->mlx);
	return (0);
}
