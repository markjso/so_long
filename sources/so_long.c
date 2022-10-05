/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarks <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 15:53:39 by jmarks            #+#    #+#             */
/*   Updated: 2022/10/04 17:33:11 by jmarks           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	init_components(t_map *map)
{
	map->pcount = 0;
	map->ccount = 0;
	map->ecount = 0;
	map->copy_ccount = 0;
	map->copy_ecount = 0;
	map->end = 0;
	map->counter = 0;
	map->steps = 1;
}

static int	get_width(char *str)
{
	int	x;

	x = 0;
	while (str[x] != '\0')
		x++;
	if (str[x - 1] == '\n')
		x--;
	return (x);
}

t_map	*read_map(char *argv)
{
	t_map	*new;
	int		y;

	new = (t_map *) ft_calloc(1, sizeof(t_map));
	new->fd = open(argv, O_RDONLY);
	new->h = 0;
	y = 0;
	if (new->fd < 0)
	{
		ft_putstr("Map file does not exist\n");
		exit (1);
	}
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
	close(new->fd);
	new->w = get_width(new->map[0]);
	return (new);
}

int	main(int argc, char **argv)
{
	t_map	*map;

	if (argc != 2)
	{
		ft_putstr("Error\nInvalid number of argument, there must be 2.\n");
		return (1);
	}
	if (check_map_file(argv[1]))
		return (1);
	map = read_map(argv[1]);
	init_components(map);
	valid_map(map);
	map->mlx = mlx_init();
	map->win = mlx_new_window(map->mlx, map->w * 32, map->h * 32, "so_long");
	render_map(map);
	parse_map(map);
	mlx_hook(map->win, 17, 0, exitprogram, NULL);
	mlx_hook(map->win, 2, 1L << 0, keypress_hook, map);
	mlx_loop(map->mlx);
	return (0);
}
