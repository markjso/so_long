/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarks <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 18:51:04 by jmarks            #+#    #+#             */
/*   Updated: 2022/09/30 15:58:34 by jmarks           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	valid_move(t_map *map, int y, int x, int keycode)
{
	if (map->map[y][x] == '1')
		return (-1);
	if (map->map[y][x] == 'C')
		map->ccount--;
	if (map->map[y][x] == 'E' && map->ccount == 0)
	{
		map->end = 1;
		ft_putstr("Congratulations, you have won the game!");
		exit (1);
	}
	else if (map->map[y][x] == 'E')
	{
		ft_putstr("You have not collected all of the treasure!\n");
		return (-1);
	}
	if (keycode != LEFT && keycode != RIGHT && keycode != UP && keycode != DOWN)
		return (-1);
	else
		return (0);
}

static void	move(t_map *map, int y, int x, int keycode)
{
	int	check;
	int	col;
	int	row;

	col = map->playery;
	row = map->playerx;
	check = valid_move(map, y, x, keycode);
	if (check != -1)
	{
		map->map[col][row] = '0';
		map->playery = y;
		map->playerx = x;
		map->map[y][x] = 'P';
		ft_putstr("Number of steps: ");
		ft_putnbr(map->steps++);
		ft_putstr("\n");
		ft_putstr("Amount of treasure to collect: ");
		ft_putnbr(map->ccount);
		ft_putstr("\n");
	}
}

int	keypress_hook(int keycode, t_map *map)
{
	int	y;
	int	x;

	y = map->playery;
	x = map->playerx;
	if (keycode == LEFT)
		x--;
	else if (keycode == RIGHT)
		x++;
	else if (keycode == UP)
		y--;
	else if (keycode == DOWN)
		y++;
	else if (keycode == ESC)
	{
		ft_putstr("Thanks for playing! So long.\n");
		exit (1);
	}
	if (map->end != 1)
		move(map, y, x, keycode);
	parse_map(map);
	return (0);
}
