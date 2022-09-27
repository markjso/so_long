/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*  checks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarks <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 17:07:20 by jmarks            #+#    #+#             */
/*   Updated: 2022/09/26 15:45:19 by jmarks           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

static void	valid_shape(t_map *map)
{
	int	y;
	int	x;
	int	line;

	y = 0;
	x = 0;
	line = ft_strlen(map->map[0]);
	while (map->map[x] != 0)
	{
		y = ft_strlen(map->map[x]);
		if (y != line)
		{
			ft_putstr("Error\nThe map is not a rectangle\n");
			closeprogram();
		}
		x++;
	}
}

void	check_walls(t_map *map)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (map->map[y][x + 1])
	{
		if (map->map[y][x] != '1' || map->map[map->h - 1][x] != '1')
		{
			ft_putstr("Error\nMap is not surrounded by walls\n");
			closeprogram();
		}
		x++;
	}
	while (map->map[y])
	{
		if (map->map[y][0] != '1' || map->map[y][map->w - 1] != '1')
		{
			ft_putstr("Error\nMap is not surrounded by walls\n");
			closeprogram();
		}
		y++;
	}
	valid_shape(map);
}

static void	item_count(t_map *map, int y, int x)
{
	if (map->map[y][x] != '1' &&
			map->map[y][x] != '0' &&
			map->map[y][x] != 'P' &&
			map->map[y][x] != 'E' &&
			map->map[y][x] != 'C')
	{
		ft_putstr("Error\nInvalid character in map file\n");
		closeprogram();
	}
	else if (map->map[y][x] == 'E')
		map->ecount++;
	else if (map->map[y][x] == 'C')
		map->ccount++;
	else if (map->map[y][x] == 'P')
	{
		map->pcount++;
		y = map->playery;
		x = map->playerx;
	}
}

void	valid_map(t_map *map)
{
	int	y;
	int	x;

	y = 0;
	while (y < map->h - 1)
	{
		x = 0;
		while (x < map->w - 1)
		{
			item_count(map, y, x);
			x++;
		}
		y++;
	}
	if (map->ccount < 1)
	{
		ft_putstr("Error\nThere are no collectables\n");
		closeprogram();
	}
	if (map->pcount > 1 || map->ecount > 1)
	{
		ft_putstr("Error\nThere is more than one player or exit\n");
		closeprogram();
	}
}
