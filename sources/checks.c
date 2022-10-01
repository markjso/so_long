/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*  checks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarks <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 17:07:20 by jmarks            #+#    #+#             */
/*   Updated: 2022/09/28 15:16:20 by jmarks           ###   ########.fr       */
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
			closeprogram("The map is not a rectangle\n");
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
			closeprogram("Map is not surrounded by walls\n");
		}
		x++;
	}
	while (map->map[y])
	{		if (map->map[y][0] != '1' || map->map[y][map->w - 1] != '1')
		{
			closeprogram("Map is not surrounded by walls\n");
		}
		y++;
	}
	valid_shape(map);
}

static int	item_count(t_map *map, int y, int x)
{
	if (map->map[y][x] == 'E')
		map->ecount++;
	if (map->map[y][x] == 'C')
		map->ccount++;
	if (map->map[y][x] == 'P')
	{
		map->pcount++;
		y = map->playery;
		x = map->playerx;
	}
	if (map->map[y][x] != '1' &&
			map->map[y][x] != '0' &&
			map->map[y][x] != 'P' &&
			map->map[y][x] != 'E' &&
			map->map[y][x] != 'C')
	{
		closeprogram("Invalid character in map file\n");
		return (0);
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
	if (map->ccount == 0)
		closeprogram("There are no collectables\n");
	if (map->pcount < 1)
		closeprogram("There must be a player in the game\n");
	if (map->pcount > 1)
		closeprogram("There cannot be more than one player\n");
	if (map->ecount < 1)
		closeproegram("here must be an exit in the game\n");
	if (map->ecount > 1)
		closeprogram("There can only be one exit in the game\n");
	check_walls(map);
}

void	flood_fill(t_map *map, int y, int x)
{
	if (map->map[y][x] == 'P' || map->map[y][x] == 'C' || map->map[y][x] == 'E' || map->map[y][x] == '0')
	{
		flood_fill(map, y, x + 1);
		flood_fill(map, y, x - 1);
		flood_fill(map, y + 1, x);
		flood_fill(map, y - 1, x);
	}
	return (1);
}
