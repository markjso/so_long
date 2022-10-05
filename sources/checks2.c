/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarks <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 19:02:08 by jmarks            #+#    #+#             */
/*   Updated: 2022/10/05 10:50:54 by jmarks           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

int	check_map_file(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	if (str[i - 1] != 'r' && str[i - 2] != 'e'
		&& str[i - 3] != 'b' && str[i - 4] != '.')
	{
		ft_putstr("Error\nMap must be a .ber file\n");
		return (1);
	}
	return (0);
}

static void	flood_fill(t_map *copy, int paint, int y, int x)
{
	if (copy->map_copy[y][x] == '1')
		return ;
	else if (copy->map_copy[y][x] == 'C')
	{
		copy->copy_ccount++;
		copy->map_copy[y][x] = '0';
	}
	else if (copy->map_copy[y][x] == 'E')
	{
		copy->copy_ecount++;
		copy->map_copy[y][x] = '0';
	}
	if (copy->map_copy[y][x] == '0')
	{
		copy->map_copy[y][x] = paint;
		flood_fill(copy, paint, y, x + 1);
		flood_fill(copy, paint, y, x - 1);
		flood_fill(copy, paint, y + 1, x);
		flood_fill(copy, paint, y - 1, x);
	}
}

static int	valid_path(t_map *map, int y, int x)
{
	map->map_copy = malloc(sizeof(char *) * (map->w + 1));
	copy_map(map->map_copy, map->map);
	y = map->playery;
	x = map->playerx;
	map->map_copy[y][x] = '0';
	flood_fill(map, 'P', y, x);
	if (map->ccount != map->copy_ccount)
	{
		closeprogram("Map cannot be solved, path is not valid\n");
	}
	if (map->ecount != map->copy_ecount)
	{
		closeprogram("Map cannot be solved, path is not valid\n");
	}
	return (1);
}

int	valid_map(t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (map->map[y] != NULL)
	{
		x = 0;
		while (map->map[y][x] != '\0')
		{
			if (map->map[y][x] == 'P')
			{
				map->playerx = x;
				map->playery = y;
			}
			x++;
		}
		y++;
	}
	check_walls(map);
	valid_count(map);
	valid_path(map, map->playery, map->playerx);
	return (0);
}
