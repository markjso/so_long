/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarks <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 12:05:18 by jmarks            #+#    #+#             */
/*   Updated: 2022/09/26 16:52:37 by jmarks           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	place_player(t_map *map, int height, int width)
{
	mlx_put_image_to_window(map->mlx, map->win, map->player,
		width * 32, height * 32);
	map->playery = height;
	map->playerx = width;
}

void	place_collectable(t_map *map)
{
	int	height;
	int	width;

	height = 0;
	while (map->map[height])
	{
		width = 0;
		while (map->map[height][width])
		{
			if (map->map[height][width] == 'C')
				mlx_put_image_to_window(map->mlx, map->win,
					map->collectable, width * 32, height * 32);
			width++;
		}
		height++;
	}
}

void	render_map(t_map *map)
{
	int	x;
	int	y;

	map->wall = mlx_xpm_file_to_image(map->mlx, "graphics/water.xpm", &x, &y);
	map->space = mlx_xpm_file_to_image(map->mlx, "graphics/sand.xpm", &x, &y);
	map->player = mlx_xpm_file_to_image(map->mlx,
			"graphics/pirate.xpm", &x, &y);
	map->collectable = mlx_xpm_file_to_image(map->mlx,
			"graphics/treasure.xpm", &x, &y);
	map->exit = mlx_xpm_file_to_image(map->mlx, "graphics/x.xpm", &x, &y);
}

void	parse_map(t_map *map)
{
	int		height;
	int		width;

	height = 0;
	while (map->map[height])
	{
		width = 0;
		while (map->map[height][width])
		{
			if (map->map[height][width] == '1')
				mlx_put_image_to_window(map->mlx, map->win, map->wall,
					width * 32, height * 32);
			if (map->map[height][width] == '0')
				mlx_put_image_to_window(map->mlx, map->win, map->space,
					width * 32, height * 32);
			if (map->map[height][width] == 'P')
				place_player(map, height, width);
			if (map->map[height][width] == 'E')
				mlx_put_image_to_window(map->mlx, map->win, map->exit,
					width * 32, height * 32);
			width++;
		}
		height++;
		place_collectable(map);
	}
}
