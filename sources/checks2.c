/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarks <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 19:02:08 by jmarks            #+#    #+#             */
/*   Updated: 2022/10/01 19:59:35 by jmarks           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

static void	flood_fill(t_map *map, int paint, int y, int x)
{
	if (map->map_copy[y][x] == 'C')
	{
		map->copy_ccount++;
		map->map_copy[y][x] = '0';
	}
	else if (map->map_copy[y][x] == 'E')
	{
		map->copy_ecount++;
		map->map_copy[y][x] = '0';
	}
	if (map->map_copy[y][x] == '0')
	{
		map->map_copy[y][x] = paint;
		flood_fill(map, paint, y, x + 1);
		flood_fill(map, paint, y, x - 1);
		flood_fill(map, paint, y + 1, x);
		flood_fill(map, paint, y - 1, x);
	}
}

int	valid_path(t_map *map, int y, int x)
{
	map->map_copy = ft_calloc(1, sizeof(map->map));
	y = map->playery;
	x = map->playerx;
	copy_map(map->map, map->map_copy);
	flood_fill(map, 'P', y, x);
	if (map->ccount != map->copy_ccount)
	{
		closeprogram("Map cannot be solved\n");
	}
	if (map->ecount != map->copy_ecount)
	{
		closeprogram("Map cannot be solved\n");
	}
	return (1);
}

int	valid_map(t_map *map)
{
	check_walls(map);
	valid_count(map);
	valid_path(map, map->playery, map->playerx);
	return (0);
}
